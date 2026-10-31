#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data[101];
    int front;
    int rear;
} Queue;

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    initQueue(&obj->q1);
    initQueue(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(&obj->q2, x);

    while (!isQueueEmpty(&obj->q1)) {
        enqueue(&obj->q2, dequeue(&obj->q1));
    }

    Queue temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;

    initQueue(&obj->q2);
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q1);
}

int myStackTop(MyStack* obj) {
    return obj->q1.data[obj->q1.front];
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(&obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj);
}