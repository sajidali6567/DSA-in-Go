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
        if(root == NULL) return;
        mp[root->val]++; // add the root node to the map
        if(root->left == NULL && root->right == NULL) { // leaf node
            checkForPalindrome();
        }
        DFS(root->left);
        DFS(root->right);
        mp[root->val]--; // remove once we are done with the left and right of it
    }
    void checkForPalindrome() {
        // cout << "************\n";
        int oddCount = 0;
        for(auto it:mp) {
            // cout << it.first << " - > " << it.second << endl;
            if (it.second%2 != 0) oddCount++;
        }
        if(oddCount <= 1) count++;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        DFS(root);
        return count;
    }
};