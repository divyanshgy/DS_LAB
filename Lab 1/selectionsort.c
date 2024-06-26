#include<stdio.h>
int main(){
int size,min,temp,i,j,k,arr[5];
size=5;
printf("Enter numbers:");
for(i=0;i<size;i++){
    scanf("%d",&arr[i]);
}
for(k=0;k<size-1;k++){
    min=arr[k];
    for(j=k+1;j<size;j++){
        if(arr[j]<arr[min]){
            temp=arr[j];
            arr[j]=arr[min];
            arr[min]=temp;
        }
    }
}
for(i=0;i<size;i++)
    printf("%d\t",arr[i]);
return 0;
}
