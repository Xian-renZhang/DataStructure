#include<stdio.h>
#define MAXSIZE 50
#define TRUE 1
#define FALSE 0

typedef int ElemType;

typedef struct {
	ElemType elem[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

//��ʼ������Q
int InitQueue(SeqQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
	
	return  TRUE;
}

//�ж϶����Ƿ�Ϊ��
int IsEmpty(SeqQueue* Q) {
	if (Q->front == Q->rear) {
		return TRUE;
	}
	return FALSE;
}

//�ж϶����Ƿ�����
int IsFull(SeqQueue* Q) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		return TRUE;
	}
	return FALSE;
}

//�ڶ��еĶ�β����x
int EnterQueue(SeqQueue* Q, ElemType x) {
	if ((Q->rear + 1) % MAXSIZE == Q->front) {
		return FALSE;
	}
	Q->elem[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return TRUE;
}

//�����еĶ�ͷԪ�س��ӣ�����x������ֵ
int DeleteQueue(SeqQueue* Q, ElemType* x) {
	if (Q->front == Q->rear) {
		return FALSE;
	}
	*x = Q->elem[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return TRUE;
}

//ȡ���еĶ�ͷԪ��
int GetHead(SeqQueue* Q, ElemType* x) {
	if (Q->front == Q->rear) {
		return FALSE;
	}
	*x = Q->elem[Q->front];
	return TRUE;
}

//��������Ϊ�ն���
int Clear(SeqQueue* Q) {
	Q->front = Q->rear = 0;
	return TRUE;
}

//���ض���Ԫ�ظ���
int QueueLength(SeqQueue* Q) {
	if (Q->front == Q->rear) {
		return FALSE;
	}
	return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

//��ӡ����
int PrintQueue(SeqQueue* Q) {
	if (Q->front == Q->rear) {
		return FALSE;
	}
	for (int i = Q->front; i != Q->rear; i = (i + 1) % MAXSIZE) {
		printf("&d ", Q->elem[i]);
	}
	return TRUE;
}