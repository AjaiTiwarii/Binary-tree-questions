// link - https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

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

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if(root == np) return {};
        
        vector<int> ans;
        
        map<int, int> mp;  // <hd, topnode->data >
        
        queue<pair<Node*, int>> q;  // < node, hd >
        
        q.push({root, 0});
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // create 1:1 mappind (if alrrady exist don't do anything)
            if(mp.find(hd) == mp.end()){
                mp[hd] = frontNode->data;
            }
            
            if(frontNode->left){
                q.push({frontNode->left, hd-1});
            }
            
            if(frontNode->right){
                q.push({frontNode->right, hd+1});
            }
        }
        
        for(auto i : mp){
            ans.push_back(i.second);
        }
        
        return ans;
    }

};


int main(){
    return 0;
}