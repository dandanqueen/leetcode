#include <climits>

class Solution {
public:
    int myAtoi(string str) {
    	long long num = 0;
    	int len = 0;
    	bool negative = false;
    	bool positive = false;
    	bool number = false;
        for (int i = 0;str[i] != '\0';i ++) {
        	if (48<=str[i] && str[i]<=57) {
        		number = true;
        		if (negative)
        			num = num * 10 - (str[i]-48);
        		else
        			num = num * 10 + (str[i]-48);
        	}else if (str[i] == '-' and !negative and !positive and !number) {
        		negative = true;
        	}else if (str[i] == '+' and !negative and !positive and !number) {
        		positive = true;
        	}else if (str[i] == ' ' and !negative and !positive and !number) {
        		continue;
        	}else {
        		break;
        	}
        	if (num < INT_MIN) {
        		num = INT_MIN;
        		break;
        	}
        	if (num > INT_MAX) {
        		num = INT_MAX;
        		break;
        	}
        }
        return num;
    }
};