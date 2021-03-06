/**
* 分析：找最后一个小于等于m*p的数，转化为找第一个大于m*p的数，然后下标减1即为所求位置，再用位置计算数量
*       因为按题型刷的知道这是二分题，所以很快能AC。。。平时自已要能反应过来用什么算法
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100010;

LL d[maxn];

int main() {
    int n, cnt = 1;
    LL p;
    scanf("%d%lld", &n, &p);
    for(int i = 0; i < n; i++)
        scanf("%lld", &d[i]);
    sort(d, d + n);
    for(int i = 0; i < n; i++) {
        LL min = d[i];
        int pos = upper_bound(d + i, d + n, min * p) - d - 1;
        cnt = max(cnt, pos - i + 1);
    }
    printf("%d\n", cnt);
    return 0;
}
