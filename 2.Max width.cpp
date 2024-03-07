// link - https://leetcode.com/problems/maximum-width-of-binary-tree/description/

#include<bits/stdc++.h>
using namespace std;


// template <typename T>
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// NOT CONSIDERING NULL NODES
int getMaxWidth(TreeNode *root)
{
    if(root==nullptr) return 0;

    int ans = INT_MIN;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        int cnt = 0;
        while(q.front() != nullptr){
            TreeNode* temp = q.front();
            q.pop();

            if(temp != nullptr){
                cnt++;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
        }

        q.pop();
        ans = max(ans, cnt);

        if(!q.empty()){
            q.push(nullptr);
        }
    }

    return ans;
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 1});

        while(!q.empty()){
            int size = q.size();
            long long left = q.front().second;
            long long right = left;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                right = q.front().second;
                q.pop();

                if(node->left) q.push({node->left, 2 * right});
                if(node->right) q.push({node->right, 2 * right + 1});
            }

            ans = max(ans, (int)(right - left + 1));
        }

        return ans;
    }
};
