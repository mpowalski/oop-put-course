#include <iostream>
#include <map>
using namespace std;

class Cantor {
 public:
  Cantor() = default;
  virtual ~Cantor() = default;
  virtual double Rate(const string& abbreviation) const = 0;
};
class FakeUsdCantor : public Cantor {
 private:
  map<string, double> rates_;
 public:
  FakeUsdCantor() {
    rates_ = {
      {"EUR", 0.85},
      {"JPY", 110.66},
      {"GBP", 0.73},
      {"CHF", 0.91},
      {"CAD", 1.25},
      {"AUD", 1.34},
      {"CNY", 6.47},
      {"HKD", 7.78},
      {"NZD", 1.44},
      {"KRW", 1153.89}
    };
  }
  double Rate(const string& abbreviation) const override {
    auto it = rates_.find(abbreviation);
    if (it != rates_.end()) {
      return it->second;
    }
    return 0.0;
  }
};
class Currency {
 public:
  Currency() = default;
  virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
  virtual string Abbreviation() const = 0;
  virtual double Amount() const = 0;
};
class Euro : public Currency {
private:
    string abbr;
    double amount;
public:
    Euro(double a){abbr = "JPY"; amount = a;}
    string Abbreviation()const override{return abbr;}
    double Amount()const override{return amount;}
    double ConvertedToDollars(const Cantor& cantor) const override {return amount/cantor.Rate(abbr);};
};
int main() {
    class Euro euro(1000.0);
    class FakeUsdCantor FUC;
    cout << euro.Abbreviation() << " ";
    cout << euro.Amount() << endl;
    cout << "in USD: " << euro.ConvertedToDollars(FUC) << endl;
  return 0;
}
