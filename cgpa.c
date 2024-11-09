#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char name[20];
	char reg_no[10];
	float cgpa;
}Student;


void read_details(FILE *file, Student students[],int *count);
void sort_details_reg(Student students[], int count);
int search_details(Student students[],int count, const char *reg_no);
int main(int argc, char const *argv[])
{
	Student students[10];
	int count = 0;
	FILE *file;
	char reg_no[10];

	file=fopen("details.txt","r");

	if(file==NULL)
	{
		printf("File not found\n");
		return 1;
	}

	read_details(file, students, &count);
	fclose(file);

	sort_details_reg(students, count);

	printf("Sorted order:\n");
	for (int i = 0; i < count; i++)
	{
		printf("%s\t%s\t%.2f\n", students[i].reg_no, students[i].name, students[i].cgpa);
	}

	printf("Enter Reg no for details:");
	scanf("%s",reg_no);
	int index = search_details(students,count,reg_no);
	if (index!=-1)
	{
		printf("Student found!!\n");
		printf("Reg No: %s\nName: %s\nCGPA: %.2f\n", students[index].reg_no, students[index].name, students[index].cgpa);
	}
	else
	{
		printf("Not Found!!!\n");
	}
	return 0;
}

void read_details(FILE *file, Student students[], int *count)
{
	while(fscanf(file,"%10[^,],%20[^,],%f\n",students[*count].reg_no, students[*count].name, &students[*count].cgpa)!=EOF)
	{
		(*count)++;
	}
}

void sort_details_reg(Student students[], int count)
{
	for(int i = 0; i<count-1; i++)
	{
		for (int j = 0; j < count-i-1; j++)
		{
			if(strcmp(students[j].reg_no, students[j+1].reg_no)>0)
			{
				Student temp = students[j];
				students[j]=students[j+1];
				students[j+1]=temp;
			}
		}
	}
}
int search_details(Student students[],int count, const char *reg_no)
{
	int left = 0, right=count-1;
	while(left<=right)
	{
		int mid = left+(right-left)/2;
		int comp = strcmp(students[mid].reg_no,reg_no);
		if (comp==0)
		{
			return mid;
		}
		if (comp<0)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	return -1;
}