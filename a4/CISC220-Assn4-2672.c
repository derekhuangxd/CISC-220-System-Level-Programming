#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void swap(int *a, int *b)
{
   int t;
 
   t  = *b;
   *b = *a;
   *a = t;
}

int compare(int *a, int *b) {
    if(*a > *b) {
        return 1;
    }
    else {
        return 0;
    }
}

void main(){
    srand ( time(NULL) ); //for generating different random values each time
    //int * arr = malloc(7 * sizeof(int));
    int arr[7];
    for (int i=0; i<7; i++){
        arr[i] = (rand() % 99 + 1);
        printf("%d\t", arr[i]);
        if (i==6){
            printf("Randomly generated Array\n\n");
        }
    }
    
    int count=0;
    int i, j; 
    bool swapped; 
    for (i = 0; i < 6; i++) { 
        swapped = false; 
        for (j = 0; j < 6-i; j++) { 
            if (compare(&arr[j], &arr[j+1])) { 
                swap(&arr[j], &arr[j+1]); 
                swapped = true; 
            } 
        }

     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 

    count++;
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\tIteration No. %d\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], count);
    }
    
    printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\tSorted Final Array\n", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6]);    
}