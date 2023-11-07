#include <bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template <typename T>
using vec = vector<T>;

// https://www.hackerrank.com/challenges/kruskalmstrsub/problem

int find(int a, vec<int> &parent)
{
    return parent[a] = (parent[a] == a) ? a : find(parent[a], parent);
}

void Union(vec<int> &parent, vec<int> &rank, int a, int b)
{
    a = find(a, parent);
    b = find(b, parent);

    if (a == b)
        return;
    if (rank[a] >= rank[b])
    {
        rank[a]++;
        parent[a] = b;
    }
    else
    {
        rank[b]++;
        parent[b] = a;
    }
}

struct Edges
{
    int src;
    int dst;
    int wts;
};

bool cmp(Edges e1, Edges e2)
{
    return e1.wts < e2.wts;
}

ll Kruskals(vec<Edges> &input, int n, int e)
{
    sort(input.begin(), input.end(), cmp);
    vec<int> parent(n + 1);
    vec<int> rank(n + 1, 0);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    int edgeCnt = 0;
    int i = 0;
    ll ans = 0;
    while (edgeCnt < n - 1 and i <= input.size())
    {
        Edges curr = input[i];
        int srcPrnt = find(curr.src, parent);
        int dstPrnt = find(curr.dst, parent);
        cout << curr.src << " " << curr.dst << " " << curr.wts << "\n";
        if (srcPrnt != dstPrnt)
        {
            Union(parent, rank, srcPrnt, dstPrnt);
            // cout << curr.src << " " << curr.dst << " " << curr.wts << "\n";
            ans += curr.wts;
            edgeCnt++;
        }
        i++;
    }
    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vec<Edges> input(e);
    for (int i = 0; i < e; i++)
    {
        cin >> input[i].src >> input[i].dst >> input[i].wts;
    }
    cout << Kruskals(input, n, e);
    return 0;
}