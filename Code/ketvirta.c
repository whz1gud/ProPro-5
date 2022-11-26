#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

int checkIfPrime(int);

int main()
{
    int arr[CAPACITY], prime[CAPACITY];
    int num, i = 0, x = 0;
    int flag;

    printf("Enter positive values\nTo finish enter a non-positive value:\n");
    do
    {
        scanf("%d", &num);
        if (num > 0)
        {
            arr[i] = num;
            i++;
        }
    } while (num > 0);

    for (int j = 0; j < i; ++j)
    {
        flag = 0;
        for (int z = 2; z < arr[j]; ++z)
        {
            if (arr[j] == 2 || arr[j] % z != 0)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            prime[x] = arr[j];
            x++;
        }
    }
    
    //Sort array
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = i + 1; j < x; j++)
        {
            int temp;
            if (prime[i] > prime[j])
            {
                temp = prime[j];
                prime[j] = prime[i];
                prime[i] = temp;
            }
        }
    }

    //Remove duplicates and print
    int sum = 1;
    int place = 0;
    printf("Prime numbers are: ");
    for (place; place < x; ++place)
    {
        sum = 1;
        for (int j = place + 1; j < x; ++j)
        {
            if (prime[place] == prime[j])
            {
                sum++;
            }
        }
        
        place += sum - 1;
        printf("%d ", prime[place]);
    }

    return 0;
}

