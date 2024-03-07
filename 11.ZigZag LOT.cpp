#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

//link - https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
class GFG{
public:
    vector<int> zigZagTraversal(Node* root){
        if(root == np) return {};

        vector<int> res;

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);

            for(int i=0; i<size; i++){
                Node* temp = q.front();
                q.pop();

                int index = leftToRight ? i : size - i -1;

                ans[index] = temp->data;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            for(auto i: ans){
                res.push_back(i);
            }

            //changing direction
            leftToRight = !leftToRight;

        }

        return res;
    }
};

//link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

class Leetcode {
public:
    vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>> ans;
        int cnt = 0;

        if (root == NULL) return ans;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            vector<int> aux;

            while(q.front() != NULL){
                Node* temp = q.front();
                q.pop();

                if(temp != NULL){
                    aux.push_back(temp->data);

                    if(temp->left) q.push(temp->left);

                    if(temp->right) q.push(temp->right);
                } 
            }

            q.pop();
            cnt++;
            if(cnt%2 == 0) reverse(aux.begin(), aux.end());
            ans.push_back(aux);

            if(!q.empty()){
                q.push(NULL);
            }
        }

        return ans;
    }
};

int main(){
    return 0;
}