# map

常见有三种使用情况：

**(1) 建立字符串与整数之间的映射**

​	通常是建立字符串到整型的映射，即map<string,int>，因为在知道数量的前提下整型到字符串之间的映射用一个字符串数组即可，如string str[n]；还有一种整型到字符数组的映射，即char ch[m][n]，表示m个长度为n的字符数组，ch[i]表示第i个char[n]，我觉得可以这么理解，具体情况具体分析吧

**(2) 判断大整数是否存在**

​	替代hash；有负数的时候也会用来替代hash，hash只能是正整数映射某种类型，要和map区分

**(3) 建立字符串与字符串的映射**  
<br />
<br />
注意：在字符串相关的题可能会用到cctype下的isalnum()函数，用来判断是否为字母或数字，可以减少代码量，还有isdigit()函数用来判断数字；map映射到整型，默认值为0；iterator.find找不到会返回end()  
