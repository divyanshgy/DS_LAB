#include<stdio.h>
int main(){
int arr[5],left,right,temp,i=0,j=0,n=5;
printf("Enter 5 elements");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
for(i=0;i<n;i++){
    printf("%d\t",arr[i]);
}
}
