/**
* 分析：排序，认真读题，不要弄错排序规则
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct people {
    char id[9];
    int vir;
    int tal;
    int tol;
    int flag;
} pel[maxn];

bool cmp(people a, people b) {
    if(a.flag != b.flag)
        return a.flag < b.flag;
    else if(a.tol != b.tol)
        return a.tol > b.tol;
    else if(a.vir != b.vir)
        return a.vir > b.vir;
    else if(a.id != b.id)
        return strcmp(a.id, b.id) < 0;
}

int main() {
    int n, l, h;
    int rank = 0, norank = 0;
    scanf("%d %d %d", &n, &l, &h);
    for(int i = 0; i < n; i++) {
        scanf("%s %d %d", pel[i].id, &pel[i].vir, &pel[i].tal);
        pel[i].tol = pel[i].vir + pel[i].tal;
        if(pel[i].vir >= h && pel[i].tal >= h)
            pel[i].flag = 1;
        else if(pel[i].vir >= h && pel[i].tal < h && pel[i].tal >= l)
            pel[i].flag = 2;
        else if(pel[i].vir < h && pel[i].vir >= l && pel[i].tal < h && pel[i].tal >= l && pel[i].vir >= pel[i].tal)
            pel[i].flag = 3;
        else if(pel[i].vir >= l && pel[i].tal >= l)
            pel[i].flag = 4;
        else {
            pel[i].flag = 5;
            norank++;
        }
    }
    rank = n - norank;
    printf("%d\n", rank);
    sort(pel, pel + n, cmp);
    for(int i = 0; i < rank; i++)
        printf("%s %d %d\n", pel[i].id, pel[i].vir, pel[i].tal);
    return 0;
}
