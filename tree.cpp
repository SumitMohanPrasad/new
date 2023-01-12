#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node{
 int data;
 node* left;
 node* right;
 node(int x){
 data=x;
 left=NULL;
 right=NULL;
 }
};
void inorder(node *root){
 if(root==NULL)
  return;
 cout<<root->data<<" ";
 inorder(root->left);
 inorder(root->right);
}

int height(node *root){
 if(root==NULL)
    return 0;
 return max(height(root->left),height(root->right))+1;
}

void printKdist(node *root,int k){
 if(root==NULL)
    return;
 if(k==0){
    cout<<"\n"<<root->data;
 }
 printKdist(root->left,k-1);
 printKdist(root->right,k-1);
}

void printLevel(node *root){
 if(root==NULL){
    return;
 }
 queue<node*>q;
 q.push(root);
 while(q.empty()==false){
    node *curr=q.front();
    q.pop();
    cout<<" "<<curr->data;
    if(curr->left!=NULL){
        q.push(curr->left);
    }
    if(curr->right!=NULL){
        q.push(curr->right);
    }
 }
}
void printLevelOrderLine(node *root){
 if(root==NULL) return;
 queue<node*>q;
 q.push(root);
 while(q.empty()==false){
    int count=q.size();
 for(int i=0;i<count;i++){
    node *curr=q.front();
    q.pop();
    cout<<curr->data;
    if(curr->left!=NULL)
      q.push(curr->left);
    if(curr->right!=NULL)
        q.push(curr->right);
 }
 cout<<"\n";
 }
}

int getSize(node *root){
 if(root==NULL)
    return 0;
 else
 return (1+getSize(root->left)+getSize(root->right));

}

int getMax(node *root){
 if(root==NULL) return INT_MIN;
 else
    return max(root->data,max(getMax(root->left),getMax(root->right)));
}

int maxLevel=0;
void printleft(node *root,int level){
 if(root==NULL) return;
 if(maxLevel<level){
    cout<<"\n"<<root->data;
    maxLevel=level;
 }
 printleft(root->left,level+1);
 printleft(root->right,level+1);
}
void printleftView(node *root){
 printleft(root,1);
}

void printLeftIterative(node *root){
  if(root==NULL) return;
  queue<node *>q;
  q.push(root);
  while(q.empty()==false){
    int count=q.size();
    for(int i=0;i<count;i++){
        node *curr=q.front();
        q.pop();
        if(i==0){
            cout<<"\n"<<curr->data;
        }
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
  }
}
bool iscSum(node *root){
 if(root==NULL) return true;
 if(root->left==NULL && root->right==NULL){
    return true;
 }
 int sum=0;
 if(root->left!=NULL) sum+=root->left->data;
 if(root->right!=NULL) sum+=root->right->data;
 return (root->data==sum && iscSum(root->left) && iscSum(root->right));
}

int isBalanced(node *root){
 if(root==NULL)
    return 0;
 int lh=isBalanced(root->left);
 if(lh==-1) return -1;
 int rh=isBalanced(root->right);
 if(rh==-1) return -1;
 if(abs(lh-rh)>1) return -1;
  else
    return max(lh,rh)+1;
}

int maxWidth(node *root){
 if(root==NULL)
    return 0;
 queue<node *>q;
 q.push(root);
 int res=0;
 while(q.empty()==false){
    int count=q.size();
    res=max(res,count);
    for(int i=0;i<count;i++){
        node *curr=q.front();
        q.pop();
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
 }
 return res;
}

//convert a Binary Tree to Doubly Linked List

node *pre=NULL;
node *btToDLL(node *root){
 if(root==NULL) return root;
 node *head=btToDLL(root->left);
 if(pre==NULL) {
    head=root;
 }
 else{
    root->left=pre;
    pre->right=root;
 }
    pre=root;
    btToDLL(root->right);
    return head;
}

//construct binary tree from inorder and preorder
int preindex=0;
node *cTree(int in[],int pre[],int is,int ie){
 if(is>ie) return NULL;
 node *root=new node(pre[preindex++]);
 int index;
 for(int i=is;i<=ie;i++){
    if(root->data==in[i])
        index=i;
 }
 root->left=cTree(in,pre,is,index-1);
 root->right=cTree(in ,pre,index+1,ie);
 return root;
}

void printSpiral(node *root){
 if(root==NULL) return;
 queue<node*>q;
 stack<int>s;
 bool revers=false;
 q.push(root);
 while(q.empty()==false){
    int count=q.size();
    for(int i=0;i<count;i++){
       node *curr=q.front();
       q.pop();
       if(revers==true) {s.push(curr->data);}
       else{
        cout<<curr->data<<" ";
       }
       if(curr->left!=NULL) q.push(curr->left);
       if(curr->right!=NULL) q.push(curr->right);
    }
    if(revers==true){
        while(s.empty()==false)
           {
            cout<<s.top()<<" ";
            s.pop();
            }
    }
    revers=!revers;
    cout<<"\n";
    break;
 }
}
class diam{
public:
int res;
diam(int r){
res=r;
}
int diameter(node *root){
if(root==NULL)
    return 0;
int lh=diameter(root->left);
int rh=diameter(root->right);
res = max(res,lh+rh+1);
return 1+max(lh,rh);
}
void print(){
 cout<<res;
}
};
int main(){
node *root=new node(10);
root->left=new node(20);
root->right=new node(30);
root->left->left=new node(30);
inorder(root);
cout<<"\n"<<height(root);
cout<<"\n";
printKdist(root,2);
cout<<"\n";
printLevel(root);
cout<<"\n";
printLevelOrderLine(root);
cout<<"\n";
cout<<getSize(root);
cout<<"\n";
cout<<getMax(root);
cout<<"\n";
printleftView(root);
cout<<"\n";
printLeftIterative(root);
cout<<"\n";
cout<<iscSum(root);
cout<<"\n";
cout<<isBalanced(root);
cout<<"\n";
cout<<maxWidth(root);
cout<<"\n";
cout<<btToDLL(root)->data;
int in[]={20,10,30};
int pre[]={10,20,30};
int is=0,ie=2;
cout<<"\n";
//cout<<cTree(in,pre,is,ie)->data;
cout<<"Spiral";
//printSpiral(root);
diam d(0);
d.diameter(root);
d.print();
}
