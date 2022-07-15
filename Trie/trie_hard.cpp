#include<iostream>
using namespace std;

// creation

https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
   public:
   TrieNode* root;
   Trie(){
    root=new TrieNode('\0');
   }
   void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
           root->isTerminal=true;
           return;
        }
        int index=word[0]-'a';
        TrieNode* child;

        // present element 
        if(root->children[index] != NULL){
            child=root->children[index];
        }

        // not present
        else{
            child=new TrieNode(word[0]);
            root->children[index] = child;
        }
       insertUtil(child,word.substr(1));
   }

   void insert(string word){
    insertUtil(root,word);
   }


// print all the suggestion 
    void printsuggestion(TrieNode* curr,vector<string> &temp,string prefix){
        if(curr->isTerminal){
            // push the all the one side suggestion to the temp
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            TrieNode* next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printsuggestion(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    
   vector<vector<string>> getSuggestion(string str){
    // contain previous and curr node 
       TrieNode* prev=root;
       vector<vector<string>> output;
       string prefix="";
       for(int i=0;i<str.length();i++){
           char lastch=str[i];
        //    we include prefix here bcz we dont traverse the trie from the root when we print suggestion 
           prefix.push_back(lastch);
           TrieNode *curr=prev->children[lastch-'a'];
           
//            if not found
           if(curr==NULL){
               break;
           }
           vector<string>temp;
           printsuggestion(curr,temp,prefix);
           output.push_back(temp);
           temp.clear();
           prev=curr;
       }
       return output;
   }
};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t=new Trie();
    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insert(str);
    }
    return t->getSuggestion(queryStr);
}

// medium question

https://www.codingninjas.com/codestudio/problems/implement-trie_1387095
class TrieNode{
    public:
    TrieNode* children[26];
    int countPrefix,countWord;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;          
        }
        countPrefix=0;
        countWord=0;
    }
};
class Trie{

    public:
    TrieNode* root;
    Trie(){
        // Write your code here.
        root=new TrieNode();
    }

    void insert(string &word){
        // Write your code here.
        TrieNode* curr=root;
        // insertion through iteration
        for(int i=0;i<word.length();i++){
            if(curr->children[word[i]-'a'] == NULL)
                curr->children[word[i]-'a']=new TrieNode();
              curr=curr->children[word[i]-'a'];
            //  track of count prefix during insertion  
              curr->countPrefix++;
        }
        // similiar track count word during insertion 
        curr->countWord+=1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        TrieNode* curr= root;
        // here we traverse the whole string in the end we find the count word that show 
        // how many string come to the similiar name
        for(int i=0;i<word.length();i++){
            if(curr->children[word[i]-'a'] == NULL)
                return 0;
            curr=curr->children[word[i]-'a'];
        }
        return curr->countWord;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        TrieNode* curr=root;
        // here we traverse when string is not over 
        // when we track the every letter come by the help of countPrefix that why we find that how many time
        // the prefix has come  
        for(int i=0;i<word.length();i++){
            if(curr->children[word[i]-'a'] == NULL)
                return 0;
            curr=curr->children[word[i]-'a'];
        }
        return curr->countPrefix;
    }

    void erase(string &word){
        // Write your code here.
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++){
            curr=curr->children[word[i]-'a'];
            curr->countPrefix--;
        }
        curr->countWord--;
    }
};
