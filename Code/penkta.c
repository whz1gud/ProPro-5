#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int return_digit_count(int);

int main()
{
    int x, xSorted, num, i = 0, arr[100], xNumArr[100];
    char sxSorted[100];

    // Dealing with input
    printf("Enter a number:\n");
    scanf("%d", &x);
    printf("Enter numbers to check; Type 0 to finish:\n");
    while (scanf("%d", &num) == 1)
    {
        if (num == 0)
        {
            break;
        }
        arr[i] = num;
        i++;
    }

    // Converting x number into array of its digits
    int xLen = return_digit_count(x);
    int k = 0;
    for (int j = xLen; j > 0; --j)
    {
        int temp;
        temp = x / pow(10, j - 1);
        temp = (int)temp;
        xNumArr[k] = temp % 10;
        k++;
    }

    // Sorting x number's array of digits from smallest to largest
    for (int l = 0; l < k - 1; l++)
    {
        for (int j = l + 1; j < k; j++)
        {
            int temp;
            if (xNumArr[l] > xNumArr[j])
            {
                temp = xNumArr[j];
                xNumArr[j] = xNumArr[l];
                xNumArr[l] = temp;
            }
        }
    }
    
    // Turning x's sorted array into an Integer
    int z = 0;
    for (int j = k; j > 0; --j)
    {
        xSorted += xNumArr[z] * pow(10, j - 1);
        z++;
    }

    // Converting sorted array Integer into String
    itoa(xSorted, sxSorted, 10);

    

    int flag = 0;
    for (int j = 0; j < i; ++j)
    {
        int currNumArr[100], currNumSorted = 0;
        char scurrNumSorted[100];
        int currNumLen = return_digit_count(arr[j]);
        int currNumDigSum = 0;
        // Converting Current number into array of its digits
        for (int l = currNumLen; l > 0; --l)
        {
            int temp;
            temp = arr[j] / pow(10, l - 1);
            temp = (int)temp;
            currNumArr[currNumDigSum] = temp % 10;
            currNumDigSum++;
        }

        // Sorting those digits from smallest to largest
        for (int l = 0; l < currNumDigSum - 1; l++)
        {
            for (int p = l + 1; p < currNumDigSum; p++)
            {
                int temp;
                if (currNumArr[l] > currNumArr[p])
                {
                    temp = currNumArr[p];
                    currNumArr[p] = currNumArr[l];
                    currNumArr[l] = temp;
                }
            }
        }      

        // Converting currNum's sorted array into an Integer
        int z = 0;
        for (int l = currNumDigSum; l > 0; --l)
        {
            currNumSorted += currNumArr[z] * pow(10, l - 1);
            z++;
        }

        // Converting currNum sortedArray Value that is Integer into a String
        itoa(currNumSorted, scurrNumSorted, 10);

        if (strstr(sxSorted, scurrNumSorted) != NULL)
        {
            flag = 1;
            continue;
        }
        else
        {
            flag = 0;
            printf("Element %d cannot be created from %d digits!", arr[j], x);
            break;
        }
    }

    if (flag == 1)
    {
        printf("All elements in the array can be created out of number's '%d' digits!", x);
    }
    
    return 0;
}

int return_digit_count(int num)
{
    if (num / 10 == 0)
    {
        return 1;
    }

    return 1 + return_digit_count(num / 10);
}