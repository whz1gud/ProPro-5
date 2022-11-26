#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 100

int main()
{
    int x[CAPACITY];
    int s, n, num;

    printf("Enter values s, n: \n");
    scanf("%d%d", &s, &n);

    printf("Give %d positive values: ", n);
    for (int i = 0; i < n; ++i)
    {
        do
        {
            scanf("%d", &num);
            if (num <= 0)
            {
                printf("That is not a positive number!\nTry again: ");
            }
            else
                printf("*Value accepted*\n");
        } while (num <= 0);

        x[i] = num;
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     printf("%d ", x[i]);
    // }

    for (int i = 0; i < n; ++i) // 4 5 7 9 14; s = 45, tai (5, 9) ats
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if (x[i] * x[j] == s)
                {
                    printf("(%d, %d)\n", x[i], x[j]);
                }
            }
        }
    }

    return 0;
}
