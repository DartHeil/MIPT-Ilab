#ifndef _assembler_H_
#define _assembler_H_
                                                                                                                                        #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

#define MAX_COMMANDS 1000
#define MAXLEN 100
#define LAB 100
#define StartSize 10

typedef struct Pointer_s
{
	char * PointerName;
	int Place;
				
}Pointer;



Pointer * As_Resize(Pointer * Pointers, int number)
{
	int i = 0;
	Pointer * suicider = NULL;

	suicider  = realloc(Pointers, (number - 1) * 2);

	if( suicider != NULL)
		for (i = number; i < number * 2; i++)
		{
			suicider[i].PointerName = NULL;
			suicider[i].Place = 0;
		}
	else
		{
			printf("Нахуя ты прогаешь на этом говне? Купи нормальный комп!");
			exit(1);
		}

	free(Pointers);

	return suicider;

}



Pointer * CollectPointers()
{
	Pointer * Pointers = calloc(StartSize, sizeof(Pointer));
	int j = 0;
	int i = 0;
	int number = 0;
	int length = 0;
	int check = StartSize;
	int n = 0;

	FILE* f = fopen ( "program.txt", "r" );
	char command [ MAXLEN ] = "";

	while ( fscanf ( f, "%s", &command ) == 1 )
	{	
		if ( (command [0] == ':') && (strcmp ( command, ":main" ) != 0) )
		{
			length = strlen(command);			

			Pointers[number].PointerName = calloc(length - 1, sizeof(char));
	
			for(j = 1; j < length; j++)
			{
				Pointers[number].PointerName[j - 1] = command[j];
			}
	
			Pointers[number].Place = i - n; 
	
			number++;
	
			if (number > check)
			{
				Pointers = As_Resize(Pointers, number);
				check = check * 2;
			}
			n++;
		}
		
		i++;
	}

	return Pointers;
}



void ass_ ( double* commands, Pointer * Pointers );


void assembler ( )
{
    double commands [ MAX_COMMANDS ] = {};
    Pointer * Pointers = CollectPointers();

    ass_ ( &commands, Pointers );
}



