#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

struct Edges {
	int src, dst, wts;
};

bool cmp(Edges &e1, Edges &e2) {
	return e1.wts < e2.wts;
}

int find(vector<int> &parent, int n) {
	return parent[n] = (parent[n] == n) ? n : find(parent, parent[n]);
}

void Union(vector<int> &parent, vector<int> &rank, int a, int b) {
	a = find(parent, a);
	b = find(parent, b);
	if(a == b) return;
	if(rank[a] >= rank[b]) {
		rank[a]++;
		parent[b] = a;
	} else {
		rank[b]++;
		parent[a] = b;
	}
}

int kruskals(vector<Edges> &graph, int n) {
	vector<int> parent(n+1), rank(n+1, 1);
	for(int i = 1 ; i <= n ; i++) {
		parent[i] = i;
	}
	sort(graph.begin(), graph.end(), cmp);
	int ans = 0;
	for(int i = 0 ; i < graph.size() ; i++) {
		int src = find(parent, graph[i].src);
		int dst = find(parent, graph[i].dst);
		if(src == dst) continue;
		Union(parent, rank, src, dst);
		ans += graph[i].wts;
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(parent[i] == i) cnt++;
	}
	return cnt == 1 ? ans : -1;
}

int getMinimumCost(int n, int m, vector<vector<int>> &connections) {
	//	Write your code here.
	vector<Edges> graph(connections.size());
	for(int i =  0 ; i < connections.size() ; i++) {
		graph[i].src = connections[i][0];
		graph[i].dst = connections[i][1];
		graph[i].wts = connections[i][2];
	}
	return kruskals(graph, n);
}

int main() {
    
    return 0;
}