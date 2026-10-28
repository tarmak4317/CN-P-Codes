#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int n, x;
	printf("\nEnter number of frames to be sent:");
	scanf("%d", &n);
	for(int i = 0;i < n;i++)
	{
		printf("\nTransmitting frame:%d", i + 1);
		x = rand() % 15;
		if(x % 5 == 0)
		{
			printf("\nWaiting for acknowledgement");
			sleep(1);
			printf("\nRetransmitting frame:%d", i);
		}
		printf("\nAcknowledgement for frame %d received", i + 1);
	}
	printf("\nEnd of stop and wait protocol");
	return 0;
}
