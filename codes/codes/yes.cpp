#include <iostream>
using namespace std;
char islem;
double x;
double y;
int main (){
   cout << "1.sayiyi girin: ";
   cin >> x;
   cout << "yapmak istediginiz islemi (+,-,*,/) girin: ";
   cin >> islem;
   cout << "2.sayiyi girin: ";
   cin >> y;
   if (islem == '+') {
    cout << x + y;
   }
   if (islem == '-') {
    cout << x - y;
   }
   if (islem == '*') {
    cout << x * y;
   }
   if (islem == '/') {
    cout << x / y;
   }
}
