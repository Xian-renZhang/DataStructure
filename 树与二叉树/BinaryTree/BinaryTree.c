#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node* LChild;
	struct Node* RChild;
}BiTNode,*BiTree;

void InitTree(BiTree *bt) {
	*bt = (BiTree)malloc(sizeof(BiTNode));
	if (*bt == NULL) {
		printf("�ڴ���䲻�ɹ���");
		return;
	}
	(*bt)->LChild == NULL;
	(*bt)->RChild == NULL;
	return;
}

void CreatTree(BiTree bt) {
	int data=0;
	printf("������ڵ���ֵ��(������-1ʱ��ǰ��㴴�����)\n");
	scanf("%d", &data);

	if (data == -1) {
		return;
	}
	else {		
		bt->data = data;
		BiTNode* node = (BiTNode*)malloc(sizeof(BiTNode));
		printf("\n����%d�����ӣ�", data);
		CreatTree(&node);
		printf("\n����%d���Һ��ӣ�", data);
		CreatTree(&)
	}
}