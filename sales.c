#include <stdio.h>
#include "sales.h"

const char *salesFilename = "sales.dat";

int recordSale(Sale details)
{
    FILE *fp;
    fp = fopen(salesFilename, "ab");
    if (!fp)
        return -1;
    fwrite(&details, sizeof(details), 1, fp);
    fclose(fp);
    return 0;
}

int readSales(Sale **list, int *len)
{
    int file_size;
    FILE *fp = fopen(salesFilename, "rb");
    if (!fp)
    {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *len = file_size / sizeof(Sale);
    *list = (Sale *)calloc(*len, sizeof(Sale));
    if (fread(*list, 1, file_size, fp) != file_size)
    {
        fclose(fp);
        return -2;
    }
    fclose(fp);
    return 0;
}
