/**
* 分析：开始用的暴力，全部读入然后排序比大小，代码量有点多。。。
*       参考晴神宝典，声明完结构体后，写一个比较函数用来比较时间大小
*       建立三个结构体变量temp、ans1、ans2，分别用来读取变量和存放最早最晚时间
*       然后分别读入签到时间和签离时间，在输入数据的过程直接进行比较
*       注意初始最早最晚时间的初始化，分别初始化为最小和最大
*       注意学习比较函数的写法，我写的那种太直白太蠢了。。。
*       不过考试的时候不会就暴力确实好使嘻嘻嘻
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct pNode {
    char id[20];
    int hh, mm, ss;
} temp, ans1, ans2; //ans1存放最早签到时间，ans2存放最晚签到时间

//node1的时间大于node2的时间则返回true
bool great(pNode node1, pNode node2) {
    if (node1.hh != node2.hh)
        return node1.hh > node2.hh;
    if (node1.mm != node2.mm)
        return node1.mm > node2.mm;
    return node1.ss > node2.ss;
}

int main() {
    int n;
    scanf("%d", &n);
    ans1.hh = 24, ans1.mm = 60, ans1.ss = 60; //把初始签到时间设为最大
    ans2.hh = 0, ans2.mm = 0, ans2.ss = 0; //把初始签离时间设为最小
    for (int i = 0; i < n; i++) {
        //先读入签到时间
        scanf("%s %d:%d:%d", &temp.id, &temp.hh, &temp.mm, &temp.ss);
        if (great(temp, ans1) == false)
            ans1 = temp; //ans1取更小的签到时间
        //temp再作为签离时间读入
        scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
        if (great(temp, ans2) == true)
            ans2 = temp; //ans2取更大的签离时间
    }
    printf("%s %s\n", ans1.id, ans2.id);
    return 0;
}

/*
    暴力解法 代码量多 效率还低

    struct Record {
        char ID_number[16];
        int HH1, MM1, SS1;
        int HH2, MM2, SS2;
    };

    int main() {
        int M;
        scanf("%d", &M);
        Record records[M];
        for(int i = 0; i < M; i++) {
            cin >> records[i].ID_number;
            scanf("%d:%d:%d", &records[i].HH1, &records[i].MM1, &records[i].SS1);
            scanf("%d:%d:%d", &records[i].HH2, &records[i].MM2, &records[i].SS2);
        }
        int minID = 0, minH = records[0].HH1, minM = records[0].MM1, minS = records[0].SS1;
        for(int i = 1; i < M; i++) {
            if(records[i].HH1 < minH) {
                minID = i;
                minH = records[i].HH1;
                minM = records[i].MM1;
                minS = records[i].SS1;
            } else if(records[i].HH1 == minH) {
                if(records[i].MM1 < minM) {
                    minID = i;
                    minM = records[i].MM1;
                    minS = records[i].SS1;
                } else if(records[i].MM1 == minM) {
                    if(records[i].SS1 < minS) {
                        minID = i;
                        minS = records[i].SS1;
                    }
                }
            }
        }
        int maxID = 0, maxH = records[0].HH2, maxM = records[0].MM2, maxS = records[0].SS2;
        for(int i = 1; i < M; i++) {
            if(records[i].HH2 > maxH) {
                maxID = i;
                maxH = records[i].HH2;
                maxM = records[i].MM2;
                maxS = records[i].SS2;
            } else if(records[i].HH2 == maxH) {
                if(records[i].MM2 > maxM) {
                    maxID = i;
                    maxM = records[i].MM2;
                    maxS = records[i].SS2;
                } else if(records[i].MM2 == maxM) {
                    if(records[i].SS2 > minS) {
                        maxID = i;
                        maxS = records[i].SS2;
                    }
                }
            }
        }
        cout << records[minID].ID_number << " " << records[maxID].ID_number;
        return 0;
    }
*/
