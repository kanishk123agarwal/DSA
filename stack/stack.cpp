#include<iostream>
#include<stack>
using namespace std;

// set the precedence
int prec(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    return -1;
}

void infixToPostfix(string s){
    stack<char> st;
    char c;
    string result;
    for(int i=0;i<s.length();i++){
        c=s[i];
        if((c>='a' && c<='z') || (c>='A' && c<= 'Z') || (c>='0' && c<='9')){
            result+=c;

        }
        else if(c=='('){
            st.push('(');
        }
        else if(c==')'){
            while(st.top() != '('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(s[i]) <= prec(st.top())){
                if(c=='^' && st.top() != '^'){
                    break;
                }
                else{
                    result+=st.top();
                    st.pop();
                }
                
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    cout<<result<<endl;
}

int main(){
    string s="a+b*(c^d-e)^(f+g*h)-i";

    infixToPostfix(s);
    return 0;
}