#include <stdio.h>

# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

int up(int idx, int* ary);
int max(int len, int* ary);
int down(int idx, int* ary, int len);


int main()
{
	int ary[10] = { 2,1,4,7,3,5,10,8,6,9 };
	int i, j, k;
	
	int temp;
	int idx =0;
	
	int len = sizeof(ary) / sizeof(ary[0]) ;
	
	// printf("정렬전\n");
	for (i = 0; i < len; i++)
		printf("%d, ", ary[i]);
	printf("\n");
	k = 1;

	for (i = len; i >0; i--)
	{
		idx = max(i, ary);
		up(idx, ary);
		down(idx, ary, i);
		
		// printf("%d 번 정렬\n", k);
		k++;
		for (j = 0; j < len; j++)
		{
			printf("%d, ", ary[j]);
		}

		printf("\n\n");

	}
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

int up(int idx,int* ary)
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