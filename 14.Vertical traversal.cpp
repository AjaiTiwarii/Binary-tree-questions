// link - https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

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

class Solution{
public:
    vector<int> verticalOrder(Node* root){
        if(root == np) return {};

        map<int, map<int, vector<int>>> mp;
        queue<pair<Node* , pair<int, int>>> q;

        vector<int> ans;

        q.push({root, {0, 0}});

        while(!q.empty()){
            pair<Node* , pair<int, int>> temp = q.front();
            q.pop();

            Node* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            mp[hd][lvl].push_back(frontnode->data);

            if(frontnode->left) q.push({frontnode->left, {hd-1, lvl+1}});
            if(frontnode->right) q.push({frontnode->right, {hd+1, lvl+1}});

        }

        for(auto i: mp){

            for(auto j : i.second){

                for(auto k : j.second){

                    ans.push_back(k);

                }
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}