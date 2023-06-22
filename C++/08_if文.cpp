#include <iostream>
using namespace std;

int main()
{
    if (10) {
        cout << "Execute because it is non-zero\n";
        cout << "The second line can also be executed by {}\n";
    }
    
    int x;
    cout << "Put any number you like in x\n";
    cin >> x;
    if (x == 10){
        cout << "x is 10\n";
    }
    if (x != 5){
        cout << "x is not 5\n";
    }
    if (x > 5 && x < 20){
        cout << "x is between 5 and 20\n";
    }
    if (x < 0 || x > 5){
        cout << "x is more than 5 or less than 0\n";
    }

    int y = 15;

    if (x == y){
        cout << "x is y\n";
    } else {
        cout << "x is not y\n";
    }

    if (x == y){
        cout << "x is y\n";
    } else if (x > y){
        cout << "x is more than y\n";
    } else{
        cout << "x is less than y\n";
    }
}


