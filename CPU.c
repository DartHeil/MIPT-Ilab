#include <stdio.h>
#include <asm.h>
#include <commands.h>
#include <stack.h>

typedef struct CPU_s
{
	Stack* stack;
	T ax, bx, cx, dx, ex, fx, gx, hx;
	
} CPU;




