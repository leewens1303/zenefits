#include <stdio.h>
#include <string.h>

int getSmallerInRight(char* str, int l, int h)
{
	int count_Right = 0, i;

	for (i = l+1; i <= h; ++i)
		if (str[i] < str[l])
			++count_Right;

	return count_Right;
}

int fact(int n)
{
	return (n <= 1)? 1 :n * fact(n-1);
}

int get_Rank (char* str)
{
	int len = strlen(str);
	int mul = fact(len);
	int rank = 1;
	int count_Right;

	int i;
	for (i = 0; i < len; ++i)
	{
		mul /= len - i;

		count_Right = getSmallerInRight(str, i, len-1);

		rank += count_Right * mul ;
	}

	return rank;
}

//main function
int main()
{
	char str[] = "arc";
	printf ("%d", get_Rank(str));
	return 0;
}

