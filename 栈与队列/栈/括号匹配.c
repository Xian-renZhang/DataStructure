#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "˳��ջ.c"

int BracketMatch(char* str);

int main()
{
    char str[100];

    printf("Please input a string:");  
    gets_s(str);
    switch (BracketMatch(str))
    {
    case 0:
        printf("\n����ƥ�䣡");
        break;
    case 1:
        printf("\n�����Ŷ��࣡");
        break;
    case 2:
        printf("\n�����Ŷ��࣡");
        break;
    case 3:
        printf("\n�������Ų�ƥ�䣡");
        break;
    }
    getchar();  getchar();
    return 0;
}

// �ж�������ch1����ch2�Ƿ�ƥ�䣬ƥ�䷵��TRUE�����򷵻�FALSE
int Match(char ch1, char ch2)
{   
    switch (ch1) 
    {
    case '(':
        if (ch2 == ')')
            return 1;
        break;
    case '[':
        if (ch2 == ']')
            return 1;
        break;
    case '{':
        if (ch2 == '}')
            return 1;
    }
    return 0;
}

int BracketMatch(char* str)
{   // str[]��Ϊ������ַ��������ö�ջ�����������ַ����е������Ƿ�ƥ��
    SeqStack S;  int i;  char ch;

    InitStack(&S);
    for (i = 0; str[i] != '\0'; i++)   // ���ַ����е��ַ���һɨ��
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{': 
            Push(&S, str[i]);  
            break;
        case ')':
        case ']':
        case '}': 
            if (IsEmpty(&S)) {
                return 2;
            }
            else {
                GetTop(&S, &ch);
                if (Match(ch, str[i]))    // ��Match�ж����������Ƿ�ƥ��
                    Pop(&S, &ch);         // ��ƥ��������ų�ջ
                else  
                    return 3;
            }
        }
    }
    return (IsEmpty(&S) ? 0 : 1);
}