class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), max=0;
        if (size <= 1)
        	return 0; 
        vector<vector<int>> dp(size);
        for (int i=0; i<size; i++)
        	dp[i].resize(2);
        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];
        dp[1][0] = (dp[0][1]+prices[1] > dp[0][0] ? dp[0][1]+prices[1] : dp[0][0]);
        dp[1][1] = (dp[0][1] > dp[0][0]-prices[1] ? dp[0][1] : dp[0][0]-prices[1]);
        max = (dp[1][0] > max ? dp[1][0] : max);
        for (int i=2; i<size; i++){
        	dp[i][0] = (dp[i-1][0] > dp[i-1][1]+prices[i] ? dp[i-1][0] : dp[i-1][1]+prices[i]);
        	max = (dp[i][0] > max ? dp[i][0] : max);
        	dp[i][1] = (dp[i-1][1] > dp[i-2][0]-prices[i] ? dp[i-1][1] : dp[i-2][0]-prices[i]);
        	max = (dp[i][1] > max ? dp[i][1] : max);
        }
        return max;
    }
};