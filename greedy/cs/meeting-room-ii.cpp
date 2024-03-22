#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define pp pair<int, int>
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://www.codingninjas.com/studio/problems/meeting-room-ii_893289?leftPanelTabValue=PROBLEM

int minRooms(vector<vector<int>> intervals)
{
    // Write your code here
    int n = intervals.size();
    vector<int> strt(n), endd(n);
    for(int i = 0 ; i < n ; i++) {
        strt[i] = intervals[i][0];
        endd[i] = intervals[i][1];
    }
    sort(strt.begin(), strt.end());
    sort(endd.begin(), endd.end());
    int rooms = 0;
    int ans = 0;
    int i = 0, j = 0;
    while(i < n) {
        if(strt[i] < endd[j]) {
            rooms++;
            i++;
        } else if(strt[i] > endd[j]) {
            rooms--;
            j++;
        } else {
            i++; j++;
        }
        ans = max(ans, rooms);
    }
    return ans == 0 ? 1 : ans;
}


int main() {
    
    return 0;
}