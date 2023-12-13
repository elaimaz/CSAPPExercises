typedef struct ELE *tree_ptr;

struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
};

long traverse(tree_ptr tp);

int main() {
    return 0;
}

long traverse(tree_ptr tp)
{
    long value = -9223372036854775808;
    if (tp == 0)
    {
        return value;
    }
    

    value = traverse(tp->left) > value ? traverse(tp->left) : value;
    return value = traverse(tp->right) > value ? traverse(tp->right) : value;
  
}