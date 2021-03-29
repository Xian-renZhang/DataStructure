#include<stdio.h>
#include "������.c"

int DelSameX(LinkList L);

int main() 
{
	LinkList L;
	InitList(&L);
	CreateFromTail(L);
	DelSameX(L);
	DispList(L);
	return 0;
}


//ɾ���ǵݼ��������е��ظ�Ԫ��
int DelSameX(LinkList L) {
	Node* pre, * p;
	pre = L->next;
	if (pre == NULL) {
		return 0;
	}
	p = pre->next;
	while (p != NULL) {
		if (pre->data == p->data) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = pre->next;
			p = p->next;
		}
	}
	return 0;
}