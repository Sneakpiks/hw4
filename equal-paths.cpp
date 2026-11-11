#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here


bool equalPaths(Node * root)
{
    // Add your code below
    if(root == nullptr) return true;

    Node* L = root->left;
    Node* R = root->right;

    if(L == nullptr && R == nullptr) return true;

    if(L == nullptr) return equalPaths(R);
    if(R == nullptr) return equalPaths(L);

    bool leftLeaf = (L->left == nullptr && L->right == nullptr);
    bool rightLeaf = (R->left == nullptr && R->right == nullptr);
    if(leftLeaf != rightLeaf) return false;

    if(!equalPaths(L)||!equalPaths(R)) return false;

    Node temp(0);

    temp.left = L->left;
    if(temp.left == nullptr){
      temp.left = L->right;
    }

    temp.right = R->left;
    if(temp.right == nullptr){
      temp.right = R->right;
    }
    
    return equalPaths(&temp);
}

