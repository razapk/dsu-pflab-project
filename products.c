#include <stdio.h>
#include "products.h"

const char *filename = "products.dat";

int read_products(Product **list)
{
    int file_size;
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        printf("Error in opening file %s.\n", filename);
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *list = (Product*) malloc(file_size);
    if (fread(*list, 1, file_size, fp) != file_size)
    {
        printf("Cannot read whole file %s.\n", filename);
        fclose(fp);
        return 0;
    }
    fclose(fp);
    return file_size / sizeof(Product);
}

int insert_product(Product product)
{
    FILE *fp = fopen(filename, "ab");
    if (!fp)
    {
        printf("Error in opening file %s.\n", filename);
        return -1;
    }
    fwrite(&product, sizeof(product), 1, fp);
    fclose(fp);
    return 0;
}
