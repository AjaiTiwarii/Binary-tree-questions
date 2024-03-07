// link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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


#define np nullptr

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == np) return {};

        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        vector<vector<int>> ans;

        q.push({root,  {0, 0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            mp[hd].push_back({lvl, node->val});

            if(node->left) q.push({node->left, {hd-1, lvl+1}});
            if(node->right) q.push({node->right, {hd+1, lvl+1}});
        }

        for(auto &i: mp){
            sort(i.second.begin(), i.second.end());
            vector<int> col;
            for(auto &j: i.second){
                col.push_back(j.second);
            }
            ans.push_back(col);
        }

        return ans;
    }
};
