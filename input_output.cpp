#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#include "comparators.h"
#include "sort.h"
#include "swap.h"
#include "input_output.h"

int GetFileSize(FILE* fp)
{
    int startPos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int fsize = ftell(fp);
    fseek(fp, startPos, SEEK_SET);
    return fsize;
}

struct line* InputData(FILE* fp, int fsize, int* n)     //new
{
    char* buffer = (char*)calloc(fsize + 1, sizeof(char));
    int nLines = 0;

    int rsize = fread(buffer, sizeof(char), fsize, fp);
    assert(rsize == fsize);

    if(buffer[rsize - 1] != '\n')
        buffer[rsize] = '\n';
    else
        buffer[rsize] = '\0';

    for(int i = 0; i < rsize + 1; i++)
    {
        if(buffer[i] == '\r')
        {
            buffer[i] = '\0';
            i += 1;
            buffer[i] = '\0';
            nLines++;
        }
        else if(buffer[i] == '\n')
        {
            nLines++;
            buffer[i] = '\0';
        }
    }

    printf("nLines - %d\n", nLines);
    struct line* data = (struct line*)calloc(nLines, sizeof(struct line));

    int j = 0;
    int oldind = 0;

    data[j].str = buffer;
    j++;
    for(int i = 0; i < rsize + 1; i++)
    {
        if(buffer[i] == '\0')
        {
            if(j <= nLines)
            {
                data[j].str = buffer + i + 1;
                data[j - 1].len = i - oldind;
                oldind = i + 1;

                if(buffer[i + 1] == '\0')
                {
                    data[j].str++;
                    i++;
                    oldind++;
                }
                j++;
            }
        }
    }

    *n = nLines;
    return data;
}

/*struct line* InputData(FILE* fp, int fsize, int* n)
{
    char* buffer = (char*)calloc(fsize + 1, sizeof(char));
    int nLines = 0;

    int rsize = fread(buffer, sizeof(char), fsize, fp);
    assert(rsize == fsize);

    if(buffer[rsize - 1] != '\n')
        buffer[rsize] = '\n';
    else
        buffer[rsize] = '\0';

    for(int i = 0; i < rsize + 1; i++)
    {
        if(buffer[i] == '\r')
        {
            i += 1;
            nLines++;
        }
        else if(buffer[i] == '\n')
            nLines++;
    }

    printf("nLines - %d\n", nLines);
    struct line* data = (struct line*)calloc(nLines, sizeof(struct line));

    int j = 0;
    int oldind = 0;

    data[j].str = buffer;
    j++;
    for(int i = 0; i < rsize + 1; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';                                             //поменять все на \0 в цикле выше

            if(j <= nLines)
            {
                data[j].str = buffer + i + 1;
                data[j - 1].len = i - oldind;
                oldind = i + 1;
                j++;
            }
        }
        if(buffer[i] == '\r')
        {
            buffer[i] = '\0';

            if(j <= nLines)
            {
                data[j].str = buffer + i + 2;

                data[j - 1].len = i - oldind;
                oldind = i + 2;
                j++;
                i += 1;
            }
        }
    }

    *n = nLines;
    return data;
}*/


void PrintData(struct line* data, int data_size)
{
    for(int i = 0; i < data_size; i++)
        puts(data[i].str);
}

void DataOut(FILE* fp, struct line* data, int nLines)
{
    for(int i = 0; i < nLines; i++)
        fprintf(fp, "%s\n", data[i].str);
}
