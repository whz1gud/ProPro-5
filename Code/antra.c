#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CAPACITY 1000
            
int main() 
{
    int arr[CAPACITY];
    int a, b, c;
    

    printf("Enter values a, b, c: \n");
    scanf("%d%d%d", &a, &b, &c);

    srand(time(NULL));

    for (int i = 0; i < c; ++i)
    {
        arr[i] = (rand() % (b + 1 - a) + a);
        //rand() % (max_number + 1 - minimum_number) + minimum_number
    }

    for (int i = 0; i < c; ++i)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
