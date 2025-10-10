#include "LinkedList.h"
#include <stdlib.h>

typedef struct node_s
{
    int data;
    struct node_s *next;
} Node_t;

typedef struct List_s
{
    Node_t *head;
} List_t;

static Node_t *CreateNode(int data);
static Node_t *CreateNode(int data)
{
    Node_t *newNode = (Node_t *)malloc(sizeof(Node_t));
    if (newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

List_t *makelist()
{
    List_t *list = malloc(sizeof(List_t));
    if (list == NULL)
        return NULL;
    list->head = NULL;
    return list;
}

void display(List_t *list)
{
    Node_t *curr = list->head;
    while (curr != NULL)
    {
        printf("dataElemnt:%d\n", curr->data);
        curr = curr->next;
    }
}

List_t *addElement(List_t *list, int data)
{
    Node_t *tmpNode = CreateNode(data);
    if (tmpNode == NULL)
        return NULL;
    if (list->head == NULL)
    {
        list->head = tmpNode;
    }
    else
    {
        Node_t *curr = list->head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = tmpNode;
    }
    return list;
}

List_t *removeData(List_t *list, int data)
{
    Node_t *Curr = list->head;
    Node_t *previous = Curr;
    while (Curr != NULL)
    {
        if (Curr->data == data)
        {
            // check if it the first element
            if (Curr == list->head)
                list->head = Curr->next;
            previous->next = Curr->next; // shortcut
            free(Curr);
        }
        previous = Curr;
        Curr = Curr->next;
    }
    return list;
}

List_t *reverse(List_t *list)
{
    Node_t *curr = list->head;
    Node_t *pre = NULL;
    Node_t *tmp = curr;
    while (curr != NULL)
    {
        tmp = curr;
        curr = curr->next;
        tmp->next = pre;
        pre = tmp;
        //    curr->next = pre;
    }
    if (pre != NULL)
        list->head = pre;

    return list;
}

int main()
{
    List_t *list = makelist();
    for (size_t i = 0; i < 50; i++)
    {
        addElement(list, i);
    }
    display(list);
}
