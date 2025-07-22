#include <iostream>
#include <string>
using namespace std;

class Student
{
  // initially in c++ all variables are private by default
  string name;
  int age, roll_no;
  string grade;

public:
  void setName(string s)
  {
    name = s;
  }
  void setAge(int a)
  {
    age = a;
  }
  void setRollNo(int r)
  {
    roll_no = r;
  }

  void setGrade(string g)
  {
    grade = g;
  }
  void display()
  {
    cout << "Name:" << name << "\n"
         << "Age:" << age << "\n"
         << "Roll No:" << roll_no << "\n"
         << "Grade:" << grade << endl;
  }
};

class A
{
};

class B
{
public:
};

class C
{
  char c;
  int a;
};

class D
{
  char a;
  int b;
  char c;
};

class E
{
  char a;
  char c;
  int b;
};

int main()
{
  // it doesn't work because we declare all variabe private so we can't access this from outside class
  // Solution
  // 1) Declare Public variables
  // 2) Use Getters and setters method to use them
  // Student s1;
  // s1.name="kanishk";
  // s1.age=20;
  // s1.roll_no=20;
  // s1.grade="A";

  // Solution 1:
  // Student s1;
  // s1.setName("kanishk");
  // s1.setAge(20);
  // s1.setGrade("A++");
  // s1.setRollNo(20);
  // s1.display();

  // Now calculate the size of class
  // 1) Empty class
  // Why it  should give 1 byte when we don't specify any element

  A a;
  cout << sizeof(a) << endl;

  // 2) Empty class with public access specifier
  B b;
  cout << sizeof(b) << endl;

  // 3) We have some variable and size is calculated on padding and alignment
  // Padding means space taken by variable int - 4 and char -1 but it give 8 bytes because it's do padding
  C c;
  cout << sizeof(c) << endl;

  // now we talk about alignment in two different class how size is change
  D d;
  cout << sizeof(d) << endl; // it give size of 12 byte bcz of alignment

  E e;
  cout << sizeof(e) << endl; //it give size of 8 byte bcz of alignment

  // the only difference is we put variable or we can say that alignment is different
  // in 1st casee 
  // char take 1 then padding of 3 byte ,int take 4 byte from 5 to 8 and then char take 1 byte from 9 to 9 and we know that computer take only take size of 2 ki power mai so total is 12 byte 

  // in 2nd case
  // char take 1 byte another char take 1 byte so it consumes 2 byte and next 2 are padding(cross) and int take 4 byte from 5 to 8 so total is 8 byte 
  return 0;
}