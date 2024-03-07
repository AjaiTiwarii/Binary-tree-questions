#include<iostream>
using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;

  Node(int x){
    data = x;
    left = NULL;
    right = NULL;
  }

};

// link - https://www.geeksforgeeks.org/problems/construct-tree-1/1
class Solution{
    public:
    // ye function ki tc -> O(n), mapping kr skte ho O(1) mein laane ke lie lekin duplicate numbers h tb dikkat hogi
    int findPosition(int element, int in[], int n){
        for(int i=0; i<n; i++){
            if(in[i] == element){
                in[i] = -108; // any value so that it doesn't match next time
                return i;
            }
        }
        return -1;
    }
    
    Node* f(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n){
        
        // base case
        if(index >= n || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        
        int position = findPosition(element, in, n);
        
        // left and right calls for building

        // left ki call pehle jayegi
        root->left = f(in, pre, index, inOrderStart, position - 1, n);
        
        root->right = f(in, pre, index, position + 1, inOrderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        int inOrderStart = 0, inOrderEnd = n-1;
        
        Node* ans = f(in, pre, preOrderIndex, inOrderStart, inOrderEnd, n);
        
        return ans;
    }
};

int main(){
    return 0;
}