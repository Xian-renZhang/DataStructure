#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WEIGHT 100;

typedef struct
{
    int weight;                // ������Ÿ�������Ȩֵ
    int parent, LChild, RChild; // ָ��˫�ס����ӽ���ָ��
}HTNode, * HuffmanTree;      // ��̬�������飬�洢��������

typedef char** HuffmanCode; // ��̬�������飬�洢����������

void select(HuffmanTree ht, int n, int* s1, int* s2)
{   // ��ht[1]~ht[n]��Χ��ѡ������parentΪ0��weight��С�Ľ�㣬����ŷֱ�ֵ��s1��s2
    int i,node1,node2;
    int min = MAX_WEIGHT;
    for (i = 1; i <= n; i++)
    {
        if ((ht[i].parent == 0)&&(ht[i].weight<min)) 
        {
            min = ht[i].weight;
            node1 = i;
        }
    }
    min = MAX_WEIGHT;
    for (i = 1; i <= n; i++)
    {
        if (i == node1)
        {
            continue;
        }
        if ((ht[i].parent == 0) && (ht[i].weight < min))
        {
            min = ht[i].weight;
            node2 = i;
        }
    }
    *s1 = node1;
    *s2 = node2;
}

void CrtHuffmanTree(HuffmanTree ht, int* w, int n)
{   // �����������ht[m+1], w[]�����֪��n��Ȩֵ
    int i, m, s1, s2;

    for (i = 1; i <= n; i++)   // 1~n�ŵ�Ԫ���Ҷ�ӽ�㣬��ʼ��
    {
        ht[i].weight = w[i];
        ht[i].parent = ht[i].LChild = ht[i].RChild = 0;
    }
    m = 2 * n - 1;
    for (i = n + 1; i <= m; i++) // n+1~m�ŵ�Ԫ��ŷ�Ҷ�ӽ�㣬��ʼ��
        ht[i].weight = ht[i].parent = ht[i].LChild = ht[i].RChild = 0;

    // ��ʼ����ϣ����´�����Ҷ�ӽ�㣬����������
    for (i = n + 1; i <= m; i++)
    {
        select(ht, i - 1, &s1, &s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[s1].parent = ht[s2].parent = i;
        ht[i].LChild = s1;  
        ht[i].RChild = s2;
    }
}

void PreOrderHuffman(HuffmanTree HT, int m)
{   // ���������������
    if (m == 0)
        return;
    printf("%d  ", HT[m].weight);
    PreOrderHuffman(HT, HT[m].LChild);
    PreOrderHuffman(HT, HT[m].RChild);
}

void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)
{   // ��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
    char* cd;
    int i, start, p, c;

    cd = (char*)malloc(n * sizeof(char));  // ������ǰ����Ĺ����ռ�
    if (cd == NULL)
        return;
    cd[n - 1] = '\0';         // ����������λ��ű��룬���ȴ�ű��������
    for (i = 1; i <= n; i++)  // ��n��Ҷ�ӽ���Ӧ�Ĺ���������
    {
        start = n - 1;        // ��ʼ��������ʼָ��
        for (c = i, p = ht[i].parent; p != 0; c = p, p = ht[p].parent) // ��Ҷ�ӵ�����������
            cd[--start] = ((ht[p].LChild == c) ? '0' : '1'); // ���֧��0���ҷ�֧��1
        hc[i] = (char*)malloc((n - start) * sizeof(char));      // Ϊ��i���������ռ�
        strcpy(hc[i], &cd[start]);
    }
    free(cd);
}

int main()
{
    HuffmanTree HT;  HuffmanCode HC;
    int i, n, m;  
    int* w;

    // ����Ҷ�ӽ������Ȩ��
    printf("Input the number of total leaves of Huffman Tree:");
    scanf("%d", &n);  
    m = 2 * n - 1;

    // 0�ŵ�Ԫ��δʹ��
    HT = (HTNode*)malloc((m + 1) * sizeof(HTNode));
    HC = (char**)malloc((n+1) * sizeof(char*));
    w = (int*)malloc((n + 1) * sizeof(int));

    for (i = 1; i <= n; i++)
    {
        printf("Input the %d element's weight:", i);
        scanf("%d", &w[i]);  // ��������5 7 3 2 8
    }

    // ���ɹ������������
    CrtHuffmanTree(HT, w, n);
    for (i = 1; i <= m; i++)
    {
        printf("\n%5d%5d%5d%5d", HT[i].weight, HT[i].parent, HT[i].LChild, HT[i].RChild);
    }
    printf("\n\n");

    // ���������������
    PreOrderHuffman(HT, m);  
    printf("\n\n");

    // ���ɹ��������벢���
    CrtHuffmanCode(HT, HC, n);
    for (i = 1; i <= n; i++)
    {
        printf("%d����Ϊ%s\n", HT[i].weight, HC[i]);
    }

    getchar();  getchar();
    return 0;
}