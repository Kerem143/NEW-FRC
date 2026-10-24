#include <iostream>
using namespace std;
string ad;
int sifre;
string islem;
int para;
int bakiye = 10000;
int main() {
    cout << "FRC Bank'a hosgeldiniz!" << endl;
    cout << "Lutfen giris yapin: " << endl;
    cout << "Kullanici Adi: ";
    getline(cin,ad);
    cout << "Sifre: ";
    cin >> sifre;
    cin.ignore();
    cout <<"Hosgeldiniz " << ad << endl;
    cout << "Bakiye: " << bakiye << endl;
    cout << "Yapmak istediginiz islemi (Cek, Yatir) secin: ";
    cin >> islem;
    cout << "Miktari giriniz: ";
    cin >> para;
    if (islem == "Cek" ) {
        if (para > bakiye) {
            cout << "Yetersiz Bakiye! ";
        }
        else{
        cout << "Kalan bakiye:" << bakiye - para << endl;
        bakiye = bakiye - para;
        cout << "Yine bekleriz! ";
        }
    }
    if (islem == "Yatir" ) {
        cout << "Mevcut bakiye:" << bakiye + para << endl;
        bakiye = bakiye + para;
        cout << "Yine bekleriz! ";
    }
}
