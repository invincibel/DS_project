#include<bits/stdc++.h>
#include<string.h>
using namespace std;

struct Node
{
    string str;
    float key;
    struct Node *left;
    struct Node *right;
    int height;
};
Node * search(Node *root,string key)
{
    if (root == NULL || root->str == key)
       return root;


    if (root->str < key)
       return search(root->right, key);
    if (root->str>key)
        return search(root->left, key);

}
double * graph_search (Node *root,string key)
{
    Node *abc=search(root,key);
    double a[3]={abc->c,abc->b,abc->d};
    return a;
}
