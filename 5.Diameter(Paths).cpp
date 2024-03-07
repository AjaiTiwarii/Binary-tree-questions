//link - https://leetcode.com/problems/diameter-of-binary-tree/description/

#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// TC -> O(n^2)
class Solution {
private:
    int height(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        int ans = 1 + max(left, right);
        
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);

        int wholeTree = height(root->left) + height(root->right);

        int ans = max(leftDia, max(rightDia, wholeTree));

        return ans;
    }
};


// TC -> O(n)
class Optimised {
private:
    pair<int, int> DiameterFast(TreeNode* root){
        if(root == nullptr){
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = DiameterFast(root->left);
        pair<int, int> right = DiameterFast(root->right);
        
        int ld = left.first;
        int rd = right.first;
        int wholetree = left.second + right.second;
        
        int dia = max(ld, max(rd, wholetree));
        int height = 1 + max(left.second, right.second);
        
        pair<int, int> ans = make_pair(dia, height);
        
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        return DiameterFast(root).first;
    }
};

int main(){
    return 0;
}