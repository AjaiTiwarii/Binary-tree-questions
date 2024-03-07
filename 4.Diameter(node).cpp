// link - https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

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


// TC -> O(n^2)
class Solution {
  private:
    int height(Node* root){
        if(root == nullptr) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return (1 + max(left, right));
    }
  public:
    int diameter(Node* root) {
        if(root == nullptr) return 0;
        
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        
        int whole = height(root->left) + 1 + height(root->right);
        
        return max(whole, max(ld, rd));
    }
};


// TC -> O(n)
class Optimised {
  private:
  //pair<diameter, height>  
    pair<int, int> DiameterFast(Node* root){
        if(root == nullptr){
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        pair<int, int> left = DiameterFast(root->left);
        pair<int, int> right = DiameterFast(root->right);
        
        int ld = left.first;
        int rd = right.first;
        int wholetree = left.second + 1 + right.second;
        
        int dia = max(ld, max(rd, wholetree));
        int height = 1 + max(left.second, right.second);
        
        pair<int, int> ans = make_pair(dia, height);
        
        return ans;
    }
    
    
    
  public:
    int diameter(Node* root) {
        
        return DiameterFast(root).first;
    }
};


int main(){
    return 0;
}