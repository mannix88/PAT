/**
* 分析：排序入门题，掌握解题步骤，注意排序下标
**/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30010;

struct student {
    char id[14];
    int score;
    int locid;
    int locrank;
    int finrank;
} stu[maxn];

bool cmp(student a, student b) {
    if(a.score != b.score)
        return a.score > b.score;
    else if(a.id != b.id)
        return strcmp(a.id, b.id) < 0;
}

int main() {
    int n, k;
    int num = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].locid = i;
            num++;
        }
        sort(stu + num - k, stu + num, cmp); //每次排序结尾必是到stu+num，开头则是结尾-排序人数即stu+num-k
        stu[num - k].locrank = 1;
        for(int t = num - k; t < num; t++) {
            if(stu[t + 1].score != stu[t].score)
                stu[t + 1].locrank = t + 1 + 1 - (num - k);
            else
                stu[t + 1].locrank = stu[t].locrank;
        }
    }
    sort(stu, stu + num, cmp);
    stu[0].finrank = 1;
    printf("%d\n", num);
    for(int i = 0; i < num; i++) {
        if(stu[i + 1].score != stu[i].score)
            stu[i + 1].finrank = i + 2;
        else
            stu[i + 1].finrank = stu[i].finrank;
        printf("%s %d %d %d\n", stu[i].id, stu[i].finrank, stu[i].locid, stu[i].locrank);
    }
    return 0;
}
