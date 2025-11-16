// initStack(capacity) : 스택 초기화, push(stack, void* data) : 데이터 주소 넣기
// void* pop(stack) : 주소값 반환, isEmpty(), isFull() 보조함수

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 10

typedef enum {
    TYPE_INT = 0,
    TYPE_DOUBLE = 1,
    TYPE_STRING = 2,
    TYPE_UNKNOWN = 3
} DataType;

typedef struct {
    void *data;
    DataType type;
    bool owns_memory;
} StackElement;

typedef struct {
    StackElement *data;
    int top;
    int capacity;
} Stack;

Stack* initStack(int capacity)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));

    s->data = (void*)malloc(sizeof(StackElement) * capacity);
    s->top = -1;
    s->capacity = capacity;

    return s;
}

void printStackElement(StackElement *s)
{
    switch (s->type) {
        case 0:
            printf("data: %d\n", *(int*)s->data);
            break;
        case 1:
            printf("data: %f\n", *(double*)s->data);
            break;
        case 2:
            printf("data: %s\n", *(char**)s->data);
            break;
        default:
            printf("data type error!\n");
    }
}

int isFull(Stack *s)
{
    return s->top == s->capacity - 1;
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int push(Stack *s, void *data, DataType type, bool owns_memory)
{
    if (isFull(s)) { return 1; }

    s->top += 1;
    s->data[s->top].data = data;
    s->data[s->top].type = type;
    s->data[s->top].owns_memory = owns_memory;
    return 0;
}

StackElement * pop(Stack *s)
{
    if (isEmpty(s)) { printf("It's empty Stack.\n"); return NULL; }
    return &s->data[s->top--];
}

StackElement * peek(Stack* s)
{
    if (isEmpty(s)) { printf("It's empty Stack.\n"); return NULL; }
    return &s->data[s->top];
}

// 개발 디버그용 스택 확인
void printAllStack(Stack* s)
{
    printf("=== Print All Stack ===\n");
    for (int i = 0; i <= s->top; i++) {
        printf("%d. ", i);
        printStackElement(&(s->data[i]));
    }
    printf("=== until here ===\n");
}

void destroyStack(Stack *s)
{
    for (int i = 0; i < MAXSIZE; i++) {
        if (s->data[i].owns_memory) {
            free(s->data[i].data);
        }
    }
    s->top = -1;
}

int main()
{
    Stack *s = initStack(MAXSIZE);

    int v = 10;
    push(s, &v, TYPE_INT, false);
    push(s, "Hello", TYPE_STRING, false);
    char *str = malloc(10);
    strcpy(str, "world!");
    push(s, str, TYPE_STRING, true);

    printAllStack(s);

    printStackElement(pop(s));

    destroyStack(s);
    free(s->data);
    free(s);
}
