class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	int size = A.size();
    	if (size < 3)
    		return 0;
    	vector<int> dp(size);
    	dp[size-3] = 0;
    	if (A[size-2]-A[size-3] == A[size-1]-A[size-2])
    		dp[size-3] = 1; 
    	int sum = dp[size-3];
    	for (int i=size-4; i>=0; i--){
    		if (A[i+1]-A[i] == A[i+2]-A[i+1])
    			dp[i] = dp[i+1]+1;
    		sum += dp[i];
    	}
    	return sum;
    }
};