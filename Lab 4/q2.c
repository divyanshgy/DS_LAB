#include<stdio.h>
#define MAX 20
int main()
{
int b1[MAX][3],b2[MAX][3],m,n,i,j,t,Q;
printf("Enter the size of matrix (rows,columns):");
scanf("%d%d",&m,&n);
b1[0][0]=m;
b1[0][1]=n;
printf("\nEnter no. of non-zero elements:");
scanf("%d",&t);
b1[0][2]=t;
for(i=1;i<=t;i++)
{
printf("\nEnter the next(row,column,value):");
scanf("%d%d%d",&b1[i][0],&b1[i][1],&b1[i][2]);
}

b2[0][0]=b1[0][1];
b2[0][1]=b1[0][0];
b2[0][2]=b1[0][2];
int k=1;
n=b1[0][2];
for(i=0;i<b1[0][1];i++)
for(j=1;j<=n;j++)
if(i==b1[j][1])
{
b2[k][0]=i;
b2[k][1]=b1[j][0];
b2[k][2]=b1[j][2];
k++;
}
Q=b2[0][2];
printf("\nAfter Transpose:");
printf("\nrow\t\tcolumn\t\tvalue");
for(i=0;i<=n;i++)
    printf("%d\t\t%d\t\t%d\n",b2[i][0],b2[i][1],b2[i][2]);
}

