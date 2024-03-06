#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/

class Solution {
public:
#define mod 1000000007
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int o = 0, e = 0, cnt = 0;
        for(int i = 0 ; i < n ; i++) {
            if(arr[i]%2 == 0) e++;
            else {
                swap(o, e);
                o++;
            }
            ans = (ans%mod+o)%mod;
        }
        return ans;
    }
};

int main() {

    return 0;
}