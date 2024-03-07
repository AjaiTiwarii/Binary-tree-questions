// link - https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

#include<iostream>
using namespace std;

struct Node{

    int data;
    struct Node* left;
    struct Node* right;

    Node(int n){
        data = n;
        left = right = NULL;
    }

};

#define np nullptr

class Solution{
public:
    Node* lca(Node* root, int n1, int n2){
        if(root == np) return np;

        if(root->data == n1 || root->data == n2) return root;

        Node* leftans = lca(root->left, n1, n2);
        Node* rightans = lca(root->right, n1, n2);

        if(leftans != np && rightans != np){
            return root;
        }
        else if(leftans != np && rightans == np){
            return leftans;
        }
        else if(leftans == np && rightans != np){
            return rightans;
        }

        return np;
    }
};


int main(){
    return 0;
}