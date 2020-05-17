class Solution {
public:
    bool canCross(vector<int>& stones) {
    	int size = stones.size();
    	vector<vector<int>> dp(size);
    	for (int i=0; i<size; i++)
            dp[i].resize(size+1); 
        dp[0][1] = 1;
        for (int i=0; i<size-1; i++)
        	for (int j=1,k,m; j<=i+1; j++)
        		if (dp[i][j]){
        			k = stones[i]+j;
        			m = binarySearch(stones,i+1,k);
        			if (m == size-1)
        				return true;
        			if (m != -1)
        				dp[m][j] = dp[m][j-1] = dp[m][j+1] = 1;
        		}
        return false;
    }

    int binarySearch(vector<int>& stones, int i, int num){
    	int m, j=stones.size()-1;
    	while(i <= j){
    		m = (i + j) / 2;
    		if (stones[m] == num)
    			return m;
    		if (stones[m] < num)
    			i = m+1;
    		else
    			j = m-1;

    	}
    	return -1;
    }
};  