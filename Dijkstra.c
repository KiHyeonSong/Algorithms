#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#pragma warning (disable :4996)

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000



typedef struct GraphType {
	int n;  // ���� ����� ����
	int weight[MAX_VERTICES][MAX_VERTICES];  // ����ġ ǥ��
} GraphType;

int distance[MAX_VERTICES];    // �ִ� �Ÿ� ǥ��
int found[MAX_VERTICES];       // �鸰 �� ǥ��

int choose(int distance[], int n, int found[]);  // �Լ� ����
void print_status(GraphType* g);				 // �Լ� ����
void shortest_path(GraphType* g, int start);     // �Լ� ����

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
	};                             // �ʱⰪ ǥ��


	shortest_path(&g, 0);           // �Լ��� �׷��� �ּҶ� ���� �� ���� ǥ���ؼ� �Ѱ��ش�.
	return 0;
}

int choose(int distance[], int n, int found[])
{
	
	int min, minpos;
	min = INT_MAX;    // int �ִ� �� ����
	minpos = -1;  
	for (int i = 0; i < n; i++)    // ���� ������ŭ for�� ����
		if (distance[i] < min && !found[i])  
			// ���� distance�� ���� ó������ ���Ѱ�, ���߿��� ���� ����ġ���� ������ �׸���
			// found �ִܰ�θ� ���� ã�� ���ߴٸ� �� �� ������ �����ϸ� if���� ���´�.
		{
			min = distance[i];    //ã�� ����ġ�� �� ������ min�� ����
			minpos = i;             // ������ i ����
		}
	return minpos;
}

void print_status(GraphType* g)          
{
	static int step = 1;               
	printf("STEP %d: ", step++);   // ������ ǥ���ϱ� ����
	printf("distance: ");
	for (int i = 0; i < g->n; i++)     // ����� ������ŭ for��
	{
		if (distance[i] == INF)      // ����ġ�� ���� ��û���� �涧 * �� ǥ�����ش�.
		{
			printf(" * ");
		}
		else
		{
			printf("%2d ", distance[i]);   // �׷��� ������ distance�� ����Ǿ��ִ� ����ġ ǥ��
		}
			
	}
	printf("\n");
	printf(" found: ");    // ���� �ִ� ��� ã�°��� ǥ���ϱ�
	for (int i = 0; i < g->n; i++)
	{
		printf("%2d ", found[i]);     // ���� ã�� �ִ� ��δ� ǥ���ϱ�
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start)   // �׷����� ������ �κ� ���� ��
{
	int i, u, w;
	for (i = 0; i < g->n; i++)  // ����(0) �κ� ���� ����� ���� for��
	{
		distance[i] = g->weight[start][i];   // 0���� 0���� ����ġ�� distance�� �����Ѵ�. ����ġ ����
		found[i] = FALSE;                    // found �迭 0���� �ʱ�ȭ
	}
	found[start] = TRUE;                  // 0���� 0���� ��δ� ã�ұ⶧���� 1�� ǥ�����ش�.
	distance[start] = 0;                  // 0���� 0���� ��δ� ����ġ�� 0�̱� ������ 0�� �־��ش�.
	for (i = 0; i < g->n-1; i++)       // �����ϴ� �κ��� �����ϰ� �˻�
	{
		print_status(g);                 // �Լ��� �׷����� �Ѱ��ش�.
		u = choose(distance, g->n, found);   // choose �Լ��� ���� �ִܰ�ΰ� ����Ǿ��ִ� �迭, ���� �ִ� ��� ã�� �迭 ������
		found[u] = TRUE;            // ���� ���� �ε���u �迭�� �ִ� ��θ� ã�ұ⿡ ǥ�����ش�.
		for (w = 0; w < g->n; w++)
			if (!found[w])           //ã�� ���Ѱ� �ִٸ�
				if (distance[u] + g->weight[u][w] < distance[w]) //distance[w]�� ����� ����ġ ���� distance[u]�� weight������� ����ġ ������ ũ��
					distance[w] = distance[u] + g->weight[u][w]; // �� ���� ���� �־��ش�. ��, �ִ� �Ÿ��� �־��ش�.
	}
}