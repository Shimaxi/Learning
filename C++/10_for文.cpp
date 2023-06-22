#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string message = ": Hello World!\n";
    for (int i = 0; i < 5; i++){
        cout <<  i+1 << message;
    }

    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            cout << i*j << "|";
            //printf("%2d|",i*j);
        }
        cout << "\n";
    }

    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            cout << setw(3) << i*j << "|";
        }
        cout << "\n";
    }
}