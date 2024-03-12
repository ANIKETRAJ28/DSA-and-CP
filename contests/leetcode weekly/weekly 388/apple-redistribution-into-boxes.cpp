#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/apple-redistribution-into-boxes/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = capacity.size();
        int m = apple.size();
        int apples = 0;
        for(int i = 0 ; i < m ; i++) {
            apples += apple[i];
        }
        int cnt = 0;
        sort(capacity.begin(), capacity.end());
        for(int i = n-1 ; i >= 0 ; i--) {
            apples -= capacity[i];
            cnt++;
            if(apples <= 0) return cnt;
        }
        return cnt;
    }
};

int main() {
    
    return 0;
}