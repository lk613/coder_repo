#include "suffix_expression.h"
#include <string.h>

int evalRPN(char **tokens, int tokensSize)
{
    Stack *stack_num = CreateStack();
    for (int i = 0; i < tokensSize; i++)
    {
        if ((strlen(tokens[i]) > 1) || ('0' <= tokens[i][0] && tokens[i][0] <= '9'))
        {
            Push(stack_num, atoi(tokens[i]));
        }else
        {
            int num_snd = Top(stack_num);
            Pop(stack_num);
            int num_fst = Top(stack_num);
            Pop(stack_num);
            switch (tokens[i][0])
            {
                case '+':
                    Push(stack_num, num_fst + num_snd);
                    break;
                case '-':
                    Push(stack_num, num_fst - num_snd);
                    break;
                case '*':
                    Push(stack_num, num_fst * num_snd);
                    break;
                case '/':
                    Push(stack_num, num_fst / num_snd);
                    break;
                default:
                    break;
            }
        }
    }

    return Top(stack_num);
}