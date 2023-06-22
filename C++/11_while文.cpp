#include <iostream>
using namespace std;

int main()
{
    int num = 100;
    while(num > 0){
        num -= 10;
        cout << num + 10 <<  " - 10 = " << num << "\n";
    }

    do{
        cout << "Don't enter a value greater than 0!\n";
        cin >> num;
    }while(num > 0);
    cout << "Good. Now you're out of the endless loop.\n";
}