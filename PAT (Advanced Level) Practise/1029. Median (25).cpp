/**
* 分析：此题有坑，坑很大，一般做法会超限，超限的测试点在2-3个不等，多刷几次能差2分左右。。。
*       参考柳神解法，开一个数组，第一组数据完全读入，第二组数据在线处理
**/

#include <cstdio>
using namespace std;
const int maxn = 400020;
const int inf = 1000000000;

int n, m, temp, mid, p = 1, count = 0;
int d[maxn];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    d[n + 1] = inf;
    scanf("%d", &m);
    mid = (n + m + 1) / 2;
    for(int i = 1; i <= m; i++) {
        scanf("%d", &temp);
        while(d[p] < temp) {
            count++;
            if(count == mid)
                printf("%d", d[p]);
            p++;
        }
        count++;
        if(count == mid)
            printf("%d", temp);
    }
    while(p <= n) {
        count++;
        if(count == mid)
            printf("%d", d[p]);
        p++;
    }
    return 0;
}
