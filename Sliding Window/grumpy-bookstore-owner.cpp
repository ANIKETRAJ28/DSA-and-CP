#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/grumpy-bookstore-owner/description/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int ans = 0, maxAns = 0, res = 0;
        for(int i = 0 ; i < n ; i++) if(grumpy[i] == 0) res += customers[i];
        int j = 0, i = 0;
        while(i < n && grumpy[i] != 1) {
            i++;j++;
        }
        for(i ; i < n ; i++) {
            if(minutes > 0 && grumpy[i] == 1) {
                ans += customers[i];
            }
            minutes--;
            maxAns = max(maxAns, ans);
            while(j < n && minutes == 0) {
                if(grumpy[j] == 1) {
                    ans -= customers[j];
                }
                minutes++;
                j++;
            }
            while(j < n && grumpy[j] != 1) {
                minutes++;
                j++;
            }
        }
        return res+maxAns;
    }
};

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int n = customers.size();
        int idx = 0;
        int loss = 0;
        for(int i = 0 ; i < minutes ; i++) {
            if(grumpy[i] == 1) {
                loss += customers[i];
            }
        }
        int maxLoss = loss;
        int i = 0, j = minutes;
        while(j < n) {
            if(grumpy[i] == 1) {
                loss -= customers[i];
            }
            if(grumpy[j] == 1) {
                loss += customers[j];
            }
            if(maxLoss < loss) {
                maxLoss = loss;
                idx = i+1;
            }
            i++;
            j++;
        }
        for(i = idx ; i < idx+minutes ; i++) {
            grumpy[i] = 0;
        }
        for(int i = 0 ; i < n ; i++) {
            if(grumpy[i] == 0) {
                ans += customers[i];
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}