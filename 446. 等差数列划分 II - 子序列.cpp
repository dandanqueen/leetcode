class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
    	int size = A.size();
    	if (size < 3)
    		return 0;
    	if (size == 3 && (A[1]-A[0]) == (A[2]-A[1]))
			return 1;
		if(size == 3 && (A[1]-A[0]) != (A[2]-A[1]))
			return 0;
		vector<long> B(size);
		for (int i=0; i<size; i++)
			B[i] = A[i];
    	vector<vector<int>> dp(size);
    	for (int i=0; i<size; i++)
    		dp[i].resize(size);
    	int sum = 0;
    	for (int i=2,j,k,e; i<size; i++){
    		for (j=0,e=0; j<i; j++){
    			if (B[i] == B[j])
    				e ++;
    			else{
    				for (k=0; k<j; k++)
    					if (B[j]-B[k] == B[i]-B[j]){
							dp[j][i] += dp[k][j];
							dp[j][i] += 1;
						}
    				sum += dp[j][i];
    			}
    		}
    		if (e >= 2)
    			sum += (pow(2,e)-e-1);
    	}
    	return sum;
    }
};