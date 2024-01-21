#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/count-good-numbers/description/

#define mod 1000000007
class Solution {
public:
    long long pow(long long x, long long n) {
        if(n == 0) return 1;
        long long ans = pow(x, n/2);
        ans *= ans;
        ans %= mod;
        if(n %2 == 1){
            ans *= x;
            ans %= mod;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2 + n%2;
        return (pow(5, even)*pow(4, odd))%mod;
    }
};

int main(){
    
    return 0;
}