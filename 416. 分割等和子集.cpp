class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        if (size < 2)
            return false;
        if (size == 2 && nums[0] == nums[1])
            return true;
        if (size == 2 && nums[0] != nums[1])
            return false;
        int sum = 0;
        for (int i=0; i<size; i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;
        int dp_size = sum/2;
        vector<bool> dp(dp_size);
        for (int i=0,max=0; i<size; i++){
            if (nums[i]*2 == sum)
                return true;
            for (int j=1,t=max; j<=t; j++)
                if (dp[j]){
                    if ((j+nums[i])*2 == sum)
                        return true;
                    if (j+nums[i] < dp_size){
                        dp[j+nums[i]] = true;
                        max = (j+nums[i]) > max ? (j+nums[i]) : max;
                    }
                }
            if (nums[i] < dp_size){
                dp[nums[i]] = true;
                max = nums[i] > max ? nums[i] : max;
            }
        }
        return false;
    }
};
