#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<bool> Sieve(int n){
    vector<bool>sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    // for(int i=2;i<=n;i++){  //optimization 2nd in the outer loop
    for(int i=2;i*i<=n;i++){
        if(sieve[i]==true){
            // int j=i*2;
            // first otimization in the inner loop 
            int j=i*i; //bcz there is repetition of number that mark false in the above multiple like 2*3 or 3*2 /  2*5 or 5*2
            while(j<=n){
                sieve[j]=false;
                j=j+i;
            }
        }
    }
    return sieve;
}

// now talk about segement sieve
vector<bool> segSieve(int l,int r){
    vector<bool>sieve=Sieve(sqrt(r));
    vector<int>basePrime;
    for(int i=0;i<sieve.size();i++){
        if(sieve[i]){
            basePrime.push_back(i);
        }
    }

    vector<bool>segSieve(r-l+1,true);
    if(l==1 || l==0){
        segSieve[l]=false;
    }
    for(auto prime:basePrime){
        int first_mul=(l/prime)*prime;
        if(first_mul<l){
            first_mul+=prime;
        }
        int j=max(first_mul,prime*prime);
        while(j<=r){
            segSieve[j-l]=false;
            j=j+prime;
        }
    }
    return segSieve;
}
int main(){
    // vector<bool>sieve=Sieve(25);
    // for(int i=2;i<=25;i++){
    //     if(sieve[i]){
    //         cout<<i<<" ";
    //     }
    // }

    int l=110;
    int r=130;
    vector<bool>ss=segSieve(l,r);
    for(int i=0;i<ss.size();i++){
        if(ss[i]){
            cout<<i+l<<" ";
        }
    }
    return 0;
}