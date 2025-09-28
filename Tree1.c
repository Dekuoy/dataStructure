#include <stdio.h>
#include <stdlib.h>

// 前向声明（可选，因为我们会在后面定义）
typedef struct TreeNode TreeNode;
typedef struct TreeNode* BiTree;

// 定义 ElemType
typedef struct {
    int value;
} ElemType;

// 定义树节点结构体
typedef struct TreeNode {
    ElemType data;
    TreeNode *lchild;
    TreeNode *rchild;
} TreeNode, *BiTree;  // 注意：这里重复使用 BiTree 是允许的，但更推荐上面的写法

// 函数声明（放在 main 之前）
BiTree GBiTree();
TreeNode* GTreeNode(int value);
void visit(TreeNode* root);
void PrintTree(BiTree root);

// 主函数
int main() {
    BiTree root = GBiTree();
    TreeNode* p = GTreeNode(2);
    root->lchild = p;

    // 调用遍历函数打印树（先序）
    PrintTree(root);
    printf("\n");

    // 可选：释放内存
    free(p);
    free(root);

    return 0;
}

// 创建根节点（值为1）
BiTree GBiTree() {
    BiTree root = (BiTree)malloc(sizeof(TreeNode));
    if (root == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    root->data.value = 1;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

// 创建新节点
TreeNode* GTreeNode(int value) {
    TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    p->data.value = value;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

// 访问节点
void visit(TreeNode* root) {
    printf("%d ", root->data.value);
}

// 中序遍历打印
void PrintTree(BiTree root) {
    if (root != NULL) {
        
        PrintTree(root->lchild);
        visit(root);
        PrintTree(root->rchild);
    }
}