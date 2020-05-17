#include <iostream>
#include <cstdio>

using namespace std;

bool choose(bool *dp, int maxChoosableInteger, int desiredTotal){
    for (int i=1; i<=maxChoosableInteger; i++){
        if (!dp[i]){
            if (i >= desiredTotal){
                return true;
            }
            dp[i] = true;
            bool win = choose(dp, maxChoosableInteger, desiredTotal-i);
            dp[i] = false;
            if (!win){
                return true;
            }
        }
    }
    return false;
}



bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger >= desiredTotal)
        return true;
    bool dp[38][131073];
    for (int i=1; i<=maxChoosableInteger; i++){

    }
    return false;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", sizeof(bool));
    bool res = canIWin(10,40);
    printf("%d\n", res);
    return 0;
}
