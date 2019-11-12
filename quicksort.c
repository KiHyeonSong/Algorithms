# include <stdio.h>
# define MAX_SIZE 10
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

void quick_sort(int* ary, int first, int last);

void main() {
	int i;
	int ary[MAX_SIZE] = { 2,1,4,7,3,5,9,8,6,10};

	printf("정렬 전\n");
	for (i = 0; i < MAX_SIZE; i++) {
		printf("%d  ", ary[i]);
	}
	printf("\n");

	quick_sort(ary, 0, MAX_SIZE - 1);
	
	printf("정렬 후\n");
	for (i = 0; i < MAX_SIZE; i++) {
		printf("%d  ", ary[i]);
	}
	printf("\n");

	
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