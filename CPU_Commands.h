#ifndef CPU_commands_H_INCLUDED 
#define CPU_commands_H_INCLUDED

#include <stdio.h>
#include <math.h>

#include <commands.h>
#include <stack.h>

#define ERROR -1
#define NotEquall -2
#define Equall -3
#define NotAbove -4
#define NotAboveOrEquall -5
#define NotBelow -6
#define NotBelowOrEquall -7

typedef struct CPU_s
{
		Stack * stack;
		T ax, bx, cx, dx, ex, fx, gx, hx;
				
}CPU;


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

	fprintf(Raport, "Проблема в CPU\n");

	fprintf(Raport, "Номер ошибки: %d\n", CPU_check(cpu));

	fprintf(Raport, "Указатель на cpu: %p\n",  cpu);
	fprintf(Raport, "Указатель на data: %p\n",  cpu -> stack -> data);

	fprintf(Raport, "Мой stack:\n");

	if ( cpu -> stack -> data)
		fprintf(Raport,"В top лежит: %lf\n", cpu -> stack -> data  [cpu -> stack -> top]);

	fprintf(Raport, "Указатель на data: %p\n",  cpu -> stack -> data);
	fprintf(Raport,"Top по счету: %d\n", cpu -> stack -> top);
	fprintf(Raport,"Размер стэка: %d\n", cpu -> stack -> size);
	fprintf(Raport, "Stack:");

	if (cpu -> stack -> data)
		for (i = 0; i <= (cpu -> stack -> size); i++)
			fprintf(Raport, "%lf\n", cpu -> stack -> data [i]);

	fprintf(Raport, "Я закончился");

	fclose(Raport);
}

void CPU_death(CPU * cpu)
{
	CPU_damp(cpu);

	exit(1);
}

void CPU_assert(CPU * cpu)
{
	if (CPU_check(cpu) != 0)
		CPU_death(cpu);
}

CPU* CPU_create()
{
	CPU *out = calloc(1, sizeof(CPU));
	
	out -> stack = CreateStack();

	out -> ax = 0;
	out -> bx = 0;
	out -> cx = 0;
	out -> dx = 0;
	out -> ex = 0;
	out -> fx = 0;
	out -> gx = 0;
	out -> hx = 0;
	
	CPU_assert(out);

	return out;
} 

void CPU_delete(CPU * cpu)
{
	DeleteStack(cpu -> stack);
	free(cpu);
	cpu = NULL;
}

void CPU_in(CPU * cpu, int reg)
{
	T value = 0;

	CPU_assert(cpu);	
	
	printf("Введите значение регистра %d\n", reg);
	scanf("%lf\n", &value);	
	
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
	{
		printf("Я же сказал, невлезай. Теперь пинай на себя, все косяки на твоей совести");
		cpu -> hx = value;
	}

	CPU_assert(cpu);
}

T CPU_out(CPU * cpu, int reg)
{
	CPU_assert(cpu);

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
	{
		printf("Не, ну распечатать ты его можешь, только сам в него не лезь.");
		return cpu -> hx;
	}

	return ERROR;
}

void CPU_add(CPU * cpu)
{
	CPU_assert(cpu);

	int a = stack_pop(cpu -> stack);
	int b = stack_pop(cpu -> stack);
	stack_push(cpu -> stack, a + b);

	CPU_assert(cpu);
}

void CPU_mul(CPU * cpu)
{
	CPU_assert(cpu);

	int a = stack_pop(cpu -> stack);
	int b = stack_pop(cpu -> stack);
	stack_push(cpu -> stack, a * b);

	CPU_assert(cpu);
}

void CPU_sub(CPU * cpu)
{
	CPU_assert(cpu);

	int a = stack_pop(cpu -> stack);
	int b = stack_pop(cpu -> stack);
	stack_push(cpu -> stack, a - b);

	CPU_assert(cpu);
}

void CPU_div(CPU * cpu)
{
	CPU_assert(cpu);

	int a = stack_pop(cpu -> stack);
	int b = stack_pop(cpu -> stack);
	stack_push(cpu -> stack, a / b);

	CPU_assert(cpu);
}

/*void CPU_sqrt(CPU * cpu)
{
	CPU_assert(cpu);

	T a = stack_pop(cpu -> stack);
	stack_push(cpu -> stack, sqrt(a));

	CPU_assert(cpu);
}*/

