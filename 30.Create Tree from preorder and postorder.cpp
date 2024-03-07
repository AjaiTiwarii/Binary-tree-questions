// link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:

    TreeNode* f(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, 
                    int postStart, int postEnd)
    {
        // base case
        if(preStart > preEnd) {
            return NULL;
        }

        int element = preorder[preStart];
        TreeNode* root = new TreeNode(element);

        // check if only one node is there in tree
        if(preStart == preEnd) return root;

        int ind = postStart;
        int totalElementsInLeftSubTree = 0;
        while(postorder[ind] != preorder[preStart + 1]){
            ind++;
        }
        totalElementsInLeftSubTree = ind - postStart + 1;

        root->left = f(preorder, postorder, preStart+1, preStart+totalElementsInLeftSubTree,
                        postStart, postStart+totalElementsInLeftSubTree-1);

        root->right = f(preorder, postorder, preStart+totalElementsInLeftSubTree+1, preEnd,
                        postStart+totalElementsInLeftSubTree, postEnd);;

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        int preStart = 0, preEnd = n-1;
        int postStart = 0, postEnd = n-1;

        TreeNode* ans = f(preorder, postorder, preStart, preEnd, postStart, postEnd);

        return ans;
    }
};