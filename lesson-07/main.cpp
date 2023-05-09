#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
class Logarithm {
private:
  double base_;
  double argument_;
 public:
  Logarithm(double base, double argument) {base_ = base; argument_ = argument;}
  double Calculate() const {return std::log(argument_) / std::log(base_);}
  void Errors(){
      if(base_ <= 0)
        throw invalid_argument("base is < or = 0");
      if(base_ == 0)
        throw invalid_argument("base is = 0");
      if(argument_ <= 0)
        throw invalid_argument("argument is < or = 0");
  }
};

int main()
{
    while(1){
        double b = 0, a = 0;
        cout << "base: " << endl;
        cin >> b;
        cout << "argument: " << endl;
        cin >> a;
        try{
            Logarithm log(b, a);
            log.Calculate();
            log.Errors();
        }catch(invalid_argument e){
            cerr << e.what();
        }
    }
    return 0;
}
