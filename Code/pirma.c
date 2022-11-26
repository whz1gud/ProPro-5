#include <stdio.h>

#define CAPACITY 10
            
int main() 
{
    int arr[CAPACITY] = {0}; // a)
    for (int i = 0; i < CAPACITY; ++i)
    {
        printf("Place %d, element %d \n", i+1, arr[i]); // j)
    }
    printf("\n");

    arr[0] = 1;
    arr[3] = 2;
    arr[9] = 3; // c)

    for (int i = 2; i < CAPACITY; ++i)
    {
        arr[i] = arr[i + 1]; // d)
    }

    //pirma pastumiu elementus i desine
    for (int i = CAPACITY - 1; i > 6; --i)
    {
        arr[i] = arr [i - 1];
    }
    //tada iterpiu 4
    arr[6] = 4;


    for (int i = 0; i < CAPACITY; ++i)
    {
        printf("Place %d, element %d \n", i+1, arr[i]); // f)
    }
    printf("\n");

    int x, y;
    printf("x, y, where y = value to insert to place x: ");
    scanf("%d%d", &x, &y);

    arr[x-1] = y; // g)

    printf("x, where x = place to delete value: ");
    scanf("%d", &x);

    for (int i = x-1; i < CAPACITY; ++i)
    {
        arr[i] = arr[i+1]; // h)
    }

    // for (int i = 0; i < CAPACITY - 1; ++i)
    // {
    //     printf("Place %d, element %d \n", i+1, arr[i]);
    // }
    // printf("\n");

    printf("x, y, where y = value to insert to place x: ");
    scanf("%d%d", &x, &y);

    // pirma perstumiu elementus nuo duotos index x reiksmes i desine
    for (int i = CAPACITY - 1; x-1 < i; --i)
    {
        arr[i] = arr[i - 1]; // i)
    }
    //tada iterpiu duota reiksme y i vieta x
    arr[x-1] = y;

    for (int i = 0; i < CAPACITY; ++i)
    {
        printf("Place %d, element %d \n", i+1, arr[i]); // j)
    }
    printf("\n");


    return 0;
}
