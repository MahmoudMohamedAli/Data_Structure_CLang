
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Node
    {
        void *data;
        struct Node *next;
    } Node_t;

    typedef struct queue_s queue_t;
    Node_t *CreateNode(void *data, size_t allocatesize);
    queue_t *Createqueue(size_t allocate_size);
    queue_t *Enqueue(queue_t *queue, void *data);
    queue_t *Dequeue(queue_t *queue, void *data);

    queue_t *clearQueue(queue_t *queue);
    size_t get_Size(queue_t *queue);
    size_t get_allocatedSize(queue_t *queue);
    queue_t *queue_copy(queue_t *queue);
    int queue_isEmpty(queue_t *queue);

#ifdef __cplusplus
}
#endif