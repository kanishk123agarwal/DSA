// QUES 1 :- CYCLE DETECTION IN UNDIRECTED GRAPH BY USING
// 1)BFS
// 2)DFS


// QUES 2 :- CYCLE DETECTION IN DIRECTED GRAPH BY USING 
// 1) DFS 
// 2) BFS 


// QUES 3 :- TOPOLOGICAL SORT 
// 1) DFS
// 2) BFS

// QUES 4 :- Shortest path in an unweighted graph
// BFS 



// check the cycle in undirected graph using bfs and dfs
https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<stack>
#include<vector>
#include<limits.h>
#include<iostream>
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



    //     using BFS
//     create adjacent list 
    unordered_map<int,list<int> > adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;
        
        adj[u].push_back(v);
    }
    
    vector<int> indegree(n);
    for(auto i: adj){
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }
    
//     0 indegree waaloko push krna hai
    queue<int> q;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
//     do bfs
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
//         inc cnt
        cnt++;
        
//         update the indegree of neighbour
        for(auto neighbour: adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }
    if(cnt==n){
        return  false;
    }
    return true;
45
}



// topological sort by using bfs and dfs
Topological Sort

Problem Statement
A Directed Acyclic Graph (DAG) is a directed graph that contains no cycles.
Topological Sorting of DAG is a linear ordering of vertices such that for every directed edge from vertex ‘u’ to vertex ‘v’, vertex ‘u’ comes before ‘v’ in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
Given a DAG consisting of ‘V’ vertices and ‘E’ edges, you need to find out any topological sorting of this DAG. Return an array of size ‘V’ representing the topological sort of the vertices of the given DAG.
For example, Consider the DAG shown in the picture.

In this graph, there are directed edges from 0 to 1 and 0 to 3, so 0 should come before 1 and 3. Also, there are directed edges from 1 to 2 and 3 to 2 so 1 and 3 should come before 2.
So, The topological sorting of this DAG is {0 1 3 2}.
Note that there are multiple topological sortings possible for a DAG. For the graph given above one another topological sorting is: {0, 3, 1, 2}
Note:
1. It is guaranteed that the given graph is DAG.
2. There will be no multiple edges and self-loops in the given DAG.
3. There can be multiple correct solutions, you can find any one of them. 
4. Don’t print anything, just return an array representing the topological sort of the vertices of the given DAG.
Input Format:
The first line of input contains an integer ‘T’ denoting the number of test cases. The description of  ‘T’ test cases follows.

The first line of each test case contains two space-separated integers ‘V’, ‘E’, representing the number vertices and edges in the graph respectively.

Then ‘E’ lines follow,  each containing 2 space-separated integers ‘u’, ‘v’ representing that there is a directed edge from vertex ‘u’ to vertex ‘v’
Output Format :
For each test case, return an array representing the topological sort of the vertices of the given DAG.
Note :
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 50
1 <= V <= 10^4
0 <= E <= 10^4
0 <= u, v < V 

Where ‘T’ is the total number of test cases, ‘V’ is the number of vertices, ‘E’ is the number of edges, and ‘u’ and ‘v’ both represent the vertex of a given graph.

Time limit: 2 sec
Sample Input 1:
2
2 1
1 0
3 2
0 1
0 2
Sample Output 1:
1 0
0 2 1
Explanation Of Sample Input 1:
Test case 1:
The number of vertices ‘V’ = 2 and number of edges ‘E’ = 1.
The graph is shown in the picture: 

The topological sorting of this graph should be {1, 0}  as there is a directed edge from vertex 1 to vertex 0, thus 1 should come before 0 according to the given definition of topological sorting.

Test case 2:
The number of vertices ‘V’ = 3 and number of edges ‘E’ = 2.
The graph is shown in the picture:

As there are two directed edges starting from 0, so 0 should come before 1 and 2 in topological sorting. 
Thus the topological sorting of this graph should be {0, 2, 1} or {0, 1, 2}
Sample Input 2:
2
1 0
4 4
0 1
0 3
1 2
3 2
Sample Output 2:
0
0 1 3 2
Explanation Of Sample Input 2:
Test case 1:   
There is only a single vertex in the graph that is 0, so its topological sort will be {0}.

Test case 2:
See problem statement for its explanation
Previous
Next
 
}
1
#include<unordered_map>
2
#include<list>
3
#include<stack>
4
#include<queue>
5
#include<vector>
6
​
7
// using DEPTH FIRST SEARCH
8
void topoSort(int node,vector<bool> &visited,stack<int> &s,unordered_map<int,list<int> > &adj){
9
    visited[node]=true;
10
    for(auto neighbour:adj[node]){
11
        if(!visited[neighbour]){
12
            topoSort(neighbour,visited,s,adj);
13
        }
14
    }
15
    s.push(node);
16
}
17
​
18
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
19
    // Write your code here
