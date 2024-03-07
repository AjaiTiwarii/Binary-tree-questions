// link - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

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
    vector<int> ans;

    void traverseLeft(Node* root){
        //base case-> root null ho ya fir leaf node ho to mt lo
        if((root == np) || (root->left == np && root->right == np)){
            return ;
        }

        ans.push_back(root->data);

        if(root->left){
            traverseLeft(root->left);
        }
        else{
            traverseLeft(root->right);
        }
    }

    void traverseLeaf(Node* root){
        if(root == np){
            return;
        }

        if(root->left == np && root->right == np){
            ans.push_back(root ->data);
        }

        traverseLeaf(root->left);
        traverseLeaf(root->right);
    }

    void traverseRight(Node* root){
        if((root == np) || (root->left == np && root->right == np)){
            return;
        }

        if(root->right){
            traverseRight(root->right);
        }
        else{
            traverseRight(root->left);
        }

        //wapas aagye
        ans.push_back(root->data);
    }

    vector <int> boundary(Node *root){
        if(root == np) return {};

        ans.push_back(root->data);

        // left walo ko store krlo
        traverseLeft(root->left);

        // leaf node ko store kr lo ab
        traverseLeaf(root->left);
        traverseLeaf(root->right);

        //right walo lo store kr lo
        traverseRight(root->right);

        return ans;
    }
};


int main(){
    return 0;
}