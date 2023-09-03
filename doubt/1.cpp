#include<iostream>
#include"2.h"
using namespace std;
void fun(){
    cout<<"Fun ho gya 1"<<endl;
}
int main(){
    fun();
    funFrom2();

}

// to run this file so we use this command of line
// g++ -c 1.cpp so it makes 1.o means 1.object file 
// g++ -c 2.cpp so it makes 2.o means 2.object file

// here -c denote that it help to makes the cpp file to object file 

// NOW WE LINK BOTH CPP FILE 
// g++ 1.o 2.o -o run 
// ./run 