#include<stdio.h>
int main(){
int arr[5],num,i,flag=0,fi,high=5,low=0,mid;
printf("Enter the elements:");
for(i=0;i<5;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the element you want to find:");
scanf("%d",&num);
mid=(low+high)/2;
while(low<=high){
mid=(low+high)/2;
    if(num==arr[mid]){
    flag=1;
    break;
    //printf("found at %d",mid);
    }
    else if(num>arr[mid]){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
if(flag==0)
    printf("Didn't find %d",num);
    else if(flag==1)
    printf("Found %d",num);
return 0;
}

