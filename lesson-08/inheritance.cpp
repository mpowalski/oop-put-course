#include <iostream>
using namespace std;

class Product{
private:
    string name;
    float price;
    int pID;
public:
    Product(string n_, float p_){name = n_; price = p_; pID = 123456;}
    ~Product() = default;
    string productName(){return name;}
    float productPrice(){return price;}
};
class Customer{
private:
    string name;
    string email;
    int cID;
public:
    Customer(){name = "Bob"; email = "bob@gmail.com"; cID = 654321;}
    ~Customer() = default;
};
class Order{
private:
    int oID;
    string order[100];
    int items = 0;
    float amount = 0;
public:
    Order(){oID = 162534;}
    ~Order() = default;
    void addToOrder(string pname){
        items++;
        for(int i = 0; i < items; i++){
            order[i] = pname;
            cout << "order: " << order[i] << endl;
        }
    }
    void amountSum(float a){
        amount += a;
        cout << "amount: " << amount << "$" << endl;
    }
};
int main()
{
    string n_;
    float p_;
    cout << "name of product: ";
    cin >> n_;
    cout << "price of product: ";
    cin >> p_;
    class Product p(n_, p_);
    class Customer c;
    class Order o;
    o.addToOrder(p.productName());
    o.amountSum(p.productPrice());
    cout << "name of product: ";
    cin >> n_;
    cout << "price of product: ";
    cin >> p_;
    class Product p2(n_, p_);
    o.addToOrder(p2.productName());
    o.amountSum(p2.productPrice());
    return 0;
}
