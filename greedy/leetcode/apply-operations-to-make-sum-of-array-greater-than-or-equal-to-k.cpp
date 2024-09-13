#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/

class Solution {
public:
    int minOperations(int k) {
        int plus = 0;
        int num = 1;
        int ans = INT_MAX;
        while(num <= k) {
            int val = num;
            int dubl = 0;
            while(val < k) {
                val += num;
                dubl++;
            }
            ans = min(ans, dubl+plus);
            dubl = 0;
            num++;
            plus++;
        }
        return ans;
    }
};

class Solution {
public:
    int minOperations(int k) {
        if(k == 1) return 0;
        int minOp = INT_MAX;
        for(int i = 1 ; i <= k ; i++) {
            int inc = i-1;
            int dbl = ceil(k/(i*1.0))-1;
            minOp = min(minOp, inc+dbl);
        }
        return minOp;

        if(k == 1) return 0;
        int inc = ceil(sqrt(k))-1;
        int dup = ceil((k*1.0)/(inc+1))-1;
        return inc+dup;
    }
};

int main() {
    
    return 0;
}