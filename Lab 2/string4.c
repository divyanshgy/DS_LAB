#include<stdio.h>
int main(){
char str1[50],str2[50],str3[50];
int i,n,len=0,len2=0,k=0,a=0;
printf("Enter main string");
gets(str1);
printf("Enter sub string");
gets(str2);
printf("Enter position:");
scanf("%d",&n);
i=0;
while(str1[i]!='\0'){
    len++;
    i++;
}
int j=0;
while(str2[j]!='\0'){
    len2++;
    j++;
}
i=0;
j=0;
for(i=0;i<n;i++){
    str3[i]=str1[i];
}
while(j<len2){
    str3[i]=str2[j];
    j++;
    i++;
}
while(a<len-n){
    str3[i]=str1[i-n];
    i++;
    a++;
}
puts(str3);
}

