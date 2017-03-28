#include <stdio.h>
#include <math.h>

#include <assembler.h>
#include <commands.h>
#include <stack.h>
//#include <assembler.h>
#include <CPU_Commands.h>

/*typedef struct CPU_s
{
	Stack* stack;
	T ax, bx, cx, dx, ex, fx, gx, hx;
	
} CPU;*/

int CPU_Function(CPU * cpu)
{
//	FILE* CPU_code = fopen( "CPU_code.txt", "r" );
	int command = 0;
	double value = 0;
	int CommandCounter = 0;
	int CountOfCommand = 0;
	FILE* CPU_code = fopen( "CPU_code.txt", "r" );
	
/*	if((CPU_code == NULL)
	{
	printf("Cannot open file.");
	return 1;
	}
	fread(, sizeof (int), CountOfCommand, fp);
	fclose (fp);
	return 0;
	} */

	fseek(CPU_code,0,SEEK_END);
	CountOfCommand = ftell(CPU_code)/sizeof(int);
	int * Programm = calloc(CountOfCommand, sizeof(int));
	fread(Programm, sizeof(int), CountOfCommand, CPU_code);
	fclose(CPU_code);	

	while ( CommandCounter < CountOfCommand - 2 )
        {
		if ( Programm[CommandCounter] == CMD_PUSH )
		{
			++ CommandCounter;
			
			CPU_push(cpu, Programm[CommandCounter]);

			++ CommandCounter;
		}

		if ( Programm[CommandCounter] == CMD_ADD )
		{
			++ CommandCounter;
			CPU_add(cpu);
		}

		if ( Programm[CommandCounter] == CMD_DIV )
		{
			++ CommandCounter;
			CPU_div(cpu);
		}

		if ( Programm[CommandCounter] == CMD_MUL )
		{
			++ CommandCounter;
			CPU_mul(cpu);
		}

		if ( Programm[CommandCounter] ==  CMD_SUB )
		{
			++ CommandCounter;
			CPU_sub(cpu);
		}

	/*	if ( Programm[CommandCounter] ==  CMD_SQRT )
		{
			++ CommandCounter;
			CPU_sqrt(cpu);
		} */

		if ( Programm[CommandCounter] == CMD_POPR )
		{
			++ CommandCounter;

			CPU_popr(Programm[CommandCounter], cpu);

			++ CommandCounter;
		}

		if ( Programm[CommandCounter] == CMD_OUT )
		{
			++ CommandCounter;

			printf("Значение регистра %d: %lg\n", Programm[CommandCounter], CPU_out(cpu, value));

			++ CommandCounter;
		}
	
		if ( Programm[CommandCounter] == CMD_PUSHR )
		{
			++ CommandCounter;

			CPU_pushr(Programm[CommandCounter], cpu);

			++ CommandCounter;
		}

		if ( Programm[CommandCounter] == CMD_IN )
		{
			++ CommandCounter;

			CPU_in(cpu, Programm[CommandCounter]);

			++ CommandCounter;
		}

		if ( Programm[CommandCounter] ==  CMD_END )
		{
			++ CommandCounter;
			CPU_end(cpu);
		}

	/*	if( Programm[CommandCounter] == CMD_JMP )
		{
			++CommandCounter */
					



	}
	
	return 0;
}

int main()
{
	CPU * cpu = CPU_create();
	int a = 0;

	assembler();

	a = CPU_Function(cpu);

	return 0;
}

	
	


		






