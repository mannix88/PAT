/**
* 分析：树的遍历，这次我是刚学完基础知识看晴神写的第一题
*       所以写的很快20分钟不到直接AC，但是不算我的
*       不过说明这类题熟练之后上了考场是能很快AC的，哪怕是30分压轴题
*       然后这道题要注意输出按权值从大到小输出，所以要先对每个结点的子树按权值进行排序
*       其他的没什么，理清思路，想明白递归边界和递归式就好
**/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 101;

int n, m, s;
int path[maxn];

struct Node {
    int weight;
    vector<int> child;
} node[maxn];

bool cmp(int a, int b) {
    return node[a].weight > node[b].weight;
}

void DFS(int index, int num, int sum) {
    if(sum > s)
        return;
    if(sum == s) {
        if(node[index].child.size() == 0) {
            for(int i = 0; i < num; i++) {
                printf("%d", node[path[i]].weight);
                if(i < num - 1)
                    printf(" ");
                else
                    printf("\n");
            }
        }
    }
    for(int i = 0; i < node[index].child.size(); i++) {
        int child = node[index].child[i];
        path[num] = child;
        DFS(child, num + 1, sum + node[child].weight);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0; i < n; i++)
        scanf("%d", &node[i].weight);
    for(int i = 0; i < m; i++) {
        int id, cnt, child;
        scanf("%d%d", &id, &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &child);
            node[id].child.push_back(child);
        }
    }
    for(int i = 0; i < n; i++)
        sort(node[i].child.begin(), node[i].child.end(), cmp);
    path[0] = 0;
    DFS(0, 1, node[0].weight);
    return 0;
}
