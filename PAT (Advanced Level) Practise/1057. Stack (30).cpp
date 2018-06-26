#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 100010;
const int sqrN = 316; //sqrt(100001)，表示块内元素个数

stack<int> st; //栈
int block[sqrN]; //记录每一块中存在的元素个数
int table[maxn]; //hash数组，记录元素当前存在个数

void peekMedian(int K) {
    int sum = 0; //sum存放当前累计存在的数的个数
    int idx = 0; //块号
    //找到第K大的数所在块号
    while (sum + block[idx] < K)
        sum += block[idx++]; //未达到K，则累加上当前块的元素个数
    int num = idx * sqrN; //idx号块的第一个数
    while (sum + table[num] < K)
        sum += table[num++]; //累加块内元素个数，直到sum达到K
    printf("%d\n", num); //sum达到K，找到了第K大的数为num
}

void Push(int x) {
    st.push(x); //入栈
    block[x / sqrN]++; //x所在块的元素个数加1
    table[x]++; //x的存在个数加1
}

void Pop() {
    int x = st.top(); //获得栈顶
    st.pop(); //出栈
    block[x / sqrN]--; //x所在块的元素个数减1
    table[x]--; //x的存在个数减1
    printf("%d\n", x); //输出x
}

int main() {
    int x, query;
    memset(block, 0, sizeof(block));
    memset(table, 0, sizeof(table));
    char cmd[20]; //命令
    scanf("%d", &query); //查询数目
    for (int i = 0; i < query; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "Push") == 0) {
            //Push x
            scanf("%d", &x);
            Push(x); //入栈
        } else if (strcmp(cmd, "Pop") == 0) {
            //Pop
            if (st.empty() == true)
                printf("Invalid\n"); //栈空
            else
                Pop(); //出栈
        } else {
            //PeekMedian
            if (st.empty() == true) {
                printf("Invalid\n"); //栈空
            } else {
                int K = st.size();
                if (K % 2 == 1)
                    K = (K + 1) / 2; //K为中间位置
                else
                    K = K / 2;
                peekMedian(K); //输出中位数，即第K大
            }
        }
    }
    return 0;
}
