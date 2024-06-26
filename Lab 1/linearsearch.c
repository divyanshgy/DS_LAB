#include<stdio.h>
int main(){
int arr[10],num,i,flag=0,fi;
printf("Enter the elements:");
for(i=0;i<10;i++){
    scanf("%d",&arr[i]);
}
printf("Enter the element you want to find:");
scanf("%d",&num);
for(i=0;i<10;i++){
    if(num==arr[i]){
     flag=1;
     fi=arr[i];
    }
}
if(flag==1){
    printf("found %d",fi);
}
else{
    printf("Didn't find %d",num);
}
return 0;
}
