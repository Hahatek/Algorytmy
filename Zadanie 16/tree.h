#ifndef TREE_H
#define TREE_H

typedef struct tree {
    int key;
    struct tree* right;
    struct tree* left;
    struct tree* parent;
} tree;
typedef tree* starT;

starT createNode(int value);
starT addNewNode(starT* T, int value);
starT nastepnik(starT T, int value);
starT minnodes(tree* T);

int porownaj(starT tree1, starT tree2);
void printTree(starT root, int level, char direction);

#endif //TREE_H
