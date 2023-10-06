#include<bits/stdc++.h>
#define ll long long int
#define infp INT_MAX
#define infn INT_MIN
#define mod 1000000007

using namespace std;
template<typename T>
using vec = vector<T>;

// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:

    void dfs(vector<vector<int>>& rooms, unordered_set<int> &visited, int idx){

        visited.insert(idx); // room visited
        for(auto keys : rooms[idx]){
            if(visited.count(keys) == 0){ // neighbour not yet visited
                dfs(rooms, visited, keys);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        // queue<int> qu;
        // qu.push(0);
        // visited.insert(0);

        // while(not qu.empty()){
        //     int curr = qu.front();
        //     qu.pop();

        //     for(auto neighbour : rooms[curr]){
        //         if(visited.count(neighbour) == 0){ // neighbour not yet visited
        //             visited.insert(neighbour);
        //             qu.push(neighbour);
        //         }
        //     }
        // }
        // return visited.size() == rooms.size();
        dfs(rooms, visited, 0);
        return visited.size() == rooms.size();
    }
};

int main(){
    
    return 0;
}