#include <stdio.h>
#include <stdlib.h>

int top = -1;

void push(int *stack, int value){
    stack[++top] = value;
}

void pop(int *stack) {
    stack[top--] = -1;
}

int main() {
    int size;
    int isEnable = 1;
    int count = 1;
    int resultCounter = 0;
    scanf("%d", &size);
    
    int *arr = (int*)malloc(sizeof(int) * size);
    int *stack = (int*)malloc(sizeof(int) * 100000);
    char *result = (char*)malloc(sizeof(char) * 100000); 


    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<size; i++) {
        while(count <= arr[i]) {
            push(stack, count);
            result[resultCounter++] = '+';  
            count++;
        }
        if(arr[i] == stack[top]) {
            pop(stack);
            result[resultCounter++] = '-';
        }
        else {
            isEnable = 0;
            break;
        }
    }

    if(isEnable == 1) {
        result[resultCounter] = '\0';
        printf("%s", result); 
    }
    else {
        printf("NO");
    }
  

    free(arr);
    free(stack);
    free(result);
    return 0;
}
