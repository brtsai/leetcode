/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        std::vector<std::vector<int>> levelValues;
        std::vector<TreeNode*> currLevel = {root};
        while (currLevel.size() > 0) {
            std::vector<TreeNode*> nextLevel;
            std::vector<int> currLevelValues;

            for (std::vector<TreeNode*>::iterator itor = currLevel.begin(); itor != currLevel.end(); ++itor) {
                TreeNode* currNode = *itor;

                currLevelValues.push_back(currNode->val);
                if (currNode->left != nullptr) nextLevel.push_back(currNode->left);
                if (currNode->right != nullptr) nextLevel.push_back(currNode->right);
            }
            levelValues.push_back(currLevelValues);
            currLevel = nextLevel;
        }

        return levelValues;
    }
};
