#include<stdio.h>
int main(){
int i=0,j=0,a=0;
char str1[50],str2[50];
printf("Enter a string:");
gets(str1);
printf("Enter a string:");
gets(str2);
while((str2[i]!= '\0')|| (str1[i] != '\0')){
    a=1;
    if(str1[i]!=str2[i]){
        printf("Strings arent equal");
        a=0;
        break;
        }
        i++;
}

if(a==1){
    printf("Strings are equal");
}
}
