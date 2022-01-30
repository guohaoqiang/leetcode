class Solution {
public:
    int count = 0;
    int minCameraCover(TreeNode* root) {
        if (helper(root)==0){
            count++;
        }
        return count;
    }
    
    int helper(TreeNode* root){
        if (!root)  return 2;
    
        int l = helper(root->left);
        int r = helper(root->right);
        //either one child is not covered, set a cam here
        if (l==0 || r==0){
            count++;
            return 1;
        }
        // either child has a cam, the current node is covered
        if (l==1 || r==1){
            return 2;
        }
        // both child are covered, the current node is not covered
        if (l==2 && r==2){
            return 0;
        }
        
        return -1;
    }
};
