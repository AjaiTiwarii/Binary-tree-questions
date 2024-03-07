// link - https://www.geeksforgeeks.org/problems/k-sum-paths/1

#include<bits/stdc++.h>
using namespace std;


struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// TLE -> O(n^2)
class Solution{
  public:
  
    void f(Node* root, int k, int &cnt, vector<int> path){
        //base case
        if(root == nullptr) return;
        
        // adding root->data to path
        path.push_back(root->data);
        
        // left path ki call
        f(root->left, k, cnt, path);
        //right path ki call
        f(root->right, k, cnt, path);
        
        int sum = 0;
        for(int i=path.size()-1; i>=0; i--){
            sum += path[i];
            if(sum == k){
                cnt++;
            }
        }
        
        // backtracking
        path.pop_back();
    }
  
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int cnt = 0;
        
        f(root, k, cnt, path);
        
        return cnt;
    }
};


// link - https://leetcode.com/problems/path-sum-iii/description/
class Solution{
  public:
    void f(Node* root, int k, int &cnt, unordered_map<int, int> &prefixSum, int currSum){
        //base case
        if(root == nullptr) return;
        
        // adding root->data to currSum
        currSum += root->data;
        
        // if currSum equals to k, increment the count
        if(currSum == k) cnt++;
        
        // if currSum-k exists in map, add its frequency to count
        if(prefixSum.find(currSum - k) != prefixSum.end()) cnt += prefixSum[currSum - k];
        
        // add currSum to map
        prefixSum[currSum]++;
        
        // recursive call to left and right child
        f(root->left, k, cnt, prefixSum, currSum);
        f(root->right, k, cnt, prefixSum, currSum);
        
        // remove currSum from map (backtracking)
        prefixSum[currSum]--;
    }
  
    int sumK(Node *root,int k)
    {
        unordered_map<int, int> prefixSum;
        int cnt = 0;
        
        f(root, k, cnt, prefixSum, 0);
        
        return cnt;
    }
};

int main(){
    return 0;
}