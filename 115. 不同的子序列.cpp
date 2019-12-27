class Solution {
public:
    int numDistinct(string s, string t) {
    	int lens=s.length(), lent=t.length();
	    if (lens == 0)
	    	return lent == 0 ? 1 : 0;
	    if (lent == 0)
	    	return 1;
	    if (s == t)
	    	return 1;
	    if (s != t && lens <= lent)
	    	return 0;
	    vector<unsigned long> dp(lens);
	    for (int i=0; i<lens; i++){
	    	if (s[i] == t[lent-1])
	    		dp[i] = 1;
	    }
	    for (int j=lent-2; j>=0; j--){
	    	unsigned long sum = 0;
	    	for (int i=lens-1; i>=0; i--){
	    		unsigned long tmp = dp[i];
	    		if (s[i] == t[j] && sum > 0)
	    			dp[i] = sum;
	    		else
	    			dp[i] = 0;
	    		sum += tmp;
	    	}
	    }
	    unsigned long sum = 0;
	    for (int i=0; i<lens; i++)
	    	sum += dp[i];
	    return sum;
	}
};
