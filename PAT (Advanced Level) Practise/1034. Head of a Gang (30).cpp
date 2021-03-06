/**
* 分析：虽然是双向但可以转化成无向图
*       首先解决字符串和数字的转化，选用的是map，因为自动实现题目要求的字典序排序
*       然后输入数据，输入的时候就存储好点权和边权，转为无向图
*       最后是DFS的编写，具体见代码注释
*       坑点在于先统计边权再DFS，否则图中有环的情况会少算一条边
*       因此又会导致重复计算边，因此每统计完一条边要删一条
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;

int n, k;
int g[maxn][maxn], weight[maxn];
bool vis[maxn] = {false};

int nump = 0; //人数 顺便用来编号
map<string, int> id; //姓名->编号
map<int, string> name; //编号->姓名
map<string, int> gang; //头目姓名->团伙人数

//DFS需要得出点权最大的顶点，连通分量顶点个数，以及总边权
int head, num, sum; //设为全局变量，否则需要引用，后续记得每次DFS前初始化
void DFS(int u) {
    vis[u] = true;
    if(weight[u] > weight[head])
        head = u;
    num++;
    for(int v = 0; v < nump; v++) {
        if(g[u][v] != 0) {
            sum += g[u][v]; //应该先加边权再DFS，否则图中有环的情况，会有一条边统计不到
            g[u][v] = g[v][u] = 0; //统计完删边，防止重复统计
            if(vis[v] == false) {
                DFS(v);
            }
        }
    }
}

void DFSTrave() {
    for(int u = 0; u < nump; u++) {
        if(vis[u] == false) {
            head = u, num = 0, sum = 0;
            DFS(u);
            if(num > 2 && sum > k) {
                gang[name[head]] = num;
            }
        }
    }
}

int main() {
    int d;
    string s1, s2;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> d;
        if(id.find(s1) == id.end()) {
            id[s1] = nump;
            name[nump] = s1;
            nump++;
        }
        if(id.find(s2) == id.end()) {
            id[s2] = nump;
            name[nump] = s2;
            nump++;
        }
        int u = id[s1], v = id[s2];
        weight[u] += d;
        weight[v] += d;
        g[u][v] += d;
        g[v][u] = g[u][v];
    }
    DFSTrave();
    if(gang.size() != 0) {
        cout << gang.size() << endl;
        for(auto it = gang.begin(); it != gang.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
    } else {
        cout << "0" << endl;
    }
    return 0;
}
