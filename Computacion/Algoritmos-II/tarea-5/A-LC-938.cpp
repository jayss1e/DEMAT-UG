#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;
        
        // cout << "IN "<<root->val<<'\n';

        int ans = 0;
        if (low <= root->val && root->val <= high)
            ans += root->val;
        
        if (root->left && root->val >= low)
            ans += rangeSumBST(root->left, low, high);
        if (root->right && root->val <= high)
            ans += rangeSumBST(root->right, low, high);

        return ans;
    }
};