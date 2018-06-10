#include <iostream>
#include <queue>

using namespace std;

struct Node{
char data;
Node *left=NULL;
Node *right=NULL;
Node *NextBrother=NULL;
};

Node *addvalue(int x){
Node *temp = new Node;
temp->left = temp->right = NULL;
temp->data = x;
return temp;
}

void printNextBrother(Node *r){
   if(r==NULL)
    return;
   queue<Node *> q;
   q.push(r);
   while(!q.empty()){
    Node *cur = q.front();
    cout<<cur->data<<"  "<<cur->NextBrother;
    if(cur->NextBrother!=NULL) cout<<"   "<<cur->NextBrother->data;
    cout<<endl;
    if(cur->left!=NULL) q.push(cur->left);
    if(cur->right!=NULL) q.push(cur->right);
    q.pop();
   }
}

void makerightbrothernull(Node **r){
//    cout<<(*r)->data<<endl;

   if((*r)->right==NULL){
     return;
   }
  (*r)->right->NextBrother = NULL;
  makerightbrothernull(&((*r)->right));
}

void Stitchany(Node **r){
   if(*r==NULL)
    return;
   queue<Node *> q;
   if((*r)->left!=NULL)q.push((*r)->left);
   if((*r)->right!=NULL)q.push((*r)->right);
   while(!q.empty()){
    Node *cur = q.front();
//    cout<<cur->data<<endl;
   // printqueue(q);
   if((cur)->left!=NULL)q.push((cur)->left);
   if((cur)->right!=NULL)q.push((cur)->right);
    q.pop();
    if(q.empty())return;
    Node *cur1 = q.front();
    cur->NextBrother = cur1;
   }
}

void Stitch(Node **r){
Stitchany(r);
makerightbrothernull(r);
}

int main()
{

    Node *root = addvalue('A');
    root->left = addvalue('B');
    root->left->left = addvalue('D');
    root->left->right = addvalue('E');
    root->left->right->left = addvalue('G');
    root->right = addvalue('C');
    root->right->right = addvalue('F');
    root->right->right->right = addvalue('H');

    Stitch(&root);

    printNextBrother(root);


    return 0;
}
