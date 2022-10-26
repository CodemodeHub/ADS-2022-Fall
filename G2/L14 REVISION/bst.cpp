#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isValidBST(TreeNode* root) {
    return isValid(root, -2147483653, 2147483652);
}

bool isValid(TreeNode* root, long long lower, long long upper) {
    bool isLeftValid = true, isRightValid = true;
    TreeNode* left = root->left, *right = root->right;
    if(left)
        isLeftValid = left->val > lower && left->val < upper && left->val < root->val && isValid(left, lower, root->val); 
    if(right)
        isRightValid = right->val > lower && right->val < upper && right->val > root->val && isValid(right, root->val, upper);
    return isLeftValid && isRightValid;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lca;
    if(root->val > min(p->val, q->val) && root->val < max(p->val, q->val))
        lca=root;
    else if(root->val < p->val && root->val < q->val)
        lca=lowestCommonAncestor(root->right, p, q);
    else if(root->val > p->val && root->val > q->val){
        lca=lowestCommonAncestor(root->left, p, q);
    }
    return lca;
}