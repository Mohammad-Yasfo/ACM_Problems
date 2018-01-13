#include <iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
struct node
{
	int key;
	int h, sum;
	node*l, *r;
	node(int k)
	{
		key = k;
		sum = 1;
		h = 0;
		l = NULL;
		r = NULL;
	}
};
node *root = NULL;
int h(node *t){ return (t == NULL ? -1 : t->h); }
int sum(node*t){ return (t == NULL ? 0 : t->sum); }
int bal(node *t)
{
	return h(t->l) - h(t->r);
}
void fix(node *t)
{
	t->h = max(h(t->l), h(t->r)) + 1;
	t->sum = sum(t->l) + sum(t->r) + 1;
}
node *rotateR(node *t)
{
	node *l = t->l;
	t->l = l->r;
	l->r = t;
	fix(t);
	fix(l);
	return l;
}
node *rotateL(node*t)
{
	node *r = t->r;
	t->r = r->l;
	r->l = t;
	fix(t);
	fix(r);
	return r;
}
node *balance(node*t)
{
	if (bal(t) < -1)
	{
		if (bal(t->r)>0)
			t->r = rotateR(t->r);
		t = rotateL(t);
	}
	else if (bal(t) > 1)
	{
		if (bal(t->l) < 0)
			t->l = rotateL(t->l);
		t = rotateR(t);
	}
	return t;
}
node *insert(node *t, int key)
{
	if (key>t->key)
	{
		if (t->r == NULL)
			t->r = new node(key);
		else
			t->r = insert(t->r, key);
	}
	else if (key < t->key)
	{
		if (t->l == NULL)
			t->l = new node(key);
		else
			t->l = insert(t->l, key);
	}
	else
		return t;
	fix(t);
	t = balance(t);
	return t;
}
void insert(int key)
{
	if (root == NULL)
		root = new node(key);
	else
		root = insert(root, key);
}
int count(node *t, int key)
{
	if (t == NULL)return 0;
	if (key >= t->key)
		return count(t->r, key);
	else
		return count(t->l, key) + sum(t->r) + 1;
}
int count(int key)
{
	return count(root, key);
}
int main()
{
	int n, t;
	int tmp;
	long long sum = 0;
	
	scanf("%d", &t);
	for (int q = 0; q < t; ++q){
		root = NULL;
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &tmp);
			sum += count(tmp);
			insert(tmp);
		}
		printf("%lld\n", sum);
	}
	return 0;
}