#include <iostream>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1=word1.size(), len2=word2.size();
        if (len1 == 0 || len2 == 0)
        	return abs(len1-len2);
        vector<vector<int>> dp(len1);
        for (int i=0; i<len1; i++)
        	dp[i].resize(len2);
        dp[0][0] = (word1[0]==word2[0]) ? 0 : 1;
        for (int j=1; j<len2; j++)
        	dp[0][j] = (word1[0] == word2[j]) ? j : (dp[0][j-1] + 1);
        for (int i=1; i<len1; i++)
        	dp[i][0] = (word1[i] == word2[0]) ? i : (dp[i-1][0] + 1);
        for (int i=1; i<len1; i++)
        	for (int j=1; j<len2; j++){
        		if (word1[i] == word2[j])
        			dp[i][j] = this->min(dp[i-1][j-1], dp[i-1][j]+1, dp[i][j-1]+1);
        		else
        			dp[i][j] = this->min(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1);
        	}
        return dp[len1-1][len2-1];
    }
    int min(int x, int y, int z){
    	int tmp = (x < y) ? x : y;
    	return (tmp < z) ? tmp : z;
    }
};