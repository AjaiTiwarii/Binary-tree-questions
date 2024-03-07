// link - https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

#define np nullptr

Node* f(Node* root, int &k, int node){
    //base case
    if(root == np){
        return np;
    }
    
    // node mil gyi
    if(root->data == node){
        return root;
    }
    
    Node* leftAns = f(root->left, k, node);
    Node* rightAns = f(root->right, k, node);
    
    // wapas ja rhe ho node se left aur right ki call maarne ke bad
    
    if(leftAns != np && rightAns == np){
        k--;
        if(k<=0){
            // answer wali node mil gyi h, ko lock kr do
            k = INT_MAX;
            return root;
        }
        
        return leftAns;
    }
    
    if(leftAns == np && rightAns != np){
        k--;
        if(k<=0){
            // answer wali node mil gyi h, ko lock kr do
            k = INT_MAX;
            return root;
        }
        
        return rightAns;
    }
    
    return np;
}



int kthAncestor(Node *root, int k, int node)
{
    Node* ans = f(root, k, node);
    
    if(ans == np){
        return -1;
    }
    
    // special edge case -> ki agar tumhara answer node hi aagya, lekin accd to ques k>=1 , to node to kabhi answer nhi ho skti
    if(ans->data == node){
        return -1;
    }
    
    return ans->data;
    
}
