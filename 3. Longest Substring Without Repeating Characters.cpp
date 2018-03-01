class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char appear[256] = {0}; /*记录字符出现情况*/
        int position[256]; /*记录字符出现位置*/
        int len = s.length();
        int max = 0;
        int sublen = 0;
        for (int i = 0, j = 0;i < len;i ++) {
            if (appear[s[i]]) {
                if (sublen > max)
                    max = sublen;
                for (int k = j;k <= position[s[i]];k ++){ /*重置前无效部分，重新开始需找*/
                    appear[s[k]] = 0;
                }
                sublen = i - position[s[i]] - 1; /*从重复字符串后一个字符串开始需找下一个子字符串*/
                j = position[s[i]] + 1; /*下一个子字符串开始位置*/
            }
            position[s[i]] = i;
            appear[s[i]] = 1;
            sublen ++;
        }
        if (sublen > max) /*直到字符串结束任然没有找到重复字符情况*/
            max = sublen;
        return max;
    }
};