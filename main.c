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
            // read_products(ProductProduct**list)
        }
        else if (option == 2)
        {
        }
        else if (option == 3)
        {
            int id, stock;
            char name[100], manufacturer[100];
            float price;
            printf("Enter product id: ");
            scanf("%d", &id);
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter product manufacturer: ");
            scanf("%s", manufacturer);
            printf("Enter product price: ");
            scanf("%f", &price);
            printf("Enter product stock: ");
            scanf("%d", &stock);
        }
        else if (option == 3)
        {
        }
        else if (option == 4)
        {
        }
        else if (option == 5)
        {
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