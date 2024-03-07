// link - https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

#include<iostream>
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

int height(Node* node){
    if(node == nullptr){
        return 0;
    }

    int left = height(node->left);
    int right = height(node->right);

    int ans = 1 + max(left, right);

    return ans;
}

int main(){
    return 0;
}