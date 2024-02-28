#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int main()
{
    TreeNode *root = new TreeNode(5);
    TreeNode *left = new TreeNode(6);
    TreeNode *right = new TreeNode(7);
    root->left = left;
    root->right = right;
    left->left = new TreeNode(9);
    left->right = new TreeNode(10);
    right->right = new TreeNode(11);
    vector<int> traversal;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        TreeNode *temp = stk.top();
        stk.pop();
        if (temp->right)
            stk.push(temp->right);
        if (temp->left)
            stk.push(temp->left);
        traversal.push_back(temp->val);
    }
    for (auto it : traversal)
    {
        cout << it << " ";
    }

    return 0;
}