#include <iostream>
#include <stdio.h>
using namespace std;
 
struct node{
	node *left, *right;
	int key,val;
	int sum,h;
	node(int k,int v){
		key=k;
		val=v;
		left=NULL;
		right=NULL;
		sum=1;
		h=0;
	}
};
 
node *root=NULL;
int sum(node* t){ return ((t==NULL)?0:t->sum); };
void _fix(node* t){
	t->h=max((t->left==NULL)?-1:t->left->h,(t->right==NULL)?-1:t->right->h)+1;
	t->sum=sum(t->left)+sum(t->right)+1;
}
int bal(node* t){
	return ((t->left==NULL)?-1:t->left->h)-((t->right==NULL)?-1:t->right->h);
}
node* rotateR(node* t){
	node* left=t->left;
	t->left=left->right;
	left->right=t;
	_fix(t);
	_fix(left);
	return left;
}
node* rotateL(node* t){
	node* right=t->right;
	t->right=right->left;
	right->left=t;
	_fix(t);
	_fix(right);
	return right;
}
node* balance(node* t){
	if(bal(t)>1){
		if(bal(t->left)<0){
			t->left=rotateL(t->left);
		}
		t=rotateR(t);
	} else if(bal(t)<-1){
		if(bal(t->right)>0){
			t->right=rotateR(t->right);
		}
		t=rotateL(t);
	}
	return t;
}
node* _insert(node* t,int key,int val){
	if(key<t->key){
		if(t->left==NULL){
			t->left=new node(key,val);
		} else {
			t->left=_insert(t->left,key,val);
		}
	} else if(key>t->key){
		if(t->right==NULL){
			t->right=new node(key,val);
		} else {
			t->right=_insert(t->right,key,val);
		}
	} else {
		return t;
	}
	_fix(t);
	t=balance(t);
	return t;
}
void insert(int key,int val){
	if(root==NULL){
		root=new node(key,val);
		return;
	}
	root=_insert(root,key,val);
}
node* _erase(node* t,int key){
	if(t==NULL) return NULL;
	if(key<t->key){
		t->left=_erase(t->left,key);
	}
	if(key>t->key){
		t->right=_erase(t->right,key);
	}
	if(key==t->key){
		if(t->left==NULL && t->right==NULL){
			return NULL;
		}
		if(t->left==NULL){
			t->val=t->right->val;
			t->key=t->right->key;
			t->right=NULL;
			_fix(t);
			return t;
		}
		if(t->right==NULL){
			t->val=t->left->val;
			t->key=t->left->key;
			t->left=NULL;
			_fix(t);
			return t;
		}
		node* tmp=t->left;
		while(tmp->right!=NULL){
			tmp=tmp->right;
		}
		t->val=tmp->val;
		t->key=tmp->key;
		t->left=_erase(t->left,tmp->key);
	}
	_fix(t);
	t=balance(t);
	return t;
}
void erase(int key){
	root=_erase(root,key);
}
int _kth(node* t,int k){
	if(sum(t->left)+1==k){
		return t->val;
	} else if(sum(t->left)+1>k){
		return _kth(t->left,k);
	} else {
		return _kth(t->right,k-sum(t->left)-1);
	}
}
int kth(int k){
	return _kth(root,k);
}
int _cnt(node *t,int key){
	if(t==NULL) return 0;
	if(key<=t->key){
		return _cnt(t->left,key);
	} else {
		return _cnt(t->right,key)+sum(t->left)+1;
	}
}
int count(int key){
	return _cnt(root,key);
}
int n,tmp;
char c;
//int arr[1400004],kk=0;
int main(){
	//cin.sync_with_stdio(false);
	//cout.sync_with_stdio(false);
	//cin>>n;
	scanf("%d",&n);
	//srand(342);
	while(n--){
		//cin>>c>>tmp;
		scanf(" %c %d",&c,&tmp);
		//c='I';
		//tmp=rand()*rand();
		//arr[kk++]=tmp;
		if(c=='I'){
			insert(tmp,tmp);
		}
		if(c=='C'){
			printf("%d\n",count(tmp));
			//cout<<count(tmp)<<endl;
		}
		if(c=='K'){
			if(((root==NULL)?0:root->sum)<tmp){
				//cout<<"invalid"<<endl;
				printf("invalid\n");
			} else {
				//cout<<kth(tmp)<<endl;
				printf("%d\n",kth(tmp));
			}
		}
		if(c=='D'){
			erase(tmp);
		}
	}
}