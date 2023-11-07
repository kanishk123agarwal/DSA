// subsequence of string 
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

// void subSequences(string str,string output,int index){
//     // base case
//     if(index>=str.length()){
//         cout<<output<<endl;
//         return ;
//     }

//     char ch=str[index];
//     // exclude
//     subSequences(str,output,index+1);

//     // include
//     output.push_back(ch);
//     subSequences(str,output,index+1);
// }


// T.C - O(n*2^n)
void subsequence(string &str){
   int num_seq=pow(2,str.size());

   for(int n=0;n<num_seq;n++){
    string out;
    int num=n;

    // convert num to binary
    int i=0;
    while(num){
        int b=(num & 1); //it gives last binary digit 
        if(b)
            out.push_back(str[i]);
        i++;
        num>>=1;
    }
    cout<<out<<endl;
   }
}

// permutation of a string -- important

void printPermutation(string &str,int index){
    // base case
    if(index>=str.length()){
        cout<<str<<" ";
        return;
    }

    for(int j=index;j<str.length();j++){
        swap(str[index],str[j]);
        printPermutation(str,index+1);
        // backtracking - recursion ki tarah hai bs apan bapas aate hua kuch operation perform krte hai
        swap(str[index],str[j]);
    }
}


int main(){
    // string str="abc";
    // subSequences(str,"",0);


    string str="abc";
    // subsequence(str);
    int index=0;
    printPermutation(str,index);
    return 0;
}