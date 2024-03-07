// link - https://leetcode.com/problems/house-robber-iii/description/?envType=study-plan-v2&envId=dynamic-programming

#include<iostream>
#include<algorithm>
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
    int rob(TreeNode* root) {
        if(root == np){
            return 0;
        }
        
            int leftleftGrandchild = 0;
            int leftrightGrandchild = 0;

            int rightleftGrandchild = 0;
            int rightrightGrandchild = 0;

            if(root->left != np){
                leftleftGrandchild = rob(root->left->left);
                leftrightGrandchild = rob(root->left->right);
            }

            if(root->right != np){
                rightleftGrandchild = rob(root->right->left);
                rightrightGrandchild = rob(root->right->right);
            }

            int includingRoot = (root->val + leftleftGrandchild + leftrightGrandchild + 
                                    rightleftGrandchild + rightrightGrandchild);

            int leftChild = rob(root->left);
            int rightChild = rob(root->right);

            int excludingRoot = (leftChild + rightChild);

            return max(includingRoot, excludingRoot);
        
    }
};

int main(){
    return 0;
}