#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left; 
    TreeNode* right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};



/* Function to traverse the binary tree without recursion
   and without stack */
void MORRIS_TRAVERSAL(TreeNode* root){

    struct TreeNode *current, *pre;

    if(root == NULL) return;

    current = root;

    while(current != NULL){

        if(current->left == NULL){
            cout << current->data << " ";
            current = current->right;
        }
        else{

            /*Find the inorder predecessor of current*/
            pre = current->left;
            while(pre->right!=NULL && pre->right!=current){
                pre = pre->right;
            }

            /*make current as the right child of its inorder predecessor*/
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }
            else{
                /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}

int main(){

    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
  */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    MORRIS_TRAVERSAL(root);

    return 0;
}