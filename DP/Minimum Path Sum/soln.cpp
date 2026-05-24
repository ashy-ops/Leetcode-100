#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    class point
    {
        public:
            int x;
            int y;

            point(int x,int y)
            {
                this->x = x;
                this->y = y;
            }


        bool isEqual(point p)
        {
            return (this->x == p.x && this->y == p.y);
        }

    };

    int solve(point s,point d, vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        if(dp[s.x][s.y]!=-1) return dp[s.x][s.y];
       else if(s.x ==d.x)
        {
            int sum = 0;
            for(int i=s.y;i<=d.y;i++)sum += grid[s.x][i];

            return sum;
        }
        else if(s.y==d.y)
        {
            int sum=0;
            for(int i=s.x;i<=d.x;i++) sum+=grid[i][s.y];

            return sum;
        }
        else
        {
            return dp[s.x][s.y] = grid[s.x][s.y] + min(solve({s.x,s.y+1},d,grid,dp), solve({s.x+1,s.y},d,grid,dp));
        }
    }

    int minPathSum(vector<vector<int>>& grid){
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));

        return solve( {0,0} , { (int)grid.size()-1, (int)grid[0].size()-1} , grid,dp );
    }
};
