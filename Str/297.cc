class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        encode(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
    
    TreeNode* decode(istringstream& in){
        string val;
        in >> val;
        if (val=="#")   return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = decode(in);
        root->right = decode(in);
        return root;
    }
    void encode(TreeNode* root, ostringstream& out){
       
        if (root){
            out << root->val <<' ';
            encode(root->left,out);
            encode(root->right,out);
        }else{
            out << "# ";
        }
        
    }
};
