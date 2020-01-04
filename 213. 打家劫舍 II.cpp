class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
        	return 0;
        if (size == 1)
        	return nums[0];
        if (size == 2)
        	return nums[0] > nums[1] ? nums[0] : nums[1];
        if (size == 3){
        	int max = nums[0] > nums[1] ? nums[0] : nums[1];
        	max = nums[2] > max ? nums[2] : max;
        	return max;
        }
        vector<vector<int> > dp(size);
        for (int i=0; i<size; i++)
            dp[i].resize(2);
        dp[1][0] = 0;
        dp[1][1] = nums[1];
        for (int i=2; i<size; i++){
        	dp[i][0] = dp[i-1][0] > dp[i-1][1] ? dp[i-1][0] : dp[i-1][1];
        	dp[i][1] = dp[i-1][0] + nums[i];
        }
        int max1 = dp[size-1][0] > dp[size-1][1] ? dp[size-1][0] : dp[size-1][1];
        dp[2][0] = nums[0];
        dp[2][1] = nums[0] + nums[2];
        for (int i=3; i<size-1; i++){
        	dp[i][0] = dp[i-1][0] > dp[i-1][1] ? dp[i-1][0] : dp[i-1][1];
        	dp[i][1] = dp[i-1][0] + nums[i];
        }
        int max2 = dp[size-2][0] > dp[size-2][1] ? dp[size-2][0] : dp[size-2][1];
        return max1 > max2 ? max1 : max2;
    }
};