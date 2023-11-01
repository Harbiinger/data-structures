#include <stdio.h>
#include <stdlib.h>

/********************** 
* Binary Search Tree  *
**********************/

#define TRUE 1 
#define FALSE 0

struct Bst {
    int data;
    struct Bst* lson;
    struct Bst* rson;
    unsigned int empty;
    unsigned int lsonEmpty;
    unsigned int rsonEmpty;
};

struct Bst* create_node() {
    struct Bst* node = (struct Bst*)malloc(sizeof(struct Bst));
    node->empty = TRUE;
    node->lsonEmpty = TRUE;
    node->rsonEmpty = TRUE;
    return node;
}

void insert(struct Bst* t, int data) {
    if (t->empty == TRUE) {
        t->data = data;
        t->empty = FALSE;
    }
    else {
        if (data <= t->data) {
            if (t->lsonEmpty == TRUE) {
                t->lson = create_node();
                t->lsonEmpty = FALSE;
            }
            insert(t->lson, data);
        }
        else {
            if (t->rsonEmpty == TRUE) {
                t->rson = create_node();
                t->rsonEmpty = FALSE;
            }
            insert(t->rson, data);
        }
    }
}

unsigned int find(struct Bst* t, int data) {
    if (t->empty == FALSE) {
        if (t->data == data) {
            return TRUE;
        }
        if (t->data > data && t->lsonEmpty == FALSE) {
            return find(t->lson, data);
        }
        if (t->data < data && t->rsonEmpty == FALSE) {
            return find(t->rson, data);
        }
    }
    return FALSE;
}

int find_min(struct Bst* t) {
    if (t->lsonEmpty == TRUE) {
        return t->data;
    }
    return find_min(t->lson);
}

void delete(struct Bst* t, int data) {
    if (t->empty == FALSE) {
        if (t->data == data) {
            if (t->lsonEmpty == TRUE && t->rsonEmpty == TRUE) {
                t->empty = TRUE;
            }
            else if (t->lsonEmpty == TRUE && t->rsonEmpty == FALSE) {
                t = t->rson;
            }
            else if (t->lsonEmpty == FALSE && t->rsonEmpty == TRUE) {
                t = t->lson;
            }
            else {
                int rsonMin = find_min(t->rson);
                t->data = rsonMin;
                delete(t->rson, rsonMin);
            }
        }
        else if (t->data > data && t->lsonEmpty == FALSE) {
            delete(t->lson, data);
        }
        else if (t->data < data && t->rsonEmpty == FALSE) {
            delete(t->rson, data);
        }
    }
}

void print_tree(struct Bst* t, int level) {
    if (t->empty == TRUE)
            return;
    for (int i = 0; i < level; i++)
            printf(i == level - 1 ? "|-" : "  ");
    printf("%d\n", t->data);
    if (t->lsonEmpty == FALSE) {
        print_tree(t->lson, level + 1);
    }
    if (t->rsonEmpty == FALSE) {
        print_tree(t->rson, level + 1);
    }
}

int main() {
    struct Bst* t = create_node();
    insert(t, 7);
    insert(t, 6);
    insert(t, 9);
    insert(t, 8);
    print_tree(t, 0);
    delete(t, 7);
    print_tree(t, 0);
    return EXIT_SUCCESS;
}
