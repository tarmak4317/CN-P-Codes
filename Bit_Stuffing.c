#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[100], b[100];
	int n, count, k;
	printf("\nEnter string (1s and 0s only):");
	scanf("%s", a);
	n = strlen(a);
	count = 0;
	k = 0;
	for(int i = 0;i < n;i++)
	{
		if((a[i] != '1') && (a[i] != '0'))
		{
			printf("\nInvalid input");
			exit(0);
		}
		else if(a[i] == '1')
		{
			count++;
			b[k++] = '1';
			if(count == 5)
			{
				b[k++] = '0';
				count = 0;
			}
		}
		else
		{
			b[k++] = '0';
			count = 0;
		}
	}
	b[k] = '\0';
	printf("\nString length is:%d", n);
	printf("\nFrame after character stuffing is:%s", b);
	return 0;
}
