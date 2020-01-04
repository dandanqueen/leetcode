class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        long long dp_max=nums[0], dp_min=nums[0], max=nums[0], dp_max_cur, dp_min_cur;
        for (int i=1; i<size; i++){
            dp_max_cur = dp_max*nums[i] > nums[i] ? dp_max*nums[i] : nums[i];
            if (dp_min*nums[i] > dp_max_cur)
                dp_max_cur = dp_min*nums[i];
            dp_min_cur = dp_min*nums[i] < nums[i] ? dp_min*nums[i] : nums[i];
            if (dp_max*nums[i] < dp_min_cur)
                dp_min_cur = dp_max*nums[i];
            if (dp_max_cur > max)
                max = dp_max_cur;
            dp_max = dp_max_cur;
            dp_min = dp_min_cur;
        }
        return max;
    }
};