// link - https://www.geeksforgeeks.org/problems/sum-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

// Should return true if tree is Sum Tree, else false

#define np nullptr

class Solution
{
    public:
    
    pair<bool, int> f(Node* root){
        //base case
        if(root == np){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        //not considering leaf nodes
        if(root->left == np && root->right == np){
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool, int> leftans = f(root->left);
        pair<bool, int> rightans = f(root->right);
        
        // sumtree condn
        bool condn = root->data == leftans.second + rightans.second;
        
        pair<bool, int> ans;
        if(leftans.first && rightans.first && condn){
            ans = make_pair(true, 2*root->data);
            return ans;
        }
        else{
            ans = make_pair(false, root->data);
        }
        
        return ans;
    }
    
    
    
    bool isSumTree(Node* root)
    {
        return f(root).first;
    }
};


int main(){
    return 0;
}