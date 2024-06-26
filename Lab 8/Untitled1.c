#include<stdio.h>
#include<stdlib.h>
struct node{
struct node* leftlink;
int data;
struct node *rightlink;
};
typedef struct node* NODE;


int main(){
    int n;
    printf("i.) Insert an element at the rear end of the list\nii.) Delete an element from the rear end of the list\niii.) Insert an element at a given position of the list\niv.) Delete an element from a given position of the list\nv.) Insert an element after another element\nvi.) Insert an element before another element/nvii.) Traverse the list\nviii.)Reverse the list");
    scanf("%d",&n);
    switch(n){
    case 1:
    }
    return 0;
}
