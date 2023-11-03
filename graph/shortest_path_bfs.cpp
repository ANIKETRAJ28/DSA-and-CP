#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vec vector<ll>
#define vecvec vector<vector<ll>>
using namespace std;

vector<list<int>> graph;
int v; // vertex
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void bfs(int src, int dest, vector<int> &dist){
    queue<int> q;
    visited.clear();
    dist.resize(v, 0); // shortest path of src from src is 0
    // dist[src] = 0;
    q.push(src);
    visited.insert(src);

    while(not q.empty()) {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto neighbour : graph[curr]){
            if(not visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
                dist[neighbour] = 1 + dist[curr];
            }
        }
    }
    cout<<"\tthe sequence in which elements are being input\n";
}

int main(){
    cin>>v;
    graph.resize(v, list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s, d;
        cin>>s>>d;
        add_edge(s, d);
    }
    int s, d;
    cin>>s>>d;
    vector<int> dist;
    bfs(s, d, dist);
    for(auto ele : dist){
        cout<<ele<<" ";
    }
    return 0;
}
// eg. input
// 7
// 8
// 0 1
// 0 4
// 1 3
// 4 3
// 1 5
// 5 6
// 6 2
// 5 2
// 0 6