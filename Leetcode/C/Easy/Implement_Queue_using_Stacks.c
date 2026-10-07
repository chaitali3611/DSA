#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *stackIn;
    int *stackOut;
    int topIn;
    int topOut;
    int capacity;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));

    queue->capacity = 100;
    queue->stackIn = (int*)malloc(queue->capacity * sizeof(int));
    queue->stackOut = (int*)malloc(queue->capacity * sizeof(int));

    queue->topIn = -1;
    queue->topOut = -1;

    return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[++obj->topIn] = x;
}

/** Transfers elements from stackIn to stackOut if needed. */
void transfer(MyQueue* obj) {
    if (obj->topOut == -1) {
        while (obj->topIn >= 0) {
            obj->stackOut[++obj->topOut] =
                obj->stackIn[obj->topIn--];
        }
    }
}

/** Removes the element from the front of queue. */
int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->stackOut[obj->topOut--];
}

/** Returns the element at the front. */
int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->stackOut[obj->topOut];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return obj->topIn == -1 && obj->topOut == -1;
}

/** Frees the memory. */
void myQueueFree(MyQueue* obj) {
    free(obj->stackIn);
    free(obj->stackOut);
    free(obj);
}