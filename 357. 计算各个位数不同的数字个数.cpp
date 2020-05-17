class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        n = n <= 11 ? n : 11;
        int total = 10, max = 9;
        for (int i=2; i<=n; i++){
            total += max*(11-i);
            max *= (11-i);
        }
        return total;
    }
};