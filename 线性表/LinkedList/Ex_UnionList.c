#include<stdio.h>
#include "LinkedList.c"

// �����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
int Union(LinkList La, LinkList Lb) {   
    int La_Len, Lb_Len, i;  ElemType e;

    La_Len = ListLength(La);
    Lb_Len = ListLength(Lb);
    for (i = 1; i <= Lb_Len; i++) {
        GetData(Lb, i, &e);       // ȡLb�е�i������Ԫ�ظ���e
        if (!Locate(La, e))       // La�в����ں�e��ͬ������Ԫ��
            if (!InsList(La, e, ++La_Len))    // ����
                return ERROR;
    }
    return OK;
}

int main() {
    LinkList A, B;

    printf("Union\nInput elements of SET A ( END with $) :\n");
    InitList(&A);  CreateFromTail(A);
    printf("Input elements of SET B ( END with $) :\n");
    InitList(&B);  CreateFromTail(B);
    printf("SET A : ");  PrintList(A);
    printf("SET B : ");  PrintList(B);
    Union(A, B);
    printf("After A = A U B , SET A : ");  PrintList(A);
    getchar();  getchar();
    return 0;
}