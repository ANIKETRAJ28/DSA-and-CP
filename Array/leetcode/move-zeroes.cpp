#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        while(i < n && j < n) {
            if(nums[i]) i++;
            else {
                if(j <= i) j = i+1;
                while(j < n && !nums[j]) j++;
                if(j < n) swap(nums[i], nums[j]);
                i++; j++;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        int idx1 = -1;
        int idx2 = -1;
        for(int i = 0 ; i < n ; i++){ // 1 2 3 0 0 0 0 0 5    1 1 1 1 1 1 1   0 0 0 0 0 0
            if(a[i] == 0){
                idx1 = i;
                for(int j = idx1+1 ; j < n ; j++){
                    if(a[j] != 0){
                        idx2 = j;
                        break;
                    }
                }
                break;
            }
        }
        if(idx1 == -1 or idx2 == -1) return;
        while(idx2 < n){
            if(a[idx2] != 0){
                swap(a[idx1], a[idx2]);
                idx1++;
            }
            idx2++;
        }
        return;
    }
};

int main() {
    
    return 0;
}