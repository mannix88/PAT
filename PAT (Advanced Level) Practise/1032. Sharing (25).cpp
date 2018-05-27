#include <cstdio>
#include <cstring>
const int maxn = 100010;

struct Node {
    char data; //数据域
    int next; //指针域
    bool flag; //结点是否在第一条链表中出现
} node[maxn];

int main() {
    for (int i = 0; i < maxn; i++)
        node[i].flag = false;
    int s1, s2, n; //s1与s2分别代表两条链表的首地址
    scanf("%d%d%d", &s1, &s2, &n);
    int addreass, next; //结点地址与后继结点地址
    char data;
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &addreass, &data, &next);
        node[addreass].data = data;
        node[addreass].next = next;
    }
    int p;
    for (p = s1; p != -1; p = node[p].next)
        node[p].flag = true; //枚举第一条链表的所有结点，令其出现次数为1
    for (p = s2; p != -1; p = node[p].next) {
        if (node[p].flag == true)
            break; //找到第一个已经在第一条链表中出现的结点
    }
    //如果第二条链表还没有到达结尾，说明找到了共用结点
    if (p != -1)
        printf("%05d\n", p);
    else
        printf("-1\n");
    return 0;
}
