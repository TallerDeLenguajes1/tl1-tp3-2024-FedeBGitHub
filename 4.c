#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // AlgÃºn valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
struct Producto *Productos; //El tamaÃ±o de este arreglo depende de la variable
// â€œCantidadProductosAPedirâ€
};

void mostrar(struct Cliente *clientes,int cantClientes);
float costoProducto(struct Producto producto);

int main () {
    struct Cliente *clientes;
    int cantClientes;
    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d",&cantClientes);
    printf("cantidad %d",cantClientes);
    fflush(stdin);
    clientes=(struct Cliente*)malloc(sizeof(struct Cliente) * cantClientes );

    int tipo;
    char buff[100];
    float costoUnProducto;
    for (int i = 1; i <= cantClientes; i++)
    {
        printf("\n  ##### CLIENTE %d #####",i);
        clientes[i].ClienteID = i;
        printf("\nNombre del cliente: ");
        gets(buff);
        clientes[i].NombreCliente = (char *)malloc((strlen(buff)+1) * sizeof(char));
        strcpy(clientes[i].NombreCliente,buff);
        srand(time(NULL));
        clientes[i].CantidadProductosAPedir = rand() %5 + 1 ;
        clientes[i].Productos = malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto ));
        //cargar los productos
        for (int j = 1; j <=  clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j;
            clientes[i].Productos[j].Cantidad = rand() %10 + 1;
            tipo = rand() %5;
            clientes[i].Productos[j].TipoProducto = TiposProductos[tipo];
            clientes[i].Productos[j].PrecioUnitario = rand() %91 + 10;
        }
    }

    mostrar(clientes,cantClientes);
    costoUnProducto = costoProducto(clientes[1].Productos[1]);
    printf("\n(FUNCION costoUnProducto) El costo del producto es: $%.2f",costoUnProducto);
    return 0;
}

void mostrar(struct Cliente *clientes,int cantClientes){
    float totalaPagar;
    for (int i = 1; i <=cantClientes; i++)
    {
        totalaPagar = 0;
        printf("\n---------- Cliente %d ----------\n",i);
        printf("ClienteID: %d\n",clientes[i].ClienteID);
        printf("Nombre del cliente: %s\n",clientes[i].NombreCliente);
        printf("Cantidad de productos: %d\n",clientes[i].CantidadProductosAPedir);
        
        for (int j = 1; j <= clientes[i].CantidadProductosAPedir ; j++)
        {
            printf("--- Producto %d ---\n",j);
            printf("ProductoID: %d\n",clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n",clientes[i].Productos[j].Cantidad);
            printf("Tipo de producto: %s\n",clientes[i].Productos[j].TipoProducto);
            printf("Precio unitario: $%.2f\n",clientes[i].Productos[j].PrecioUnitario);
            totalaPagar += clientes[i].Productos[j].Cantidad * clientes[i].Productos[j].PrecioUnitario;
        }
        printf("TOTAL A PAGAR: $%.2f\n",totalaPagar);
    }
}

float costoProducto(struct Producto producto){
    float costo;
    costo = producto.PrecioUnitario * producto.Cantidad;
    return costo;
}