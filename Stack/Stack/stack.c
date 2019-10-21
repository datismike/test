#include "stack.h"

typedef struct PrivateStack
{
	PNode head;
	PNode tail;
} PrivateStack;

void push(Stack *pstack, int data)
{
	if (pstack->isEmpty(pstack))
	{
		PNode node = (PNode *)malloc(sizeof(PNode));
		node->data = data;
		node->next = NULL;
		node->prev = NULL;
		((PrivateStack *)pstack->privateData)->head = node;
		((PrivateStack *)pstack->privateData)->tail = node;
		return;
	}
	for (PNode node = ((PrivateStack *)pstack->privateData)->tail; node != NULL; node = node->next)
	{
		if (node->next == NULL)
		{
			PNode head = (PNode *)malloc(sizeof(PNode));
			head->data = data;
			head->next = NULL;
			head->prev = node;
			((PrivateStack *)pstack->privateData)->head = head;
			node->next = head;
			return;
		}
	}
}

void pop(Stack *pstack)
{
	if (((PrivateStack *)pstack->privateData)->head == (((PrivateStack *)pstack->privateData))->tail)
	{
		free(((PrivateStack *)pstack->privateData)->head);
		free(((PrivateStack *)pstack->privateData)->tail);
		((PrivateStack *)pstack->privateData)->head = NULL;
		((PrivateStack *)pstack->privateData)->tail = NULL;
		return;
	}
	PNode nodeToFree = ((PrivateStack *)pstack->privateData)->head;
	((PrivateStack *)pstack->privateData)->head = ((PrivateStack *)pstack->privateData)->head->prev;
	free(((PrivateStack *)pstack->privateData)->head->next);
	((PrivateStack *)pstack->privateData)->head->next = NULL;
}

int getTail(Stack *pstack)
{
	if (!pstack->isEmpty(pstack))
		return ((PrivateStack *)pstack->privateData)->tail->data;
	else
		return 0;
}

int getHead(Stack *pstack)
{
	if (!pstack->isEmpty(pstack))
		return ((PrivateStack *)pstack->privateData)->head->data;
	else
		return 0;
}

BOOL isEmpty(Stack *pstack)
{
	if (((PrivateStack *)pstack->privateData)->head == NULL)
		return TRUE;
	else
		return FALSE;
}

Stack *newStack()
{
	Stack *pstack = (Stack *)malloc(sizeof(Stack));
	pstack->privateData = (PrivateStack *)malloc(sizeof(PrivateStack));
	((PrivateStack *)pstack->privateData)->head = NULL;
	((PrivateStack *)pstack->privateData)->tail = NULL;
	pstack->push = &push;
	pstack->pop = &pop;
	pstack->getTail = &getTail;
	pstack->getHead = &getHead;
	pstack->isEmpty = &isEmpty;
}

void freeStack(Stack *pstack)
{
	free(pstack);
}