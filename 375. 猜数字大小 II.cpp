class Solution {
public:
    int getMoneyAmount(int n) {
    	vector<vector<int>> dp(n+1);
        for (int i=0; i<n+1; i++)
            dp[i].resize(n+1);
        for (int i=1; i<=n; i++)
        	dp[i][i] = 0;
        for (int i=1; i<n; i++)
        	dp[i+1][i] = i;
        for (int i=1; i<n-1; i++)
        	dp[i+2][i] = i+1;
        for (int i=4,max,tmp; i<=n; i++)
        	for (int j=i-3; j>=1; j--){
        		max = INT_MAX;
        		for (int k=i-1; k>j; k--){
        			tmp = dp[i][k+1] > dp[k-1][j] ? k+dp[i][k+1] : k+dp[k-1][j];
        			if (tmp < max)
        				max = tmp;
        		}
        		dp[i][j] = max;
        	}
        return dp[n][1];
    }
};