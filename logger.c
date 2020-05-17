#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char *stack, int value, int *top){
    stack[++*top] = value;
}

char pop(char *stack, int *top) {
    if(*top == -1) exit(0);
    return stack[(*top)--];
}


int main(){
    int left_top = -1;
    int right_top = -1;
   
    char *data =  (char*)malloc(sizeof(char) * 1000000);

    scanf("%s",data);

    char *left_stack = (char*)malloc(sizeof(char) * strlen(data));
    char *right_stack = (char*)malloc(sizeof(char) * strlen(data));

    for(int i=0; i<strlen(data); i++){
        if(data[i]=='-')
        {
            if(left_top!=-1){
                pop(left_stack, &left_top);
            }
        }
        else if(data[i]=='<')
        {   
           
            if(left_top!=-1){
                push(right_stack, pop(left_stack, &left_top), &right_top);
            }
            
        }
        else if(data[i]=='>' )
        {
            if(right_top!=-1){
                push(left_stack, pop(right_stack, &right_top), &left_top);
            }
        }
        else {
            push(left_stack, data[i], &left_top);
        }

    }
 
    for(int i=0; i<=left_top; i++)
    {
        printf("%c",left_stack[i]);
    }

    for(int i=right_top; i>=0; i--)
    {
        printf("%c",right_stack[i]);
    }
    return 0;
}