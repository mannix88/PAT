/**
* 分析：一个一分的运行时错误写你吗呢我真是服球了
*       注意找不到字符的情况为0
*       妈的我自己傻逼，测试样例都不全看
**/

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    string a,  na, b, nb;
    char da, db;
    long long la, lb, ans;
    cin >> a >> da >> b >> db;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == da)
            na += da;
    }
    for(int i = 0; i < b.size(); i++) {
        if(b[i] == db)
            nb += db;
    }
    la = na == "" ? 0 : stol(na);
    lb = nb == "" ? 0 : stol(nb);
    ans = la + lb;
    cout << ans;
    return 0;
}
