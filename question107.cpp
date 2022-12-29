//Top View of Binary Tree - GFG
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution{
public:
vector<int> topView(Node *root){
vector<int>ans;
queue<pair<Node* , int>>q;
map<int , int>mp;
if(root == NULL){return ans ;}
q.push({root , 0});
while(!q.empty()){
auto it = q.front();
q.pop();
Node* node = it.first;
int line = it.second;
if(mp.find(line) == mp.end()){mp[line] = node->data;}
if(node->left){q.push({node->left , line-1});}
if(node->right){q.push({node->right , line+1});}
}
for(it:mp){
ans.push_back(it.second);}
return ans;
}
};

