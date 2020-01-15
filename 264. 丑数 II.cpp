class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[1690], ug_2=0, ug_3=0, ug_5=0;
        dp[0] = 1;
        for (int i=1; i<n; i++){
        	dp[i] = this->min(dp[ug_2]*2, dp[ug_3]*3, dp[ug_5]*5);
        	if (dp[i] >= dp[ug_2]*2)
        		ug_2 += 1;
        	if (dp[i] >= dp[ug_3]*3)
        		ug_3 += 1;
        	if (dp[i] >= dp[ug_5]*5)
        		ug_5 += 1;
        }
        return dp[n-1];
    }
    int min(int x, int y, int z) {
    	int t = (x < y ? x : y);
    	t = (t < z ? t : z);
    	return t;
    }
};