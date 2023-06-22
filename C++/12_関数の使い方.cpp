#include <iostream>
using namespace std;

void hello(){
    cout << "Hello World!\n";
}

void tashizan(int a,int b){
    cout << a + b << "\n";
}

int kakezan(int a, int b){
    int c = a*b;
    return c;
}

void nibai(int);

int main()
{
    hello();
    int x =5;
    int y = 10;
    tashizan(x,y);
    int result = kakezan(x,y);
    cout << "The result of the multiplication is " << result << "\n";
    nibai(x);
    return 0;
}

void nibai(int a){
    cout << 2*a;
}