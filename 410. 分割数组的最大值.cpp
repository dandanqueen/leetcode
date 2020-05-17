class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        unsigned int size = nums.size(), sum=0; 
        for (int i=0; i<size; i++)
            sum += nums[i];
        if (m == 1)
            return sum;
        vector<vector<unsigned int>> dp(m-1);
        for(int i=0; i<m-1;i ++)
            dp[i].resize(size);
        dp[0][size-1] = nums[size-1];
        for(int i=size-2; i>=0; i--)
            dp[0][i] = dp[0][i+1] + nums[i];
        for(int i=1; i<m-1; i++){
            for(int j=0; j<size-i; j++){
                dp[i][j] = UINT_MAX;
                for(int k=j,t=0; k<size-i; k++){
                    t += nums[k];
                    dp[i][j] = min(dp[i][j], max(t,dp[i-1][k+1]));
                }
            }
        }
        unsigned int mx = UINT_MAX;
        for(int i=0,t=0; i<=size-m; i++){
            t += nums[i];
            mx = min(mx, max(t,dp[m-2][i+1]));
        }
        return mx;
    }
    unsigned int min(unsigned int a, unsigned int b){
        return a < b ? a : b;
    }
    unsigned int max(unsigned int a, unsigned int b){
        return a > b ? a : b;
    }  
};