#include<stdio.h>
int main(){
int i=0;
char str1[100],str2[100];
printf("Enter first sting:");
gets(str1);
printf("Enter second sting:");
gets(str2);
while(str1[i]!='\0'){
    i++;
}
int j=0;
while(str2[j]!='\0'){
    str1[i]=str2[j];
    j++;
    i++;
}
str1[i]='\0';
puts(str1);
return 0;
}
