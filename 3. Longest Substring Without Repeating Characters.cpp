class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int appear[256] = {0};
        int position[256];
        int length = s.length();
        int i=0,j=0,max = 0;
        for (;i < length; i++){
            if (appear[s[i]] && position[s[i]] >= j){
                int len = i-j;
                if (len > max){
                    max = len;
                }
                j = position[s[i]]+1;
            }
            appear[s[i]] = 1;
            position[s[i]] = i;
        }
        int len = i-j;
        if (len > max){
            max = len;
        }
        return max;
    }
};
