#pragma once
#ifndef _SOLUTIONTREE_H_
#define _SOLUTIONTREE_H_
#include "TreeNode.h"

class SolutionTree {
public:
	TreeNode* SetTree(std::vector<int> nums);
	std::vector<int> RecPreorderTraversal(TreeNode* root);// ǰ��ݹ�
	std::vector<int> ItePreorderTraversal(TreeNode* root);// ǰ�����
	std::vector<int> RecInorderTraversal(TreeNode* root);// ����ݹ�
	std::vector<int> IteInorderTraversal(TreeNode* root);// �������
	std::vector<int> RecPostorderTraversal(TreeNode* root);// ����ݹ�
	std::vector<int> ItePostorderTraversal(TreeNode* root);// �������
	std::vector<std::vector<int>> LevelOrder(TreeNode* root);// ����ݹ�
};
#endif // !_SOLUTIONTREE_H_
