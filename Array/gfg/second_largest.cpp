#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest

class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(int arr[], int n) {
        // code here
        int f_max = INT_MIN, s_max = INT_MIN;
        for(int i = 0 ; i < n ; i++) {
            if(f_max < arr[i]) {
                s_max = f_max;
                f_max = arr[i];
            } else if(s_max < arr[i] && arr[i] != f_max) {
                s_max = arr[i];
            }
        }
        return s_max == INT_MIN ? -1 : s_max;
    }
};

int main() {
    
    return 0;
}