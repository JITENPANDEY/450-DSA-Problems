string serializer(Node* root, unordered_map<string, int>&mp){
        if(root==NULL) return "X";
        string s ="";
        if(!root->left && !root->right){
            s = to_string(root->data);
            return s;
        }
        string leftSubtree = serializer(root->left, mp);
        string rightSubtree = serializer(root->right, mp);
        
        s = to_string(root->data) +","+ leftSubtree +","+ rightSubtree;
        mp[s]++;
        return s;
    }
    int dupSub(Node *root) {
         // code here
        unordered_map<string,int> mp;
        serializer(root, mp);
        for(auto x:mp) 
         {
             cout<<x.first<<"->"<<x.second<<endl;
             
         }
        for(auto x:mp) 
         {
             if(x.second>=2) return true;
         }
         return false;
    }