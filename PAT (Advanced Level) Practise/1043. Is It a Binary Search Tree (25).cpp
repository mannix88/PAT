/**
* 分析：一定要仔细啊！！！
*       BST，镜像问题，用静态实现，插入建树处理数组下标的时候比较麻烦
*       注意插入一定要用引用，考虑下是不是动态静态灵活处理一下，不要一昧使用静态实现。。。
*       我再写写看，不行就灵活处理，然后静态实现的固定写法要记下来
**/

#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1010;

int n, temp, root = -1; //定义根结点为空
vector<int> origin, pre, prem, post, postm;

struct Node {
    int data;
    int lchild, rchild;
} node[maxn];

int index = 0;
void insert(int &root, int x) {
    if(root == -1) {
        node[index].data = x;
        node[index].lchild = -1;
        node[index].rchild = -1;
        root=index++;
        return;
    }
    if(x < node[root].data)
        insert(node[root].lchild, x);
    else
        insert(node[root].rchild, x);
}

void preorder(int root) {
    if(root == -1)
        return;
    pre.push_back(node[root].data);
    preorder(node[root].lchild);
    preorder(node[root].rchild);
}

void preorderm(int root) {
    if(root == -1)
        return;
    prem.push_back(node[root].data);
    preorderm(node[root].rchild);
    preorderm(node[root].lchild);
}

void postorder(int root) {
    if(root == -1)
        return;
    postorder(node[root].lchild);
    postorder(node[root].rchild);
    post.push_back(node[root].data);
}

void postorderm(int root) {
    if(root == -1)
        return;
    postorderm(node[root].rchild);
    postorderm(node[root].lchild);
    postm.push_back(node[root].data);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        insert(root, temp);
        origin.push_back(temp);
    }
    preorder(root);
    preorderm(root);
    postorder(root);
    postorderm(root);
    if(origin == pre) {
        printf("YES\n");
        for(int i = 0; i < post.size(); i++) {
            if(i < post.size() - 1)
                printf("%d ", post[i]);
            else
                printf("%d", post[i]);
        }
    } else if(origin == prem) {
        printf("YES\n");
        for(int i = 0; i < postm.size(); i++) {
            if(i < postm.size() - 1)
                printf("%d ", postm[i]);
            else
                printf("%d", postm[i]);
        }
    } else {
        printf("NO");
    }
    return 0;
}
