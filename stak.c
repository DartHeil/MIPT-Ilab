#define StartSize 10
#define MOREGOLD 2
typedef double T;
#include <stdio.h>
#include <stdlib.h>
typedef struct Stack_s
{
	T* data;
	int size;
	int top;
} Stack;

int CheckStack(Stack * stack)
{
	if (stack == NULL)
		return 1;

	if (stack -> data == NULL)
		return 2;

	if (stack -> data [stack -> top] != 0)
		return 3;

	if (stack -> size < 0)
		return 4;
	
	if (stack -> top > stack -> size)
		return 5;

//	if (stack -> top == 0)
//		return 6;
	
	return 0;
}

void damp(Stack * stack)
{
	FILE * Raport;
	int i = 0;
	Raport = fopen("Raport.txt","wt");

	fprintf(Raport, "Номер ошибки: %d\n", CheckStack(stack));

	if ( stack -> data)
		fprintf(Raport,"В top лежит: %lf\n", stack -> data  [stack -> top]);

	fprintf(Raport, "Указатель на data: %p\n",  stack -> data);
	fprintf(Raport,"Top по счету: %d\n", stack -> top);
	fprintf(Raport,"Размер стэка: %d\n", stack -> size);
	fprintf(Raport, "Stack:");

	if (stack -> data)
		for (i = 0; i <= stack -> size; i++)
			fprintf(Raport, "%lf\n", stack -> data [i]);

	fprintf(Raport, "Я закончился");

	fclose(Raport);
}

void Death(Stack * stack)
{
	damp(stack);

	exit(1);
}

void WrongStackDeath(Stack * stack)
{
	if (CheckStack(stack) != 0)
		Death(stack);
}

void DeleteStack(Stack * stack)
{
	WrongStackDeath(stack);

	free(stack -> data);
	free(stack);
	stack = NULL;
}

Stack* CreateStack()
{
	Stack *out = calloc(1, sizeof(Stack));
	
	out->size = StartSize;
	out->data = calloc(out -> size, sizeof(T));
	
	out->top = 0;
	
	WrongStackDeath(out);

	return out;
} 

T stack_get(Stack * stack)
{
	WrongStackDeath;
	
	return stack -> data [(stack -> top) - 1];
}

void Resize(Stack *stack)
{
	int i = 0;
	T* suicider = 0;

	WrongStackDeath(stack);

	stack -> size = stack -> size * MOREGOLD;
	suicider  = realloc(stack -> data, (stack -> size) * sizeof(T));

	if (suicider != 0)
	{
		stack -> data = suicider;

		for (i = stack -> top; i <= stack -> size; i++)
			stack -> data [i] = 0;		
	}

	else
		Death(stack);

	WrongStackDeath(stack);
}

void push(Stack *stack, T value)
{
	WrongStackDeath(stack);

	if (stack -> top >= stack -> size)
		Resize(stack);

	stack -> data [stack -> top] = value;
	stack -> top ++;

	WrongStackDeath(stack);
}

T pop(Stack *stack)
{
	WrongStackDeath(stack);

	stack -> top = stack -> top - 1;
	T a = stack -> data [stack -> top];
	stack -> data [stack->top] = 0;

	WrongStackDeath(stack);

	return a;

int main()
{

	return 0;
}







	

