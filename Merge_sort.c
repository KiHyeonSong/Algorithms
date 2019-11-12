#include <stdio.h>

#define MAX_SIZE 10

int sort[MAX_SIZE];

void merge(int* ary, int middle, int m, int n);
void merge_sort(int* ary, int m, int n);;

int main() {
	int ary[MAX_SIZE] = { 2,1,4,7,3,5,9,8,6,10 };
	
	int i;
	
	printf("합병정렬 전\n");
	for (i = 0; i < MAX_SIZE; i++) {
		printf("%d ", ary[i]);
	}

	merge_sort(ary, 0, MAX_SIZE - 1);

	printf("\n합병정렬 후\n");

	for (i = 0; i < MAX_SIZE; i++) {
		printf("%d ", ary[i]);
	}
	return 0;

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
	if(m < n)
	{
		int middle = (m + n) / 2;
		merge_sort(ary, m, middle);
		merge_sort(ary, middle + 1, n);
		merge(ary, m, middle, n);
	}
}