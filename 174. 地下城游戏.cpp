class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(), n=dungeon[0].size();
        vector<vector<int> > dp(m);
        for (int i=0; i<m; i++)
            dp[i].resize(n);
        dp[m-1][n-1] = 1;
        if (dungeon[m-1][n-1] < 0)
        	dp[m-1][n-1] = 1 - dungeon[m-1][n-1];
        for (int i=n-2; i>=0; i--){
        	dp[m-1][i] = dp[m-1][i+1] - dungeon[m-1][i];
        	if (dp[m-1][i] <= 0)
        		dp[m-1][i] = 1;
        }
        for (int i=m-2; i>=0; i--){
        	dp[i][n-1] = dp[i+1][n-1] - dungeon[i][n-1] ;
        	if (dp[i][n-1] <= 0)
        		dp[i][n-1] = 1
        }
        int tmp1, tmp2;
        for (int i=m-2; i>=0; i--){
        	for (int j=n-2; j>=0; j--){
        		tmp1 = dp[i][j+1] - dungeon[i][j];
        		tmp2 = dp[i+1][j] - dungeon[i][j];
        		dp[i][j] = tmp1 < tmp2 ? tmp1 : tmp2;
        		if (dp[i][j] <= 0)
        			dp[i][j] = 1;
        	}
        }
        return dp[0][0];
    }
};