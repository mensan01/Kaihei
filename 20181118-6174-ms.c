//这条注释用于GitHub测试
#include <stdio.h>
void convert(int input, int *a, int *b);

int main()
{
	int test[1000];
	int i = 0, j = 0;
	int a, b, temp;

	scanf("%d", test);
	printf("%d", test[0]);
	while(i < 1000)
	{
		convert(test[i], &a, &b);
		test[++i] = b - a;
		for (j = 0; j < i; j++)
		{
			if (test[j] == test[i])
			{
				printf("->%d", test[i]);
				return 0;
			}	
		}
		printf("->%d", test[i]);
	}
	return 0;
}

void convert(int input, int *a, int *b)
{
	int bit[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i, j;
	int output = 0;

	while (input != 0)
	{
		bit[input % 10]++;
		input = input / 10;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = bit[i]; j > 0; j--)
		{
			output = output * 10;
			output += i;
		}
	}
	*a = output;
	output = 0;
	for (i = 9; i >= 0; i--)
	{
		for (j = bit[i]; j > 0; j--)
		{
			output = output * 10;
			output += i;
		}
	}
	*b = output;
}
