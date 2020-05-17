class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return 1;
        int sub=0, pre=0;
        for (int i =1; i<size-1; i++){
            if (nums[pre]<=nums[i] && nums[i]<=nums[i+1])
                sub ++;
            else if (nums[pre]<=nums[i] && nums[i]<=nums[i+1])
                sub ++;
            else if (nums[pre]>=nums[i] && nums[i]>=nums[i+1])
                sub ++;
            else if (nums[pre]>=nums[i] && nums[i]>=nums[i+1])
                sub ++;
            else
                pre = i;
        }
        if (nums[size-1] == nums[pre])
            sub ++;
        return size-sub;
    }
};