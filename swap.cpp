#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdint.h>

#include "comparators.h"
#include "sort.h"
#include "swap.h"
#include "input_output.h"

/*void Swap(void* X, void* Y, size_t s)
{
    char* x = (char*)X;
    char* y = (char*)Y;

    unsigned long long temp = 0;

    int ullsize = sizeof(uint64_t);

    int n = s >> 3;


    for(int i = 0; i < n; i++)
    {
        memcpy(&temp, y, ullsize);
        memcpy(y, x, ullsize);
        memcpy(x, &temp, ullsize);
        x += ullsize;
        y += ullsize;
    }

    memcpy(&temp, y, s & 0x07);
    memcpy(y, x, s & 0x07);
    memcpy(x, &temp, s & 0x07);


        0         1         2         3
    0000'0100 0000'0000 0000'0000 0000'0000
    7       0 15      8           31      24

    rax - 64 ����
    eax - ������� 32 ����
    ax  - ������� 16 ���
    ah  - ������� 8 ��� ax
    al  - ������� 8 ��� ax
}*/

void Swap(void* X, void* Y, size_t s)
{
    char* x = (char*)X;
    char* y = (char*)Y;

    unsigned long long temp = 0;

    int copysize = sizeof(uint64_t);

    int n = s >> 3;

    for(int i = 0; i < n; i++)
    {
        memcpy(&temp, y, copysize);
        memcpy(y, x, copysize);
        memcpy(x, &temp, copysize);
        x += copysize;
        y += copysize;
    }

    if(s & 7 != 0)
    {
        copysize = sizeof(uint32_t);
        memcpy(&temp, y, copysize);
        memcpy(y, x, copysize);
        memcpy(x, &temp, copysize);
    }

    if(s & 3 != 0)
    {
        copysize = sizeof(uint16_t);
        memcpy(&temp, y, copysize);
        memcpy(y, x, copysize);
        memcpy(x, &temp, copysize);
    }


    if(s & 1 != 0)
    {
        copysize = sizeof(uint8_t);
        memcpy(&temp, y, copysize);
        memcpy(y, x, copysize);
        memcpy(x, &temp, copysize);
    }
}
