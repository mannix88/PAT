#include <cstdio>

int main() {
    int n;
    double v, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &v); //第i位的值
        ans += v * i * (n + 1 - i); //第i位的总出现次数
    }
    printf("%.2f\n", ans);
    return 0;
}
