//Postfix evaluation
#include<stdio.h>
#define size 20
#include<math.h>
#include<ctype.h>
#include<string.h>

void main()
{
    char que[20],symbol;
    int top=-1,res,op1,op2,s[size];
    printf("enter postfix expression:");
    scanf("%s",que);

    for(int i=0;i<strlen(que);i++)
    {
        symbol = que[i];
        if(isdigit(symbol))
        {
            s[++top]=symbol-'0';
        }
        else
        {
            op2 = s[top--];
            op1 = s[top--];

            // Perform the operation based on the symbol
            switch (symbol)
            {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
        }
         s[++top] = res;
    }
    print("%d",s[top]);
}
