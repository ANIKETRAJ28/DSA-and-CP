#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/time-needed-to-buy-tickets/description

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int n = tickets.size();
        for(int i = 0 ; i < n ; i++) {
            if(i <= k) {
                ans += (tickets[i] < tickets[k]) ? tickets[i] : tickets[k];
            } else {
                ans += (tickets[i] < tickets[k]) ? tickets[i] : tickets[k]-1;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}