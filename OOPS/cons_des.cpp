#include <iostream>
#include <string>
using namespace std;
class Customer{
  string name;
  int balance;
  int acc_no;
  public:
  // Default Constructor
  Customer(){
    name="";
    balance=0;
    acc_no=0;
  }

  // Parameterized Constructor
  Customer(string n,int b,int a){
    name=n;
    balance=b;
    acc_no=a;
  }

  // Overloading Constructor
  // Customer(string name,int balance){
  //   this->name=name;
  //   this->balance=balance;
  // }

  // inline constructor
  inline Customer(string name,int acc):name(name),acc_no(acc){}

  // copy Constructor
  Customer(Customer &c){
    name=c.name;
    balance=c.balance;
    acc_no=c.acc_no;
  }

  void display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Balance: "<<balance<<endl;
    cout<<"Account No: "<<acc_no<<endl;
  }

  // Destructor
  ~Customer(){
    cout<<"Destructor called"<<endl;
  }
};

int main(){
  Customer a1;
  Customer a2("Kanishk",1000,1234);
  Customer a3("Rohit",2000);
  Customer a4("Neha",5678);
  Customer a5(a2);

  a1.display();
  a2.display();
  a3.display();
  a4.display();
  a5.display();

}