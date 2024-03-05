#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int n = arr.size();
        for(int i = 0 ; i < k ; i++) {
            sum += arr[i];
        }
        int ans = 0;
        int i = 0;
        int j = k;
        while(j < n) {
            if(sum/k >= threshold) ans++;
            sum -= arr[i];
            sum += arr[j];
            i++; j++;
        }
        if(sum/k >= threshold) ans++;
        return ans;
    }
};

int main() {
    
    return 0;
}