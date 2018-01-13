/*

struct N
{
    N *left, *right;
    long balance, height, num, size;
    bool leftHeavy()
    {
        return balance < 0 ? true : false;
    }
    bool rightHeavy()
    {
        return balance > 0 ? true : false;
    }
    bool unbalancedLeft()
    {
        return balance < -1 ? true : false;
    }
    bool unbalancedRight()
    {
        return balance > 1 ? true : false;
    }
    N(long newNum)
    {
        num = newNum;
        balance = height = 0;
        size = 1;
        left = right = NULL;
    }
};

class T
{
private:
    N *root;
    long atPos(N *t, long p);
    long count(N *t, long n);
    N* erase(N *t, long num);
    N* insert(N *t, long num);
    long leftMost(N *t);
    N *rotateL(N *t);
    N* rotateR(N *t);
    N *rotateLR(N *t);
    N* rotateRL(N *t);
public:
    T();
    long atPos(long p);
    long count(long n);
    void erase(long num);
    void insert(long num);
} Tree;

long T::atPos(N *t, long p)
{
    long l = t->left == NULL ? 0 : t->left->size;
    long curr = l + 1;
    long r = t->right == NULL ? 0 : t->right->size;

    if(p < curr)
        return atPos(t->left, p);
    if(p == curr)
        return t->num;

    return atPos(t->right, p - curr);
}

long T::atPos(long p)
{
    if(root == NULL || p > root->size)
        return INVALID;

    return atPos(root, p);
}

long T::count(N *t, long n)
{
    if(t == NULL)
        return 0;

    if(n <= t->num)
        return count(t->left, n);

    long ls = t->left == NULL ? 0 : t->left->size;
    return ls + 1 + count(t->right, n);
}

long T::count(long n)
{
    return count(root, n);
}

N* T::rotateL(N *t)
{
    N *b = t->right;
    t->right = b->left;
    b->left = t;

    long oldBalT = t->balance;
    long oldBalB = b->balance;

    t->balance = oldBalT - 1 - max(oldBalB, (long) 0);
    b->balance = oldBalB - 1 + min(t->balance, (long) 0);

    long lh = t->left == NULL ? 0 : t->left->height;
    long ls = t->left == NULL ? 0 : t->left->size;
    long rh = t->right == NULL ? 0 : t->right->height;
    long rs = t->right == NULL ? 0 : t->right->size;
    t->height = max(lh, rh) + 1;
    t->size = ls + rs + 1;

    lh = b->left == NULL ? 0 : b->left->height;
    ls = b->left == NULL ? 0 : b->left->size;
    rh = b->right == NULL ? 0 : b->right->height;
    rs = b->right == NULL ? 0 : b->right->size;
    b->height = max(lh, rh) + 1;
    b->size = ls + rs + 1;

    return b;
}

N* T::rotateR(N *t)
{
    N *b = t->left;
    t->left = b->right;
    b->right = t;

    long oldBalT = t->balance;
    long oldBalB = b->balance;

    t->balance = oldBalT + 1 - min(oldBalB, (long) 0);
    b->balance = oldBalB + 1 + max(t->balance, (long) 0);

    long lh = t->left == NULL ? 0 : t->left->height;
    long ls = t->left == NULL ? 0 : t->left->size;
    long rh = t->right == NULL ? 0 : t->right->height;
    long rs = t->right == NULL ? 0 : t->right->size;
    t->height = max(lh, rh) + 1;
    t->size = ls + rs + 1;

    lh = b->left == NULL ? 0 : b->left->height;
    ls = b->left == NULL ? 0 : b->left->size;
    rh = b->right == NULL ? 0 : b->right->height;
    rs = b->right == NULL ? 0 : b->right->size;
    b->height = max(lh, rh) + 1;
    b->size = ls + rs + 1;

    return b;
}


*/

N* T::rotateRL(N *t)
{
    t->left = rotateL(t->left);
    long rh = t->right == NULL ? 0 : t->right->height;
    long rs = t->right == NULL ? 0 : t->right->size;
    t->height = max(t->left->height, rh) + 1;
    t->size = t->left->size + rs + 1;
    t->balance = rh &mdash; t->left->height;
    return rotateR(t);
    return t;
}

N* T::rotateLR(N *t)
{
    t->right = rotateR(t->right);
    long lh = t->left == NULL ? 0 : t->left->height;
    long ls = t->left == NULL ? 0 : t->left->size;
    t->height = max(lh, t->right->height) + 1;
    t->balance = t->right->height &mdash; lh;
    t->size = ls + t->right->size + 1;
    return rotateL(t);
    return t;
}

N* T::insert(N *t, long num)
{
    if(num < t->num)
    {
        if(t->left == NULL)
            t->left = new N(num);

        t->left = insert(t->left, num);
    }
    if(num > t->num)
    {
        if(t->right == NULL)
            t->right = new N(num);

        t->right = insert(t->right, num);
    }

    long lh = t->left == NULL ? 0 : t->left->height;
    long ls = t->left == NULL ? 0 : t->left->size;
    long rh = t->right == NULL ? 0 : t->right->height;
    long rs = t->right == NULL ? 0 : t->right->size;
    t->height = max(lh, rh) + 1;
    t->size = ls + rs + 1;
    t->balance = rh - lh;

    if(t->unbalancedLeft())
    {
        if(t->left->rightHeavy())
            return rotateRL(t);
        else
            return rotateR(t);
    }
    if(t->unbalancedRight())
    {
        if(t->right->leftHeavy())
            return rotateLR(t);
        else
        return rotateL(t);
    }

    return t;
}

long T::leftMost(N *t)
{
    if(t->left == NULL)
        return t->num;

    return leftMost(t->left);
}

N* T::erase(N *t, long num)
{
    if(num < t->num)
    {
        if(t->left == NULL)
            return t;

        t->left = erase(t->left, num);
    }
    if(num > t->num)
    {
        if(t->right == NULL)
            return t;

        t->right = erase(t->right, num);
    }
    if(num == t->num)
    {
        int children = 0;
        children += t->left != NULL ? 1 : 0;
        children += t->right != NULL ? 1 : 0;

        if(children == 0)
            return NULL;
        if(children == 1)
            return t->right != NULL ? t->right : t->left;
        if(children == 2)
        {
            long suc = leftMost(t->right);
            t->right = erase(t->right, suc);
            t->num = suc;
        }
    }

    long lh = t->left == NULL ? 0 : t->left->height;
    long ls = t->left == NULL ? 0 : t->left->size;
    long rh = t->right == NULL ? 0 : t->right->height;
    long rs = t->right == NULL ? 0 : t->right->size;
    t->height = max(lh, rh) + 1;
    t->size = ls + rs + 1;
    t->balance = rh - lh;

    if(t->unbalancedLeft())
    {
        if(t->left->rightHeavy())
            return rotateRL(t);
        else
            return rotateR(t);
    }
    if(t->unbalancedRight())
    {
        if(t->right->leftHeavy())
            return rotateLR(t);
        else
            return rotateL(t);
    }

    return t;
}

void T::erase(long num)
{
    if(root == NULL)
        return;

    root = erase(root, num);
}

void T::insert(long num)
{
    if(root == NULL)
    {
        root = new N(num);
        return;
    }

    root = insert(root, num);
}

T::T()
{
    root = NULL;
}