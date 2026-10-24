#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int gizliSayi = (rand() % 10) + 1;
    int tahmin;
    cout << "Sayi tahmin oyununa hosgeldiniz!" << endl;
    while (true) {
        cout << "Tahmininiz: ";
        if (!(cin >> tahmin)) {
            cout << "Gecersiz giris!" << endl;
            break;
        }
        if (tahmin < 1 || tahmin > 10) {
            cout << "Lutfen 1 ile 10 arasinda bir sayi giriniz!" << endl;
        }
        else if (tahmin < gizliSayi) {
            cout << "Yukari cik!" << endl;
        }
        else if (tahmin > gizliSayi) {
            cout << "Asagi in!" << endl;
        }
        else {
            cout << "Tebrikler, bildiniz!" << endl;
            break;
        }
    }
    return 0;
}
