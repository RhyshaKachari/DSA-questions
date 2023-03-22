//Floor in BST - GFG

//Time Complexity = O(Height of the BST)
//Space Complexity = O(1)

int floor(Node* root , int x){
  int floor = -1;
  if(root == NULL){
    return floor ;
  }  
  while(root){
    if(root->data == x){
        return root->data;
    }
    else if(root->data > x){
        root= root->left;
    }
    else{
        floor = root->data;
        root = root->right;
    }
  }
  return floor;
}