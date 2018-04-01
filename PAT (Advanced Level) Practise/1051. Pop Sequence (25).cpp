#include <cstdio>
#include <stack>
using namespace std;
const int maxn = 1010;

int arr[maxn]; //待测试出栈序列
stack<int> st;

int main() {
    int M, N, K;
    scanf("%d%d%d", &M, &N, &K);
    //循环执行K次
    while (K--) {
        //栈不为空时清空栈
        while (!st.empty()) {
            st.pop();
        }
        //读入待测试数据
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }
        int current = 1; //指向待测数组
        bool flag = true; //标记出栈序列是否合法
        for (int i = 1; i <= N; i++) {
            st.push(i);
            if (st.size() > M) {
                flag = false;
                break;
            }
            while (!st.empty() && st.top() == arr[current]) {
                st.pop();
                current++;
            }
        }
        if (st.empty() == true && flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
