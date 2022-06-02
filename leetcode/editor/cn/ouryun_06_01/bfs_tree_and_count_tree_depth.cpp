#include <iostream>
#include <queue>

using namespace std;

struct TNode {
    int val;
    TNode *lchild, *rchild;
    TNode() : val(0), lchild(NULL), rchild(NULL){}
    TNode(int val) : val(val), lchild(NULL), rchild(NULL){}
    TNode(int val, TNode *lchild, TNode *rchild) : val(val), lchild(lchild), rchild(rchild){}
};

TNode *init() {
    TNode *node0 = new TNode(0, NULL, NULL);
    TNode *node1 = new TNode(1, NULL, NULL);
    TNode *node2 = new TNode(2, NULL, NULL);
    TNode *node3 = new TNode(3, node0, NULL);
    TNode *node4 = new TNode(4, node1, NULL);
    TNode *node5 = new TNode(5, node3, node2);
    TNode *root = new TNode(6, node5, node4);

    return root;
}

void traval(TNode* root) {
    if (root == NULL) return ;

    traval(root->lchild);
    printf("%d ", root->val);
    traval(root->rchild);
}

void BFS(TNode* root) {
    if (root == NULL) return ;
    queue<TNode*> que;
    que.push(root);

    while(!que.empty()) {
        TNode *node = que.front();
        printf("%d ", node->val);

        if (node->lchild) {
            que.push(node->lchild);
        }

        if (node->rchild) {
            que.push(node->rchild);
        }
        que.pop();
    }
    printf("\n");
}

int maxLen(TNode* root) {
    if (root == NULL) return 0;
    int maxleft = 0, maxright = 0;
    int ret = 0;

    maxleft = maxLen(root->lchild);

    maxright = maxLen(root->rchild);

    ret = maxleft > maxright ? maxleft + 1 : maxright + 1;
    return ret;
}

int maxLen2(TNode* root) {
    if (root == NULL) return 0;
    int maxleft = 0, maxright = 0;
    int ret = 0;

    if (root->lchild) {
        maxleft = maxLen(root->lchild);
    }
    
    if (root->rchild) {
        maxright = maxLen(root->rchild);
    }
    
    ret = maxleft > maxright ? maxleft + 1 : maxright + 1;
    return ret;
}

void testtraval() {
    TNode *root = init();
    traval(root);
    printf("\n");
}

void testBFS() {
    TNode *root = init();
    BFS(root);
    printf("\n");
}

void testlen() {
    TNode *root = init();
    int ret = maxLen(root);
    printf("ret:%d\n", ret);
}

void testlen2() {
    TNode *root = init();
    int ret = maxLen2(root);
    printf("ret:%d\n", ret);
}

int main() {
    //testtraval();
    //testBFS();
    testlen();
    testlen2();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
