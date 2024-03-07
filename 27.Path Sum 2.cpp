// link - https://leetcode.com/problems/path-sum-ii/description/

#include<bits/stdc++.h>
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
    vector<vector<int>> ans;

    void f(TreeNode* root, int t, int currSum, vector<int> &temp)
    {
        if(root == nullptr){
            return;
        }

        currSum += root->val;
        temp.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            if(currSum == t){
                ans.push_back(temp);
            }
        } else {
            f(root->left, t, currSum, temp);
            f(root->right, t, currSum, temp);
        }

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int t) {
        if(root == nullptr) return {};
        vector<int> temp ;

        f(root, t, 0, temp);

        return ans;
    }
};
