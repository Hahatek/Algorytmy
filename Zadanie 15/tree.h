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
void deleteNode(starT* T, int value);
starT searchNode(starT T, int value);
int poprzednik(starT T, int value);
int nastepnik(starT T, int value);
int maxnodes(tree* T);
int minnodes(tree* T);

void printTree(starT root, int level, char direction);

void saveTree(starT T, const char* filename);
starT loadTreeFromFile(FILE* file, starT parent);
void saveTree(starT T, const char* filename);
starT loadTree(const char* filename);
#endif //TREE_H
