#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "SequenceStack.c"
//�Ľ���
//1.ʹ�õ�����ջ���Ƕ�����ջ
//2.��ν��ж�λ��������
//3.�������"()"���ű��ʽ
//Ŀǰ������õ�����charջ��������Ҫ�����ַ�ת���������˳���Ŀɶ��ԣ�����������������ֻ����һλ��

int ExprEvaluation(char* expr);

int main()
{
    char expr[80];
    printf("Input a expression(end with #): ");
    gets_s(expr,sizeof(expr));
    printf("Its value: %d\n", ExprEvaluation(expr));
    return 0;
}

#define OPSet    "+-*/#"

int In(char c, char op[]);
char Compare(char c1, char c2);
int Execute(char a, char op, char b);

int ExprEvaluation(char* expr)
{   // �������ŵ��������ʽ��ֵ����������㷨
    SeqStack OPTR, OPND;
    char a, b;
    char ch, op, e;

    InitStack(&OPTR);
    InitStack(&OPND);
    Push(&OPTR, '#');
    ch = *expr++;
    GetTop(&OPTR, &e);
    while (ch != '#' || e != '#')
    {
        if (!In(ch, OPSet))
        {
            Push(&OPND, ch);  ch = *expr++;
        }
        else
            switch (Compare(ch, e))
            {
            case '>': Push(&OPTR, ch);  ch = *expr++;  break;
            case '<': Pop(&OPTR, &op);  Pop(&OPND, &b);  Pop(&OPND, &a);
                      Push(&OPND, Execute(a, op, b));  break;
            }
        GetTop(&OPTR, &e);
    }
    GetTop(&OPND, &a);
    return a;
}

int In(char c, char op[])
{   // �ж��ַ�c�Ƿ�������������Ƿ���0���Ƿ��ط�0
    // �ҹ涨'+'����1��'-'����2��'*'����3����������
    int i;
    for (i = 0; i < 5; i++) {
        if (c == op[i]) {
            break;
        }
    }
    if (i < 5) {
        return ++i;
    }
    return 0;
}

char Compare(char c1, char c2)
{   // �Ƚ������c1�������c2�����ȼ�
    // c1����c2����>��c1����c2����<��c1����c2����=
    char com[][5] = {
        {'>','>','<','<','>'},
        {'>','>','<','<','>'},
        {'>','>','>','>','>'},
        {'>','>','>','>','>'},
        {'<','<','<','<','<'},
    };
    return com[In(c1, OPSet)-1][In(c2, OPSet)-1];
}

int Execute(char a, char op, char b)
{   // ����a��b����op���㣬����������
    int result=0;
    int op1 = a - '0';
    int op2 = b - '0';
    switch (op)
    {
    case '+':
        result = op1 + op2; break;
    case '-':
        result = op1 - op2; break;
    case '*':
        result = op1 * op2; break;
    case '/':
        result = op1 / op2; break;
    }
    return result;
}
