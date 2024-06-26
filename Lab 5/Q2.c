#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define max 100

int stack[max];
int top = -1;
void push(int item) {
    if(top>=max-1){
printf("Stack Overflow");
    }
    else{
    top++;
    stack[top] = item;
    }
}
int pop() {
    if (top < 0) {
printf("Stack Underflow\n");
    }
    else{
    int item = stack[top];
    top--;
    return item;
    }
}
int isopr(char opr) {
    if (opr=='+' || opr=='-' || opr=='*' || opr=='/'||opr=='^') {
        return 1;
    }
    return 0;
}
int evaluate(char* expression) {
    int i=0;
    char symbol=expression[i];
    int operand1,operand2,result;
    while(symbol!='\0'){
        if(symbol>='0' && symbol<='9'){
            int num=symbol-'0';
            push(num);
        }
        else if(isopr(symbol)) {
            operand2 = pop();
            operand1 = pop();
            switch(symbol){
                case '+':
                    result=operand1+operand2;
                    break;
                case '-':
                    result=operand1-operand2;
                    break;
                case '*':
                    result=operand1*operand2;
                    break;
                case '/':
                    result=operand1/operand2;
                    break;
                case '^':
                    result=pow(operand1,operand2);
            }
            push(result);
        }
        i++;
        symbol = expression[i];
    }
    result=pop();
    return result;
}

int main(){
    char expression[max];
    printf("Enter the equation:");
    gets(expression);
    int result=evaluate(expression);
printf("Result= %d\n",result);
return 0;
}
