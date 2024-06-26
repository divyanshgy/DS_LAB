#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 100
char stack[100];
int top=-1;
void push(char a){
int len=0;
if(top==MAX_SIZE-1){
printf("Stack overflow");
}
else{
        top=top+1;
        stack[top]=a;
}
}
char pop(char s[]){
int j=0;
if(top==-1){
    printf("Stack underflow");}
    else{
        for(int i=top;i>=0;--i){
            printf("%c",stack[i]);
            s[j]=stack[i];
            j++;
        }
    }
}
int main()
{
 char arr[100],arr2[100];
 int len,key=1;
 printf("Enter string:");
 gets(arr);
 len=strlen(arr);
 for(int i=0;i<len;i++){
    push(arr[i]);
 }
pop(arr2);
for(int k=0;k<len;k++){
    if(arr[k]!=arr2[k]){
        key=0;
        break;
    }
}
if(key==0)
    printf("\nIts not a palindrome");
else
    printf("\nIts a palindrome");
return 0;
}

