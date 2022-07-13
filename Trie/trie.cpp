#include<iostream>
using namespace std;
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
        int index=word[0]-'A';
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


//    searching
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
           return root->isTerminal;
        }
        int index=word[0]-'A';
        TrieNode* child;

        // present element 
        if(root->children[index] != NULL){
            child=root->children[index];
        }

        // not present
        else{
            return false;
        }
       return searchUtil(child,word.substr(1));
    }

    bool search(string word){
        return searchUtil(root,word);
    }
     
     bool isEmpty(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i]){
                return false;
            }

        }
        return true;
     }
    // deletion
    TrieNode* removeUtil(TrieNode* root,string word,int depth=0){
        if(root==NULL){
            return NULL;
        }
        if(depth==word.size()){
           if(root->isTerminal){
            root->isTerminal=false;
           }
           if(isEmpty(root)){
            delete root;
            return NULL;
           }
           return root;
        }

        int index=word[depth]-'A';
        root->children[index] = removeUtil(root->children[index],word,depth+1);
        if(isEmpty(root) && root->isTerminal==false){
            delete root;
            root=NULL;
        }
        return root;
    }
    void remove(string word){
       removeUtil(root,word);
    }
};
int main(){
    Trie *t=new Trie();
    t->insert("ARM");
    t->insert("DO");
    t->insert("TIME");
    cout<<"search or not: "<<t->search("DO")<<endl;
    cout<<"search or not: "<< t->search("TIME")<<endl;
    t->remove("DO");
    cout<<"search or not: "<<t->search("DO")<<endl;
}