void CPU_push(CPU * cpu, T value)
{
	CPU_assert(cpu);

	stack_push(cpu -> stack, value);

	CPU_assert(cpu);
}

void CPU_popr(int reg, CPU * cpu)
{
	CPU_assert(cpu);		

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
	{
		printf("Я же сказал, невлезай. Теперь пинай на себя, все косяки на твоей совести");
		cpu -> hx = stack_pop(cpu -> stack);
	}

	CPU_assert(cpu);
}

void CPU_pushr(int reg, CPU * cpu)
{
	CPU_assert(cpu);
	
	if ( reg == ax )
		CPU_push(cpu, cpu -> ax); 
	if ( reg == bx )
		CPU_push(cpu, cpu -> bx); 
	if ( reg == cx )
		CPU_push(cpu, cpu -> cx); 
	if ( reg == dx )
		CPU_push(cpu, cpu -> dx); 
	if ( reg == ex )
		CPU_push(cpu, cpu -> ex); 
	if ( reg == fx )
		CPU_push(cpu, cpu -> fx); 
	if ( reg == gx )
		CPU_push(cpu, cpu -> gx); 
	if ( reg == hx )
	{
		printf("Я же сказал, невлезай. Теперь пинай на себя, все косяки на твоей совести");
		CPU_push(cpu, cpu -> hx);
	}

	CPU_assert(cpu); 
}

void CPU_end(CPU * cpu)
{
	CPU_assert(cpu);
	
	printf("Successfully\n");

	CPU_delete(cpu);
}

int CPU_jmp(CPU * cpu, int Destination)
{
	return Destination;
}

int CPU_je(CPU * cpu, int Destination)
{
	T StackPop1 = stack_pop(cpu -> stack);
	T StackPop2 = stack_pop(cpu -> stack);

	if ( StackPop1 == StackPop2 )
	{
		CPU_push(cpu, StackPop1);
		CPU_push(cpu, StackPop2);
		return ( CPU_jmp(cpu, Destination) );
	}
	
	else
		return NotEquall;
}

int CPU_jne(CPU * cpu, int Destination)
{
	T StackPop1 = stack_pop(cpu -> stack);
	T StackPop2 = stack_pop(cpu -> stack);

	if ( StackPop1 != StackPop2 )
	{
		CPU_push(cpu, StackPop1);
		CPU_push(cpu, StackPop2);
		return ( CPU_jmp(cpu, Destination) );
	}
	
	else
		return Equall;
}


int CPU_ja(CPU * cpu, int Destination)
{
	T StackPop1 = stack_pop(cpu -> stack);
	T StackPop2 = stack_pop(cpu -> stack);

	if ( StackPop1 > StackPop2 )
	{
		CPU_push(cpu, StackPop1);
		CPU_push(cpu, StackPop2);
		return ( CPU_jmp(cpu, Destination) );
	}
	
	else
		return NotAbove;
}

int CPU_jae(CPU * cpu, int Destination)
{
	T StackPop1 = stack_pop(cpu -> stack);
	T StackPop2 = stack_pop(cpu -> stack);

	if ( StackPop1 >= StackPop2 )
	{
		CPU_push(cpu, StackPop1);
		CPU_push(cpu, StackPop2);
		return ( CPU_jmp(cpu, Destination) );
	}
	
	else
		return NotAboveOrEquall;
}

int CPU_jb(CPU * cpu, int Destination)
{
	T StackPop1 = stack_pop(cpu -> stack);
	T StackPop2 = stack_pop(cpu -> stack);

	if ( StackPop1 < StackPop2 )
	{
		CPU_push(cpu, StackPop1);
		CPU_push(cpu, StackPop2);
		return ( CPU_jmp(cpu, Destination) );
	}
	
	else
		return NotBelow;
}

int CPU_jbe(CPU * cpu, int Destination)
{
	T StackPop1 = stack_pop(cpu -> stack);
	T StackPop2 = stack_pop(cpu -> stack);

	if ( StackPop1 <= StackPop2 )
	{
		CPU_push(cpu, StackPop1);
		CPU_push(cpu, StackPop2);
		return ( CPU_jmp(cpu, Destination) );
	}
	
	else
		return NotBelowOrEquall;
}

int CPU_call(CPU * cpu, int Destination, int StartPointer)
{
	cpu -> hx = (T) StartPointer;
	return Destination;
}

int CPU_ret(CPU * cpu)
{
	T a = cpu -> hx;
	cpu -> hx = -1;
	
	return a;
}
	





#endif
	



















