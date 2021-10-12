class FileSystem {
private:
    struct trienode{
        trienode():is_file(false),content(""){}
        unordered_map<string,trienode*> next;
        bool is_file;
        string content;
    };
    trienode* root;
public:
    trienode* parse(string path){
        trienode* cur = root;
        istringstream s(path);
        string file;
        while (getline(s,file,'/')){
            if (!cur->next[file]){
                cur->next[file] = new trienode();
            }
            cur = cur->next[file];
        }
        
        return cur;
    }
    FileSystem() {
        root = new trienode();
    }
    
    vector<string> ls(string path) {
        trienode* dir = parse(path);
        if (dir->is_file){
            return {path.substr(path.find_last_of('/')+1)};
        }
        
        vector<string> ans;
        for (auto f:dir->next){
            ans.push_back(f.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        trienode* dir = parse(path);
    }
    
    void addContentToFile(string filePath, string content) {
        trienode* dir = parse(filePath);
        dir->is_file = true;
        dir->content += content;
    }
    
    string readContentFromFile(string filePath) {
        trienode* dir = parse(filePath);
        return dir->content;
    }
};

