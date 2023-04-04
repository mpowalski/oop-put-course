#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

class Lottery {
public:
    Lottery(){}
    virtual class Lottery* IncreaseRange(int in) = 0;
    virtual int Draw() = 0;
};
class BigLottery : Lottery {
private:
    int range;
public:
    BigLottery(int x){range = x;}
    class BigLottery* IncreaseRange(int in){return new BigLottery(in + range);}
    int Draw(){return(rand() % range);}
};
int main()
{
    srand(time(NULL));
    class BigLottery basicL(10);
    cout << "basic range (10) draw: " << basicL.Draw() << endl;
    class BigLottery* extraL = basicL.IncreaseRange(10);
    cout << "extra range (10 + 10) draw: " << extraL->Draw() << endl;
    return 0;
}
