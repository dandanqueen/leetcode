class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
    	m=matrix.size();
    	if (m==0)
    		return;
    	n=matrix[0].size();
    	dp.resize(m);
    	for (int i=0; i<m; i++)
        	dp[i].resize(n);
        dp[m-1][n-1] = matrix[m-1][n-1];
        for (int i=m-2; i>=0; i--)
        	dp[i][n-1] = dp[i+1][n-1] + matrix[i][n-1];
        for (int i=n-2; i>=0; i--)
        	dp[m-1][i] = dp[m-1][i+1] + matrix[m-1][i];
        for (int i=m-2; i>=0; i--){
        	for (int j=n-2; j>=0; j--){
        		dp[i][j] = matrix[i][j] + dp[i][j+1] + dp[i+1][j] - dp[i+1][j+1];
        	}
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    	int sum = dp[row1][col1];
    	if (col2 < n-1)
    		sum -= dp[row1][col2+1];
    	if (row2 < m-1)
    		sum -= dp[row2+1][col1];
    	if (col2 < n-1 && row2 < m-1)
    		sum += dp[row2+1][col2+1];
    	return sum;
    }

 private:
 	vector<vector<int>> dp;
 	int m, n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */