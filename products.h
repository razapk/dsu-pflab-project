typedef struct
{
    int id;
    char name[100];
    char manufacturer[100];
    float price;
} Product;

int readProducts(Product **list);
int insertProduct(Product product);
