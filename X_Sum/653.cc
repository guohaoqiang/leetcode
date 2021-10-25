class Solution {
public:
    void inorder_visit(TreeNode* root){
        if (root->left) inorder_visit(root->left);
        tree.push_back(root->val);
        if (root->right) inorder_visit(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder_visit(root);
        int i=0,j=tree.size()-1;
        while (i<j){
            if (tree[i]+tree[j]<k){
                i++;
            }else if (tree[i]+tree[j]>k){
                j--;
            }else {
                return true;
            }
        }
        return false;
    }
    vector<int> tree;
};

