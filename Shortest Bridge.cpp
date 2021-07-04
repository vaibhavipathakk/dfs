/*
934. Shortest Bridge
Medium


In a given 2D binary array grid, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)

 

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
 

Constraints:

2 <= grid.length == grid[0].length <= 100
grid[i][j] == 0 or grid[i][j] == 1

*/


class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector <pair<int, int>> &r){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j]==0)
            return;
        grid[i][j] = 0;
        r.push_back(make_pair(i,j));
        dfs(grid, i+1, j, r);
        dfs(grid, i-1, j, r);
        dfs(grid, i, j-1, r);
        dfs(grid, i, j+1, r);
        return;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int count = 0;
        vector <pair<int, int>> x;
        vector <pair<int, int>> y;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    count++;
                    if(count == 1){
                        dfs(grid, i, j, x);   
                    }
                    if(count == 2){
                        dfs(grid, i, j, y);   
                    }   
                }
            }
        }
        int min_dist = INT_MAX;
        for(int i=0; i<x.size(); i++){
            for(int j=0; j<y.size(); j++){
                int dist = abs(x[i].first - y[j].first) + abs(x[i].second - y[j].second) - 1;
                if(dist < min_dist)
                    min_dist = dist;
            }
        }
        return min_dist;
    }
};
