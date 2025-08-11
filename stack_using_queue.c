#include <stdio.h>
#define MAX 100
int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;
void enqueue1(int val) {
    if (rear1 == MAX - 1) {
        printf("Queue1 is full\n");
        return;
    }
    if (front1 == -1) front1 = 0;
    q1[++rear1] = val;
}

int dequeue1() {
    if (front1 == -1) {
        printf("Queue1 is empty\n");
        return -1;
    }
    int val = q1[front1++];
    if (front1 > rear1) front1 = rear1 = -1;
    return val;
}

void enqueue2(int val) {
    if (rear2 == MAX - 1) {
        printf("Queue2 is full\n");
        return;
    }
    if (front2 == -1) front2 = 0;
    q2[++rear2] = val;
}

int dequeue2() {
    if (front2 == -1) {
        printf("Queue2 is empty\n");
        return -1;
    }
    int val = q2[front2++];
    if (front2 > rear2) front2 = rear2 = -1;
    return val;
}

// Push into stack using 2 queues
void push(int val) {
    // Step 1: Put new element in q2
    enqueue2(val);

    // Step 2: Move all elements from q1 to q2
    while (front1 != -1) {
        enqueue2(dequeue1());
    }

    // Step 3: Move all elements from q2 back to q1
    while (front2 != -1) {
        enqueue1(dequeue2());
    }
}

// Pop from stack
int pop() {
    if (front1 == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return dequeue1();
}

// Display stack
void display() {
    if (front1 == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = front1; i <= rear1; i++) {
        printf("%d ", q1[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    display();  // 30 20 10

    printf("Popped: %d\n", pop());
    display();  // 20 10

    push(40);
    display();  // 40 20 10

    return 0;
}
