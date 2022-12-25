//Preorder Traversal - GFG
//Iterative approach
//Time Complexity = O(N)
//Space Complexity = O(N)

vector <int> preorder(Node* root)
{vector<int> pre ;
stack<Node*>s;
if(root == NULL){
return pre;}
s.push(root);
while(!s.empty()){
Node* node = s.top();
pre.push_back(node->data);
s.pop();
if(node->right != NULL){ s.push(node->right) ;}
if(node->left!= NULL){s.push(node->left);}
}
return pre;
}

