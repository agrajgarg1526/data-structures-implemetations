#include<iostream>
#include<queue>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* insertatBST(node*root, int d)
{
	if (root == NULL)
		return new node(d);

	if (d <= root->data)
	{
		root->left = insertatBST(root->left, d);
	}
	else
	{
		root->right = insertatBST(root->right, d);
	}
	return root;

}
node*buildtree()
{
	int d;
	cin >> d;

	node*root = NULL;
	while (d != -1)
	{
		root = insertatBST(root, d);
		cin >> d;
	}
	return root;
}

void printIn(node*root) {
	if (root == NULL) {
		return;
	}
	printIn(root->left);
	cout << root->data << " ";
	printIn(root->right);
}

void bfs(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* t = q.front();
		if(t==NULL)
		{
			cout<<endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
		cout<<t->data<<" ";
		q.pop();

		if(t->left){
			q.push(t->left);
		}
		if(t->right){
			q.push(t->right);
		}
	}
	}
	return ;
}

void printPre(node*root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	printPre(root->left);
	printPre(root->right);
}

bool search(node*root,int d)
{
	if(root==NULL)
		return false;

	if(root->data==d)
		return true;

	if(d<root->data)
		return search(root->left,d);
	else
		return search(root->right,d);
}

node* deleteInTree(node*root,int key){
	if(root==NULL){
		return NULL;
	}
	if(root->data==key){
		//ise delete krna
		//1. no child
		if(root->left==NULL and root->right==NULL){
			delete root;
			return NULL;
		}
		else if(root->left==NULL and root->right!=NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL and root->left!=NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}
		else{
			//find the inorder successor
			node*temp = root->right;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			root->data  = temp->data;
			root->right = deleteInTree(root->right,root->data);
			return root;
		}
	}
	else if(root->data<key){
		//right mei se delete hoga 
		root->right = deleteInTree(root->right,key);
	}
	else{
		root->left = deleteInTree(root->left,key);
	}
	return root;
}

bool isBST(node*root,int minV,int maxV){
	if(root==NULL){
		return true;
	}

	//Rec Case
	if(root->data >=minV and root->data<=maxV and isBST(root->left,minV,root->data) and 
		isBST(root->right,root->data,maxV)){
		return true;
	}
	return false;
}

class LinkedList{
public:
	node*head;
	node*tail;
};

LinkedList convertTree2LL(node*root){
	LinkedList l;
	if(root==NULL){
		l.head = l.tail =NULL;
		return l;
	}
	//Leaf Node
	if(root->left==NULL and root->right==NULL){
		l.head = l.tail = root;
		return l;
	}
	//Left Child
	if(root->left!=NULL and root->right==NULL){
		LinkedList leftLL = convertTree2LL(root->left);
		leftLL.tail->right = root;
		l.head = leftLL.head;
		l.tail = root;
		return l;
	}
	else if(root->left==NULL and root->right!=NULL){
		LinkedList rightLL = convertTree2LL(root->right);
		//leftLL.tail->right = root;
		root->right = rightLL.head;
		l.head = root;
		l.tail = rightLL.tail;
		return l;
	}
	else{
		LinkedList leftLL = convertTree2LL(root->left);
		LinkedList rightLL = convertTree2LL(root->right);
		leftLL.tail->right = root;
		root->right = rightLL.head;
		l.head = leftLL.head;
		l.tail = rightLL.tail;
		return l;
	}
}


int main()
{
	node*root = NULL;
	root = buildtree();
	printIn(root);
	deleteInTree(root,5);
	cout<<endl;
	printIn(root);
}