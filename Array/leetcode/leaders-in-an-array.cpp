#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> leader;
        int ldr = arr[n-1];
        leader.push_back(arr[n-1]);
        for(int i = n-2 ; i >= 0 ; i--) {
            if(arr[i] >= ldr) {
                ldr = arr[i];
                leader.push_back(ldr);
            }
        }
        reverse(leader.begin(), leader.end());
        return leader;
    }
};

int main() {
    
    return 0;
}