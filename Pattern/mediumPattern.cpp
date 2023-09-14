#include<iostream>
using namespace std;
int main(){
    // pattern 1 fliped solid diamond
// **** ****
// ***   ***
// **     **
// *       *
// *       *
// **     **
// ***   ***
// **** ****
    // int num=8;
    // int n=4;
    // for(int i=0;i<n;i++){
    //     // inverted pyramid 1
    //     for(int j=0;j<n-i;j++){
    //         cout<<"*";
    //     }
    //     // full pyramid 1
    //     for(int j=0;j<2*i+1;j++){
    //         cout<<" ";
    //     }
    //     // inverted pyramid 2
    //     for(int j=0;j<n-i;j++){
    //          cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     // inverted pyramid 1
    //     for(int j=0;j<i+1;j++){
    //         cout<<"*";
    //     }
    //     // full pyramid 1
    //     for(int j=0;j<2*n-2*i-1;j++){
    //         cout<<" ";
    //     }
    //     // inverted pyramid 2
    //     for(int j=0;j<i+1;j++){
    //          cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // fancy pattern
// 1
// 2*2
// 3*3*3
// 4*4*4*4
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<2*i+1;j++){
    //         if(j%2==1){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<i+1;
    //         }
    //     }
    //     cout<<endl;
    // }

    // hollow inverted half pyramid
    // for(int i=0;i<6;i++){
    //     for(int j=0;j<6-i;j++){
    //         if(i==0){
    //             cout<<"* ";
    //         }
    //         else if(j==0 || j==6-i-1){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // increasing alphabet
    // for(int i=0;i<5;i++){
    //     char ch;
    //     for(int j=0;j<i+1;j++){
    //         ch='A' + j;
    //         cout<<ch;
    //     }
    //     // end tk jana hai jab tk A nhi aata
    //     for(char alphabet=ch-1;alphabet>='A';alphabet--){
    //         cout<<alphabet;
    //     }
    //     cout<<endl;
    // }

    // numeric hollow inverted half pyramid
// 12345
// 2  5
// 3 5
// 45
// 5
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5-i;j++){
    //         if(i==0){
    //             cout<<j+1;
    //         }
    //         else if(j==0){
    //             cout<<i+1;
    //         }
    //         else if(j==5-i-1)cout<<5;
    //         else cout<<" ";
    //     }
    //     cout<<endl;
    // }

    // numeric palindrome equilateral pyramid
//     1
//    121
//   12321
//  1234321
// 123454321
    // for(int i=0;i<5;i++){
    //     int no=1;
    //     for(int j=0;j<5;j++){
    //         if(j<5-i-1){
    //             cout<<" ";
    //         }
    //         else cout<<no++;
    //     }
    //     for(int j=no-2;j>=1;j--){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }

    // pattern
// ********1********
// *******2*2*******
// ******3*3*3******
// *****4*4*4*4*****
// ****5*5*5*5*5****
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<2*5-i-2;j++){
    //         cout<<"*";
    //     }
    //     cout<<i+1;
    //     for(int j=0;j<i;j++){
    //         cout<<"*"<<i+1;
            
    //     }
    //     for(int j=0;j<2*5-i-2;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    // floyd triangle
    // int count=1;
    // for(int i=0;i<6;i++){
        
    //     for(int j=0;j<i+1;j++){
    //         cout<<count;
    //         count++;
    //     }
    //     cout<<endl;
    // }

    // solid half diamond pattern
// *
// **
// ***
// ****
// ***
// **
// *
    // int n=4;
    // for(int i=0;i<2*n-1;i++){
    //     if(i<n){
    //         for(int j=0;j<i+1;j++){
    //             cout<<"*";
    //         }
    //     }
    //     else{
    //         for(int j=0;j<2*n-i-1;j++){
    //             cout<<"*";
    //         }
    //     }
    //     cout<<endl;
    // }

    // butterfly pattern
// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout<<"*";
    //     }
    //     for(int j=0;j<2*4-2*i-2;j++){
    //        cout<<" ";
    //     }
    //     for(int j=0;j<i+1;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4-i;j++){
    //        cout<<"*";
    //     }
    //     for(int j=0;j<2*i;j++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<4-i;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    
    // hollow full pyramid
//     *    
//    * *   
//   *   *  
//  *     * 
// *********
    // for(int i=0;i<5;i++){
    //     int k=0;
    //     for(int j=0;j<2*5-1;j++){
    //         if(j<5-i-1) cout<<" ";
    //         else if(k<2*i+1){
    //             if(k==0||k==2*i||i==5-1){
    //                 cout<<"*";
    //             }
    //             else cout<<" ";
    //             k++;
    //         }
    //         else cout<<" ";
    //     }
    //     cout<<endl;
    // }

    // fancy pattern
// 1
// 2*3
// 4*5*6
// 7*8*9*10
// 7*8*9*10
// 4*5*6
// 2*3
// 1
    // int c=1;
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout<<c;
    //         c++;
    //         if(j<i)cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // int start=c-4;
    // for(int i=0;i<4;i++){
    //     int k=start;
    //     for(int j=0;j<4-i;j++){
    //         cout<<k;
    //         k++;
    //         if(j<4-i-1)cout<<"*";
    //     }
    //     start=start-(4-i-1);
    //     cout<<endl;
    // }

    // fancy 3
// 1
// 121
// 12321
// 121
// 1
    // for(int i=0;i<5;i++){
    //     int cond=i<=5/2 ?  2*i:2*(5-i-1);
    //     for(int j=0;j<=cond;j++){
    //         if(j<=cond/2){
    //             cout<<j+1;
    //         }
    //         else{
    //             cout<<(cond-j+1);
    //         }
    //     }cout<<endl;
    // }


    // pascal triangle--fix all things

    // formula c=c*(i-j)/j 
    // for row [1,n] 
    // for column [1,i]
    // for(int i=1;i<=4;i++){
    //     int C=1;
    //     for(int j=1;j<=i;j++){
    //         cout<<C<<" ";
    //         C = C * (i-j)/j;
    //     }
    //     cout<<endl;
    // }


    // new pattern
// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1
    // for(int i=0;i<5;i++){
    //     int k=1;
    //     for(int j=0;j<5;j++){
    //         if(j<5-i){
    //            cout<<k;
    //            k++;
    //         }
    //         else{
    //             cout<<"*";
    //         }
    //     }
    //     int count=5-i;
    //     for(int j=0;j<5;j++){
    //         if(j<i)cout<<"*";
    //         else cout<<count--;
    //     }
    //     cout<<endl;
    // }

    // hollow half pyramid
    for(int i=0;i<9;i++){
        for(int j=0;j<2*i+1;j++){
            if(i==0 || j==0 || i==9-1 || j==2*i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}