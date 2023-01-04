#include <stdio.h>
#include <conio.h>
#include "products.h"

int main()
{
    int option;

    printf("Select an option : \n");
    printf("1: Manage products\n");
    printf("2: Record sale\n");
    printf("3: View sale history\n");
    scanf("%d", &option);

    if (option == 1)
    {
        printf("Select an option : \n");
        printf("1: List products\n");
        printf("2: Find a product\n");
        printf("3: Add product\n");
        printf("4: Edit product\n");
        printf("5: Delete product\n");
        scanf("%d", &option);

        if (option == 1)
        {
            Product *list;
            int len, ret, i;
            ret = readProducts(&list, &len);
            if (ret != 0)
            {
                printf("Cannot read products file.");
            }
            else
            {
                for (i = 0; i < len; i++)
                {
                    printf("Id: %d\n", list[i].id);
                    printf("Name: %s\n", list[i].name);
                    printf("Manufacturer: %s\n", list[i].manufacturer);
                    printf("Price: %f\n", list[i].price);
                    printf("Stock: %d\n", list[i].stock);
                    printf("***************************************************\n");
                    printf("***************************************************\n");
                }
                free(list);
            }
        }
        else if (option == 2)
        {
            int id, ret;
            Product item;
            printf("Enter your ID: ");
            scanf("%d", &id);
            ret = findProduct(id, &item);
            if (ret != 0)
            {
                printf("Product not found");
            }
            else
            {
                printf("Id: %d\n", item.id);
                printf("Name: %s\n", item.name);
                printf("Manufacture: %s\n", item.manufacturer);
                printf("Pirce: %f\n", item.price);
                printf("Stock: %d\n", item.stock);
            }
        }
        else if (option == 3)
        {
            Product item;
            int id, stock;
            char name[100], manufacturer[100];
            float price;
            printf("Enter product id: ");
            scanf("%d", &item.id);
            printf("Enter product name: ");
            scanf("%s", item.name);
            printf("Enter product manufacturer: ");
            scanf("%s", item.manufacturer);
            printf("Enter product price: ");
            scanf("%f", &item.price);
            printf("Enter product stock: ");
            scanf("%d", &item.stock);
            int ret = insertProduct(item);
            if (ret == 0)
            {
                printf("Your product has been added successfully");
            }
            else
            {
                printf("Please use a unique ID");
            }
        }
        else if (option == 4)
        {
        }
        else if (option == 5)
        {
            int id;
            printf("Product ID: ");
            scanf("%d", &id);
            deleteProduct(id);
        }
        else
        {
            printf("Invalid option");
        }
    }
    else if (option == 2)
    {
        int id;
        int quantity;
        char c;
        do
        {
            printf("**************************************************************\n");
            printf("Enter product ID: ");
            scanf("%d", &id);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            printf("Press N to add another item or any other key to create a bill.\n");
            printf("**************************************************************\n");
            c = _getch();
        } while (c == 'N' || c == 'n');
    }
    else if (option == 3)
    {
    }
    else
    {
        printf("Invalid option");
    }

    return 0;
}