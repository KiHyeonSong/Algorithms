#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#pragma warning (disable :4996)

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000



typedef struct GraphType {
	int n;  // 정점 노드의 갯수
	int weight[MAX_VERTICES][MAX_VERTICES];  // 가중치 표시
} GraphType;

int distance[MAX_VERTICES];    // 최단 거리 표시
int found[MAX_VERTICES];       // 들린 곳 표시

int choose(int distance[], int n, int found[]);  // 함수 정의
void print_status(GraphType* g);				 // 함수 정의
void shortest_path(GraphType* g, int start);     // 함수 정의

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
	};                             // 초기값 표시


	shortest_path(&g, 0);           // 함수에 그래프 주소랑 시작 할 번지 표시해서 넘겨준다.
	return 0;
}

int choose(int distance[], int n, int found[])
{
	
	int min, minpos;
	min = INT_MAX;    // int 최대 수 저장
	minpos = -1;  
	for (int i = 0; i < n; i++)    // 정점 개수만큼 for문 실행
		if (distance[i] < min && !found[i])  
			// 만약 distance의 값이 처음에는 무한값, 나중에는 현재 가중치보다 작으면 그리고
			// found 최단경로를 아직 찾기 못했다면 이 두 조건이 만족하면 if문이 들어온다.
		{
			min = distance[i];    //찾은 가중치가 더 작으면 min에 저장
			minpos = i;             // 리턴할 i 저장
		}
	return minpos;
}

void print_status(GraphType* g)          
{
	static int step = 1;               
	printf("STEP %d: ", step++);   // 스탭을 표시하기 위함
	printf("distance: ");
	for (int i = 0; i < g->n; i++)     // 노드의 개수만큼 for문
	{
		if (distance[i] == INF)      // 가중치가 무한 엄청나게 길때 * 로 표시해준다.
		{
			printf(" * ");
		}
		else
		{
			printf("%2d ", distance[i]);   // 그렇지 않으면 distance에 저장되어있는 가중치 표시
		}
			
	}
	printf("\n");
	printf(" found: ");    // 현재 최단 경로 찾는것은 표시하기
	for (int i = 0; i < g->n; i++)
	{
		printf("%2d ", found[i]);     // 현재 찾은 최단 경로는 표시하기
	}
	printf("\n\n");
}

void shortest_path(GraphType* g, int start)   // 그래프랑 시작한 부분 받은 후
{
	int i, u, w;
	for (i = 0; i < g->n; i++)  // 시작(0) 부분 부터 모든점 까지 for문
	{
		distance[i] = g->weight[start][i];   // 0에서 0가는 가중치를 distance에 저장한다. 가중치 저장
		found[i] = FALSE;                    // found 배열 0으로 초기화
	}
	found[start] = TRUE;                  // 0에서 0가는 경로는 찾았기때문에 1로 표시해준다.
	distance[start] = 0;                  // 0에서 0가는 경로는 가중치가 0이기 때문에 0을 넣어준다.
	for (i = 0; i < g->n-1; i++)       // 시작하는 부분을 제외하고 검색
	{
		print_status(g);                 // 함수로 그래프를 넘겨준다.
		u = choose(distance, g->n, found);   // choose 함수에 현재 최단경로가 저장되어있는 배열, 현재 최단 경로 찾은 배열 보내기
		found[u] = TRUE;            // 리턴 받은 인덱스u 배열은 최단 경로를 찾았기에 표시해준다.
		for (w = 0; w < g->n; w++)
			if (!found[w])           //찾기 못한게 있다면
				if (distance[u] + g->weight[u][w] < distance[w]) //distance[w]에 저장된 가중치 값이 distance[u]랑 weight에저장된 가중치 값보다 크면
					distance[w] = distance[u] + g->weight[u][w]; // 더 작은 값을 넣어준다. 즉, 최단 거리로 넣어준다.
	}
}