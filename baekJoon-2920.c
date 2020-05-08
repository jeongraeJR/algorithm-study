#include <stdio.h>
#include <string.h>

int main() {
    int arr[8] = {0,};
    int ascFlag = 1;
    int descFlag = 1;
    char cType[11] = "";

    for(int i=0; i<8; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=1; i<8; i++){
        if(arr[i] > arr[i-1] ){
            descFlag = 0;
        } else if(arr[i] < arr[i-1]) {
            ascFlag = 0 ;
        }
    }
    
    if(ascFlag == 1) {
        strcpy(cType, "ascending");
    }
    else if(descFlag == 1) {
        strcpy(cType,"descending");
    }
    else {
        strcpy(cType, "mixed");
    }
    printf("%s", cType);
    return 0;
}