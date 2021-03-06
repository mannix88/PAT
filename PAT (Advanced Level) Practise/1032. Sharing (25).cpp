/**
* 分析：链表处理题，按解题模板做即可，要注意的是此题没有步骤4
**/

#include <cstdio>
const int maxn = 100010;

//定义链表
struct Node {
    int address, data, next;
    int flag;
} node[maxn];

int main() {
    //初始化
    for(int i = 0; i < maxn; i++)
        node[i].flag = 0;
    //读取数据
    int b1, b2, n;
    int address, next;
    char data;
    scanf("%d %d %d", &b1, &b2, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    //遍历链表标记特殊性质，此题不需要统计有效结点
    while(b1 != -1) {
        node[b1].flag = 1;
        b1 = node[b1].next;
    }
    //此题不需要排序，直接进行第⑤步
    while(b2 != -1) {
        if(node[b2].flag == 1)
            break;
        else
            b2 = node[b2].next;
    }
    if(b2 != -1)
        printf("%05d", b2);
    else
        printf("-1\n", b2);
    return 0;
}
