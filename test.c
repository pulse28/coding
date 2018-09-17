#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * test_func(char* str)
{
	int n = strlen(str);
	printf("%d\n", n);
	char * res = (char*)malloc(sizeof(char)*n);
	int index=0;
	for(int i=0;i<n;i++)
	{
		res[i] = 0;
		if(str[i]<97)
		{
			res[index] = str[i];
			index++;
		}
	}
	return res;
}

int main()
{
	char str[10] = {"HeLlO"};
	//str = ;
	printf("%s\n", test_func(str));
	return 0;
}