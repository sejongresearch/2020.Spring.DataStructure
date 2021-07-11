#pragma warning(disable:4996)
#include <stdio.h>
#include<stdlib.h>

typedef struct poly {
    int coef, exp; 
    struct poly* next;
}poly;

void appendTerm(poly *k, int c, int e) {
    poly *t = (poly*)malloc(sizeof(poly));
    t->coef = c;
    t->exp = e;
    t->next = k->next;
    k->next = t;
}

void deletion(poly* k) {
    poly *t, *temp;
    t = k;
    temp = t;
    while (t != NULL) {
        temp = temp->next;
        free(t);
        t = temp;
    }
}

poly* addPoly(poly *x, poly *y) {
    poly *result, *i, *j, *k;
    int sum;

    result = (poly*)malloc(sizeof(poly));
    result->next = NULL;

    i = x->next;
    j = y->next;
    k = result;
    while (i != NULL && j != NULL) {
        if (i->exp < j->exp) {
            appendTerm(k, i->coef, i->exp);
            i = i->next;
        }
        else {
            if (i->exp > j->exp) {
                appendTerm(k, j->coef, j->exp);
                j = j->next;
            }
            else {
                sum = i->coef + j->coef;
                if (sum != 0) {
                    appendTerm(k, sum, i->exp);
                }
                i = i->next;
                j = j->next;

            }
        }
    }

    while (i != NULL) {
        appendTerm(k, i->coef, i->exp);
        i = i->next;
    }
    while (j != NULL) {
        appendTerm(k, j->coef, j->exp);
        j = j->next;
    }

    return result;
}

int main() {
    poly *x=NULL, *y=NULL, *result, *j, *k;
    x = (poly*)malloc(sizeof(poly));
    y = (poly*)malloc(sizeof(poly));
    x->next = NULL;
    y->next = NULL;

    int i, n,c,e;

    scanf("%d", &n);
    for (i = 0;i < n;i++) {
        scanf("%d %d", &c, &e);
        appendTerm(x, c, e);
    }

    scanf("%d", &n);
    for (i = 0;i < n;i++) {
        scanf("%d %d", &c, &e);
        appendTerm(y, c, e);
    }
    result = addPoly(x, y);
    k = result->next;
    while (k != NULL) {
        printf("%d %d\n", k->coef, k->exp);
        k = k->next;
    }

    k = result->next;
    deletion(k);
    k = x->next;
    deletion(k);
    k = y->next;
    deletion(k);
}

// 19011845 
