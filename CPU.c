#include <stdio.h>
#include <math.h>

#include <assembler.h>
#include <commands.h>
#include <stack.h>
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

	printf("RRR\n");
	
/*	if((CPU_code == NULL)
	{
	printf("Cannot open file.");
	return 1;
	}
	fread(, sizeof (int), CountOfCommand, fp);
	fclose (fp);
	return 0;
	} */

	int i = 0;
	int s = 0;
 
	while ((fscanf(CPU_code, "%d",&s)!=EOF))
	{    if(!CPU_code) break;    
	        CountOfCommand+=1;
	}
	int * Programm = (int*) calloc(CountOfCommand, sizeof(int)); 
 
	rewind(CPU_code);
	for(i = 0; i < CountOfCommand; i++)
	{
	    fscanf(CPU_code, "%d", &Programm[i]);
	    printf("c[%d]=%d\n", i, Programm[i]);
	}
	fclose(CPU_code);

/*	fseek(CPU_code,0,SEEK_END);
	CountOfCommand = ftell(CPU_code)/sizeof(int);
	int * Programm = calloc(CountOfCommand, sizeof(int));
	fread(Programm, sizeof(int), CountOfCommand, CPU_code);
	fclose(CPU_code); */	
	

Kek:	if ( Programm[CommandCounter] ==  CMD_END )
	{
		++ CommandCounter;
		CPU_end(cpu);
		return 0;
	}
	else
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

			printf("Значение регистра %d: %lg\n", Programm[CommandCounter], CPU_out(cpu, Programm[CommandCounter]));

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

	/*	if ( Programm[CommandCounter] ==  CMD_END )
		{
			++ CommandCounter;
			CPU_end(cpu);
		} */

	/*	if( Programm[CommandCounter] == CMD_JMP )
		{
			++CommandCounter */
					
		goto Kek;


	}
	
	return 1;
}

int main()
{	
	printf("SSS\n");
	CPU * cpu = CPU_create();

	printf("DDD\n");	

	int a = 0;

	assembler();

	printf("FFF\n");

	a = CPU_Function(cpu);

	return 0;
}

	
	


		






