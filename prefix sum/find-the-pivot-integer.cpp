#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/find-the-pivot-integer/description

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n), suffix(n);
        int sum = 0;
        for(int i = 0  ; i < n ; i++) {
            sum += i+1;
            prefix[i] = sum;
        }
        sum = 0;
        for(int i = n-1  ; i >= 0 ; i--) {
            sum += i+1;
            suffix[i] = sum;
        }
        for(int i = 0 ; i < n ; i++) {
            if(prefix[i] == suffix[i]) return i+1;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}