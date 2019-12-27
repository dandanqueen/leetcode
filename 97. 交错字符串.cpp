class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.length(), len2=s2.length(), len3=s3.length();
        if (len1 == 0)
            return s2 == s3;
        if (len2 == 0)
            return s1 == s3;
        if (len3 == 0)
            return len1 + len2 == 0;
        if (len1+len2 != len3)
            return 0;
        vector<vector<bool> > dp(len1+1);
        for (int i=0; i<=len1; i++)
            dp[i].resize(len2+1);
        dp[0][0] = true;
        for (int i=1; i<=len2; i++)
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        for (int i=1; i<=len1; i++)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for (int i=1; i<=len1; i++)
            for (int j=1; j<=len2; j++){
                dp[i][j] = false;
                if ((dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]))
                    dp[i][j] = true;
            }
        return dp[len1][len2];
    }
};

