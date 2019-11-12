#include <stdio.h>

#define SWAP(X,Y,Z) ((Z) = (X) , (X) = (Y), (Y)=(Z))

int main(void) {
	int ary[10] = { 1,10,5,8,7,6,4,3,2,9 };
	int i, j, temp, index;

	// printf("버블 정렬 전\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}
	printf("\n");

	for (j = 9; j > 0; j--)
	{
		for (i = 0; i < j; i++)
		{
			if (ary[i] > ary[i + 1]) {
				SWAP(ary[i], ary[i + 1], temp);
			}
		}

	}
	// printf("버블 정렬 후\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ary[i]);
	}

	return 0;
}
