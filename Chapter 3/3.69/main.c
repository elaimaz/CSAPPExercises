typedef struct ELE *tree_ptr;

struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
};

long trace(tree_ptr tp);

int main() {
    return 0;
}

long trace(tree_ptr tp) {
    while (tp->right != 0) {
        tp = tp->right;
    }
}