// 二叉树的三种序

//                      1
//                2           3
//             4     5     6     7

// 1) 先序：对于任何一棵子树 按照 中 左 右 的顺序遍历 如：1 2 4 5 3 6 7
// 2) 中序：对于任何一棵子树 按照 左 中 右 的顺序遍历 如：4 2 5 1 6 3 7
// 3) 后序：对于任何一棵子树 按照 左 右 中 的顺序遍历 如：4 5 2 6 7 3 1

#include<bits/stdc++.h>

using namespace std;

typedef struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode , *PTN;

// 递归基本的样子，用来理解递归序
// 递归序：1[1] 2[1] 4[1] 4[2] 4[3] 2[2] 5[1] 5[1] 5[1] 2[3] 1[2] 3[1] 6[1] 6[2] 6[3] 3[2] 7[1] 7[2] 7[3] 3[3] 1[3]
void Recursive(PTN H)
{
    if(H == NULL)
    {
        return;
    }
    
    // 1 第一次碰到数
    Recursive(H->left);
    // 2 第二次碰到数
    Recursive(H->right);
    // 3 第三次碰到数
}

void PreOrder(PTN H)
{
    if(H==NULL)
    {
        return;
    }

    printf("%d " , H->val);
    PreOrder(H->left);
    PreOrder(H->right);
}

void MidOrder(PTN H)
{
    if(H==NULL)
    {
        return;
    }

    MidOrder(H->left);
    printf("%d " , H->val);
    MidOrder(H->right);
}

void EndOrder(PTN H)
{
    if(H==NULL)
    {
        return;
    }

    EndOrder(H->left);
    EndOrder(H->right);
    printf("%d " , H->val);
}

void InitTree(PTN& H)
{
    H = new TreeNode;
    int x;
    scanf("%d" , &x);
    H->val = x;
    H->left = NULL;
    H->right = NULL;
}

void CreateTree_Left(PTN& H)
{
    PTN P = new TreeNode;
    int x=0;
    scanf("%d" , &x);
    P->val = x;
    P->left = NULL;
    P->right = NULL;
    H->left = P;
}

void CreateTree_Right(PTN& H)
{
    PTN P = new TreeNode;
    int x=0;
    scanf("%d" , &x);
    P->val = x;
    P->left = NULL;
    P->right = NULL;
    H->right = P;
}

int main()
{
    PTN H;
    InitTree(H);
    CreateTree_Left(H);
    CreateTree_Right(H);
    CreateTree_Left(H->left);
    CreateTree_Right(H->left);
    CreateTree_Left(H->right);
    CreateTree_Right(H->right);

    printf("先序：");
    PreOrder(H);
    printf("\n");

    printf("中序：");
    MidOrder(H);
    printf("\n");

    printf("后序：");
    EndOrder(H);
    printf("\n");

    // cout << H->val << endl;
    // cout << H->left->val << endl;
    // cout << H->right->val << endl;
    // cout << H->left->left->val << endl;
    // cout << H->left->right->val << endl;
    // cout << H->right->left->val << endl;
    // cout << H->right->right->val << endl;

    return 0;
}