#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "../../ջ�����/Queue/CircularQueue.c"

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node* lChild;
	struct Node* rChild;
}binaryTreeNode,*binaryTree;

//����������
void createTree(binaryTree* root) {
	DataType data = 0;
	printf("������ڵ���ֵ��������100ʱ��ǰ��㴴����ϣ���");
	scanf("%d", &data);

	if (data == 100) {
		*root = NULL;
	}
	else {
		*root = (binaryTreeNode*)malloc(sizeof(binaryTreeNode));
		if (*root == NULL) {
			return;
		}
		(*root)->data = data;
		printf("\n����%d�����ӣ�", data);
		createTree(&(*root)->lChild);
		printf("\n����%d���Һ��ӣ�", data);
		createTree(&(*root)->rChild);
	}
}

//���ٶ�����
void destoryTree(binaryTree root) {
	if (root == NULL) {
		return;
	}
	destoryTree(root->lChild);
	destoryTree(root->rChild);
	free(root);
}

//�������
void preOrder(binaryTree root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	preOrder(root->lChild);
	preOrder(root->rChild);
}

//�������
void inOrder(binaryTree root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->lChild);
	printf("%d ", root->data);
	inOrder(root->rChild);
}

//�������
void postOrder(binaryTree root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->lChild);
	postOrder(root->rChild);
	printf("%d ", root->data);
}

//��α���
void levelOrder(binaryTree root) {
	seqQueue queue;
	binaryTreeNode* node = NULL;	//���д�Žڵ�ָ��

	initQueue(&queue);	
	if (root == NULL) {
		return;
	}

	enterQueue(&queue, root);	//���ڵ����
	while (!isEmpty(&queue)) {
		deleteQueue(&queue, &node);
		printf("%d ", node->data);

		if (node->lChild != NULL) {
			enterQueue(&queue, node->lChild);
		}
		if (node->rChild != NULL) {
			enterQueue(&queue, node->rChild);
		}
	}
}

//��ӡҶ�ӽڵ�
void printLeaf(binaryTree root) {
	if (root == NULL) {
		return;
	}
	if ((root->lChild == NULL) && (root->rChild == NULL)) {
		printf("%d ", root->data);
	}
	else {
		printLeaf(root->lChild);
		printLeaf(root->rChild);
	}
}

//��ӡҶ�Ӹ���
int getLeafNum(binaryTree root) {
	if (root == NULL) {
		return 0;
	}
	if ((root->lChild == NULL) && (root->rChild == NULL)) {
		return 1;
	}
	return getLeafNum(root->lChild) + getLeafNum(root->rChild);
}
//��ӡ���ĸ߶�
int getHeight(binaryTree root) {
	int lHeight=0,rHeight = 0;	//���������ĸ߶�

	if (root == NULL) {
		return 0;
	}
	if ((root->lChild == NULL) && (root->rChild == NULL)) {	//Ҷ�ӽڵ�߶�Ϊ0
		return 0;
	}

	lHeight = getHeight(root->lChild);
	rHeight = getHeight(root->rChild);

	return((lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1));
}

int main() {
	binaryTree root = NULL;
	
	printf("������������\n");
	createTree(&root);
	printf("\n���������������");
	preOrder(root);
	printf("\n���������������");
	inOrder(root);
	printf("\n���������������");
	postOrder(root);
	printf("\n��α�����������");
	levelOrder(root);
	printf("\n��ӡ������Ҷ�ӽڵ㣺");
	printLeaf(root);
	printf("\n��ӡ������Ҷ�ӽڵ������%d", getLeafNum(root));
	printf("\n��ӡ�������߶ȣ�%d", getHeight(root));

	destoryTree(root);

	return 0;
}