20
//     create an adjacent list
21
    unordered_map<int,list<int> > adj;
22
    for(int i=0;i<e;i++){
23
        int u=edges[i][0];
24
        int v=edges[i][1];
25
        
26
        adj[u].push_back(v);
27
    }
28
    
29
//     Handle all the different component in the graph
30
//     using dfs  
31
//     T.C O(V+E)
32
//     S.C O(V)
33
//     vector<bool> visited(v);
34
//     stack<int> s;
35
//     for(int i=0;i<v;i++){
36
//         if(!visited[i]){
37
//             topoSort(i,visited,s,adj);
38
//         }
39
//     }
40
//     vector<int> ans;
41
//     while(!s.empty()){
42
//         ans.push_back(s.top());
43
//         s.pop();
44
//     }
45
//     return ans;
46
    
47
    
48
//     using bfs
49
//     T.C O(N+E)
50
//     S.C O(N+E)
51
//     find all indegree 
52
    vector<int> indegree(v);
53
    for(auto i: adj){
54
        for(auto j: i.second)
55
        {
56
            indegree[j]++;
57
        }
58
    }
59
    
60
//     0 indegree waaloko push krna hai
61
    queue<int> q;
62
    vector<int> ans;
63
    for(int i=0;i<v;i++){
64
        if(indegree[i]==0){
65
            q.push(i);
66
        }
67
    }
68
    
69
//     do bfs
70
    while(!q.empty()){
71
        int front=q.front();
72
        q.pop();
73
        
74
//         ans store krwa lo 
75
        ans.push_back(front);
76
        
77
//         update the indegree of neighbour
78
        for(auto neighbour: adj[front]){
79
            indegree[neighbour]--;
80
            if(indegree[neighbour] == 0){
81
                q.push(neighbour);
82
            }
83
        }
84
    }
85
    return ans;
86
}

// Shortest path in an unweighted graph
// using bfs

#include<unordered_map>
#include<list>
#include<queue>

// T.C O(N+E)
// S.C O(N+E)

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create adj list
    unordered_map<int,list<int> > adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
//     do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                parent[neighbour]= front;
                q.push(neighbour);
            }
        }
    }
    
//     prepare sorthest path
    vector<int> ans;
    int currentNode=t;
    ans.push_back(t);
    while(currentNode != s){
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin() , ans.end());
	return ans;
}

// DIRECTED PATH IN ACYCLIC GRAPH
// using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int>> > adj;
    void addEdge(int u,int v,int weight){
       pair<int,int> p=make_pair(v,weight);
       adj[u].push_back(p);
    }
    void printAdj(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
               cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }

    // first find topological sort
    void dfs(int node,unordered_map<int,bool> &vis,stack<int> &topo){
        vis[node]=true;
        for(auto neighbour:adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour.first,vis,topo);
            }
        }
        topo.push(node);
    }

    void getShortestPath(int src,vector<int> &dis,stack<int> &topo){
        dis[src]=0;
        while(!topo.empty()){
            int top=topo.top();
            topo.pop();
            if(dis[top] != INT_MAX){
                for(auto i:adj[top]){
                    if(dis[top] + i.second <dis[i.first]){
                        dis[i.first]=dis[top]+i.second;
                    }
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(1,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    int n=6;
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }
    int src=1;
    vector<int> dis(n);
    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;

    }

  g.getShortestPath(src,dis,s);
  cout<< "answer is "<<endl;
  for(int i=0;i<dis.size();i++){
    cout<<dis[i]<<" ";

  }cout<<endl;
  return 0;
}



// DIJSTRA ALGORITHMS
https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar


#include<set>
#include<unordered_map>
#include<list>

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    
//     create adjacent list
    unordered_map<int,list<pair<int,int> > > adj;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
//     disatnce array
    vector<int> dis(vertices);
    
//     initialise distance array to maximum
    for(int i=0;i<vertices;i++){
        dis[i] = INT_MAX;
    }
    set<pair<int,int> > st;
    dis[source] = 0;
    
//     initialise the set
    st.insert(make_pair(0,source));
    
    while(!st.empty()){
        
//         fetch topNode
        auto top = *(st.begin());
        
        int distance=top.first;
        int topNode = top.second;
        
//         remove top node
        st.erase(st.begin());
        
//         traverse all neighbour
        for(auto neighbour : adj[topNode]){
            if(distance + neighbour.second<dis[neighbour.first])             {
                auto record = st.find(make_pair(dis[neighbour.first],neighbour.first));
                if(record != st.end()){
                    st.erase(record);
                }
                
//                 distance update
                dis[neighbour.first] = distance + neighbour.second;
                
//                 update the set
                st.insert(make_pair(dis[neighbour.first],neighbour.first));
            }
        }
    }
    return dis;
}

