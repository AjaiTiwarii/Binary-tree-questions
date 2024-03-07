// link - https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1

#include<bits/stdc++.h>
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


vector<int> diagonal(Node *root)
{
    if(root == nullptr) return  {};
    
    vector<int> ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        
        Node* curr = q.front();
        q.pop();
        
        while(curr){
            if(curr->left){
                q.push(curr->left);
            }
            
            ans.push_back(curr->data);
            
            curr = curr->right;
        }
    }
    
    return ans;
}