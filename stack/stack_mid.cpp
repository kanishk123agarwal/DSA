#include<iostream>
#include<stack>
using namespace std;

bool checkRedundant(string str){
    stack<char> st;
    
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        // maine pehle saare element push krdiye exept 'a,b' or any alphabet that is present in the expression
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%'){
            st.push(ch);
        }
        // ab yha pr apan ne check kiye top jab tk '(' yeh nhi hoga jabn tk apan count krenge operator ka 
        else if(ch==')'){
            int countOp=0;
            while(!st.empty() && st.top()!='('){
                // char temp=st.top();
                // if(temp=='+' || temp=='*' || temp=='-' || temp=='%' || temp=='/'){
                //     countOp++;
                // }
                countOp++;
                st.pop();
            }
            // yha pr stack ka top '(' is pai hoga to isko bhi remove krna hai 
            // mistake ho skti hai yha pr 
            st.pop();
            // agar koi operator present nhi hai to vo redundant brackets hai 
            if(countOp==0){
                return true;
            }
        }

    }
    return false;
}

int main(){
    string str="(((a+b)*(c+d)))";
    bool ans=checkRedundant(str);
    if(ans==true){
        cout<<"Redundant Brackets present"<<endl;
    }
    else{
        cout<<"Redundant Brackets not present"<<endl;
    }
}