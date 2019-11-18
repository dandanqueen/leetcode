#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector asc = vector<int>(size); 
        int max_len = 1;
        asc[0] = nums[0];
        for(int i = 1;i < size;i ++){
			if (nums[i] > asc[max_len-1]){
        		asc[max_len] = nums[i];
        		max_len ++;
        	}else if (nums[i] < asc[max_len-1]){
        		int idx = this->first_big_search(asc, max_len, nums[i]);
        		if (idx == 0 || asc[idx-1] < nums[i])
        			asc[idx] = nums[i];
        	}
        }
        return max_len;
    }

    int first_big_search(vector<int>& nums, int max_len, int num) {
    	int l = 0;
    	int r = max_len-1;
    	while(l <= r){
    		int m = (l + r) / 2;
    		if (nums[m] > num){
    			if (m == 0 || nums[m-1] <= num) return m;
    			else r = m-1;
    		}else{
	    		l = m + 1;
	    	}
    	}
    	return -1;
    }
};
