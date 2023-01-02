#include <stdio.h>
#include "products.h"

int main()
{
    int option;
    printf("Select an option:\n1. List products\t\t2. Insert product\n");
    scanf("%d", &option);
    if (option == 1)
    {
        Product *list;
        int size = read_products(&list);
        int i;
        for (i = 0; i < size; i++)
        {
            printf("Id: %d\n", list[i].id);
            printf("Name: %s\n", list[i].name);
            printf("Manufacturer: %s\n", list[i].manufacturer);
            printf("Price: %f\n", list[i].price);
            printf("---------------------------------------------------\n");
            printf("---------------------------------------------------\n");
        }
    }
    else if (option == 2)
    {
        Product product;
        printf("Enter id: ");
        scanf("%d", &product.id);
        printf("Enter name: ");
        scanf("%s", &product.name);
        printf("Enter manufacturer: ");
        scanf("%s", &product.manufacturer);
        printf("Enter price: ");
        scanf("%f", &product.price);
        if (!insert_product(product))
        {
            printf("Product inserted successfully.\n");
        }        
    }
    else 
    {
        printf("Invalid option selected.\n");
    }
    return 0;
}