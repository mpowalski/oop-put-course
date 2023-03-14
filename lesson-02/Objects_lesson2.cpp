#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
class Human{
    public:
        string name;
        string surname;
        int age;
    };
    class Wall{
    public:
        int height;
        int width;
        string colour;
    };
int main()
{
    srand(time(NULL));
    Human thomas;
    cout << "type name: ";
    cin >> thomas.name;
    cout << "type surename: ";
    cin >> thomas.surname;
    thomas.age = rand()%99;
    cout << "random age: " << thomas.age << endl;
    Wall willy;
    willy.height = 5;
    willy.width = 5;
    willy.colour = "white";
    cout << "wall hight: " << willy.height << endl;
    cout << "wall width: " << willy.width << endl;
    cout << "wall colour: " << willy.colour << endl;


    return 0;
}
