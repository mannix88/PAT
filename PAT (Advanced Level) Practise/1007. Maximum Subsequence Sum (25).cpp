/**
* 分析：经典DP模型之一，最大连续子列和 dp[i]=max{A[i],dp[i-1]+A[i]}
*       坑点在于题目要求全负为0，所以提前特判，ans初值也要设为-1，因为结果取值≥0
*       一定要审题
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;

int d[maxn], dp[maxn];

int main() {
    bool flag = false;
    int k, a, b, ans = -1;
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        scanf("%d", &d[i]);
        if(d[i] >= 0)
            flag = true;
    }
    if(!flag) {
        printf("0 %d %d", d[1], d[k]);
        return 0;
    }
    dp[1] = d[1];
    for(int i = 2; i <= k; i++)
        dp[i] = max(d[i], dp[i - 1] + d[i]);
    for(int i = 1; i <= k; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            b = i;
            a = b;
        }
    }
    int temp = ans;
    while(temp != d[a]) {
        temp -= d[a];
        a--;
    }
    printf("%d %d %d", ans, d[a], d[b]);
    return 0;
}
