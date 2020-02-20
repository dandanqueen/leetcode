class Solution {
public:
	int maxCoins(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
        	return 0;
        if (size == 1)
        	return nums[0];
        int balloons[502], dp[501][501], max, tmp;
        balloons[size+1] = balloons[0] = 1;
        for (int i=0; i<size; i++)
        	balloons[i+1] = nums[i];
        for (int i=1; i<=size; i++)
        	dp[i][i] = balloons[i-1]*balloons[i]*balloons[i+1];
        for (int k=2; k<=size; k++)
        	for (int i=1,j=k; j<=size; i++,j++){
        		max = dp[i+1][j] + balloons[i-1] * balloons[i] * balloons[j+1];
        		tmp = dp[i][j-1] + balloons[i-1] * balloons[j] * balloons[j+1];
        		if (tmp > max)
        			max = tmp;
        		for (int n=i+1; n<j; n++){
        			tmp = dp[i][n-1] + dp[n+1][j] + balloons[i-1] * balloons[n] * balloons[j+1];
        			if (tmp > max)
        				max = tmp;
        		}
        		dp[i][j] = max;
        	}
       	return dp[1][size];
    }
