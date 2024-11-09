#include <stdio.h>
#include <stdlib.h>

int mode_find(int num[],int size);

int main()
{
	int num[10];
	char filename[100];
	int count=0;
	FILE *file;
	file=fopen("numbers.txt","r");

	// Custom way to open file
	// printf("Enter filename :\n");
	// scanf("%s", filename);
	// file=fopen(filename,"r");

	if(file==NULL)
	{
		printf("File not Found\n");
		return 1;
	}

	else
	{
		printf("File found\n");
	}

	while(fscanf(file,"%d",&num[count])!=EOF)
	{
		count++;
	}

	int mode = mode_find(num, count);
	printf("Mode of the numbers in the file = %d\n",mode);

	fclose(file);

	return 0;
}

int mode_find(int num[], int size)
{
	int maxcount=0;
	int mode = num[0];

	for(int i=0;i<size;i++)
	{
		int count = 0;
		for (int j = 0; j < count; j++)
		{
			if(num[j]==num[i])
			{
				count++;
			}
		}
		if(count>maxcount)
		{
			maxcount=count;
			mode=num[i];
		}
	}
	return mode;
}