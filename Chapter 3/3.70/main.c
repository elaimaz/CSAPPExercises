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
