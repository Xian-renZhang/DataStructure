#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define Stack_Size 50
#define FALSE 0
#define TRUE 1

typedef char StackElemType;

typedef struct {
    StackElemType elem[Stack_Size];
    int top;
}SeqStack;

// ��S��ʼ��Ϊһ����ջ
void InitStack(SeqStack* S)
{   
    S->top = -1;
}

// �ж�ջS�Ƿ�Ϊ��ջ���Ƿ���TRUE�����򷵻�FALSE
int IsEmpty(SeqStack* S)
{    
    if (S->top == -1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// �ж�ջS�Ƿ��������Ƿ���TRUE�����򷵻�FALSE
int IsFull(SeqStack* S)
{    
    if (S->top == Stack_Size - 1) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

// ������Ԫ��x��ջS����ջS����������FALSE�����򷵻�TRUE
int Push(SeqStack* S, StackElemType x)
{   
    if (S->top == Stack_Size-1) {
        return FALSE;
    }
    else {
        S->top++;
        S->elem[S->top] = x;
        return TRUE;
    }
}

// ��ջS��ջ��Ԫ�س�ջ��ͨ��x����;��ջSΪ�գ�����FALSE�����򷵻�TRUE
int Pop(SeqStack* S, StackElemType* x)
{   
    if (S->top == -1) {
        return FALSE;
    }
    else {
        *x = S->elem[S->top];
        S->top--;
        return TRUE;
    }
}

// ȡջS��ջ��Ԫ�أ�ͨ��x����;��ջSΪ�գ�����FALSE�����򷵻�TRUE
int GetTop(SeqStack* S, StackElemType* x)
{   
    if (S->top == -1) {
        return FALSE;
    }
    else {
        *x = S->elem[S->top];
        return TRUE;
    }
}