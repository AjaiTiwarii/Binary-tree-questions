// link - https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

#include<iostream>
using  namespace std;

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
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == np && r2 == np) return true;
        
        if(r1 != np && r2 == np) return false;
        
        if(r1 == np && r2 != np) return false;
        
        bool value = r1->data  == r2->data;
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        
        
        if(left && right && value) return true;
        
        return false;
        
    }
};

int main(){
    return 0;
}