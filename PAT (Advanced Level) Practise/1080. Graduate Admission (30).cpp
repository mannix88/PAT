/**
* 分析：排序压轴题，写了大概40分钟？得了22分，三个测试点没有通过，其中一个是运行超时
*       和晴神思路差不多，但是晴神用了两个结构体数组，我把其中一个用vector代替
*       感觉思路更清晰顺畅，但是会超时我也找不到超时在哪。。。
*       考虑完边界情况修改玩代码还是22分，以后尽量不要用vector不要偷工减料。。。
*       暂时就这样，先不改写成两个结构体的版本了，自己理解就OK，毕竟排序出压轴的概率不大，此题过
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 40010;
const int maxm = 110;
const int maxk = 6;

struct application {
    int id;
    int ge, gi, gf;
    int rank;
    int per[maxk];
} app[maxn];

int sch[maxm];
vector<int> adm[maxm];

bool cmp(application a, application b) {
    if(a.gf != b.gf)
        return a.gf > b.gf;
    else if(a.ge != b.ge)
        return a.ge > b.ge;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d", &sch[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &app[i].ge, &app[i].gi);
        app[i].id = i;
        app[i].gf = (app[i].ge + app[i].gi) / 2;
        for(int j = 0; j < k; j++)
            scanf("%d", &app[i].per[j]);
    }
    sort(app, app + n, cmp);
    app[0].rank = 1;
    for(int i = 1; i < n; i++) {
        if(app[i].gf == app[i - 1].gf && app[i].ge == app[i - 1].ge)
            app[i].rank = app[i - 1].rank;
        else
            app[i].rank = i + 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            int temp = app[i].per[j];
            if(adm[temp].size() != 0) {
                if((sch[temp] > 0) || (sch[temp] <= 0 && app[i].rank == app[adm[temp][adm[temp].size() - 1]].rank)) {
                    adm[temp].push_back(app[i].id);
                    sch[temp]--;
                    break;
                }
            } else {
                if(sch[temp] > 0) {
                    adm[temp].push_back(app[i].id);
                    sch[temp]--;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < m; i++) {
        if(adm[i].size() != 0) {
            sort(adm[i].begin(), adm[i].end());
            for(vector<int>::iterator it = adm[i].begin(); it != adm[i].end(); it++) {
                if(it != adm[i].end() - 1)
                    printf("%d ", *it);
                else
                    printf("%d\n", *it);
            }
        } else {
            printf("\n");
        }
    }
    return 0;
}
