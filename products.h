typedef struct
{
    int id;
    char name[100];
    char manufacturer[100];
    float price;
} Product;

int read_products(Product **list);
int insert_product(Product product);
