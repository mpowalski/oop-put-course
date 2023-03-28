#include <iostream>
using namespace std;

class Account{
private:
    double USD;
    double PLN;
public:
    double Funds(){return PLN;};
    double FundsInUSD(){return USD;};
    Account(){PLN = 0.0; USD = 0.0;};
    Account(double x){PLN = x; USD = PLN * 4.32;}
    Account(string s) : Account(stod(s)){};
};
int main()
{
    class Account PKO;
    class Account PKOpremium(123.47);
    class Account PKOsecret("1876.47");
    cout << "normal account  -->  PLN: " << PKO.Funds() << "         USD: " << PKO.FundsInUSD() << endl;
    cout << "premium account -->  PLN: " << PKOpremium.Funds() << "    USD: " << PKOpremium.FundsInUSD() << endl;
    cout << "secret account  -->  PLN: " << PKOsecret.Funds() << "   USD: " << PKOsecret.FundsInUSD() << endl;
    return 0;
}
