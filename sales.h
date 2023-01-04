#ifndef __SALES_H__
#define __SALES_H__

typedef struct 
{
    int time;
    char customerName[100];
    float totalBill;
    int products[100];
    int productQuantities [100];
    int numProducts;
} Sale;

int recordSale(Sale details);
int readSales(Sale **list, int *len);

#endif