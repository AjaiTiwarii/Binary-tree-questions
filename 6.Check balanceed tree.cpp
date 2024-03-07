// link - https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// TC -> O(n^2)
class Solution{
    public:
    int height(Node* node){
        if(node == nullptr){
            return 0;
        }
    
        int left = height(node->left);
        int right = height(node->right);
    
        int ans = 1 + max(left, right);
    
        return ans;
    }
    
    
    bool isBalanced(Node *root)
    {
        if(root == nullptr) return true; // Base case: an empty tree is balanced
        
        int l = height(root->left);
        int r = height(root->right);
        
        return abs(l - r) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

};


// TC -> O(N)
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedFast(Node* root) {
        // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    
};


int main(){
    return 0;
}