#include<iostream>
using namespace std;

// FOR SOLVING THE PATTERN QUESTION WE HAVE TO TWO RULE
// 1) FIND THE NO OF ROW 
// LIKE NO OF ROWS = 4
// 2) TO FIND THE PATTERN BY SOME LOGICAL THING AUR SIMPLE ARITHMETIC OPERATION
// LIKE R0->1 STAR
// R1->2 STAR
// R3->3STAR
// R4->4 STAR
// SO PRINT SQUARE PATTERN 

int main(){
// half pyramid

    // for(int i=0;i<5;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // inverted pyramid
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5-i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // square
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // rectangle
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // hollow rectangle
    // for(int i=0;i<8;i++){
    //      for(int j=0;j<6;j++){
    //         if(i==0 || i==7){
    //             cout<<"* ";
    //         }
    //         else{
                
    //             if(j==0 || j==5){
    //                 cout<<"* ";
    //             }
    //             else{ cout<<"  ";}
    //         }
    //      }
    //      cout<<endl;
    // }

    // inverted numeric pattern
    // for(int i=0;i<5;i++){
    //     for(int j=0;j<5-i;j++){
    //         cout<<j+1<<" ";
    //     }
    //     cout<<endl;
    // }

    // full pyramid
    // for(int i=0;i<5;i++){
    //     // for space 
    //     for(int j=0;j<5-i-1;j++){
    //         cout<<" ";
    //     }
    //     // for star
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // invert full pyramid
    // for(int i=0;i<4;i++){
    //     // for space
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     // for star
    //     for(int j=0;j<4-i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // diamond -- combination of full pyramid and inverted pyramid
    // for(int i=0;i<4;i++){
    //     // for space 
    //     for(int j=0;j<4-i-1;j++){
    //         cout<<" ";
    //     }
    //     // for star
    //     for(int j=0;j<i+1;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<4;i++){
    //     // for space
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     // for star
    //     for(int j=0;j<4-i;j++){
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // hollow pyramid
    // for(int i=0;i<4;i++){
    //     // for space 
    //     for(int j=0;j<4-i-1;j++){
    //         cout<<" ";
    //     }
    //     // for star
    //     for(int j=0;j<i+1;j++){
    //         if(j==0 || j==i+1-1){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // inverted hollow pyramid
    // for(int i=0;i<4;i++){
    //     // for space
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     // for star
    //     for(int j=0;j<4-i;j++){
    //         if(j==0 || j==4-i-1){
    //             cout<<"* ";
    //         }
    //         else{
    //             cout<<"  ";
    //         }
            
    //     }
    //     cout<<endl;
    // }

    // hollow diamond
//    * 
//   * *
//  *   *
// *     *
// *     *
//  *   *
//   * *
//    *
    for(int i=0;i<4;i++){
        // for space 
        for(int j=0;j<4-i-1;j++){
            cout<<" ";
        }
        // for star
        for(int j=0;j<i+1;j++){
            if(j==0 || j==i+1-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<4;i++){
        // for space
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        // for star
        for(int j=0;j<4-i;j++){
            if(j==0 || j==4-i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
            
        }
        cout<<endl;
    }
}