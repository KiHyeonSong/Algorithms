#include <stdio.h>

#define SWAP(X,Y,Z) ((Z) = (X) , (X) = (Y) ,(Y) = (Z))

int main(void)
{
	int i, j, index, temp, min;
	int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2 ,9 };
		
	for (i = 0; i < 10; i++)
	{
		min = 9999;
		for (j = i; j < 10; j++)
		{
			if (min > ary[j])
			{
				min = ary[j];
				index = j;
			}
		}
		SWAP(ary[i], ary[index], temp);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}
	return 0;
}