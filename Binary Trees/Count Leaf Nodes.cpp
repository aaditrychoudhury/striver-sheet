/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void count(BinaryTreeNode<int> *root, int &ans){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) ans++;
    if(root->left) count(root->left,ans);
    if(root->right) count(root->right, ans);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int ans =0;
    if(root == NULL) return ans;
    count(root,ans);
    return ans;
}
