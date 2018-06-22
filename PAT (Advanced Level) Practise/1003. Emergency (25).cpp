#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 510; //最大顶点数
const int INF = 1000000000; //无穷大

int n, m, st, ed; //顶点数、边数、起点、终点
int G[MAXV][MAXV], weight[MAXV]; //邻接矩阵、点权
int d[MAXV], w[MAXV], num[MAXV]; //最短路径、最大点权之和、最短路径条数
bool vis[MAXV] = { false }; //vis[i]==true表示顶点i已访问，初值均为false

//Dijkstra算法，s为起点
void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF; //u使d[u]最小，MIN存放该最小的d[u]
        for (int j = 0; j < n; j++) {
            //未找到访问的顶点中d[]最小的
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1)
            return; //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
        vis[u] = true; //标记u为已访问
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                //如果v未访问且u能达到v
                if (d[u] + G[u][v] < d[v]) {
                    //以u为中介点时能令d[v]更小
                    d[v] = d[u] + G[u][v]; //覆盖d[v]
                    w[v] = w[u] + weight[v]; //覆盖w[v]
                    num[v] = num[u]; //覆盖num[v]
                } else if (d[u] + G[u][v] == d[v]) {
                    //找到一条相同长度的路径
                    if (w[u] + weight[v] > w[v]) {
                        //以u为中介点时点权之和更大
                        w[v] = w[u] + weight[v]; //w[v]继承自w[u]
                    }
                    //最短路径条数与点权无关，必须写在外面
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for (int i = 0; i < n; i++)
        scanf("%d", &weight[i]); //读入点权
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF); //初始化图G
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]); //最短距离条数、最短路径中的最大点权
    return 0;
}
