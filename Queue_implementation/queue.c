
#include "queue.h"
#include <memory.h>

typedef struct queue_s
{
    unsigned int size;
    unsigned int allocated_size;
    Node_t *front;
    Node_t *tail;
} queue_t;

Node_t *CreateNode(void *data, size_t allocatesize)
{
    Node_t *insert_new_Node = malloc(sizeof(Node_t));
    if (insert_new_Node == NULL)
        return NULL;

    insert_new_Node->data = malloc(allocatesize);
    if (insert_new_Node->data == NULL)
    {
        free(insert_new_Node);
        return NULL;
    }
    insert_new_Node->next = NULL;
    memcpy(insert_new_Node->data, data, allocatesize);
    return insert_new_Node;
}

queue_t *Createqueue(size_t allocate_size)
{

    queue_t *newqueue = malloc(sizeof(queue_t));
    if (newqueue == NULL)
        return NULL;
    newqueue->allocated_size = allocate_size;
    newqueue->size = 0;
    newqueue->front = newqueue->tail = NULL;
    return newqueue;
}

queue_t *Enqueue(queue_t *queue, void *data)
{
    Node_t *newNode = CreateNode(data, queue->allocated_size);
    if (newNode == NULL)
        return NULL;

    if (queue->size == 0)
    {
        queue->front = queue->tail = newNode;
        // handled in node creation
        //  newNode->next = NULL;
    }
    else // reshape the connection
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
    return queue;
}

queue_t *Dequeue(queue_t *queue, void *data)
{
    // remove first element
    Node_t *removed_node = queue->front;
    queue->front = removed_node->next; // drop the node from connection nodes

    memcpy(data, removed_node->data, queue->allocated_size);
    free(removed_node->data);
    free(removed_node);
    queue->size--;
    return queue;
}

queue_t *clearQueue(queue_t *queue)
{
    if (queue == NULL)
        return NULL;
    while (!queue_isEmpty(queue))
    {
        Node_t *tmp = queue->front;
        queue->front = tmp->next;
        free(tmp->data);
        free(tmp);
        queue->size--;
    }
}

int queue_isEmpty(queue_t *queue)
{
    return queue->size > 0 ? 0 : 1;
}
size_t get_allocatedSize(queue_t *queue)
{
    return queue->allocated_size;
}

size_t get_Size(queue_t *queue)
{
    return queue->size;
}

queue_t *queue_copy(queue_t *queue)
{
    if (queue == NULL)
        return NULL;
    queue_t *spawned_queue = Createqueue(queue->allocated_size);
    Node_t *iter = queue->front;

    while (iter != NULL)
    {
        Enqueue(spawned_queue, iter->data);
        iter = iter->next;
    }
    return spawned_queue;
}

int main()
{
    queue_t *var = Createqueue(sizeof(int));
    int x = 10;
    char str1[3] = "HI";
    Enqueue(var, str1);
    for (int i = 0; i < 100; i++)
    {
        Enqueue(var, &i);
    }
    char str2[3];
    Dequeue(var, str2);
    printf("the string = %s\n", str2);
    printf("the size = %zu\n", get_Size(var));
    int xt = get_Size(var);
    printf("the allocated size = %zu\n", get_allocatedSize(var));
    for (int i = 0; i < get_Size(var) + i; i++)
    {
        printf("the value = %d\n", i);
        Dequeue(var, &x);
        printf("the value = %d\n", x);
    }

    queue_t *strqueue = Createqueue(20 * sizeof(char));
    char v[20] = "hello world";
    char v2[20] = "Hi man!";
    Enqueue(strqueue, v);
    Enqueue(strqueue, v2);
    char str[20];
    Dequeue(strqueue, str);
    printf("the string = %s\n", str);
    Dequeue(strqueue, str);
    printf("the string = %s\n", str);

    return 0;
}
