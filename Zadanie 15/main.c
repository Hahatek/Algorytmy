#include <stdio.h>
#include "tree.h"
int main(void) {
     starT root = NULL;

    root = addNewNode(&root, 50);
    addNewNode(&root, 10);
    addNewNode(&root, 30);
    addNewNode(&root, 20);
    addNewNode(&root, 25);
    addNewNode(&root, 60);
    addNewNode(&root, 40);

saveTree(root, "tree.txt");
    starT newRoot = loadTree("tree.txt");
    printTree(newRoot, 0, 'R');

    return 0;
}