void ass_ ( double* commands, Pointer * Pointers )
{
    char command [ MAXLEN ] = "";
    double value = 0;
    int  k = 0, i = 0, j = 0;
    int check = 0;

    FILE* f = fopen ( "program.txt", "r" );
    i = 0;

    while ( fscanf ( f, "%s", &command ) == 1 )
        {
            if ( strcmp ( command, "push" ) == 0 )
            {
                commands [i] = CMD_PUSH;
                fscanf ( f, "%lg", &value );
                ++ i;
                commands [i] = value;
                ++ i;
            }

            if ( strcmp ( command, "add" ) == 0 )
            {
                commands [i] = CMD_ADD;
                ++ i;
            }
             if ( strcmp ( command, "end" ) == 0 )
            {
                commands [i] = CMD_END;
                ++ i;
            }

            if ( strcmp ( command, "popr" ) == 0 )
            {
                commands [i] = CMD_POPR;
                ++ i;
                fscanf ( f, "%s", &command );
                if ( strcmp ( command, "ax" ) == 0 )
                    commands [i] = ax;
                if ( strcmp ( command, "bx" ) == 0 )
                    commands [i] = bx;
                if ( strcmp ( command, "cx" ) == 0 )
                    commands [i] = cx;
                if ( strcmp ( command, "dx" ) == 0 )
                    commands [i] = dx;
                if ( strcmp ( command, "ex" ) == 0 )
                    commands [i] = ex;
                if ( strcmp ( command, "fx" ) == 0 )
                    commands [i] = fx;
                if ( strcmp ( command, "gx" ) == 0 )
                    commands [i] = gx;
                if ( strcmp ( command, "hx" ) == 0 )
                    commands [i] = hx;
                ++ i;
            }

            if ( strcmp ( command, "div" ) == 0 )
            {
            commands [i] = CMD_DIV;
                ++ i;
            }

            if ( strcmp ( command, "out" ) == 0 )
            {
                commands [i] = CMD_OUT;
                ++ i;
                fscanf ( f, "%s", &command );
                if ( strcmp ( command, "ax" ) == 0 )
                    commands [i] = ax;
                if ( strcmp ( command, "bx" ) == 0 )
                    commands [i] = bx;
                if ( strcmp ( command, "cx" ) == 0 )
                    commands [i] = cx;
                if ( strcmp ( command, "dx" ) == 0 )
                    commands [i] = dx;
                if ( strcmp ( command, "ex" ) == 0 )
                    commands [i] = ex;
                if ( strcmp ( command, "fx" ) == 0 )
                    commands [i] = fx;
                if ( strcmp ( command, "gx" ) == 0 )
                    commands [i] = gx;
                if ( strcmp ( command, "hx" ) == 0 )
                    commands [i] = hx;
                ++ i;
                       }

            if ( strcmp ( command, "mul" ) == 0 )
            {
                commands [i] = CMD_MUL;
                ++ i;
            }

            if ( strcmp ( command, "sub" ) == 0 )
            {
                commands [i] = CMD_SUB;
                ++ i;
            }

            if ( strcmp ( command, "sqrt" ) == 0 )
            {
                commands [i] = CMD_SQRT;
                ++ i;
            }

            if ( strcmp ( command, ":main" ) == 0 )
            {
                commands [i] = CMD_MAIN;
                ++ i;
            }

            if ( strcmp ( command, "pushr" ) == 0 )
            {
                commands [i] = CMD_PUSHR;
                ++ i;
                fscanf ( f, "%s", &command );
                    if ( strcmp ( command, "ax" ) == 0 )
                    commands [i] = ax;
                if ( strcmp ( command, "bx" ) == 0 )
                    commands [i] = bx;
                if ( strcmp ( command, "cx" ) == 0 )
                    commands [i] = cx;
                if ( strcmp ( command, "dx" ) == 0 )
                    commands [i] = dx;
                if ( strcmp ( command, "ex" ) == 0 )
                    commands [i] = ex;
                if ( strcmp ( command, "fx" ) == 0 )
                    commands [i] = fx;
                if ( strcmp ( command, "gx" ) == 0 )
                    commands [i] = gx;
                if ( strcmp ( command, "hx" ) == 0 )
                    commands [i] = hx;
                ++ i;
            }

            if ( strcmp ( command, "in" ) == 0 )
            {
                commands [i] = CMD_IN;
                ++ i;
                fscanf ( f, "%s", &command );
                if ( strcmp ( command, "ax" ) == 0 )
                    commands [i] = ax;
                if ( strcmp ( command, "bx" ) == 0 )
                    commands [i] = bx;
                if ( strcmp ( command, "cx" ) == 0 )
                    commands [i] = cx;
                if ( strcmp ( command, "dx" ) == 0 )
                    commands [i] = dx;
                if ( strcmp ( command, "ex" ) == 0 )
                    commands [i] = ex;
                if ( strcmp ( command, "fx" ) == 0 )
                    commands [i] = fx;
                if ( strcmp ( command, "gx" ) == 0 )
                    commands [i] = gx;
                if ( strcmp ( command, "hx" ) == 0 )
                    commands [i] = hx;
                ++ i;
            }


            if ( strcmp ( command, "jmp" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_JMP;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}

		if ( check == 0)
		{
			printf("Обращение к несуществующей метке %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}			


                ++ i;
             }

            if ( strcmp ( command, "je" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_JE;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}

		if ( check == 0)
		{
			printf("Обращение к несуществующей метке %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}			


                ++ i;
             }

             if ( strcmp ( command, "jne" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_JNE;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}

		if ( check == 0)
		{
			printf("Обращение к несуществующей метке %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}			


                ++ i;
             }

          if ( strcmp ( command, "ja" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_JA;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}

		if ( check == 0)
		{
			printf("Обращение к несуществующей метке %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}			


                ++ i;
             }

               if ( strcmp ( command, "jae" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_JAE;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}

		if ( check == 0)
		{
			printf("Обращение к несуществующей метке %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}			

                ++ i;
             }

               if ( strcmp ( command, "jb" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_JB;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}


		if ( check == 0)
		{
			printf("Обращение к несуществующей метке %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}			

		
                ++ i;
             }

             if ( strcmp ( command, "jbe" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_JBE;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}

		if ( check == 0)
		{
			printf("Обращение к несуществующей метке %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}

                ++ i;
             }

 	       if ( strcmp ( command, "call" ) == 0 )
            {
                char * Point = calloc(100, sizeof(char));
		j = 0;

                commands [i] = CMD_CALL;

                ++ i;

                fscanf ( f, "%s", Point );

		while( Pointers[j].PointerName != NULL)
		{
			if( strcmp ( Point, Pointers[j].PointerName ) == 0 )
			{
				check = 1;
				commands[i] = Pointers[j].Place;
			}

			j++;
		}

		if ( check == 0)
		{
			printf("Обращение к несуществующей функции %s\n", Point);
			exit(1);
		}
		else
		{
			check = 0;
		}		

                ++ i;
             }

            if ( strcmp ( command, "ret" ) == 0 )
            {
                commands [i] = CMD_RET;
                ++ i;
            } 
        }

        fclose (f);

    free ( Pointers );
    FILE *p = fopen ( "CPU_code.txt", "w" );
    for ( k = 0; k < i; ++ k )
    {
        fprintf ( p, "%lg ", commands [k] );
    }
    fclose (p);

}

#endif
