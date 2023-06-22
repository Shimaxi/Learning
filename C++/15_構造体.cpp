#include <iostream>
using namespace std;

struct Character{
    char name[128];
    int hp;
    int power;
    int defence;
};

void status(struct Character x){
    cout << "HP: " << x.hp << "\n";
}

int main()
{
    struct Character takashi = {"Takashi", 10, 15, 5};
    cout << "Name: " << takashi.name << "\n";

    status(takashi);

    struct Character *p;
    p = &takashi;
    cout << "Power: " << (*p).power << "\n";
    cout << "Defence: " << p->hp << "\n";
    return 0;
}