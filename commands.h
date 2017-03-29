#ifndef _commands_H_
#define _commands_H_

enum Commands {
                CMD_PUSH  = 1, //функция в списке функций + в CPU
                CMD_ADD   = 2, //функция в списке функций + в CPU
                CMD_END   = 3,//функция в списке функций + в CPU
                CMD_POPR  = 4,//функция в списке функций + в CPU
                CMD_DIV   = 5,//функция в списке функций + в CPU
                CMD_MUL   = 6,//функция в списке функций + в CPU
                CMD_SUB   = 7,//функция в списке функций + в CPU
                CMD_OUT   = 8,//функция в списке функций + в CPU
                CMD_SQRT  = 9,//функция в списке функций + в CPU
                CMD_PUSHR = 10,//функция в списке функций + в CPU
                CMD_IN    = 11,//функция в списке функций + в CPU
                CMD_JMP   = 12,//функция в списке функций + в CPU
                CMD_JE    = 13,
                CMD_JNE   = 14,
                CMD_JA    = 15,
                CMD_JAE   = 16,
                CMD_JB    = 17,
                CMD_JBE   = 18,
                CMD_CALL  = 19,
                CMD_RET   = 20,

                ax        = 100,//+
                bx        = 101,//+
                cx        = 102,//+
                dx        = 103,//+
                ex        = 104,//+
                fx        = 105,//+
                gx        = 106,//+
                hx        = 107,//+

              };
#endif
