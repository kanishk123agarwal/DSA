
// check the cycle in undirected graph using bfs and dfs
https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<queue>
#include<unordered_map>
#include<list>
using namespace std;
bool isCyclicBFS(int src,unordered_map<int,bool> &visited ,unordered_map<int,list<int> > &adj ){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
               return true; 
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}
bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited ,unordered_map<int,list<int> > &adj){
    visited[node]=true;
    
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclicDFS(neighbour,node,visited,adj);
            if(cycleDetected){
                return true;
            }
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // create adjacent list
    unordered_map<int,list<int> > adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
        
//     to handle the different component in the graph
//     using BFS
    unordered_map<int,bool> visited;
//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             bool ans=isCyclicBFS(i,visited,adj);
//             if(ans==true){
//                 return "Yes";
//             }
//         }
//     }
//     return "No";
    
//     cycle detected
//     using DFS
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCyclicDFS(i, -1 , visited,adj);
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No";
    
    
}


// cycle detection in directed graph using dfs
https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar



Detect Cycle In A Directed Graph
Difficulty: MEDIUM
Contributed By
Priyaraj Sharma
|
Level 1
Avg. time to solve
30 min
Success Rate
75%
Problem Statement
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].
Find whether the graph contains a cycle or not, return true if a cycle is present in the given directed graph else return false.
For Example :
In the following directed graph has a cycle i.e. B->C->E->D->B.

Note :
1. The cycle must contain at least two nodes.
2. It is guaranteed that the given graph has no self-loops in the graph.
3. The graph may or may not be connected.
4. Nodes are numbered from 1 to N.
5. Your solution will run on multiple test cases. If you are using global variables make sure to clear them.
Input Format :
The first line of input contains an integer 'T' representing the number of the test case. Then the test cases are as follows.

The first line of each test case argument given is an integer ‘N’ representing the number of nodes in the graph.

The second line of each test case contains a given integer ‘M’ representing the number of edges. 

The next ‘M’ lines in each test case contain a matrix ‘EDGES’ of size M x 2 which represents the ‘M’ edges such that there is an edge directed from node EDGES[i][0] to node EDGES[i][1].
Output Format :
For each test case, print true if a cycle is present in the given directed graph else print false.
Note :
You do not need to print anything; It has already been taken care of. 
Constraints :
1 ≤ T ≤ 5

2 <= N <= 100
1 <= M <= min(100,N(N-1)/2)
1 <= EDGES[i][0], EDGES[i][1] <= N

Where ‘T’ is the number of test cases.

Time Limit: 1 sec
Sample Input 1 :
1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1 :
true
Explanation For Input 1 :
The given graph contains cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.
Sample Input 2 :
2
5
4
1 2
2 3
3 4
4 5
2
1
1 2
Sample Output 2 :
false
false
Explanation For Input 2 :
The given graphs don’t contain any cycle.
Previous
Next
 
1
#include<unordered_map>
2
#include<list>
3
#include<queue>
4
​
5
bool checkCycle(int src,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsVisited,unordered_map<int,list<int> > &adj){
6
    visited[src]=true;
7
    dfsVisited[src]=true;
8
    for(auto neighbour:adj[src]){
9
        if(!visited[neighbour]){
10
            bool cycleDetected = checkCycle(neighbour,visited,dfsVisited,adj);
11
            if(cycleDetected){
12
                return true;
13
            }
14
        }
15
        else if(dfsVisited[neighbour]){
16
            return true;
17
        }
18
    }
    // when we returning so we give false to dfs visited that show no one can arrive abbtk
19
    dfsVisited[src]=false;
20
    return false;
21
}
22
 
23
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
24
  // create the adjacent list
25
    unordered_map<int,list<int> > adj;
26
    for(int i=0;i<edges.size();i++){
27
        int u=edges[i].first;
28
        int v=edges[i].second;
29
        
30
        adj[u].push_back(v);
31
    }
32
//     call dfs for all component
33
    unordered_map<int,bool> visited;
34
    unordered_map<int,bool> dfsVisited;
35
    
36
    for(int i=1;i<=n;i++){
37
        if(!visited[i]){
38
            bool cycleFound=checkCycle(i,visited,dfsVisited,adj);
39
            if(cycleFound){
40
                return true;
41
            }
42
        }
43
    }
44
    return false;
45
}

