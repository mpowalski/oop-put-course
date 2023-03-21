#include <iostream>

using namespace std;

class Grandma{
private:
    string recipe = "steak";
public:
    string dinner;
    void cook(){
        cout << "Grandma: Todays dinner is " + recipe << endl;
    }
};
class Grandma g;

class Grandson{
private:
    string hunger;
public:
    string wanna;
    void Eat(){
        cout << "Do I wanna eat? (y/n)" << endl;
        cin >> wanna;
        if(wanna == "y"){
            g.cook();
            hunger = "SMALL";
        }
        if(wanna == "n"){
            hunger = "BIG";
        }
    }
    string howBigHunger(){
        return "My hunger is " + hunger;
    }
};
class Grandson s;

int main()
{
    s.Eat();
    cout << s.howBigHunger() << endl;
    return 0;
}
