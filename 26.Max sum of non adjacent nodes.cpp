// link - https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


#define pii pair<int, int>
#define np nullptr


class Solution{
  public:
  
//  pair<int, int> -> < maxSum including current node, maxSum excluding current node >
  
    pii f(Node* root){
        //base case
        if(root == np){
            pii ans = {0,0};
            return ans;
        }
        
        pii leftans = f(root->left);
        pii rightans = f(root->right);
        
        pii res;
        
        // include kr rhe node ko
        res.first = root->data + leftans.second + rightans.second;
        
        // exclude kr rhe current node ko
        res.second = max(leftans.first, leftans.second) + max(rightans.first, rightans.second);
        
        return res;
    }
  
  
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pii ans = f(root);
        
        return max(ans.first, ans.second);
    }
};