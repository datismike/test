#include <stdio.h>
#include "stack.h"

int main(void)
{
	Stack *snake = newStack();

	snake->push(snake, (int)5);
	//snake->push(snake, (int)2);
	//snake->push(snake, (int)3);
	snake->pop(snake);
	printf("%d\n", snake->getTail(snake));
	printf("%d\n", snake->getHead(snake));

	freeStack(snake);
	getchar();
	return 0;
}