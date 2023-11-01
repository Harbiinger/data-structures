#include <stdio.h>
#include <stdlib.h>

/*********** 
* AVL Tree *
***********/

#define TRUE 1 
#define FALSE 0

struct Avl {
    int data;
    struct Avl* lson;
    struct Avl* rson;
    unsigned int empty;
    unsigned int lsonEmpty;
    unsigned int rsonEmpty;
    unsigned int height;
    int balance;
};

struct Avl* create_node() {
    struct Avl* node = (struct Avl*)malloc(sizeof(struct Avl));
    node->empty = TRUE;
    node->lsonEmpty = TRUE;
    node->rsonEmpty = TRUE;
    node->height = 1;
    node->balance = 0;
    return node;
}
 
void height(struct Avl* t) {
    if (t->lsonEmpty == FALSE && t->rsonEmpty == TRUE) {
        t->height = t->lson->height + 1;
    }
    else if (t->lsonEmpty == TRUE && t->rsonEmpty == FALSE) {
        t->height = t->rson->height + 1;
    }
    else if (t->lsonEmpty == FALSE && t->rsonEmpty == FALSE) {
        if (t->lson->height >= t->lson->height) {
            t->height = t->lson->height + 1;
        }
        else {
            t->height = t->rson->height + 1;
        }
    }
    else {
        t->height = 1;
    }
}

void equilibrate(struct Avl* t) {

}

void insert(struct Avl* t, int data) {
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
        height(t);
    }
}

unsigned int find(struct Avl* t, int data) {
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

int main() {
    struct Avl* t = create_node();
    insert(t, 10);
    printf("t_height: %d\n", t->height);
    insert(t, 11);
    printf("t_height: %d\n", t->height);
    insert(t, 9);
    printf("t_height: %d\n", t->height);
    insert(t, 8);
    printf("t_height: %d\n", t->height);
    return EXIT_SUCCESS;
}
