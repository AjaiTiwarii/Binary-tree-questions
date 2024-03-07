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
    int findPosition(int ele, int in[], int n){
        for(int i=n-1; i>=0; i--){
            if(in[i] == ele){
                in[i] = 1e9;   // any value so that it doesn't match next time
                return i;
            }
        }
        return -1;
    }

    Node* f(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n){
        
        //base case
        if(index < 0 || inOrderStart > inOrderEnd){
            return NULL;
        }
        
        int element = post[index--];
        Node* root = new Node(element);
        
        int position = findPosition(element, in, n);
        
        // left and right subtree build krne ke liye calls
        
        // right ki call pehle jayegi
        root -> right = f(in, post, index, position+1, inOrderEnd, n);
        
        root -> left = f(in, post, index, inOrderStart, position-1, n);
        
        return root;
    }


    Node *buildTree(int in[], int post[], int n) {
        
        int postOrderIndex = n-1;
        int inOrderStart = 0, inOrderEnd = n-1;
        
        Node* ans = f(in, post, postOrderIndex, inOrderStart, inOrderEnd, n);
        
        return ans;
    }

};

int main(){
    return 0;
}