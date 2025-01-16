#include<stdio.h>
#include <stdlib.h>
#include "tree.h"

starT createNode(int value) {
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

starT minnodes(starT T){
	if(T!=NULL)
	{
		while(T->left!=NULL)
		{
			T=T->left;
		}
	}
	return T;
}

starT nastepnik(starT T, int value) {
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
				return T->parent;

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
	return T;
}

int porownaj(starT tree1, starT tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        printf("Trees are equal\n");
        return 1;
    }

    if (tree1 == NULL || tree2 == NULL) {
        printf("Trees are not equal\n");
        return 0;
    }

    starT node_tree1 = minnodes(tree1);
    starT node_tree2 = minnodes(tree2);

    while (node_tree1 != NULL && node_tree2 != NULL) {
        if (node_tree1->key != node_tree2->key) {
            printf("Trees are not equal\n");
            return 0;
        }
        node_tree1 = nastepnik(tree1, node_tree1->key);
        node_tree2 = nastepnik(tree2, node_tree2->key);
    }

    if (node_tree1 != NULL || node_tree2 != NULL) {
        printf("Trees are not equal\n");
        return 0;
    }

    printf("Trees are equal\n");
    return 1;
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
