#include<stdio.h>
int main(){
int i,j,arr[5],key,temp;
printf("Enter 5 elements:");
for(i=0;i<5;i++){
    scanf("%d",&arr[i]);
}
for(int k=1;k<5;k++){
    key=arr[k];
    j=k-1;
    while(key<arr[j] && j>=0){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
for(int l=0;l<5;l++){
printf("%d\t",arr[l]);
}
}
