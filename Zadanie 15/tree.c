#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

starT createNode(int value){
    tree* new_node = malloc(sizeof(tree));
    new_node->key = value;
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->parent = NULL;
    return new_node;
}

starT addNewNode(starT* T, int value) {
    if (*T == NULL) {
        *T = createNode(value);
        return *T;
    }

    if ((*T)->key < value) {
        starT node_right = addNewNode(&((*T)->right), value);
        if (node_right != NULL) {
            node_right->parent = *T;
        }
    } else if ((*T)->key > value) {
        starT node_left = addNewNode(&((*T)->left), value);
        if (node_left != NULL) {
            node_left->parent = *T;
        }
    }

    return *T;
}

starT searchNode(starT T, int value) {
    if (T == NULL || value == T->key) {
        return T;
    }
    if (value < T->key) {
        return searchNode(T->left, value);
    }
    else {
        return searchNode(T->right, value);
    }
}

void deleteNode(starT* T, int value) {
    if (*T == NULL) {
        printf("Tree is empty\n");
        return;
    }

    starT node_to_delete = searchNode(*T, value);
    if (node_to_delete == NULL) {
        printf("Node not found\n");
        return;
    }

    if (node_to_delete->left == NULL && node_to_delete->right == NULL) {
        if (*T == node_to_delete) {
            *T = NULL; // jezeli to korzen
        }
        free(node_to_delete);
        return;
    }

    if (node_to_delete->right == NULL) {
        if (*T == node_to_delete) {
            *T = node_to_delete->left; // jezeli to korzen
        }
        else {
            *node_to_delete = *(node_to_delete->left);
        }
        free(node_to_delete->left);
        return;
    }

    if (node_to_delete->left == NULL) {
        if (*T == node_to_delete) {
            *T = node_to_delete->right; // jezeli to korzen
        } else {
            *node_to_delete = *(node_to_delete->right);
        }
        free(node_to_delete->right);
        return;
    }

    if (node_to_delete->left != NULL && node_to_delete->right != NULL) {
     int successor_key = minnodes(node_to_delete->right);
        node_to_delete->key = successor_key;
        deleteNode(&(node_to_delete->right), successor_key);
    }
}

int maxnodes(starT T) {
    if(T!=NULL)
    {
        while(T->right!=NULL)
        {
            T=T->right;
        }
    }
    return T->key;
}

int minnodes(starT T)
{
    if(T!=NULL)
    {
        while(T->left!=NULL)
        {
            T=T->left;
        }
    }
    return T->key;
}

int poprzednik(starT T, int value) {
    if (T == NULL) {
        return 0;
    }
    while (T != NULL) {
        if (value == T->key) {
            if (T->left != NULL) {
                return maxnodes(T->left);
            }
            while (T->parent != NULL && T == T->parent->left) {
                T = T->parent;
            }
            if (T->parent != NULL) {
                return T->parent->key;
            } else {
                return 0;
            }
        }
        if (value > T->key) {
            T = T->right;
        } else {
            T = T->left;
        }
    }
    return 0;
}

int nastepnik(starT T, int value) {
    if (T == NULL) {
        return 0;
    }
    while (T != NULL) {
        if (value == T->key) {
            if (T->right != NULL) {
                return minnodes(T->right);
            }
            while (T->parent != NULL && T == T->parent->right) {
                T = T->parent;
            }
            if (T->parent != NULL) {
                return T->parent->key;

            } else {
                return 0;
            }
        }
        if (value > T->key) {
            T = T->right;
        } else {
            T = T->left;
        }
    }
    return 0;
}

void printTree(starT T, int level, char direction) {
    if (T == NULL) return;

    for(int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%c---%d\n", direction, T->key);

    printTree(T->left, level + 1, 'L');
    printTree(T->right, level + 1, 'R');
}

void saveTreeToFile(starT T, FILE* file) {
    if (T == NULL) {
        fprintf(file, "NULL\n");
        return;
    }

    fprintf(file, "%d\n", T->key);
    saveTreeToFile(T->left, file);
    saveTreeToFile(T->right, file);
}

void saveTree(starT T, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing\n");
        return;
    }

    saveTreeToFile(T, file);
    fclose(file);
}

starT loadTreeFromFile(FILE* file, starT parent) {
    char buffer[32];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        return NULL;
    }

    // Remove newline
    buffer[strcspn(buffer, "\n")] = 0;

    if (strcmp(buffer, "NULL") == 0) {
        return NULL;
    }

    starT node = createNode(atoi(buffer));
    node->parent = parent;
    node->left = loadTreeFromFile(file, node);
    node->right = loadTreeFromFile(file, node);

    return node;
}

starT loadTree(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading\n");
        return NULL;
    }

    starT root = loadTreeFromFile(file, NULL);
    fclose(file);
    return root;
}