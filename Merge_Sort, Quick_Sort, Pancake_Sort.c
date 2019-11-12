#include <stdio.h>
#pragma warning (disable:4996)
#define MAX_SIZE 10
int sort[MAX_SIZE];
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int up(int idx, int* ary);
int max(int len, int* ary);
int down(int idx, int* ary, int len);
void merge_sort(int* ary, int m, int n);
void merge(int* ary, int m, int middle, int n);
void quick_sort(int* ary, int first, int last);


int main()
{
	int ary[MAX_SIZE] = { 2,1,4,7,3,5,10,8,6,9 };
	int i, j, k;

	int temp;
	int idx = 0;

	int len = sizeof(ary) / sizeof(ary[0]);
	//printf("%d\n", len); 
	int num;

	printf("1. merge_sort, 2. quick_sort, 3. Pencake \n :");
	scanf("%d", &num);

	k = 1;
	if (num == 1)
	{
		//printf("병합 정렬 전\n");
		for (i = 0; i < MAX_SIZE; i++) {
			printf("%d ", ary[i]);
		}

		merge_sort(ary, 0, MAX_SIZE - 1);

		//printf("\n병합 정렬 후\n");

		for (i = 0; i < MAX_SIZE; i++) {
			printf("%d ", ary[i]);
		}
	}
	else if (num == 2)
	{
		//printf("정렬 전\n");
		for (i = 0; i < MAX_SIZE; i++) {
			printf("%d  ", ary[i]);
		}
		printf("\n");

		quick_sort(ary, 0, MAX_SIZE - 1);

		//printf("정렬 후\n");
		for (i = 0; i < MAX_SIZE; i++) {
			printf("%d  ", ary[i]);	
		}
		printf("\n");
	}
	else if (num == 3)
	{
		for (i = len; i > 0; i--)
		{
			idx = max(i, ary);
			up(idx, ary);
			down(idx, ary, i);

			//printf("%d 번 정렬\n", k);
			k++;
			for (j = 0; j < len; j++)
			{
				printf("%d, ", ary[j]);
			}

			printf("\n\n");

		}
	}
	else
		// printf("제대로 입력하세요\n");
	
	return 0;
}

int max(int len, int* ary)
{
	int max = 0;
	int i;
	int maxidx;
	for (i = 0; i < len; i++)
	{
		if (max < ary[i])
		{
			max = ary[i];
			maxidx = i;
		}
	}
	return maxidx;
}

int up(int idx, int* ary)
{
	int i, j;
	int temp;

	for (i = 0; i < idx / 2 + 1; i++)
	{
		j = idx;
		SWAP(ary[i], ary[j - i], temp);
	}

}
int down(int idx, int* ary, int len)
{
	int i, j;
	int temp;
	for (i = 0; i < len / 2; i++)
	{
		j = len - 1;
		SWAP(ary[i], ary[j - i], temp);
	}

}

void merge(int* ary, int m, int middle, int n)
{
	int i = m;
	int j = m;
	int k = middle + 1;

	while (i <= middle && k <= n)
	{
		if (ary[i] <= ary[k])
		{
			sort[j] = ary[i];
			i++;
		}
		else
		{
			sort[j] = ary[k];
			k++;
		}
		j++;
	}


	if (i > middle)
	{
		for (int t = k; t <= n; t++)
		{
			sort[j] = ary[t];
			j++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sort[j] = ary[t];
			j++;
		}
	}


	for (int t = m; t <= n; t++)
	{
		ary[t] = sort[t];
	}
}

void merge_sort(int* ary, int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		merge_sort(ary, m, middle);
		merge_sort(ary, middle + 1, n);
		merge(ary, m, middle, n);
	}
}

void quick_sort(int* ary, int first, int last)
{
	if (first >= last)
	{
		return;
	}

	int key = first;
	int i = first + 1;
	int j = last;
	int temp;

	while (i <= j)
	{
		while (i <= last && ary[i] <= ary[key])
		{
			i++;
		}
		while (j > first && ary[j] >= ary[key])
		{
			j--;
		}
		if (i > j)
		{
			SWAP(ary[j], ary[key], temp);
		}
		else {
			SWAP(ary[i], ary[j], temp);
		}
		quick_sort(ary, first, j - 1);
		quick_sort(ary, j + 1, last);
	}
}