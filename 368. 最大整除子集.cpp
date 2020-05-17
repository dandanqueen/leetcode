class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1)
            return nums;
        vector<int> dp1(size), dp2(size);
        dp1[0] = -1;
        dp2[0] = 1;
        sort(nums.begin(), nums.end());
        int max_idx = 0;
        for (int i=1; i<size; i++){
            dp1[i] = -1;
            dp2[i] = 1;
            for (int j=i-1; j>=0; j--)
                if (nums[i] % nums[j] == 0 && dp2[j] + 1 > dp2[i]){
                    dp1[i] = j;
                    dp2[i] = dp2[j] + 1;
                }
            if (dp2[i] > dp2[max_idx])
                max_idx = i;
        }
        vector<int> subset(dp2[max_idx]);
        for (int i=dp2[max_idx]-1,j=max_idx; i>=0; i--){
            subset[i] = nums[j];
            j = dp1[j];
        }
        return subset;
    }
};