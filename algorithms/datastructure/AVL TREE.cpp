/*
#include <iostream>
#include <stdio.h>
using namespace std;
 
int max(int a,int b){
	return a>b?a:b;
}
 
class AVLTree{
public:
	struct node{
		int val;
		int h;
		int sum;
		bool left_son;
		node* left;
		node* right;
		node* parent;
	};
	node* AVL;
	AVLTree(){
		AVL=NULL;
	}
	
	void update_height(node* temp){
		while(temp!=NULL){
			temp->h=max(h(temp->left),h(temp->right))+1;
			temp=temp->parent;
		}
	}
	int h(node* temp){
		if(temp==NULL)return -1;
		else return temp->h;
	}
	
	void r_rotate(node* temp){
		node *parent=temp->parent,*right=temp->right;
		if(parent!=NULL)
		if(temp->left_son){
			parent->left=right;
		} else {
			parent->right=right;
		}
		right->parent=parent;
		temp->right=right->left;
		if(right->left!=NULL){
			right->left->parent=temp;
			right->left->left_son=false;
		}
		right->left=temp;
		temp->parent=right;
		right->left_son=temp->left_son;
		temp->left_son=true;
		temp->h=max(h(temp->left),h(temp->right))+1;
		temp->sum=((temp->left!=NULL)?temp->left->sum:0)+((temp->right!=NULL)?temp->right->sum:0)+1;
		right->h=max(h(right->left),h(right->right))+1;
		right->sum=((right->left!=NULL)?right->left->sum:0)+((right->right!=NULL)?right->right->sum:0)+1;
		if(parent!=NULL){
			parent->h=max(h(parent->left),h(parent->right))+1;
			parent->sum=((parent->left!=NULL)?parent->left->sum:0)+((parent->right!=NULL)?parent->right->sum:0)+1;
		}
	}
	void l_rotate(node* temp){
		node *parent=temp->parent,*left=temp->left;
		if(parent!=NULL)
		if(temp->left_son){
			parent->left=left;
		} else {
			parent->right=left;
		}
		temp->left=left->right;
		left->parent=parent;
		if(left->right!=NULL){
			left->right->parent=temp;
			left->right->left_son=true;
		}
		left->right=temp;
		temp->parent=left;
		left->left_son=temp->left_son;
		temp->left_son=false;
		temp->h=max(h(temp->left),h(temp->right))+1;
		temp->sum=((temp->left!=NULL)?temp->left->sum:0)+((temp->right!=NULL)?temp->right->sum:0)+1;
		left->h=max(h(left->left),h(left->right))+1;
		left->sum=((left->left!=NULL)?left->left->sum:0)+((left->right!=NULL)?left->right->sum:0)+1;
		if(parent!=NULL){
			parent->h=max(h(parent->left),h(parent->right))+1;
			parent->sum=((parent->left!=NULL)?parent->left->sum:0)+((parent->right!=NULL)?parent->right->sum:0)+1;
		}
	}
	void balance(node* temp){
		while(temp!=NULL){
			node *left=temp->left,*right=temp->right;
			if(h(left)-h(right)>1){
				if(h(left->right)>h(left->left)){
					r_rotate(left);
				}
				l_rotate(temp);
			} else if(h(right)-h(left)>1){
				if(h(right->left)>h(right->right)){
					l_rotate(right);
				}
				r_rotate(temp);
			}
			temp=temp->parent;
		}
	}
	void insert(int value){
		if(AVL==NULL){
			AVL=new node;
			AVL->val=value;
			AVL->h=0;
			AVL->sum=1;
			AVL->left_son=false;
			AVL->parent=NULL;
			AVL->left=NULL;
			AVL->right=NULL;
			return;
		}
		node* temp=AVL;
		while(true){
			temp->sum++;
			if(temp->val>=value){
				if(temp->left==NULL){
					temp->left=new node;
					temp->left->h=0;
					temp->left->left=NULL;
					temp->left->right=NULL;
					temp->left->parent=temp;
					temp->left->sum=1;
					temp->left->val=value;
					temp->left->left_son=true;
					update_height(temp);
					balance(temp);
					break;
				} else {
					temp=temp->left;
				}
			} else if(temp->val<=value){
				if(temp->right==NULL){
					temp->right=new node;
					temp->right->h=0;
					temp->right->left=NULL;
					temp->right->right=NULL;
					temp->right->sum=1;
					temp->right->left_son=false;
					temp->right->parent=temp;
					temp->right->val=value;
					update_height(temp);
					balance(temp);
					break;
				} else {
					temp=temp->right;
				}
			}
		}
		while(AVL->parent!=NULL){
			AVL=AVL->parent;
		}
	}

*/
	
	void del(node* temp){
		node* temp2;
		if(temp->left==NULL && temp->right==NULL){
			if(temp->parent==NULL){
			delete AVL;
				AVL=NULL;
				return;
			}
			if(temp->left_son){
				temp2=temp->parent;
				delete temp2->left;
				temp2->left=NULL;
			} else {
				temp2=temp->parent;
				delete temp2->right;
				temp2->right=NULL;
			}
			update_height(temp2);
			temp=temp2;
			while(temp2!=NULL){
				temp2->sum--;
				temp2=temp2->parent;
			}
			balance(temp);
		} else if(temp->left==NULL || temp->right==NULL){
			if(temp->left==NULL){
				temp->val=temp->right->val;
				delete temp->right;
				temp->right=NULL;
			} else {
				temp->val=temp->left->val;
				delete temp->left;
				temp->left=NULL;
			}
			update_height(temp);
			temp2=temp;
			while(temp!=NULL){
				temp->sum--;
				temp=temp->parent;
			}
			balance(temp2);
		} else {
			node* temp2;
			temp2=temp->right;
			while(temp2->left!=NULL){
				temp2=temp2->left;
			}
			temp->val=temp2->val;
			del(temp2);
		}
	}
	void kth_delete(int ind){
		node* temp=AVL;
		int i=0;
		while(true){
			if(i+(temp->left!=NULL?temp->left->sum:0)+1==ind){
				del(temp);
				break;
			} else if(i+(temp->left!=NULL?temp->left->sum:0)+1>ind){
				temp=temp->left;
			} else {
				i+=(temp->left!=NULL?temp->left->sum:0)+1;
				temp=temp->right;
			}
		}
		if(AVL!=NULL)
		while(AVL->parent!=NULL){
			AVL=AVL->parent;
		}
	}
	bool lookup(int value){
		node* temp=AVL;
		while(temp!=NULL){
			if(temp->val<value){
				temp=temp->right;
			} else if(temp->val>value){
				temp=temp->left;
			} else {
				return true;
			}
		}
		return false;
	}
	int highest_index_under(int value){
		int ret=0;
		node* temp=AVL;
		while(temp!=NULL){
			if(temp->val<=value){
				ret+=(temp->left!=NULL?temp->left->sum:0)+1;
				temp=temp->right;
			} else {
				temp=temp->left;
			}
		}
		return ret;
	}
	int lowest_index_above(int value){
		int ret=0;
		node* temp=AVL;
		while(temp!=NULL){
			if(temp->val>=value){
				ret+=(temp->left!=NULL?temp->right->sum:0)+1;
				temp=temp->left;
			} else {
				temp=temp->right;
			}
		}
		return AVL->sum-ret+1;
	}
	int kth_num(int ind){
		node* temp=AVL;
		int i=0;
		while(true){
			if(i+(temp->left!=NULL?temp->left->sum:0)+1==ind){
				return temp->val;
			} else if(i+(temp->left!=NULL?temp->left->sum:0)+1>ind){
				temp=temp->left;
			} else {
				i+=(temp->left!=NULL?temp->left->sum:0)+1;
				temp=temp->right;
			}
		}
	}
	int num(){
		if(AVL!=NULL)
		return AVL->sum;
		return 0;
	}
};
char c;
int n,t;
AVLTree tree;
int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf(" %c",&c);
		scanf("%d",&n);
		if(c=='I'){
			if(!tree.lookup(n))
			tree.insert(n);
		} else if(c=='C'){
			printf("%d\n",tree.highest_index_under(n-1));
		} else if(c=='D'){
			if(tree.lookup(n))
				tree.kth_delete(tree.highest_index_under(n));
		} else {
			if(tree.num()<n){
				printf("invalid\n");
			} else {
				printf("%d\n",tree.kth_num(n));
			}
		}
	}
}