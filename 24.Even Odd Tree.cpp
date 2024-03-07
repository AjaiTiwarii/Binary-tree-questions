// link - https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

#include<bits/stdc++.h>
using namespace  std;


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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q; // < node, lvl >
        q.push({root, 0});


        while(!q.empty()){
            pair<TreeNode*, int> temp1 = q.front();
            q.pop();

            TreeNode* r1 = temp1.first;
            int lvl1 = temp1.second;

            if(lvl1 % 2 == 0 && r1->val % 2 == 0) return false;
            if(lvl1 % 2 != 0 && r1->val % 2 != 0) return false;

            if(!q.empty()){
                pair<TreeNode*, int> temp2 = q.front();

                TreeNode* r2 = temp2.first;
                int lvl2 = temp2.second;

                if(lvl1 == lvl2 && lvl1%2==0 && r2->val <= r1->val) return false;
                if(lvl1 == lvl2 && lvl1%2!=0 && r2->val >= r1->val) return false;
            } 

            if(r1->left){
                q.push({r1->left, lvl1+1});
            }

            if(r1->right){
                q.push({r1->right, lvl1+1});
            }
        }

        return true;
    }
};