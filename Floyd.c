#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#pragma warning (disable :4996)

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];         // ǥ���� �迭 ����

void printA(GraphType* g);
void floyd(GraphType* g);

int main(void)
{

	GraphType g = { 7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF,},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF,},
	{INF,INF,INF,4,5,INF,0}}
	};
	floyd(&g);    // �Լ��� ��
	
	return 0;
}

void printA(GraphType* g)
{
	int i, j;
	printf("==========================\n");
	for (i = 0; i < g->n; i++)   // ������� ���� ��ŭ for���� ������.
	{
		for (j = 0; j < g->n; j++)   // ������� ���� ��ŭ for���� ������.
		{
			if (A[i][j] == INF)    // ���� INF ���� �Ǿ������� *�� ǥ���Ѵ�.
				printf(" * ");
			else              // �׷��� ������ ��� �ִ� ���� ǥ���Ѵ�.
				printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("==========================\n");
}

void floyd(GraphType* g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)   // ��� ������ ���� ��ŭ for��
	{
		for (j = 0; j < g->n; j++) // 2���� �迭�� ��������� ��� ���� �ִ� �Ÿ��̹Ƿ� 2���� for���� ���� ǥ���Ѵ�.
		{
			A[i][j] = g->weight[i][j];   // ���� 2������ �ִ� �׷����� A�� �ű��.
		}
	}
	printA(g);  // ��� �Լ��� 
	
	// ��� ���� ���鼭 �˻��Ѵ�.
	for (k = 0; k < g->n; k++)
	{
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (A[i][k] + A[k][j] < A[i][j])  //  ���� ������ �ִ� ����ġ���� ���� �ϳ��� ������ ������ ����ġ�� �� ������
					A[i][j] = A[i][k] + A[k][j];   // ���� ������ �ִ� ����ġ�� ����� �����ϳ��� ������ ������ ����ġ�� �ִ´�.
			}   // ��, ���� �ϳ��� ������ �� ����ġ�� �� ª���� �� ����ġ�� �迭A�� �ִ´�.
		}
		printA(g);  // �׷��� ����Ѵ�.
	}
}