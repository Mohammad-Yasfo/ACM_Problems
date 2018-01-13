#include <iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
class node
{
public:
	int key;
	int h;
	int sum;
	node*left;
	node*right;
	node(int key_)
	{
		key = key_;
		left = NULL;
		right = NULL;
		sum = 1;
		h = 0;
	}
};
node*root;
int h(node*t){ return t == NULL ? -1 : t->h; }
int sum(node*t){ return t == NULL ? 0 : t->sum; }
void fix(node*t){
	t->h = max(h(t->left), h(t->right)) + 1;
	t->sum = sum(t->left) + sum(t->right) + 1;
}
int bal(node*t)
{
	return h(t->left) - h(t->right);
}
node*rotateR(node*t)
{
	node* left = t->left;
	t->left = left->right;
	left->right = t;
	fix(t);
	fix(left);
	return left;
}
node*rotateL(node*t)
{
	node*right = t->right;
	t->right = right->left;
	right->left = t;
	fix(t);
	fix(right);
	return right;
}
node*balance(node*t)
{
	if (bal(t) > 1)
	{
		if (bal(t->left) < 0)
		{
			t->left = rotateL(t->left);
		}
		t = rotateR(t);
	}
	else if (bal(t) < -1)
	{
		if (bal(t->right)>0)
		{
			t->right = rotateR(t->right);
		}
		t = rotateL(t);
	}
	return t;
}
node*insert(node *t, int key)
{
	if (t == NULL)
	{
		t = new node(key);
		return t;
	}
	if (t->key > key)
		t->left = insert(t->left, key);
	else
		t->right = insert(t->right, key);
	fix(t);
	t = balance(t);
	return t;
}
void insert(int key)
{
	if (root == NULL)
	{
		root = new node(key);
	}
	else
		root = insert(root, key);

}
int get_kth(node*t, int k)
{
	if (sum(t->left) + 1 == k)
		return t->key;
	else if (sum(t->left) + 1 < k)
		return get_kth(t->right, k - sum(t->left) - 1);
	else
		return get_kth(t->left, k);
}
int kth(int k)
{
	return get_kth(root, k);
}
int main()
{
	int n,a,b,k,q,sum;
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		root = NULL;
		cin >> n;
		cin >> a;
		insert(a);
		sum = 1;
		q = 1;
		cout << a << " ";
		for (int x = 1; x < n; x += 2)
		{
			sum += 2;
			cin >> a >> b;
			insert(a);
			insert(b);
			cout << kth(sum / 2 + 1);
			++q;
			if (q == 10)
			{
				cout << endl;
				q = 0;
			}
			else
				cout << " ";
		}
	}

	return 0;
}