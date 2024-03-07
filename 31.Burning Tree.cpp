// link - https://www.geeksforgeeks.org/problems/burning-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//tc-> O(n) + O(n) == O(n) and SC = O(n)

class Solution{
public:
    map< Node*, Node* > parent;

    int BurnTree(Node* root, Node* startNode){
        int ans = 0;
        
        queue< Node* > q;
        q.push(startNode);

        map<Node*, int> vis;

        vis[startNode] = 1;

        while(!q.empty()){

            int size = q.size();
            int burnt = 0;

            for(int i=0; i<size; i++){

                Node* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    burnt = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    burnt = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if(parent.find(node) != parent.end() && !vis[parent[node]]){
                    burnt = 1;
                    vis[parent[node]] = 1;
                    q.push(parent[node]);
                }
            }

            if(burnt) ans++;

        }

        return ans;
    }

    Node* parentMapping(Node* root, int target){

        Node* res = NULL; // to store the address of the target node
        queue< Node* > q;

        q.push(root);

        while(!q.empty()){
            Node* node = q.front();
            if(node->data == target) res = node;

            q.pop();

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        return res;
    }

    int minTime(Node* root, int target){

        // Algo 
        // 1. Create a parent mapping for each node through LOT
        // 2. Do a BFS to cal the minimum time

        Node* startNode = parentMapping(root, target); // this function alse return the address of the target node

        int minTimeToBurn = BurnTree(root, startNode); // function to calc time

        return minTimeToBurn;
    }
};

int main(){
    return 0;
}