#include <stdio.h>
#include "products.h"

const char *filename = "products.dat";

int readProducts(Product **list, int *len)
{
    int file_size;
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *len = file_size / sizeof(Product);
    *list = (Product *)calloc(*len, sizeof(Product));
    if (fread(*list, 1, file_size, fp) != file_size)
    {
        fclose(fp);
        return -2;
    }
    fclose(fp);
    return 0;
}

int findProduct(int id, Product *product)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp)
        return -1;
    while (fread(product, sizeof(Product), 1, fp))
    {
        if (product->id == id)
        {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return -3;
}

int insertProduct(Product product)
{
    // Check if product already exists
    FILE *fp;
    Product temp;
    if (findProduct(product.id, &temp) == 0)
        return -4;

    // Insert the product
    fp = fopen(filename, "ab");
    if (!fp)
        return -1;
    fwrite(&product, sizeof(product), 1, fp);
    fclose(fp);
    return 0;
}

int updateProduct(Product product)
{
    Product temp;
    FILE *fp = fopen(filename, "rb+");
    if (!fp)
        return -1;
    while (fread(&temp, sizeof(Product), 1, fp))
    {
        if (temp.id == product.id)
        {
            fseek(fp, -1 * sizeof(Product), SEEK_CUR);
            fwrite(&product, sizeof(Product), 1, fp);
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return -3;
}

int deleteProduct(int id)
{
    Product *list;
    int len, ret, i;
    FILE *fp;

    ret = readProducts(&list, &len);
    if (ret)
    {
        return ret;
    }

    fp = fopen(filename, "wb");
    if (!fp)
    {
        free(list);
        return -1;
    }
    ret = -3;
    for (i = 0; i < len; i++)
    {
        if (list[i].id == id)
            ret = 0;
        else
            fwrite(&list[i], sizeof(Product), 1, fp);
    }
    free(list);
    fclose(fp);
    return ret;
}
