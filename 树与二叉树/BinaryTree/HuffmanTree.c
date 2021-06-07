#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WEIGHT 100;
#define STR 10;

typedef struct
{
    char data;
    int weight;                // ������Ÿ�������Ȩֵ
    int parent, LChild, RChild; // ָ��˫�ס����ӽ���ָ��
}treeNode, * huffmanTree;      // ��̬�������飬�洢��������

typedef char** huffmanCode; // ��̬�������飬�洢����������

void selectMin(huffmanTree ht, int n, int* s1, int* s2)
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

void createHuffmanTree(huffmanTree ht, int weight[], int n)
{   int i, j, m, s1, s2;

    for (i = 0,j = 1; i < 128; i++)   // 1~n�ŵ�Ԫ���Ҷ�ӽ�㣬��ʼ��
    {
        if (weight[i] != 0) 
        {
            ht[j].data = i;
            ht[j].weight = weight[i];
            ht[j].parent = ht[j].LChild = ht[j].RChild = 0;
            j++;
        }
    }
    m = 2 * n - 1;
    for (i = n + 1; i <= m; i++) // n+1~m�ŵ�Ԫ��ŷ�Ҷ�ӽ�㣬��ʼ��
        ht[i].weight = ht[i].parent = ht[i].LChild = ht[i].RChild = 0;

    // ��ʼ����ϣ����´�����Ҷ�ӽ�㣬����������
    for (i = n + 1; i <= m; i++)
    {
        selectMin(ht, i - 1, &s1, &s2);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
        ht[s1].parent = ht[s2].parent = i;
        ht[i].LChild = s1;  
        ht[i].RChild = s2;
    }
}

void preOrder(huffmanTree HT, int m)
{   // ���������������
    if (m == 0)
        return;
    printf("%d  ", HT[m].weight);
    preOrder(HT, HT[m].LChild);
    preOrder(HT, HT[m].RChild);
}

void createHuffmanCode(huffmanTree ht, huffmanCode hc, int n)
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

void countFrequency(char string[], int weight[],int *n)
{
    int i;
    for ( i = 0; i < strlen(string); i++)
    {
        weight[string[i]]++;
    }
    for (i = 0; i < 128; i++)
    {
        if (weight[i] != 0)
        {
            (*n)++;
        }
    }
}

void decode(huffmanTree ht, huffmanCode hc, char string[],int n)
{
    char* c;
    int i, j, k = 0;
    c = (char*)malloc(strlen(string) * sizeof(char));
    for (i = 0; i < strlen(string); i++,k++)
    {
        c[k] = string[i];
        c[k + 1] = '\0';
        for (j = 1; j <= n; j++)
        {
            if (strcmp(c, hc[j]) == 0)
            {
                printf("%c", ht[j].data);
                k = -1;
                c[0] = '\0';
                break;
            }
        }
    }
}

int main()
{
    huffmanTree HT;  
    huffmanCode HC;
    int i, n=0, m;  
    char string[10];
    int weight[128] = {0};

    printf("������Ҫ������ַ�����");
    gets(string);

    countFrequency(string, weight, &n);
    m = 2 * n - 1;

    // 0�ŵ�Ԫ��δʹ��
    HT = (treeNode*)malloc((m + 1) * sizeof(treeNode));
    HC = (char**)malloc((n+1) * sizeof(char*));

    // ���ɹ������������
    createHuffmanTree(HT, weight, n);
    for (i = 1; i <= m; i++)
    {
        printf("\n%5d%5d%5d%5d", HT[i].weight, HT[i].parent, HT[i].LChild, HT[i].RChild);
    }
    printf("\n\n");

    // ���������������
    preOrder(HT, m);  
    printf("\n\n");

    // ���ɹ��������벢���
    createHuffmanCode(HT, HC, n);
    for (i = 1; i <= n; i++)
    {
        printf("%c����Ϊ%s\n", HT[i].data, HC[i]);
    }

    printf("������Ҫ������ַ�����");
    gets(string);
    decode(HT, HC, string, n);

    return 0;
}