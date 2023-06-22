#include <iostream>
using namespace std;

int main()
{
    string hello[3];
    hello[0] = "Hello " ;
    hello[1] = "World! ";
    hello[2] = "C++ ";
    cout << hello[0] << hello[1] << hello[2] << "\n";

    string greeding[3] = {"Good ","Morning ","C++ "};
    cout << greeding[0] << greeding[1] << greeding[2] << "\n";

    string bye[] = {"Good ","Bye ","C++ "};
    cout << bye[0] << bye[1] << bye[2] << "\n";

    int kuku[9][9];
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            kuku[i-1][j-1] = i*j;
        }
    }
    cout << "Kuku! Select two numbers" << "\n";
    int x,y;
    cin >> x >> y;
    cout << kuku[x-1][y-1];
    return 0;
}

