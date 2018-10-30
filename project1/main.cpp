#include<iostream>
#include<fstream>
#include<cstdio>
#include<stdlib.h>
#include<sstream>

#include"search.h"

using namespace std;
struct Node 
{ 
	string str2;
    string key2; 
    string key3; 
    string key4; 
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
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->str2=str; 
    node->key2   = key; 
    node->key3   = key2;
    node->key4   = key3;  
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
struct Node* insert(struct Node* node,string str,string key,string key2,string key3) 
{ 
    if (node == NULL) 
        return(newNode(str,key,key2,key3)); 
  
    if (str < node->str2) 
        node->left  = insert(node->left,str,key,key2,key3); 
    else if (str > node->str2) 
        node->right = insert(node->right,str,key,key2,key3); 
    else 
        return node; 
  
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 

    int balance = getBalance(node); 
 
  
    if (balance > 1 && str < node->left->str2) 
        return rightRotate(node); 
  
    if (balance < -1 && str > node->right->str2) 
        return leftRotate(node); 
 
    if (balance > 1 && str> node->left->str2) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
 
    if (balance < -1 && str< node->right->str2) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    return node; 
} 
  

void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
       cout<<root->str2<<" "<<root->key2<<" "<<root->key3<<" "<<root->key4<<endl; 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
int main ()
{
    struct Node *root = NULL;
    int count=0;
    string data;
    string str;
    string f1,f2,f3;
    ifstream infile;
    infile.open("myfile.txt");
    while(infile)
    {
        infile >> data;
        
        str = data;
        infile >> data;
        f1=data;
        //stringstream ss (stringstream::in | stringstream::out);
        //ss << f;
        //float val;
        //ss >> val;
      infile >> data;
      f2=data;
      infile >> data;
      f3=data;
        count++;
        root = insert(root,str,f1,f2,f3);
      //preOrder(root);
        if(count==2)
           {
            infile>>data;
            break;
           }
    }
    infile.close();	
    preOrder(root);
    return 0;
}
