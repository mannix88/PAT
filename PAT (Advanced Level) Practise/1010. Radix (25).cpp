/**
* 分析：先讲确定进制的数存到n1，未确定的存到n2，方便后续统一计算，因为10位且有字符，输入为字符串
*       将n1转为10进制，然后二分法为n2选择进制转为十进制与n1,比较，注意进制转换的方法
*       还要确定n2进制的上下界，注意radix即基数是没有上限的（并不是2-35）
*       （理解）n2进制的下界为n2数位中最大一位+1（如最大一位为1则下界为二进制至少能表示0和1），上界为下界与n1的十进制数中的较大值加1
*       坑点在于题目默认给定进制的数转成十进制时不会溢出，而未知进制的数n2在转成十进制时可能会溢出（因为radix无上限），溢出即转换的某步小于0
*       这题卡了很久，需要仔细理解，多做几遍
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

//将radix进制的数转换为十进制数
LL strToTen(string s, LL radix) {
    LL res = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            res = res * radix + s[i] - '0'; // '0'-'9' ~ 0-9
        }
        if(s[i] >= 'a' && s[i] <= 'z') {
            res = res * radix + s[i] - 'a' + 10; // 'a'-'z' ~ 10-35
        }
        if(res < 0)
            return -1; //判断是否溢出
    }
    return res;
}

//二分查找进制
LL binarySearch(LL left, LL right, string s, LL target) {
    LL mid;
    while(left < right) {
        mid = (left + right) / 2;
        LL temp = strToTen(s, mid);
        if(temp == target)
            return mid;
        else if(temp > target || temp == -1)
            right = mid;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if(tag == 2)
        swap(n1, n2);
    LL target = strToTen(n1, radix);
    LL left, right, res;
    char temp = '0';
    for(int i = 0; i < n2.size(); i++) {
        if(n2[i] > temp)
            temp = n2[i];
    }
    if(temp >= '0' && temp <= '9') {
        left = temp - '0' + 1; // '0'-'9' ~ 0-9
    } else if(temp >= 'a' && temp <= 'z') {
        left = temp - 'a' + 10 + 1; // 'a'-'z' ~ 10-35
    }
    right = max(left, target) + 1;
    res = binarySearch(left, right, n2, target);
    if(res != -1)
        cout << res;
    else
        cout << "Impossible";
    return 0;
}
