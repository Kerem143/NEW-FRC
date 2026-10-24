import os
import subprocess
from flask import Flask, render_template, request, jsonify

app = Flask(__name__)
CODES_DIR = os.path.join(os.getcwd(), 'codes')
os.makedirs(CODES_DIR, exist_ok=True)

@app.route('/')
def index():
    files = [f for f in os.listdir(CODES_DIR) if f.endswith('.cpp')]
    return render_template('index.html', files=files)

@app.route('/run', methods=['POST'])
def run_code():
    data = request.json
    filename = data.get('filename')
    user_input = data.get('input', '')

    if not filename:
        return jsonify({'output': 'Hata: Lütfen bir C++ dosyası seçin!'})

    filepath = os.path.join(CODES_DIR, filename)
    if not os.path.exists(filepath):
        return jsonify({'output': f'Hata: {filename} dosyası bulunamadı!'})

    binary_name = filename.replace('.cpp', '')
    binary_path = os.path.join(CODES_DIR, binary_name)
    compile_proc = subprocess.run(['g++', filepath, '-o', binary_path], capture_output=True, text=True)
    if compile_proc.returncode != 0:
        return jsonify({
            'output': f"--- DERLEME HATASI ---\n{compile_proc.stderr}"
        })

  
    try:
        run_proc = subprocess.run(
            [binary_path],
            input=user_input,
            capture_output=True,
            text=True,
            timeout=5
        )
        output = run_proc.stdout
        if run_proc.stderr:
            output += f"\n[Uyarı/Hata]:\n{run_proc.stderr}"
        return jsonify({'output': output})
    except subprocess.TimeoutExpired:
        return jsonify({'output': "Hata: Program zaman aşımına uğradı (Sonsuz döngü olabilir)."})
    except Exception as e:
        return jsonify({'output': f"Çalıştırma hatası: {str(e)}"})

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=7784)
