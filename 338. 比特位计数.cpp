class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        if (num == 0)
            return dp;
        dp[1] = 1;
        if (num == 1)
            return dp;
        dp[2] = 1;
        if (num == 2)
            return dp;
        int power_cur = 2;
        int power_next = 4;
        for (int i = 3; i<=num; i++){
            if (i == power_next){
                dp[i] = 1;
                power_cur = i;
                power_next *= 2;
            }else
                dp[i] = dp[i-power_cur] + 1;
        }
        return dp;
    }
};