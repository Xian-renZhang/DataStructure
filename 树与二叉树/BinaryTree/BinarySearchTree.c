#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "../../ջ�����/Stack/SequenceStack.c"
#include "../../ջ�����/Queue/CircularQueue.c"
#define ENDKEY -1

typedef int KeyType;

typedef struct Node {
	KeyType key;
	struct Node* lChild;
	struct Node* rChild;
}BSTreeNode,*BSTree;

void insertNode(BSTree* tree, KeyType key) {
	BSTree node;
	if (*tree == NULL) {	//�����������Ϊ��������key��Ϊ����
		node = (BSTree)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->lChild = NULL;
		node->rChild = NULL;
		*tree = node;
	}
	else if (key < (*tree)->key) {
		insertNode(&((*tree)->lChild), key);
	}
	else if (key > (*tree)->key) {
		insertNode(&((*tree)->rChild), key);
	}
}

void createTree(BSTree* tree) {
	KeyType key;
	*tree = NULL;
	scanf("%d", &key);
	while (key != ENDKEY) {
		insertNode(tree, key);
		scanf("%d", &key);
	}
}

void inOrder(BSTree tree) {
	if (tree != NULL) {
		inOrder(tree->lChild);
		printf("%d ", tree->key);
		inOrder(tree->rChild);
	}
}

void destroyTree(BSTree tree) {
	if (tree != NULL) {
		if (tree->lChild) {
			destroyTree(tree->lChild);
		}
		if (tree->rChild) {
			destroyTree(tree->rChild);
		}
		free(tree);
	}
}

int isBStree(BSTree tree) {
	SeqStack S;
	BSTree p;
	InitStack(&S);

	while (tree != NULL || IsEmpty(&S)) {
		if (tree != NULL) {
			Push(&S, tree);
			tree = tree->lChild;
		}
		else {
			Pop(&S, &tree);
			GetTop(&S, &p);
			if (tree->key >= p->key) {
				return 0;
			}
			tree = tree->rChild;
		}
	}
	return 1;
}

int levelOfNode_recursion(BSTree tree, KeyType key) {
	if (tree == NULL)
		return 0;
	if (tree->key == key)
		return 1;
	int i = levelOfNode_recursion(tree->lChild,key);
	int j = levelOfNode_recursion(tree->rChild,key);

	if (i || j)
		return (i > j ? ++i : ++j);
}

int levelOfNode(BSTree tree, KeyType key) {
	if (tree == NULL)
		return 0;
	seqQueue Q;
	initQueue(&Q);
	enterQueue(&Q, tree);
	int front = 0;
	int rear = queueLength(&Q);
	int level = 1;
	int flag = 0;

	while (!isEmpty(&Q)) {
		deleteQueue(&Q, &tree);
		front++;
		if (tree->key == key) {
			flag = 1;
			break;
		}
		if (tree->lChild != NULL)
			enterQueue(&Q, tree->lChild);
		if (tree->rChild != NULL)
			enterQueue(&Q, tree->rChild);
		if (front == rear) {
			front = 0;
			rear = queueLength(&Q);
			level++;
		}
	}

	if (flag)
		return level;
	else
		return 0;
}

int main() {
	BSTree tree; 
	KeyType key;
	
	printf("����������������\n");
	createTree(&(tree));
	if (isBStree(tree)) {
		printf("�ö�����Ϊ����������\n");
	}
	inOrder(tree);
	printf("\n������ؼ��֣�");
	scanf("%d", &key);
	printf("���ҹؼ��ֲ�Σ�\n");
	printf("�ݹ飺%d\n", levelOfNode_recursion(tree, key));
	printf("�ǵݹ飺%d", levelOfNode(tree, key));	

	destroyTree(tree);

	return 0;
}