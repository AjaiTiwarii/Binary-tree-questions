// link - https://www.geeksforgeeks.org/tag/n-ary-tree/

// Diameter of N-ary tree:

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    vector<Node*> children;
    Node(int v) : val(v), children() {}
};

class Optimised {
private:
    pair<int, int> DiameterFast(Node* root) {
        if (root == nullptr) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        
        int maxHeight1 = 0, maxHeight2 = 0, maxDiameter = 0;
        for (Node* child : root->children) {
            pair<int, int> childInfo = DiameterFast(child);
            int childHeight = childInfo.second;
            maxDiameter = max(maxDiameter, childInfo.first);
            if (childHeight > maxHeight1) {
                maxHeight2 = maxHeight1;
                maxHeight1 = childHeight;
            } else if (childHeight > maxHeight2) {
                maxHeight2 = childHeight;
            }
        }
        
        int diameterThroughNode = maxHeight1 + maxHeight2;
        maxDiameter = max(maxDiameter, diameterThroughNode);
        
        return make_pair(maxDiameter, maxHeight1 + 1);
    }
public:
    int diameterOfNaryTree(Node* root) {
        return DiameterFast(root).first;
    }
};
