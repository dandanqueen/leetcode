class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int max = 0;
        while(i < j) {
        	int area;
        	if (height[i] < height[j]) {
        		// 此时以height[i]为边界的桶找到最大值
        		area = (j - i) * height[i];
        		i ++;
        	}else if (height[j] < height[i]) {
        		// 此时以height[j]为边界的桶找到最大值
        		area = (j - i) * height[j];
        		j --;
        	}else{
        		// 此时以height[i]和height[j]为边界的桶都找到最大值
        		area = (j - i) * height[i];
        		i ++;
        		j --;
        	}
        	if (area > max) {
    			max = area;
    		}
        }
        return max;
    }
};