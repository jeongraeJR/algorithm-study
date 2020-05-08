#include <stdio.h>
#include <stdlib.h>

int main() {
    int count;
    int number;
    int max = -1;
    scanf("%d %d", &count, &number);
    
    int *arr = (int*)malloc(sizeof(int)*count);

    for(int i=0; i<count; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<count; i++){
        for(int j=i+1; j<count; j++){
            for(int k=j+1; k<count; k++){
                int temp = arr[i] + arr[j] + arr[k];
                if(temp > max && temp <= number){
                    max = temp;
                }
            }
        }
    }

    printf("%d",max);

    free(arr);
}