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
