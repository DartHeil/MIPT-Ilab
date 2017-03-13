#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"

#define MAX_COMMANDS 1000
#define MAXLEN 100
#define LAB 100

void ass_ ( double* commands, double* labels );


void assembler ( )
{
    double commands [ MAX_COMMANDS ] = {};
    double* labels = ( double* ) calloc ( LAB, sizeof ( double ) );

    ass_ ( &commands, labels );

    //char command [ MAXLEN ] = "";
    /*double value = 0;
    int  k = 0, i = 0;

    for ( k = 0; k < 2; ++ k )
    {
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

            if ( command [0] == ':' )
            {
                int number = 0;

                if ( strlen ( command ) == 3 )
                {
                    number = ( command [1] - '0' ) * 10 + ( command [2] - '0' );
                    labels [ number ] = i;
                }
                       else if ( strlen ( command ) == 2 )
                {
                    number = command [1] - '0';
                    labels [ number ] = i;
                }
            }

            if ( strcmp ( command, "jmp" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JMP;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "je" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JE;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jne" ) == 0 )
                   {
                int label = 0;

                commands [i] = CMD_JNE;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "ja" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JA;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jae" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JAE;
                ++ i;
                fscanf ( f, "%d", &label );
                   commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jb" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JB;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jbe" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JBE;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "call" ) == 0 )
               {
                int label = 0;

                commands [i] = CMD_CALL;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "ret" ) == 0 )
            {
                commands [i] = CMD_RET;
                ++ i;
            }
        }

        fclose (f);

    }

    free ( labels );
    FILE *p = fopen ( "CPU_code.txt", "w" );
    for ( k = 0; k < i; ++ k )
    {
        fprintf ( p, "%lg ", commands [k] );
    }
    fclose (p);    */
    }

void ass_ ( double* commands, double* labels )
{
    char command [ MAXLEN ] = "";
    double value = 0;
    int  k = 0, i = 0;

    for ( k = 0; k < 2; ++ k )
    {
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

            if ( command [0] == ':' )
            {
                int number = 0;

                if ( strlen ( command ) == 3 )
                {
                    number = ( command [1] - '0' ) * 10 + ( command [2] - '0' );
                    labels [ number ] = i;
                }

                else if ( strlen ( command ) == 2 )
                {
                    number = command [1] - '0';
                    labels [ number ] = i;
                }
                   }

            if ( strcmp ( command, "jmp" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JMP;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "je" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JE;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jne" ) == 0 )
            {
                int label = 0;
                   commands [i] = CMD_JNE;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "ja" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JA;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jae" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JAE;
                 ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jb" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JB;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "jbe" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_JBE;
                ++ i;
                fscanf ( f, "%d", &label );
                   commands [i] = labels [label];
                ++ i;
            }
 if ( strcmp ( command, "call" ) == 0 )
            {
                int label = 0;

                commands [i] = CMD_CALL;
                ++ i;
                fscanf ( f, "%d", &label );
                commands [i] = labels [label];
                ++ i;
            }

            if ( strcmp ( command, "ret" ) == 0 )
            {
                commands [i] = CMD_RET;
                ++ i;
            }
        }

        fclose (f);
   }

    free ( labels );
    FILE *p = fopen ( "CPU_code.txt", "w" );
    for ( k = 0; k < i; ++ k )
    {
        fprintf ( p, "%lg ", commands [k] );
    }
    fclose (p);

}
