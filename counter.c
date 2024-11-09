#include <stdio.h>

void insert(int arr[], int n){
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	int arr1[n];
	int arr2[2][n];
	printf("Enter the elements: ");
	insert(arr1,n);
	for(int i = 0; i<n; i++){
		int count = 0;
		for (int j = i+1; j < n; j++)
		{
			if(arr1[i]==arr1[j]){
				count++;
			}
			
		}
		arr2[0][i]=arr1[i];
		arr2[1][i]=count;

	}
	return 0;
}