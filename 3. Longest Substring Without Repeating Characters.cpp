class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char appear[255] = {0};
        int position[255];
        int len = s.length();
        int max = 0;
        int sublen = 0;
        for (int i = 0, j = 0;i < len;i ++) {
            if (appear[s[i]]) {
                if (sublen > max)
                    max = sublen;
                sublen = i - position[s[i]] - 1;
                for (int k = j;k <= position[s[i]];k ++){
                    appear[s[k]] = 0;
                }
            }
            position[s[i]] = i;
            appear[s[i]] = 1;
            sublen ++;
        }
        if (sublen > max)
            max = sublen;
        return max;
    }
};