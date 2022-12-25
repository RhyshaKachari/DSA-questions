//Inorder Traversal - GFG
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution {
public:
vector<int> inOrder(Node* root) {
vector<int> in;
stack<Node* >st;
Node* node = root ;
while(true)
{if(node != NULL){ st.push(node);
node = node -> left;}
else{if(st.empty()){break;}

node = st.top();
st.pop();
in.push_back(node->data);
node = node->right;} }

return in;

    }
};