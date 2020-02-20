class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        int size = coins.size();
        if (size == 0)
            return -1;
        vector<int> dp(amount+1);
        dp[0] = 0;
        for (int i=1; i<=amount; i++){
            if (dp[i] == 1)
                continue;
            for (int j=0,k; j<size; j++){
                k = i-coins[j];
                if ((k == 0 || (k > 0 && dp[k])) && (!dp[i] || dp[k]+1 < dp[i]))
                    dp[i] = dp[k]+1;
            }
        }
        return dp[amount] ? dp[amount] : -1;
    }
};