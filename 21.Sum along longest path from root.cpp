// link - https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

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


class Solution
{
public:

    void f(Node* root, int len, int &maxlen, int sum, int &maxsum){
        if(root == nullptr){
            
            if(len > maxlen){
                maxsum = sum;
                maxlen = len;
            }
            else if(len == maxlen){
                maxsum = max(sum, maxsum);
            }
            
            return;
        }
        
        sum += root->data;
        
        f(root->left, len+1, maxlen, sum, maxsum);
        f(root->right, len+1, maxlen, sum, maxsum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0;
        int maxlen = 0;
        int sum = 0;
        int maxsum = 0;
        
        f(root, len, maxlen, sum, maxsum);
        
        return maxsum;
    }
};

int main(){
    return 0;
}