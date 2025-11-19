/*
// Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/

// A)
int height(struct Node* node) {
    // code here
    if (!node) return 0;
    int left = 0, right = 0;
    if (node->left){
        left = 1 + height(node->left);
    }
    if (node->right){
        right = 1 + height(node->right);
    }
    
    if (left > right) return left;
    return right;
}

// B)
int count(struct Node* node){
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    int left = count(node->left);
    int right = count(node->right);
    return left+right;
}