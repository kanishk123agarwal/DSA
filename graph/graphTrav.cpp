

// BFS TRAVERSAL
https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<set>
#include<unordered_map>
#include<list>
#include<queue>
// T.C O(V+E)
// S.C O(V+E)
void prepareAdjList(unordered_map<int,set<int> > &adjList , vector<pair<int, int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

// bfs traversl
void bfs(unordered_map<int,set<int> > &adjList, unordered_map<int,bool> &visited,vector<int> & ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        
//         store the element into the answer
        ans.push_back(frontNode);
        
//         traversal all neighbour of front node
        for(auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
        
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int,set<int> > adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    
//     make a adjacent list first 
    prepareAdjList(adjList,edges);
    
    
//     traverse all graph component
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}

// DFS
https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<unordered_map>
#include<set>
#include<list>

void dfs(int node,unordered_map<int,list<int> > &adjList,unordered_map<int,bool> &visited,vector<int> &component){
    
    // first insert the neighbour node
    component.push_back(node);

    // mark visited
    visited[node]=true;
    
//     har node ke liye recursive call
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,adjList,visited,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
//     prepare the adjacent list 
    unordered_map<int,list<int> > adjList;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    // for different-different component like
    // G - g1  g2 here the whole graph G but there in the two graph aur 
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,adjList,visited,component);            
            ans.push_back(component);
        }
    }
    return ans;
}