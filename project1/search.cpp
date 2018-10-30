#include<iostream>
#include<bits/stdc++.h>
using namespace std;
Node * search(Node *root,string key)
{
    if (root == NULL || root->key == key)
       return root;


    if (root->key < key)
       return search(root->right, key);
    if (root)

    return search(root->left, key);

}
double * graph_search (Node *root,string key)
{
    Node *abc=search(root,key);
    double a[3]={abc->c,abc->b,abc->d};
    return a;
}
