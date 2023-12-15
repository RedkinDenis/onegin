#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
                                               //wchar - для русского языка
#include "comparators.h"
#include "sort.h"
#include "input_output.h"

int main(int argc, char* argv[])
{
    char* inpName = (char*)"strings.txt";
    char* outName = (char*)"onegin_out.txt";

    if(argc == 3)
    {
        inpName = argv[1];
        outName = argv[2];
    }
    else if(argc == 2)
    {
        inpName = argv[1];
    }

    FILE* read = fopen(inpName, "rb");
    if(read == NULL)
    {
        printf("read file open error");
        return 0;
    }

    int fsize = GetFileSize(read);

    int n = 0;
    struct line* data = InputData(read, fsize, &n);

    //printf("out - %s", outName);

    FILE* out = fopen(outName, "w");
    if(out == NULL)
    {
        printf("out file open error");
        return 0;
    }

    fclose(read);

    PrintData(data, n);
    fprintf(out, "---Before sort---\n\n");
    DataOut(out, data, n);

    bsort(data, n, sizeof(struct line), RevStrCmp);

    PrintData(data, n);
    fprintf(out, "\n---After sort---\n\n");
    DataOut(out, data, n);

    fclose(out);
    getchar();
}

