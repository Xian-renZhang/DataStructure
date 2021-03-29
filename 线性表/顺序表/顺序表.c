#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define OK 1;
#define ERROR 0;

//ʹ��ǰ������ElemType����Ӧ�������������
typedef int ElemType;

typedef struct SeqList {
	ElemType* elem;
	int last;
}SeqList;

//��ʼ��˳���
void InitList(SeqList* L) {
	L->elem = (ElemType*)malloc(sizeof(ElemType));
	if (!L->elem) {
		printf("�ڴ���䲻�ɹ���\n");
		exit(-1);
	}
	L->last = -1;
}

//����˳���
int CreateList(SeqList* L) {
	int length, i;
	printf("������˳���ĳ��ȣ�\n");
	scanf("%d", &length);
	L->elem = (ElemType*)malloc(length * sizeof(ElemType));
	if (NULL == L->elem) {
		printf("�ڴ���䲻�ɹ���\n");
		exit(-1);
	}
	L->last = length-1;
	printf("������˳���ĳ�ʼԪ�أ�\n");
	for (i = 0; i < length; i++) {
		scanf("%d", &L->elem[i]);
	}
	printf("�����ɹ�!\n");
	return OK;
}

//���˳���
void PrintList(SeqList *L) {
	int i;
	printf("���˳���\n");
	for (i = 0; i <= L->last; i++) {
			printf("%d ", L->elem[i]);
	}
		printf("\n");
}

//˳���Ĳ������㣬����Ԫ�ز��뵽iλ��
int InsList(SeqList* L, int i, ElemType e) {
	ElemType* newpointer=NULL;
	if ((i < 1) || (i > L->last + 2)) {
		printf("����λ�ò��Ϸ�");
		return ERROR;
	} 
	newpointer = (ElemType*)realloc(L->elem, (L->last + 2) * sizeof(ElemType));
	if (newpointer==NULL) {
		printf("���������ڴ�ռ�ʧ�ܣ�");
		return ERROR;
	}
	else {
		L->elem = newpointer;
	}
	int j;
	for (j = L->last; j >= i - 1; j--) {
		L->elem[j+1] = L->elem[j];
	}
	L->elem[i] = e;
	L->last++;
	return OK;
}

//ɾ��˳����е�i������Ԫ�أ�����e������ֵ
int DelList(SeqList* L, int i, ElemType* e) {
	if (i<1 || i>L->last + 1) {
		printf("ɾ��λ�ò�����\n");
		return ERROR;
	}

	*e = L->elem[i - 1];
	for (int k = i; k <= L->last; k++) {
		L->elem[k - 1] = L->elem[k];
	}
	//����ͨ��realloc�ͷ�ĩβ���ڴ�ռ�
	L->last--;
	return OK;
}

//˳���İ����ݲ��ң����ظ�Ԫ���ڱ��е����
int Locate(SeqList* L, ElemType e) {
	int i = 0;
	while (i <= L->last && (L->elem[i] != e)) {
		i++;
	}
	if (i <= L->last) {
		return (i + 1);
	}
	else {
		return ERROR;
	}
}

//�ж�˳����Ƿ�Ϊ��
int ListEmpty(SeqList *L) {
	if (L->last == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

//�ÿ�˳���
void ClearList(SeqList* L) {
	L->last = -1;
}

//����˳���
void DestroyList(SeqList* L) {
	free(L->elem);
	L->elem = NULL;
	L->last = -1;
}

//˳���ĺϲ�,�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
int UnionList(SeqList* La, SeqList* Lb) {
	int i;
	for (i = 0; i <= Lb->last; i++) {
		ElemType e = Lb->elem[i];

		int k = 0;
		int flag = 0;
		while (k <= La->last && (La->elem[k] != e)) {
			k++;
		}
		if (k <= La->last) {
			flag = 1;
		}

		if (!flag) {
			ElemType* newpointer = NULL;
			newpointer = (ElemType*)realloc(La->elem, (La->last + 2) * sizeof(ElemType));
			if (newpointer == NULL) {
				printf("���������ڴ�ռ�ʧ�ܣ�");
				exit(-1);
			}
			else {
				La->elem = newpointer;
			}
			int j = (La->last + 1);
			La->elem[j] = e;
			La->last++;
		}
	}
	return OK;
}

//ɾ���ǵݼ�����˳����е��ظ�Ԫ��
int DelSameX(SeqList* L) {
	int i, j;
	if (L->last <= 1) {
		return OK;
	}
	for (i = 1, j = 1; i <= L->last; i++) {
		if (L->elem[i] != L->elem[i - 1]) {
			L->elem[j++] = L->elem[i];
		}
	}
	L->last = j - 1;
	return OK;
}