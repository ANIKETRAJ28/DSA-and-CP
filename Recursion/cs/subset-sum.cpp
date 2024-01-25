#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/subset-sum_630213?leftPanelTabValue=PROBLEM

bool flag = false;
void f(vector<int> &s, int i, int sum, int k) {
    int n = s.size();
    if(sum == k) {
        flag = true;
        return;
    }
    if(i == n or sum > k) {
        return;
    }
    if(flag) return; 
    f(s, i+1, sum, k);
    if(flag) return;
    f(s, i+1, sum + s[i], k);
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    f(a, 0, 0, k);
    return flag;
}

int main(){
    
    return 0;
}