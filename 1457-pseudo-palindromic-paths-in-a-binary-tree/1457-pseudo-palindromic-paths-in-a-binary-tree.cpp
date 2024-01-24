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
    // This approach came from the leetcode solution, I used a map to store frequency of the node values
    int bits = 0; // bits could be max of 10 bits, which denotes if the freq of 1, 2, 3 ... 9 is odd or even
    int ans = 0;
    void DFS(TreeNode* root) {
        bits ^= (1 << root->val); // add the root node to the map
        if(root->left == NULL && root->right == NULL) { // leaf node
            checkForPalindrome();
        }
        if(root->left) DFS(root->left);
        if(root->right) DFS(root->right);
        bits ^= (1 << root->val); // remove once we are done with the left and right of it
    }
    // there should be only one or zero number with odd frequency to make it palindrome
    void checkForPalindrome() {
        int oddCount = __builtin_popcount(bits);
        if(oddCount <= 1) ans++;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        DFS(root);
        return ans;
    }
};