// link - https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

#define np nullptr

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   if(root == np) return {};
       
   vector<int> ans;
   
   map<int, int> mp; // < lvl, node -> data >
   
   queue<pair<Node*, int>> q;  // <node , lvl>
   
   q.push({root , 0});
   
   while(!q.empty()){
       pair<Node*, int> temp = q.front();
       q.pop();
       
       Node* node = temp.first;
       int lvl = temp.second;
       
       if(mp.find(lvl) == mp.end())
            mp[lvl] = node->data;
       
       if(node->left){
           q.push({node->left, lvl+1});
       }
       
       if(node->right){
           q.push({node->right, lvl+1});
       }
   }
   
   for(auto i : mp){
       ans.push_back(i.second);
   }
   
   return ans;
}
