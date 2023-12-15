#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "comparators.h"
#include "sort.h"
#include "swap.h"
#include "input_output.h"

void bsort(void* arr, int size_arr, int el_size, int (*cmp)(const void*, const void*))
{
    for(int i = size_arr - 1; i > 0; i--)
    {
        int moves = 0;
        for(int j = 1; j <= i; j++)
        {
            if(cmp((char*)arr + j * el_size, (char*)arr + j * el_size - el_size) < 0)
            {
                Swap((char*)arr + j * el_size, (char*)arr + j * el_size - el_size, el_size);
                moves++;
            }
        }
        if(moves == 0)
        {
            printf("\n---sorted---\n\n");
            return;
        }
    }
    printf("\n---sorted---\n\n");
    return;
}
