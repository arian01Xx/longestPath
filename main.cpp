#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SolutionFifty{
private:
    int dfs(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<bool>>& visited){
        if(dp[x][y]!=-1) return dp[x][y];
        int n=matrix.size(), m=matrix[0].size();

        visited[x][y]=true;
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};

        int cnt=1;
        for(int i=0; i<4; i++){
            int newX=x+drow[i];
            int newY=y+dcol[i];
            if(newX>=0 && newX<n && newY>=0 && newY<m && matrix[newX][newY]>matrix[x][y]){
                cnt=max(cnt, 1 + dfs(newX, newY, matrix, dp, visited));
            }
        }
        dp[x][y]=cnt;
        return cnt;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0) return 0;
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,-1));
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans=max(ans, dfs(i,j,matrix,dp,visited));
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}