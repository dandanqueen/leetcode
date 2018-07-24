class Solution {
public:
    string longestPalindrome(string s) {
        char chars[2003];
    	chars[0] = '^';
    	chars[1] = '#';
    	int size = 2;
    	for (int i = 0;s[i] != '\0';i ++){
    		chars[size++] = s[i];
    		chars[size++] = '#';
    	}
    	chars[size++] = '$';
        int len[2003];
        memset(len, 0, sizeof(len));
        int maxbidx = 0, maxbound = 0, maxlen=0, maxid;
        for (int i = 1;chars[i] != '$';i ++){
        	if (i < maxbound){
        		int j = 2*maxbidx - i;
        		len[i] = min(len[j], maxbound-i);
        	}
        	int j = len[i] + 1;
        	while(chars[i+j] == chars[i-j]){
        		len[i]++;
        		j++;
        	}
        	if (i + len[i] > maxbound){
        		maxbound = i + len[i];
        		maxbidx = i;
        	}
        	if (len[i] > maxlen){
        		maxlen = len[i];
        		maxid = i;
        	}
        }
        string res = "";
        for (int i = maxid-maxlen+1;i < maxid+maxlen;i++){
        	if (chars[i] != '#')
        		res+=chars[i];
        }
        return res;
    }
};