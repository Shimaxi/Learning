#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Put any number you like in x\n";
    cin >> x;
    switch (x) {
    case 5:
        cout << "x is 5\n";
        cout << "The second line can be executed without {}.\n";
        break;
    case 10:
        cout << "x is 10\n";
        break;
    default:
        cout << "x is neither 5 nor 10\n";
        break;
    }
}