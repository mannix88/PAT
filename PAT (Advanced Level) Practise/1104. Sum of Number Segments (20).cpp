/**
* 分析：找规律
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double t, cnt = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &t);
        cnt += t * i * (n - i + 1);
    }
    printf("%.2f", cnt);
    return 0;
}
