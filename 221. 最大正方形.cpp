class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	int m=matrix.size();
    	if (m == 0)
    		return 0;
    	int n=matrix[0].size();
    	vector<vector<int> > dp(m);
    	for (int i=0; i<m; i++)
            dp[i].resize(n);
        int max = 0;
        for (int i=0; i<m; i++){
        	dp[i][0] = (matrix[i][0] == '1' ? 1 : 0);
        	if (dp[i][0] == 1)
        		max = 1;
        }
        for (int i=0; i<n; i++){
        	dp[0][i] = (matrix[0][i] == '1' ? 1 : 0);
        	if (dp[0][i] == 1)
        		max = 1;
        }
        int r, c;
        for (int i=1; i<m; i++)
        	for (int j=1; j<n; j++){
        		if (matrix[i][j] == '0')
        			dp[i][j] = 0;
        		else if (dp[i][j-1] == 0 || dp[i-1][j] == 0)
        			dp[i][j] = 1;
        		else if (dp[i][j-1] == dp[i-1][j]){
        			r = i - dp[i-1][j];
        			c = j - dp[i][j-1];
        			dp[i][j] = (matrix[r][c] == '1' ? dp[i-1][j]+1 : dp[i-1][j]);
        		}else
        			dp[i][j] = (dp[i][j-1] < dp[i-1][j] ? dp[i][j-1]+1 : dp[i-1][j]+1);
        		if (dp[i][j]*dp[i][j] > max)
        			max = dp[i][j]*dp[i][j];
        	}
        return max;
    }
};