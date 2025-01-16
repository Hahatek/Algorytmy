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
    
    starT someone = NULL;
    someone = addNewNode(&someone, 60);
    addNewNode(&someone, 10);
    addNewNode(&someone, 50);
    addNewNode(&someone, 20);
    addNewNode(&someone, 25);
    addNewNode(&someone, 30);
    addNewNode(&someone, 40);
   
    starT lol = NULL;
    lol = addNewNode(&lol, 20);
    addNewNode(&lol, 10);
    addNewNode(&lol, 50);
    addNewNode(&lol, 60);
    addNewNode(&lol, 25);
    addNewNode(&lol, 30);

    printf("Porownjemy dwa rowne drzewa: \n");
    porownaj(root, someone);
    
    printf("Porownjemy dwa nierowne drzewa: \n");
    porownaj(lol, someone);
    
    return 0;
}