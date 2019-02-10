#include <stdio.h>
#include <stdlib.h>

/*
 
 Name: Mohamed Imran Mohamed siddique
 CS 211
 01/23/17
 
 */
int *dynaimArray(int *grow, int *size){
    
    int *temp;
    temp = (int *) malloc ( *size * 2 * sizeof(int) );
    int i;
    for ( i = 0 ; i < *size ; i++){
        temp[i] = grow[i];}
    free (grow);
    grow = temp;
    *size = *size * 2;
    
    return grow;
}

void arrayCopy (int fromArray[], int toArray[], int size){
    int i ;
    for (i=0; i<size; i++){
        toArray[i]=fromArray[i]; /* copies the array one integer at a time*/
    }
    return;
}

void sort(int toArray[], int size)
{
    int temp, j, k;
    for (j = 0; j < size; ++j)
    {
        for (k = j + 1; k < size; ++k)
        {
            if (toArray[j] > toArray[k])
            {
                temp = toArray[j];              /* sorts the array in ascending order*/
                toArray[j] = toArray[k];
                toArray[k] = temp;
            }
        }
    }
    
    return ;
}

int linSearch (int toArray[], int size, int target, int *numComparisons)
{
    int i;
    for (i = 0; i < size; i++)
    {
        
        if (toArray[i] == target)     /* if required element found */
        {
            
            *numComparisons=*numComparisons+1;
            return i; /* returns the position of the value that was found*/
        }
        *numComparisons=*numComparisons+1;
        
    }
    return -1; /* if the value was not found*/
}

int binSearch (int toArray[], int size, int target, int *numComparisons){
    
    int start = 0;
    int end = size - 1;
    int position = (start+end)/2;
    
    while (start <= end) {
        if (toArray[position] < target){
            start = position + 1;
            *numComparisons=*numComparisons+1;}
        else if (toArray[position] == target) {
            *numComparisons=*numComparisons+1; /* if the value was found in binary search*/
            break;
        }
        else
            end = position - 1;
        
        position = (start + end)/2;
        
        *numComparisons=*numComparisons+1;
    }
    if (start > end)
    {
        
        return -1;  /* if the value was not found*/
    }
    
    return position; /* returns the position of the value in the array*/
    
    
    
}

int main (int argc, char** argv)
{
    
    int size = 10;
    int *fromArray=(int *) malloc ( size * 2 * sizeof(int) );
    int *toArray=(int *) malloc ( size * 2 * sizeof(int) );
    int count;
    int *val;
    val = (int *) malloc ( size * 2 * sizeof(int) );
    int numComparisons=0;
    int target;
    int i, c=0,d=0;
    
    
    /* prompt the user for input */
    printf ("Enter in a list of numbers followed by the terminal value of -999\n");
    
    /* loop until the user enters -999 */
    scanf ("%d", val);
    while (*val != -999)
    {
        if (*val != -999){
            fromArray[count]=*val;}
        count++;
        scanf("%d", val);
        
        if (count >= size){
            
           // fromArray=dynaimArray(fromArray, &size);
            
        }
        
    }
    
    /* prints the total of input */
    printf("\nTotal count of numbers: %d\n", count);
    
    /* copies the array and makes a duplicate with the same vaules*/
    arrayCopy (fromArray, toArray, count);
    
    /* sorts the numbers from the dupcicate array*/
    sort(toArray, count);
    
    /* prints the sorted values*/
    printf("\nSorted Value: ");
    
    for (i=0;i<count;i++){
        
        printf("%d ", toArray[i]);
        
    }
    
    printf("\n");
    
    
    /* prompts the user to enter the search integers until -999 in read in*/
    printf("\nEnter the number to search followed by the terminal value of -999\n");
    scanf("%d", &target);
    
    /* loops until -999 is read*/
    while(target != -999){
        
        /* resets the number of comparions to 0 each time an interger is read in*/
        numComparisons=0;
        
        /*  performs the linear search after each integer is entered*/
        c = linSearch ( fromArray, count, target, &numComparisons);
        
        
        
        
        /* if the value was found, it prints the position and numuber of comparisons*/
        if (c != -1){
            printf("The value %d was found in position %d of the array\n", target,c+1);
            printf("Number of comparisons: %d \n", numComparisons);
            
        }
        /* if the number is not in the array, it will print the following*/
        else {
            printf("The value %d was not found using linear search\n", target);
        }
        
        /* performs the binary search*/
        d = binSearch ( toArray, count, target, &numComparisons);
        
        /* if the value was found, it prints the position and number of comparison*/
        if (d != -1){
            printf("The value %d was found in position %d of the array\n", target,d+1);
            printf("Number of comparisons: %d \n", numComparisons);
        }
        
        /*  if the integer is not foun, it prints the following*/
        else {
            printf("The value %d was not found using binary search\n", target);
            
        }
        
        /* keeps scanning integers until the loop is broken*/
        scanf("%d", &target);
        
        
    }
    
    
    
    
    
    return 0;
}