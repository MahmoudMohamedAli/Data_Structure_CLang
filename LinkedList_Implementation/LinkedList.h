#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

typedef struct List_s List_t;

List_t *reverse(List_t *list);
List_t *addElement(List_t *list, int data);
List_t *removeData(List_t *list, int data);
void display(List_t *list);
List_t *makelist();

#endif