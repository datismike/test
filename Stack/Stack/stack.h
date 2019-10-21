#pragma once
#include <Windows.h>

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} Node;
typedef Node *PNode;

typedef struct Stack
{
	void (*push)(struct Stack *, int);
	void (*pop)(struct Stack *);
	int (*getTail)(struct Stack *);
	int (*getHead)(struct Stack *);
	//int (**getArr)(struct Stack *);
	BOOL (*isEmpty)(struct Stack *);

	void *privateData;
} Stack;

Stack *newStack();
void freeStack(Stack *);