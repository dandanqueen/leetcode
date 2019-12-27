class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size(), max;
        vector<int> dp(size);
        max = dp[0] = nums[0];
        for (int i=1;i<size;i++){
        	dp[i] = dp[i-1]+nums[i] > nums[i] ? dp[i-1]+nums[i] : nums[i];
        	if (dp[i] > max)
        		max = dp[i];
        }
        return max;
    }
};