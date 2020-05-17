class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0){
            return 0;
        }
        int len1=s1.length(), len2=s2.length(), dp[100], sum=0;
        for (int i=0; i<len2; i++){
            dp[i] = 0;
            for (int j=0,k=i; j<len1; j++){
                if (s1[j] == s2[k]){
                    dp[i] ++;
                    k = (k + 1) % len2;
                } 
            }
            if (dp[i] == 0){
                return 0;
            }
        }
        for (int i=1,j=0; i<=n1; i++){
            sum += dp[j];
            j = (j + dp[j]) % len2;
        }
        return sum/len2/n2;
    }
};