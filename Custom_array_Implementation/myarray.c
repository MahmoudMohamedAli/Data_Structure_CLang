#include "array.h"

array_t *array_init()
{
    return array_init_with_size(ARRAY_DEFAULT_SIZE);
}
array_t *array_init_with_size(size_t size)
{
    array_t *self = malloc(sizeof(array_t));
    self->buffer_size = size;
    self->length = 0;
    self->refs = 1;
    self->buffer = malloc(size * sizeof(void *));
    return self;
}

void array_push(array_t *self, void *data)
{

    if (self->buffer_size <= self->length)
        resize_array(self, self->buffer_size * 2);
    self->buffer[self->length] = data;
    self->length++; // increment length
}

void resize_array(array_t *self, size_t newsize)
{
    self->buffer = realloc(self->buffer, newsize);
    self->buffer_size = newsize;
}

void array_unshift(array_t *self, void *data)
{
    array_insert(self, 0, data);
}

void array_insert(array_t *self, size_t index, void *data)
{
    if (index < self->length)
    {
        array_push(self, NULL);
        for (int x = self->length - 1; x > index; x--)
        {
            self->buffer[x] = self->buffer[x - 1];
        }
        self->buffer[index] = data;
        return;
    }
    if (index > self->buffer_size)
    {

        while (index > self->buffer_size)
        {
            self->buffer_size *= 2;
        }
        resize_array(self, self->buffer_size);
    }
    self->buffer[index] = data;
    self->length = index + 1;
}

void *array_get(array_t *self, size_t index)
{
    if (index > self->length)
        return NULL;
    return self->buffer[index];
}

void array_put(array_t *self, size_t index, void *data)
{

    if (self->length <= index)
        return array_insert(self, index, data);
    self->buffer[index] = data;
}

ssize_t array_indexof(array_t *self, void *data)
{

    for (size_t x = 0; x < self->length; x++)
    {
        if (self->buffer[x] == data)
        {
            return x;
        }
    }
    return -1;
}

int array_contains(array_t *self, void *data)
{
    return array_indexof(self, data) > -1;
}

void *array_remove(array_t *self, size_t index)
{
    if (index >= self->length)
        return NULL;
    void *removed_item = self->buffer[index];
    for (int i = self->length - 1; i > index; i--)
    {
        self->buffer[i - 1] = self->buffer[i];
    }
    // remove element
    self->length--;
    return removed_item;
}
void *array_remove_item(array_t *self, void *data)
{
    ssize_t index = array_indexof(self, data);
    return index == -1 ? NULL : array_remove(self, index);
}
void *array_shift(array_t *self)
{
    return array_remove(self, 0);
}
void *array_pop(array_t *self)
{
    return self->length ? self->buffer[--self->length] : NULL;
}

void *array_incref(array_t *self)
{
    self->refs++;
    return self;
}

void array_decref(array_t *self)
{

    if (--self->refs)
        return;
    free(self->buffer);
    free(self);
}