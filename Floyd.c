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

int A[MAX_VERTICES][MAX_VERTICES];         // 표시할 배열 선언

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
	floyd(&g);    // 함수로 ㄱ
	
	return 0;
}

void printA(GraphType* g)
{
	int i, j;
	printf("==========================\n");
	for (i = 0; i < g->n; i++)   // 모든점의 개수 만큼 for문을 돌린다.
	{
		for (j = 0; j < g->n; j++)   // 모든점의 개수 만큼 for문을 돌린다.
		{
			if (A[i][j] == INF)    // 만약 INF 저장 되어있으면 *로 표시한다.
				printf(" * ");
			else              // 그렇지 않으면 들어 있는 값을 표시한다.
				printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("==========================\n");
}

void floyd(GraphType* g)
{
	int i, j, k;
	for (i = 0; i < g->n; i++)   // 모든 정점의 개수 만큼 for문
	{
		for (j = 0; j < g->n; j++) // 2차원 배열로 모든점에서 모든 점의 최단 거리이므로 2차원 for문을 통해 표시한다.
		{
			A[i][j] = g->weight[i][j];   // 현재 2차원에 있는 그래프를 A로 옮긴다.
		}
	}
	printA(g);  // 출력 함수로 
	
	// 모든 점을 돌면서 검사한다.
	for (k = 0; k < g->n; k++)
	{
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (A[i][k] + A[k][j] < A[i][j])  //  현재 가지고 있는 가중치보다 정점 하나를 지나쳐 갈때의 가중치가 더 작을시
					A[i][j] = A[i][k] + A[k][j];   // 현재 가지고 있는 가중치를 지우고 정점하나를 지나쳐 갈때의 가중치를 넣는다.
			}   // 즉, 정점 하나를 지나갈 때 가중치가 더 짧으면 그 가중치를 배열A에 넣는다.
		}
		printA(g);  // 그러고 출력한다.
	}
}