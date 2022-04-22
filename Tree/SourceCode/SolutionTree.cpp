#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "SolutionTree.h"
using namespace std;
TreeNode* SolutionTree::SetTree(std::vector<int> nums) // 建立完全二叉树
{
    if (nums.empty())return NULL;
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> saveNode;
    saveNode.push(root);

    for (int i = 1; i < nums.size();i++) {
        int num = nums[i];
        auto Node = saveNode.front();
        if (!Node->left) {
            TreeNode* left = new TreeNode(num);
            Node->left = left;
            saveNode.push(left);
        }
        else {
            TreeNode* right = new TreeNode(num);
            Node->right = right;
            saveNode.pop();
            saveNode.push(right);
        }
    }
    return root;
}



void preorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr) {
        return;
    }
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

vector<int> SolutionTree::RecPreorderTraversal(TreeNode* root)// 前序递归
{
    vector<int> nums;
    preorder(root, nums);
    return nums;
}

std::vector<int> SolutionTree::ItePreorderTraversal(TreeNode* root) // 前序迭代
{
    vector<int> nums;
    if (root == nullptr) {
        return nums;
    }

    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (!stk.empty() || node != nullptr) {
        while (node != nullptr) {
            nums.push_back(node->val);
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
    return nums;
}

void inorder(TreeNode* root, vector<int>& res) {
    if (!root) {
        return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

std::vector<int> SolutionTree::RecInorderTraversal(TreeNode* root)// 中序递归
{
    vector<int> res;
    inorder(root, res);
    return res;
}

std::vector<int> SolutionTree::IteInorderTraversal(TreeNode* root)// 中序迭代
{
    vector<int> nums;
    stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        nums.push_back(root->val);
        root = root->right;
    }
    return nums;
}

void postorder(TreeNode* root, vector<int>& nums) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left, nums);
    postorder(root->right, nums);
    nums.push_back(root->val);
}

std::vector<int> SolutionTree::RecPostorderTraversal(TreeNode* root)// 后序递归
{
    vector<int> nums;
    postorder(root, nums);
    return nums;
}

std::vector<int> SolutionTree::ItePostorderTraversal(TreeNode* root)// 后序迭代
{
    vector<int> nums;
    if (root == nullptr) {
        return nums;
    }

    stack<TreeNode*> stk;
    TreeNode* prev = nullptr;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.emplace(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->right == nullptr || root->right == prev) {
            nums.emplace_back(root->val);
            prev = root;
            root = nullptr;
        }
        else {
            stk.emplace(root);
            root = root->right;
        }
    }
    return nums;
}

std::vector<std::vector<int>> SolutionTree::LevelOrder(TreeNode* root)// 层序递归
{
    vector <vector <int>> ret;
    if (!root) {
        return ret;
    }

    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        ret.push_back(vector <int>());
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front(); q.pop();
            ret.back().push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    return ret;
}

