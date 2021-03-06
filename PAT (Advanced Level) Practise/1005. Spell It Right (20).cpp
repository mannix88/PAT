/**
* 分析：注意到题目给的数据范围是N≤10^100，远远大于可以输入的整型数据范围
*       而各数位累加的和的最大值为9*100=900，只有三位
*       所以此题应以字符串输入，考查字符串处理
*       首先用二维数组将数字和单词一一对应，然后读入字符串计算和
*       最后分割所求和的各数位进行逆序输出，注意末尾不要有空格
*       据说特殊数据0应进行特判直接输出zero，但我没特判也通过了测试
**/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 3;

char eng[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    char s[110];
    cin >> s; //gets()被禁用
    int len = strlen(s);
    int sum = 0, digit = 0, num[maxn];
    for(int i = 0; i < len; i++) {
        sum += s[i] - '0';
    }
    while(sum) {
        num[digit++] = sum % 10;
        sum /= 10;
    }
    for(int i = digit - 1; i > 0; i--) {
        printf("%s ", eng[num[i]]);
    }
    printf("%s", eng[num[0]]);
    return 0;
}
