#include<stdio.h>
#define MAXSIZE 50
#define TRUE 1
#define FALSE 0

typedef int* ElemType;

typedef struct {
	ElemType elem[MAXSIZE];
	int front;
	int rear;
}seqQueue;

//��ʼ������
void initQueue(seqQueue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

//�ж϶����Ƿ�Ϊ��
int isEmpty(seqQueue* queue) {
	if (queue->front == queue->rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//�ж϶����Ƿ�����
int isFull(seqQueue* queue) {
	if ((queue->rear + 1) % MAXSIZE == queue->front) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//�ڶ��еĶ�β����x
int enterQueue(seqQueue* queue, ElemType x) {
	if ((queue->rear + 1) % MAXSIZE == queue->front) {
		return FALSE;
	}
	queue->elem[queue->rear] = x;
	queue->rear = (queue->rear + 1) % MAXSIZE;
	return TRUE;
}

//�����еĶ�ͷԪ�س��ӣ�����x������ֵ
int deleteQueue(seqQueue* queue, ElemType* x) {
	if (queue->front == queue->rear) {
		return FALSE;
	}
	*x = queue->elem[queue->front];
	queue->front = (queue->front + 1) % MAXSIZE;
	return TRUE;
}

//ȡ���еĶ�ͷԪ��
int getHead(seqQueue* queue, ElemType* x) {
	if (queue->front == queue->rear) {
		return FALSE;
	}
	*x = queue->elem[queue->front];
	return TRUE;
}

//��������Ϊ�ն���
int clearQueue(seqQueue* queue) {
	queue->front = queue->rear = 0;
	return TRUE;
}

//���ض���Ԫ�ظ���
int queueLength(seqQueue* queue) {
	if (queue->front == queue->rear) {
		return FALSE;
	}
	return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}

//��ӡ����
int printQueue(seqQueue* queue) {
	if (queue->front == queue->rear) {
		return FALSE;
	}
	for (int i = queue->front; i != queue->rear; i = (i + 1) % MAXSIZE) {
		printf("&d ", queue->elem[i]);
	}
	return TRUE;
}