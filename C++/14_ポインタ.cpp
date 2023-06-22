#include <iostream>
using namespace std;

void nibai(int *x);

int main()
{
    int num = 10;
    cout << "The number is " << num << "\n";
    cout << "The number's address is "<< &num << "\n";
    int *p;
    p = &num;
    cout << "The number's address is "<< p << "\n";
    cout << "The number is "<< *p << "\n";

    nibai(&num);
    cout << "The number is "<< num << " !!!\n";
    return 0;
}

void nibai(int *x){
    *x *= 2;
}
