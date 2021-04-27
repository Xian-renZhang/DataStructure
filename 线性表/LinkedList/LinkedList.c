#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define TRUE          1
#define FALSE         0
#define OK            1
#define ERROR         0
//ʹ��ǰ������ElemType����Ӧ�������������
typedef char ElemType;

typedef struct Node {
	ElemType data;
	struct Node* next;
}Node, * LinkList;

//��ʼ����ͷ��㵥����
void InitList(LinkList* L) {
	*L = (LinkList)malloc(sizeof(Node));
	if (NULL == *L) {
		printf("�ڴ���䲻�ɹ���\n");
		exit(ERROR);
	}
	//��ͷ����nextָ����Ϊ��ָ��
	(*L)->next = NULL;
}

//β�巨����������,������$ʱ���������
void CreateFromTail(LinkList L) {
	Node* r, * s;
	char c;
	r = L;
	while ((c = getchar())!='$') {
		s = (Node*)malloc(sizeof(Node));
		if (NULL == s) {
				printf("�ڴ���䲻�ɹ���\n");
				exit(-1);
		}
		else {
			s->data = c;
			r ->next = s;
			r = s;
		}
	}
	r->next = NULL;
}

//����������
void PrintList(LinkList L) {
	Node* p;
	p = L->next;
	while (p != NULL) {
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}

//������ĳ���
int ListLength(LinkList L) {
	Node* p;
	int j = 0;
	p = L->next;
	while (p != NULL) {
		j++;
		p = p->next;
	}
	return j;
}

//�ڵ������в��ҵ�i�����
Node* Get(LinkList L, int i) {
	Node* p;
	int j = 0;
	if (i < 1) {
		return NULL;
	}
	p = L->next;
	//p->next==null:pָ�����һ�����
	//p==null:pָ�����һ������next�������ŵĿ�ָ��
	while (p != NULL) {
		j++;
		if (i == j) {
			break;
		}
		p = p->next;
	}
	//���ҳ�������Χ�󷵻ؿ�ֵ
	return p;
}

// ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
int GetData(LinkList L, int i, ElemType* e) {   
	Node* p;
	if (!(p = Get(L, i))) {
		return ERROR;
	}
	*e = p->data;
	return OK;
}

//�ڴ�ͷ���ĵ������е�i��λ�ò���ֵΪe����ֵ
int InsList(LinkList L, ElemType e, int i) {
	Node* pre, * s;
	if (i < 1) {
		return ERROR;
	}
	pre = ((i == 1) ? L : Get(L, i - 1));
	if (pre == NULL) {
		printf("����λ�ò�����");
		return ERROR;
	}
	s = (Node*)malloc(sizeof(Node));
	if (NULL == s) {
		printf("�ڴ���䲻�ɹ���\n");
		exit(ERROR);
	}
	else {
		s->data = e;
	}
	s->next = pre->next;
	pre->next = s;
	return OK;
}

//�ڴ�ͷ���ĵ�������ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����*e��
int DelList(LinkList L, int i, ElemType* e) {
	Node* pre, * r;
	if (i < 1) {
		return ERROR;
	}
	pre = ((i == 1) ? L : Get(L, i - 1));
	if (pre == NULL || pre->next == NULL) {
		printf("��ɾ����λ�ò�����");
		return ERROR;
	}
	r = pre->next;
	pre->next = r->next;
	*e = r->data;
	free(r);
	return OK;
}

//�ڵ������в���ֵΪkey�Ľ��
Node* Locate(LinkList L, ElemType key) {
	Node* p;
	p = L->next;
	while (p != NULL) {
		if (p->data == key) {
			break;
		}
		p = p->next;
	}
	return p;
}

//�жϵ������Ƿ�Ϊ��
int ListEmpty(LinkList L) {
	if (L->next == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//��յ�����
int ClearList(LinkList L) {
	Node* p, * q;
	p = L->next;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}

//���ٵ�����
int DestroyList(LinkList *L) {
	Node* p;
	while (*L != NULL) {
		p = (*L)->next;
		free(*L);
		*L = p;
	}
}