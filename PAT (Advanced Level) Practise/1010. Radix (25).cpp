//使用long long保证不溢出，待求进制的下界是待求字符串最大数字（转为十进制）加1，
//上界是已知进制字符串转为十进制的值加1。由于范围很大，使用二分法，stringToLongLong函数在进制较大时会因溢出返回-1。

#include <iostream>
#include <string>
using namespace std;
long long str2longlong(string s, long long radix) {
    long long result = 0;
    for (int i = 0; i < s.size(); i++) {
        int temp;
        if (s[i] >= '0' && s[i] <= '9') {
            temp = s[i] - '0';
            result = result * radix + temp;
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            temp = s[i] - 'a' + 10;
            result = result * radix + temp;
        } else
            return -1;

        if (result < 0)
            return -1;
    }

    return result;
}

int main() {
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    if (tag == 2)
        swap(N1, N2);
    long long target = str2longlong(N1, radix);
    long long minRadix = 2;
    long long maxRadix = target + 1;
    long long mid;
    for (int i = 0; i < N2.size(); i++) {
        if (N2[i] >= '0' && N2[i] <= '9') {
            if (N2[i] - '0' >= minRadix)
                minRadix = N2[i] - '0' + 1;
        } else if (N2[i] >= 'a' && N2[i] <= 'z')
            if (N2[i] - 'a' + 10 >= minRadix)
                minRadix = N2[i] - 'a' + 10 + 1;
    }
    while (minRadix <= maxRadix) {
        mid = (minRadix + maxRadix) / 2;
        long long temp = str2longlong(N2, mid);
        if (temp > target || temp == -1)
            maxRadix = mid - 1;
        else if (temp < target)
            minRadix = mid + 1;
        else {
            cout << mid << endl;
            return 0;
        }
    }

    cout << "Impossible" << endl;
    return 0;
}
