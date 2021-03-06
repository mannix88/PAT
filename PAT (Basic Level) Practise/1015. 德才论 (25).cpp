/**
* 分析：课设还有一天，加油加油，熬过去就好了
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct Person {
    int id, d, c, sum, flag;
} p[maxn];

bool cmp(Person a, Person b) {
    if(a.flag != b.flag)
        return a.flag < b.flag;
    else if(a.sum != b.sum)
        return a.sum > b.sum;
    else if(a.d != b.d)
        return a.d > b.d;
    else if(a.id != b.id)
        return a.id < b.id;
}

int main() {
    int n, l, h;
    scanf("%d%d%d", &n, &l, &h);
    int id, d, c, num = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d", &id, &d, &c);
        if(d >= l && c >= l) {
            p[num].id = id;
            p[num].d = d;
            p[num].c = c;
            p[num].sum = d + c;
            if(d >= h && c >= h)
                p[num].flag = 1;
            else if(d >= h && c < h)
                p[num].flag = 2;
            else if(d < h && c < h && d >= c)
                p[num].flag = 3;
            else
                p[num].flag = 4;
            num++;
        }
    }
    sort(p, p + num, cmp);
    printf("%d\n", num);
    for(int i = 0; i < num; i++)
        printf("%d %d %d\n", p[i].id, p[i].d, p[i].c);
    return 0;
}
