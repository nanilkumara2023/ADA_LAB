#include<stdio.h>
#include<stdlib.h>
#define TSIZE 11
int h[TSIZE]={0};
void insert()
{
	int i,ind,key,hkey;
	printf("enter the key to be inserted\n");
	scanf("%d",&key);
	ind=key%TSIZE;
	for(i=0;i<TSIZE;i++)
	{
		hkey=(ind+i)%TSIZE;
		if(h[hkey]==0)
		{
			h[hkey]=key;
			break;
		}
		
	}
	if(i==TSIZE)
		printf("element cannot be inserted\n");
}
void search()
{
	int i,key,ind,hkey;
	printf("enter the element to be searched\n");
	scanf("%d",&key);
	ind=key%TSIZE;
	for(i=0;i<TSIZE;i++)
	{
		hkey=(ind+i)%TSIZE;
		if(h[hkey]==key)
		{
			printf("element is present at %d ",hkey);
			return;
		}
		if(i==TSIZE)
		{
			printf("Element not found\n");
		}
	}
}
void display()
{
	int i;
	for(i=0;i<TSIZE;i++)
	{
		printf("Element at index %d : %d\n",i,h[i]);
	}
}
void main()
{
	int c;
	while(1)
	{
		printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
		printf("Enter your choice :");
		scanf("%d",&c);
		switch(c)
		{
			case 1:insert();
					break;
			case 2:search();
					break;
			case 3:display();
					break;
			default:prinf("Invalid choice\n");
					exit(0);
		}
	}
}
