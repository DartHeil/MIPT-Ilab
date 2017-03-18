#include <stdio.h>
#include <commands.h>
#include <stack.h>
#define ERROR -1

void CPU_in(CPU cpu, int reg, T value)
{
	if ( reg == ax )
		cpu -> ax = value;
	if ( reg == bx )
		cpu -> bx = value;
	if ( reg == cx )
		cpu -> cx = value;
	if ( reg == dx )
		cpu -> dx = value;
	if ( reg == ex )
		cpu -> ex = value;
	if ( reg == fx )
		cpu -> fx = value;
	if ( reg == gx )
		cpu -> gx = value;
	if ( reg == hx )
		cpu -> hx = value;
}

T CPU_out(CPU cpu, int reg)
{
	if ( reg == ax )
		return cpu -> ax
	if ( reg == bx )
		return cpu -> bx
	if ( reg == cx )
		return cpu -> cx
	if ( reg == dx )
		return cpu -> dx
	if ( reg == ex )
		return cpu -> ex
	if ( reg == fx )
		return cpu -> fx
	if ( reg == gx )
		return cpu -> gx
	if ( reg == hx )
		return cpu -> hx
	else
		return ERROR
}

void CPU_add(Stack *stack)
{
	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a + b);
}

void CPU_mul(Stack *stack)
{
	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a * b);
}

void CPU_sub(Stack *stack)
{
	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a - b);
}

void CPU_div(Stack *stack)
{
	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a / b);
}

void CPU_sqrt(Stack *stack)
{
	int a = stack_pop(stack);
	stack_push(stack, sqrt(a));
}

void CPU_push(Stack *stack, T value)
{
	stack_push(stack, value);
}

void CPU_popr(int reg, CPU cpu)
{
		

	if ( reg == ax )
		cpu -> ax = stack_pop(cpu -> stack);
	if ( reg == bx )
		cpu -> bx = stack_pop(cpu -> stack);
	if ( reg == cx )
		cpu -> cx = stack_pop(cpu -> stack);
	if ( reg == dx )
		cpu -> dx = stack_pop(cpu -> stack);
	if ( reg == ex )
		cpu -> ex = stack_pop(cpu -> stack);
	if ( reg == fx )
		cpu -> fx = stack_pop(cpu -> stack);
	if ( reg == gx )
		cpu -> gx = stack_pop(cpu -> stack);
	if ( reg == hx )
		cpu -> hx = stack_pop(cpu -> stack);
}

void CPU_pushr(int reg, CPU cpu)
{
	
	if ( reg == ax )
		CPU_push(cpu -> stack, cpu -> ax); 
	if ( reg == bx )
		CPU_push(cpu -> stack, cpu -> bx); 
	if ( reg == cx )
		CPU_push(cpu -> stack, cpu -> cx); 
	if ( reg == dx )
		CPU_push(cpu -> stack, cpu -> dx); 
	if ( reg == ex )
		CPU_push(cpu -> stack, cpu -> ex); 
	if ( reg == fx )
		CPU_push(cpu -> stack, cpu -> fx); 
	if ( reg == gx )
		CPU_push(cpu -> stack, cpu -> gx); 
	if ( reg == hx )
		CPU_push(cpu -> stack, cpu -> hx); 
}

void CPU_delete(CPU cpu)
{
	DeleteStack(cpu -> stack);
	free(cpu);
	cpu = NULL;
}

void CPU_end(CPU cpu)
{
	CPU_delete(cpu);
}
	



















