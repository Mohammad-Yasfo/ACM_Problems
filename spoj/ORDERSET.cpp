#include <iostream>
using namespace std;
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
node *erase(node *t, int key)
{
	if (t == NULL)return NULL;
	if (key > t->key)
		t->r = erase(t->r, key);
	else if (key < t->key)
		t->l = erase(t->l, key);
	else if (key == t->key)
	{
		if (t->l == NULL && t->r == NULL)
			return NULL;
		if (t->r == NULL)
		{
			t->key = t->l->key;
			t->l = NULL;
			fix(t);
			return t;
		}
		if (t->l == NULL)
		{
			t->key = t->r->key;
			t->r = NULL;
			fix(t);
			return t;
		}
		node *tmp = t->l;
		while (tmp->r != NULL)
			tmp = tmp->r;
		t->key = tmp->key;
		t->l = erase(t->l, tmp->key);
	}
	fix(t);
	t = balance(t);
	return t;
}
void erase(int key)
{
	root = erase(root, key);
}
int kth(node*t, int k)
{
	if (sum(t->l) + 1 == k)
		return t->key;
	else if (sum(t->l) + 1 > k)
		return kth(t->l, k);
	else
		return kth(t->r, k - sum(t->l) - 1);
}
int kth(int key)
{
	return kth(root, key);
}
int count(node *t, int key)
{
	if (t == NULL)return 0;
	if (key <= t->key)
		return count(t->l, key);
	else
		return count(t->r, key) + sum(t->l) + 1;
}
int count(int key)
{
	return count(root, key);
}
int main()
{
	int n;
	int tmp;
	char c;
	scanf("%d", &n);
	//cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf(" %c %d", &c, &tmp);
		if (c == 'I')
			insert(tmp);
		else if (c == 'K'){
			if (sum(root) < tmp)
				printf("invalid\n");
			else
				printf("%d\n", kth(tmp));
		}
		else if (c == 'C')
			printf("%d\n", count(tmp));
		else if (c == 'D')
			erase(tmp);
	}
	return 0;
}