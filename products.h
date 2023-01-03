typedef struct
{
    int id;
    char name[100];
    char manufacturer[100];
    float price;
    int stock;
} Product;

int readProducts(Product **list);
int findProduct(int id, Product *product);
int insertProduct(Product product);
int updateProduct(Product product);
int deleteProduct(int id);
