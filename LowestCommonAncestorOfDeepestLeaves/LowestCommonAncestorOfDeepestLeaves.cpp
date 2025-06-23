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
private:
    void recTraverseTree(TreeNode* root, size_t currDepth, size_t currIndex, size_t& lowestDepth, std::unordered_map<size_t, TreeNode*>& indexToTreeNode, std::unordered_map<size_t, std::pair<size_t, size_t>>& depthToLeftAndRightMostIndices) {
        indexToTreeNode[currIndex] = root;
        if (currDepth > lowestDepth) lowestDepth = currDepth;

        TreeNode* leftChild = root->left;
        TreeNode* rightChild = root->right;
        if (leftChild != nullptr) recTraverseTree(leftChild, currDepth + 1, currIndex * 2 + 1, lowestDepth, indexToTreeNode, depthToLeftAndRightMostIndices);
        if (rightChild != nullptr) recTraverseTree(rightChild, currDepth + 1, currIndex * 2 + 2, lowestDepth, indexToTreeNode, depthToLeftAndRightMostIndices);

        if (not depthToLeftAndRightMostIndices.contains(currDepth)) {
            depthToLeftAndRightMostIndices[currDepth] = std::pair<size_t, size_t>(currIndex, currIndex);
            return;
        }
        size_t leftMostIndex = depthToLeftAndRightMostIndices[currDepth].first;
        size_t rightMostIndex = depthToLeftAndRightMostIndices[currDepth].second;
        if (currIndex < leftMostIndex) depthToLeftAndRightMostIndices[currDepth] = std::pair<size_t, size_t>(currIndex, rightMostIndex);
        if (currIndex > rightMostIndex) depthToLeftAndRightMostIndices[currDepth] = std::pair<size_t, size_t>(leftMostIndex, currIndex);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        size_t lowestDepth = 0;
        std::unordered_map<size_t, TreeNode*> indexToTreeNode;
        std::unordered_map<size_t, std::pair<size_t, size_t>> depthToLeftAndRightMostIndices;

        recTraverseTree(root, /* currDepth= */ 0, /* currIndex= */ 0, lowestDepth, indexToTreeNode, depthToLeftAndRightMostIndices);

        std::pair<size_t, size_t> leftAndRightMostIndices = depthToLeftAndRightMostIndices[lowestDepth];
        size_t left = leftAndRightMostIndices.first;
        size_t right = leftAndRightMostIndices.second;
        while (left != right) {
            if (left % 2 == 1) {
                left = left / 2;
            } else {
                left = (left - 2) / 2;
            }
            if (right % 2 == 1) {
                right = right / 2;
            } else {
                right = (right - 2) / 2;
            }
        }

        return indexToTreeNode[left];
    }
};
