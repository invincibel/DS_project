#include<iostream>
#include<fstream>
#include<cstdio>
#include<stdlib.h>
#include<sstream>

using namespace std;
struct Node
{
    string str;
    float key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b);

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a,int b)
{
    return (a > b)? a : b;
}

struct Node* newNode(string str,float key)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->str=str;
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}


struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}


struct Node* insert(struct Node* node, string str,float key)
{
    if (node == NULL)
        return(newNode(str,key));

    if (key < node->key)
        node->left  = insert(node->left,str,key);
    else if (key > node->key)
        node->right = insert(node->right,str,key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));


    int balance = getBalance(node);


    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void preOrder(struct Node *root)
{
    if(root==NULL)
        return;
   // if(root != NULL)

        cout<<root->str<<" "<<root->key;
        cout<<endl;
        if(root->left!=NULL)
        preOrder(root->left);
        if(root->right!=NULL)
        preOrder(root->right);

}
int main ()
{
    struct Node *root = NULL;
    int count=0;
    string data;
    string str;
    string f;
    ifstream infile;
    infile.open("myfile.txt");
    while(infile)
    {
        infile >> data;
        cout << data << endl;
        str = data;
        infile >> data;
        f=data;
        stringstream ss (stringstream::in | stringstream::out);
        ss << f;
        float val;
        ss >> val;
        cout << data << endl;
        count++;
        root = insert(root,str,val);
        if(count==2)
            infile>>data;
    }
    infile.close();
    preOrder(root);
    return 0;
}
