#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-element-in-arrays

class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        int maxi = 0;
        for(int i = 0 ; i < n ; i++) {
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};

int main() {
    
    return 0;
}