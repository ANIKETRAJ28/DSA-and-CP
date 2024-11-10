#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/smallest-divisible-digit-product-i/description/

class Solution {
public:
    int prod(int n) {
        int ans = 1;
        while(n) {
            ans *= n%10;
            if(ans == 0) return 0;
            n /= 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        while(true) {
            if(prod(n)%t == 0) return n;
            n++;
        }
        return -1;
    }
};

int main() {
    
    return 0;
}