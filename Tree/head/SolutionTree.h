#pragma once
#ifndef _SOLUTIONTREE_H_
#define _SOLUTIONTREE_H_
#include "TreeNode.h"

class SolutionTree {
public:
	TreeNode* SetTree(std::vector<int> nums);
	std::vector<int> RecPreorderTraversal(TreeNode* root);// Ç°ÐòµÝ¹é
	std::vector<int> ItePreorderTraversal(TreeNode* root);// Ç°Ðòµü´ú
	std::vector<int> RecInorderTraversal(TreeNode* root);// ÖÐÐòµÝ¹é
	std::vector<int> IteInorderTraversal(TreeNode* root);// ÖÐÐòµü´ú
	std::vector<int> RecPostorderTraversal(TreeNode* root);// ºóÐòµÝ¹é
	std::vector<int> ItePostorderTraversal(TreeNode* root);// ºóÐòµü´ú
	std::vector<std::vector<int>> LevelOrder(TreeNode* root);// ²ãÐòµÝ¹é
};
#endif // !_SOLUTIONTREE_H_
