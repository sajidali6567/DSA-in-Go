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
    map<int, int> mp;
    int count = 0;
    void DFS(TreeNode* root) {
        mp[root->val]++; // add the root node to the map
        if(root->left == NULL && root->right == NULL) { // leaf node
            checkForPalindrome();
        }
        if(root->left) DFS(root->left);
        if(root->right) DFS(root->right);
        mp[root->val]--; // remove once we are done with the left and right of it
    }
    // there should be only one or zero number with odd frequency to make it palindrome
    void checkForPalindrome() {
        int oddCount = 0;
        for(auto it:mp) {
            if (it.second & 1) oddCount++;
        }
        if(oddCount <= 1) count++;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        DFS(root);
        return count;
    }
};