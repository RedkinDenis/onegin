#ifndef INPUT_OTPUT_H
#define INPUT_OTPUT_H

struct line
{
    size_t len;
    char* str;
};

struct

int GetFileSize(FILE* fp);

struct line* InputData(FILE* fp, int fsize, int* n);

void PrintData(struct line* data, int data_size);

void DataOut(FILE* fp, struct line* data, int nLines);

#endif // INPUT_OTPUT_H
