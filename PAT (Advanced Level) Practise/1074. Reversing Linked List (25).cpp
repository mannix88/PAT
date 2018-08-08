/**
* 分析：链表处理，因此此题要求按顺序输出，因此特殊性质order设为maxn
*       然后给有效结点编码，从小到大排序即可，这样无效结点都在后面
*       （其实我设成最小值也实现了从小到大排序，就是多写了两句。。。）
*       此题要注意第⑤步，对最后一个结点的next地址分情况讨论，思路要清晰
*       还有即使将有效结点按1 - count排序，数组下标仍是0 - count-1，不要忽略这个问题
**/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct Node {
    int address, data, next;
    int order;
} node[maxn];

bool cmp(Node a, Node b) {
    if(a.order == -1 || b.order == -1)
        return a.order > b.order;
    else
        return a.order < b.order;
}

int main() {
    for(int i = 0; i < maxn; i++)
        node[i].order = -1;
    int begin, n, k;
    int address, data, next;
    scanf("%d %d %d", &begin, &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &address, &data, &next);
        node[address].address = address;
        node[address].data = data;
        node[address].next = next;
    }
    int p = begin, count = 0;
    for(int i = 1; p != -1; i++) {
        node[p].order = i;
        p = node[p].next;
        count++;
    }
    sort(node, node + maxn, cmp);
//    for(int i = 0; i < count; i++)
//        printf("%05d %d %05d\n", node[i].address, node[i].data, node[i + 1].address);
//    printf("%d", count);
    //步骤⑤
    for(int i = 1; i <= count / k; i++) {
        for(int j = i * k - 1; j > 0 + (i - 1)*k; j--)
            printf("%05d %d %05d\n", node[j].address, node[j].data, node[j - 1].address);
        //将每一块的最后一个结点单独输出，根据其next地址分情况讨论
        if(i < count / k) { //不是最后一块
            printf("%05d %d %05d\n", node[0 + (i - 1)*k].address, node[0 + (i - 1)*k].data, node[(i + 1)*k - 1].address);
        } else if(i == count / k) { //是最后一块
            if(count % k == 0) { //是最后一个结点（即没有不成块的剩余结点）
                printf("%05d %d -1\n", node[0 + (i - 1)*k].address, node[0 + (i - 1)*k].data);
            } else { //不是最后一个结点
                printf("%05d %d %05d\n", node[0 + (i - 1)*k].address, node[0 + (i - 1)*k].data, node[i * k].address);
                for(int t = i * k ; t < count - 1; t++)
                    printf("%05d %d %05d\n", node[t].address, node[t].data, node[t + 1].address);
                printf("%05d %d -1\n", node[count - 1].address, node[count - 1].data);
            }
        }
    }
    return 0;
}
