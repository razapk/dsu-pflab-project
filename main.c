#include <stdio.h>
#include <conio.h>
#include "products.h"
#include "sales.h"

void printProduct(Product item)
{
    printf("Id: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Manufacture: %s\n", item.manufacturer);
    printf("Price: %f\n", item.price);
    printf("Stock: %d\n", item.stock);
}

int main()
{
    printf(" _____ ___ ___ ____  _____  __  __  _____  _____  ____\n"
           "/  _  \\\\  |  //    \\/   __\\/  \\/  \\/  _  \\/  _  \\/    \\\n"
           "|  _  < |   | \\-  -/|   __||  \\/  ||  _  ||  _  <\\-  -/\n"
           "\\_____/ \\___/  |__| \\_____/\\__ \\__/\\__|__/\\__|\\_/ |__|\n");
    int option;

    printf("***********************************\n");
    printf("** WELCOME TO BYTEMART POS APP **\n");
    printf("***********************************\n");
    printf("             ELON GATES \n");
    printf("***********************************\n");
    printf("KINDLY ENTER YOUR CHOICE\n\n");
    printf("1-MANAGE PRODUCTS\n");
    printf("2-QUICK SALE\n");
    printf("3-VIEW SALE HISTORY\n");
    printf("***********************************\n\n\n");
    scanf("%d", &option);

    if (option == 1)
    {
        printf("\t\t\t ***PRODUCT MANAGEMENT***\n\n");
        printf("Select an option : \n");
        printf("1: LIST products\n");
        printf("2: FIND a product\n");
        printf("3: ADD a product\n");
        printf("4: EDIT product details\n");
        printf("5: DELETE a product\n\n");
        printf("Option Number: ");
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
                printf("---------------------------------------------INVENTORY DETAILS---------------------------------------------\n\n");
                printf("================================================================================\n");
                printf("ID\t\tNAME\t\tMANUFACTURER\tPRICE\t\t\tSTOCK\n\n");
                for (i = 0; i < len; i++)
                {
                    printf("%d\t", list[i].id);
                    printf("\t%s\t", list[i].name);
                    printf("\t%s\t", list[i].manufacturer);
                    printf("\tPKR %f\t", list[i].price);
                    printf("\t%d\t\n", list[i].stock);
                }
                printf("================================================================================\n");
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
                printProduct(item);
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
            int id, ret;
            Product item;
            printf("Product ID: ");
            scanf("%d", &id);
            ret = findProduct(id, &item);
            if (ret != 0)
            {
                printf("Please enter Product from list!");
            }
            else
            {
                char name[100], manufacturer[100];
                float price;
                printf("Enter product name: ");
                scanf("%s", item.name);
                printf("Enter product manufacturer: ");
                scanf("%s", item.manufacturer);
                printf("Enter product price: ");
                scanf("%f", &item.price);
                printf("Enter product stock: ");
                scanf("%d", &item.stock);
                updateProduct(item);
                printf("Product has been edited successfully!");
            }
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
        int id, ret, quantity;
        char c = '\0';
        Sale details;
        Product item;
        details.numProducts = 0;
        printf("Enter customer's name: ");
        scanf("%s", details.customerName);
        float totalInvoice = 0;

        for (;;)
        {
            printf("**************************************************************\n");
            printf("Enter product ID: ");
            scanf("%d", &id);
            ret = findProduct(id, &item);
            if (ret != 0)
            {
                printf("The entered product does not exist.\n");
                continue;
            }
            printProduct(item);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            if (item.stock < quantity)
            {
                printf("Enough stock not available.\n");
                continue;
            }
            item.stock -= quantity;
            details.products[details.numProducts] = item.id;
            details.productQuantities[details.numProducts] = quantity;
            details.numProducts++;
            updateProduct(item);
            totalInvoice = totalInvoice + item.price * quantity;
            printf("Press 'B' to create a bill and any other key to continue....\n");
            c = _getch();
            if (c == 'B' || c == 'b')
                break;
            printf("**************************************************************\n");
        }
        details.totalBill = totalInvoice;
        printf("Your total bill is %f.\n", totalInvoice);
        if (recordSale(details))
        {
            printf("An error occurred.\n");
        }
    }
    else if (option == 3)
    {
        Sale *list;
        int len, i, c;
        if (readSales(&list, &len))
        {
            printf("Error in reading sales file.\n");
        }
        else
        {
            for (i = 0; i < len; i++)
            {
                printf("***************************************************\n");
                printf("***************************************************\n");
                printf("Customer name: %s\n", list[i].customerName);
                printf("...................................................\n");
                for (c = 0; c < list[i].numProducts; c++)
                {
                    Product product;
                    if (findProduct(list[i].products[c], &product))
                    {
                        printf("Error in reading product %d.", list[i].products[c]);
                    }
                    else
                    {
                        printProduct(product);
                        printf("Quantity: %d\n", list[i].productQuantities[c]);
                    }
                    printf("...................................................\n");
                }
                printf("Total bill: %f\n", list[i].totalBill);
            }
            free(list);
            printf("***************************************************\n");
            printf("***************************************************\n");
        }
    }
    else
    {
        printf("Invalid option");
    }

    return 0;
}