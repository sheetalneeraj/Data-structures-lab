#include<stdio.h>
#include<string.h>
#define MAXADDR 100
struct emp
{
char empname[20];
int age;
int empid;
}ht[MAXADDR],temp;

int hash(int key)
{
int index;
index=(key)%MAXADDR;
return index;
}
void main()
{
int n,i,index,count;
FILE *fp;
printf("\nEnter  number of employees");
scanf("%d",&n);
 fp=fopen("source.txt","w");
for(i=0;i<n;i++)
{
printf("\n Enter employee name");
//fflush(stdin);
scanf("%s",temp.empname);
printf("\nEnter employee id");
scanf("%d",&temp.empid);
printf("Enter employee age");
scanf("%d",&temp.age);
fprintf(fp,"%d\t%d\t%s\n",temp.empid,temp.age,temp.empname);
}
fclose(fp);
for(i=0;i<n;i++)
{
ht[i].empid=-1;
}
 count=0;
fp=fopen("source.txt","r");
while(fscanf(fp,"%d%d%s",&temp.empid,&temp.age,temp.empname)!=EOF)
{
if(count==MAXADDR)
{
printf("No space ");
break;
}
index=hash(temp.empid);
if(ht[index].empid==-1)
{
ht[index].empid=temp.empid;
ht[index].age=temp.age;
strcpy(ht[index].empname,temp.empname);
count=count+1;
}
else
{printf("\nCOLLISSION FOUND");
for(i=0;i<MAXADDR;i++)
{
index=(hash(temp.empid)+i)%MAXADDR;
if(ht[index].empid==-1)
{
ht[index].empid=temp.empid;
ht[index].age=temp.age;
strcpy(ht[index].empname,temp.empname);
count=count+1;
printf("\nCOLLISION RESOLVED FOR %d",temp.empid);
break;
}
}
}
}
fclose(fp);

printf("\nHA\tEmpid\tAge\t Employee name");
for(i=0;i<n;i++)
{
if(ht[i].empid!=-1)
printf("\n%d\t%d\t%d\t%s\n",i,ht[i].empid,ht[i].age,ht[i].empname);
}
}
