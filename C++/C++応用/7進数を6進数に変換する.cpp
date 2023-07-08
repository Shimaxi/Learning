#include <iostream>
using namespace std;

int main(){
    // 7進数の入力を受け取り、10進数に変換して和を取る
    string a;
    int sum = 0;
    while(cin>>a){
        sum += stoi(a, nullptr, 7);
    }
    
    // 10進数を6進数に変換
    string ans = "";
    while (sum > 0){
        int amari = sum % 6;
        ans = (char)(48 + amari) + ans;
        sum /= 6;
    }
    cout << ans << endl;
    
    return 0;
}