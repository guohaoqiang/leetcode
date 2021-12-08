class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> mp;
        // bfs
        queue<TreeNode*> q;
        if (root)   q.push(root);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                auto it = q.front();
                q.pop();
                if (it->left)   { 
                    q.push(it->left); 
                    mp[it->val].push_back(it->left->val);
                    mp[it->left->val].push_back(it->val);
                }
                if (it->right)   { 
                    q.push(it->right); 
                    mp[it->val].push_back(it->right->val);
                    mp[it->right->val].push_back(it->val);
                }
            }
        }
        
        vector<int> ans;
        if (k==0)   return mp.count(target->val)?vector<int>{target->val}:vector<int>{};
        queue<int> nq;
        unordered_set<int> v;
        if (mp.count(target->val)) nq.push(target->val);
        while (nq.size()>0 && k>0){
            int n = nq.size();
            for (int i=0; i<n; ++i){
                auto ft = nq.front();
                nq.pop();
                v.insert(ft);
                for (auto b:mp[ft]){
                    if (!v.count(b)) 
                        nq.push(b);
                }
            }
            k--;
        }
        while (nq.size()){
            ans.push_back(nq.front());
            nq.pop();
        }    
        return ans;
    }
};
