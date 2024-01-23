#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/powx-n/description/

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long double ans = 0;
        if(n < 0) {
            x = 1/x;
            n = abs(n);
        }
        ans = myPow(x, n/2);
        ans *= ans;
        if(n %2 != 0) ans *= x;
        return ans;
    }
};

int main(){
    
    return 0;
}