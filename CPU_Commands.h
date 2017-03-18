#include <stdio.h>
#include <commands.h>
#include <stack.h>
#define ERROR -1

int CPU_check(CPU * cpu)
{
	if (cpu == NULL)
		return 6;

	if (cpu -> stack == NULL)
		return 7;

	return 0;	

}

void CPU_damp(CPU * cpu)
{
	FILE * Raport;
	int i = 0;
	Raport = fopen("Raport.txt","a");

	fprintf(Raport, "Проблема в CPU\n";

	fprintf(Raport, "Номер ошибки: %d\n", CPU_check(cpu));

	fprintf(Raport, "Указатель на cpu: %p\n",  cpu);
	fprintf(Raport, "Указатель на data: %p\n",  cpu -> stack -> data);

	fprintf(Raport, "Мой stack:\n")

	if ( cpu -> stack -> data)
		fprintf(Raport,"В top лежит: %lf\n", cpu -> stack -> data  [stack -> top]);

	fprintf(Raport, "Указатель на data: %p\n",  cpu -> stack -> data);
	fprintf(Raport,"Top по счету: %d\n", cpu -> stack -> top);
	fprintf(Raport,"Размер стэка: %d\n", cpu -> stack -> size);
	fprintf(Raport, "Stack:");

	if (cpu -> stack -> data)
		for (i = 0; i <= cpu - > stack -> size; i++)
			fprintf(Raport, "%lf\n", cpu -> stack -> data [i]);

	fprintf(Raport, "Я закончился");

	fclose(Raport);
}

void CPU_death(CPU * cpu)
{
	CPU_damp(cpu);

	exit(1);
}

void CPU_assert(cpu)
{
	if (CPU_check(cpu) != 0)
		CPU_death(cpu);
}

void CPU_delete(CPU * cpu)
{
	DeleteStack(cpu -> stack);
	free(cpu);
	cpu = NULL;
}

void CPU_in(CPU * cpu, int reg, T value)
{
	CPU_assert(cpu)	

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

	CPU_assert(cpu)
}

T CPU_out(CPU * cpu, int reg)
{
	CPU_assert(cpu)

	if ( reg == ax )
		return cpu -> ax;
	if ( reg == bx )
		return cpu -> bx;
	if ( reg == cx )
		return cpu -> cx;
	if ( reg == dx )
		return cpu -> dx;
	if ( reg == ex )
		return cpu -> ex;
	if ( reg == fx )
		return cpu -> fx;
	if ( reg == gx )
		return cpu -> gx;
	if ( reg == hx )
		return cpu -> hx;
	return ERROR;
}

void CPU_add(Stack * stack)
{
	CPU_assert(cpu)

	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a + b);

	CPU_assert(cpu)
}

void CPU_mul(Stack * stack)
{
	CPU_assert(cpu)

	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a * b);

	CPU_assert(cpu)
}

void CPU_sub(Stack * stack)
{
	CPU_assert(cpu)

	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a - b);

	CPU_assert(cpu)
}

void CPU_div(Stack * stack)
{
	CPU_assert(cpu)

	int a = stack_pop(stack);
	int b = stack_pop(stack);
	stack_push(stack, a / b);

	CPU_assert(cpu)
}

void CPU_sqrt(Stack * stack)
{
	CPU_assert(cpu)

	int a = stack_pop(stack);
	stack_push(stack, sqrt(a));

	CPU_assert(cpu)
}

void CPU_push(Stack * stack, T value)
{
	CPU_assert(cpu)

	stack_push(stack, value);

	CPU_assert(cpu)
}

void CPU_popr(int reg, CPU * cpu)
{
	CPU_assert(cpu)		

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

	CPU_assert(cpu)
}

void CPU_pushr(int reg, CPU * cpu)
{
	CPU_assert(cpu)
	
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

	CPU_assert(cpu) 
}

void CPU_end(CPU * cpu)
{
	CPU_assert(cpu)

	CPU_delete(cpu);
}
	



















