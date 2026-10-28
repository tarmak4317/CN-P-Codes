#include <stdio.h>
#include <string.h>

int main()
{
	char a[100], b[100];
	int n, k = 0;
	printf("\nEnter string:");
	scanf("%s", a);
	n = strlen(a);
	b[k++] = 'd';
	b[k++] = 'l';
	b[k++] = 'e';
	b[k++] = 's';
	b[k++] = 't';
	b[k++] = 'x';
	for(int i = 0;i < n;i++)
	{
		b[k++] = a[i];
	}
	b[k++] = 'd';
	b[k++] = 'l';
	b[k++] = 'e';
	b[k++] = 'e';
	b[k++] = 't';
	b[k++] = 'x';
	b[k] = '\0';
	printf("\nFrame after character stuffing:%s", b);
}
