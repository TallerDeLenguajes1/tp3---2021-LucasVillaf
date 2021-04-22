#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------PUNTO 4----------
typedef struct Producto {
    int ProductoID;         //  Numerado en ciclo iterativo
    int Cantidad;           //  entre 1 y 10
    char *TipoProducto;     //  Algún valor del arreglo TiposProductos
    float PrecioUnitario;   //  entre 10 - 100
} Producto;

typedef struct Cliente {
    int ClienteID;                  //  Numerado en el ciclo iterativo
    char *NombreCliente;            //  Ingresado por usuario
    int CantidadProductosAPedir;    //  (alteatorio entre 1 y 5)
    Producto *Productos;             //  El tamaño de este arreglo depende de la variable
} Cliente;  

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};                        //  “CantidadProductosAPedir”

//------FUNCIONES-------
void cargarClientes(int cantClientes, Cliente *clientes);
void mostrarClientes(Cliente *clientes, int cantClientes);
float costoTotalProducto(int precio, int cantidad);


int main (){
    //variables
    int cantClientes;
    Cliente *clientes = (Cliente*)malloc(sizeof(Cliente)*cantClientes); //reserva de memoria para clientes
    
    

    printf("    ******** Distribuidora  J U A N C I T O ********\n");
    printf("    -------- Sistema de carga de productos --------\n\n");
    
    printf("    Ingrese la cantidad de clientes a visitar: ");
    scanf("%d",&cantClientes);
    printf("\n");

    while (cantClientes > 5){
        printf("    *Solo puede visitar hasta 5 clientes\n");
        printf("    Ingrese la cantidad de clientes a visitar: ");
        scanf("%d",&cantClientes);
    }
    
    cargarClientes(cantClientes,clientes);
    mostrarClientes(clientes, cantClientes);

    
    getchar();
    free(clientes);
    return 0;
}

/***********FUNCIONES*********/
void cargarClientes(int cantClientes, Cliente *clientes){
    
    for(int i=0;i<cantClientes;i++){
        char nombre[50];
        printf("    Ingrese nombre del cliente: ");
        fflush(stdin);
        gets(nombre);
        fflush(stdin);
        printf ("\n");
        clientes[i].NombreCliente = (char *) malloc(sizeof(char)*strlen(nombre));
        strcpy(clientes[i].NombreCliente, nombre);
        clientes[i].ClienteID = 110+i; //ID de cliente comienza en 110 por gusto propio
        clientes[i].CantidadProductosAPedir = 1 + rand()%(5+1-1); //hasta 5 PRODUCTOS
        int cant=clientes[i].CantidadProductosAPedir;
        clientes[i].Productos = (Producto *)malloc(sizeof(Producto)*cant);// reserva de memoria para los productos
        for(int j=0;j<clientes[i].CantidadProductosAPedir;j++){
            clientes[i].Productos[j].ProductoID = 1+j; // ID productos
            clientes[i].Productos[j].Cantidad = 1 + rand ()%(10+1-1); // cantidad entre 1 y 10
            clientes[i].Productos[j].PrecioUnitario = (float) 100 + rand ()%(100+1-10); // precio entre 10 y 100
            clientes[i].Productos[j].TipoProducto =  *(TiposProductos + rand()%(5));
            
        }
        
    }
       
}

void mostrarClientes(Cliente *clientes, int cantClientes){
    
    for (int i=0; i<cantClientes; i++){
        printf ("    -----------------------\n\n");
        printf ("\n    Nombre: %s\n", clientes[i].NombreCliente);
        printf ("    ID: 00%d\n", clientes[i].ClienteID);
        printf ("    Cantidad de productos: %d\n", clientes[i].CantidadProductosAPedir);
        printf ("    PRODUCTOS PEDIDOS: \n\n");
        float TOTAL = 0, totalProducto = 0;

        for (int j=0; j<clientes[i].CantidadProductosAPedir;j++){
            printf("    ID del producto: 000%d\n", clientes[i].Productos[j].ProductoID);
            printf("    Cantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("    Precio por unidad: %.2f\n", clientes[i].Productos[j].PrecioUnitario);
            printf("    Tipo de producto: %s\n", clientes[i].Productos[j].TipoProducto);
            totalProducto = costoTotalProducto(clientes[i].Productos[j].PrecioUnitario, clientes[i].Productos[j].Cantidad);
            printf("    Costo: %.2f\n", totalProducto);
            printf ("\n");
            TOTAL = TOTAL + totalProducto;
        }
        printf ("    Total: %.2f\n", TOTAL);
    printf ("    -----------------------\n");
    }
}

float costoTotalProducto(int precio, int cantidad ){
    return (precio*cantidad);
}
