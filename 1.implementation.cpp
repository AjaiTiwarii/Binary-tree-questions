#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(TreeNode* root){
    cout << "enter data for node: ";
    int  data; cin >> data;

    root = new TreeNode(data);

    if(data == -1) return NULL;

    cout << "enter data for inserting in left of: " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter data for inserting in right of: "<< data << endl;
    root->right = buildTree(root->right);

    return root;
}

void LevelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL); //separator

    while(!q.empty()){
        TreeNode* temp = q.front();
        
        q.pop();

        if(temp == NULL){
            //purana level complete traverse ho chuka h
            cout << endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

class levelorder {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            vector<int> aux;

            while(q.front() != NULL){
                TreeNode* temp = q.front();
                q.pop();

                if(temp != NULL){
                    aux.push_back(temp->data);

                    if(temp->left) q.push(temp->left);

                    if(temp->right) q.push(temp->right);
                } 
            }

            q.pop();
            ans.push_back(aux);

            if(!q.empty()){
                q.push(NULL);
            }
        }

        return ans;
    }
};

void inOrder(TreeNode* root){
    if(root){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void preOrder(TreeNode* root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode* root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}


int main(){

    TreeNode* root = NULL;
    root = buildTree(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //inOrder(root);
    cout << endl;
    LevelOrderTraversal(root);

    return 0;
}