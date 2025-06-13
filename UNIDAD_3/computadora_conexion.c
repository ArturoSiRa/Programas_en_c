#include <stdio.h>

#include <stdlib.h>

#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>



MYSQL *con;



void finish_with_error() {

 fprintf(stderr, "%s\n", mysql_error(con));

 mysql_close(con);

 exit(1);

}



void conectar() {

 con = mysql_init(NULL);

 if (con == NULL) {

 fprintf(stderr, "mysql_init() falló\n");

 exit(1);

 }



 if (mysql_real_connect(con, "localhost", "root", "12345", "computadora", 

 3306, NULL, 0) == NULL) {

 finish_with_error();

 }

}



void insertar_info(const char *marca, const char *modelo, const char *procesador,const char *memoria_ram, const char *almacenamiento, const char *color, int precio) {

 char query[256];

 snprintf(query, sizeof(query),

 "INSERT INTO atributos(marca, modelo, procesador, memoria_ram, almacenamiento, color, precio) VALUES('%s', '%s', '%s', '%s', '%s', '%s', %d)", marca, modelo, procesador, memoria_ram, almacenamiento, color, precio);

 if (mysql_query(con, query)) {

 finish_with_error();

 } else {

 printf("Computadora registrada.\n");

 }

}



void leer_datos() {

 if (mysql_query(con, "SELECT id, marca, modelo, procesador, memoria_ram, almacenamiento, color, precio FROM atributos")) {

 finish_with_error();

 }



 MYSQL_RES *result = mysql_store_result(con);

 if (result == NULL) {

 finish_with_error();

 }



 int num_fields = mysql_num_fields(result);

 MYSQL_ROW row;



 while ((row = mysql_fetch_row(result))) {

 for (int i = 0; i < num_fields; i++) {

    if (i == 0)
    {
         printf("%s\t", row[0] ? row[0] : "NULL");
    }
    else
    {
            
     printf("%-12s\t", row[i] ? row[i] : "NULL");
    }

 }

 printf("\n");

 }



 mysql_free_result(result);

}

void leer_poco() {
    if (mysql_query(con, "SELECT id, precio, modelo, marca FROM atributos")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    printf("%-5s %-10s %-30s\n", "ID", "Precio", "Marca");
    printf("--------------------------------\n");

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("%-5s %-10s %-30s\n",
               row[0] ? row[0] : "NULL",
               row[1] ? row[1] : "NULL",
               row[2] ? row[2] : "NULL");
    }

    mysql_free_result(result);
}

void actualizar_datos(int id, const char *nuevo_color, int nuevo_precio) {

 char query[256];

 snprintf(query, sizeof(query),

 "UPDATE atributos SET color='%s', precio=%d WHERE id=%d",

 nuevo_color, nuevo_precio, id);

 if (mysql_query(con, query)) {

 finish_with_error();

 } else {

 printf("Computadora actualizada.\n");

 }

}



void eliminar_dato(int id) {

 char query[128];

 snprintf(query, sizeof(query), "DELETE FROM atributos WHERE id=%d", id);

 if (mysql_query(con, query)) {

 finish_with_error();

 } else {

 printf("Computadora actualizada eliminada.\n");

 }

}


void insertar_garantia(int atributo_id, const char *tipo, int duracion_meses, const char *proveedor) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO garantia(tipo, duracion_meses, proveedor, atributo_id) VALUES('%s', %d, '%s', %d)",
        tipo, duracion_meses, proveedor, atributo_id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Garantía registrada.\n");
    }
}


void insertar_accesorio(int atributo_id, const char *nombre, const char *tipo, const char *marca) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO accesorios(nombre, tipo, marca, atributo_id) VALUES('%s', '%s', '%s', %d)",
        nombre, tipo, marca, atributo_id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Accesorio registrado.\n");
    }
}


void insertar_usuario(const char *nombre, const char *correo, const char *ciudad, int atributo_id) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO usuarios(nombre, correo, ciudad) VALUES('%s', '%s', '%s')",
        nombre, correo, ciudad);

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    int usuario_id = mysql_insert_id(con);

    snprintf(query, sizeof(query),
        "INSERT INTO atributo_usuario(atributo_id, usuario_id) VALUES(%d, %d)",
        atributo_id, usuario_id);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Usuario asociado con la computadora.\n");
    }
}

void mostrar_computadoras_y_usuarios() {
    const char *query =
        "SELECT a.id, a.marca, u.nombre, u.correo FROM atributos a "
        "JOIN atributo_usuario au ON a.id = au.atributo_id "
        "JOIN usuarios u ON u.id = au.usuario_id";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    printf("ID\tMarca\t\tUsuario\t\tCorreo\n");
    while ((row = mysql_fetch_row(result))) {
        printf("%s\t%-10s\t%-10s\t%-20s\n",
               row[0], row[1], row[2], row[3]);
    }

    mysql_free_result(result);
}

int main() {
    conectar();

    int opcion;
    do {
        printf("\n==== MENÚ DE OPCIONES ====\n");
        printf("1) Ingresar computadora\n");
        printf("2) Ver todas las computadoras\n");
        printf("3) Eliminar computadora\n");
        printf("4) Actualizar color y precio\n");
        printf("5) Agregar garantía (1 a 1)\n");
        printf("6) Agregar accesorio (1 a muchos)\n");
        printf("7) Asociar usuario (muchos a muchos)\n");
        printf("8) Ver computadoras con usuarios\n");
        printf("0) Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: {
                char mar[50], mod[50], proc[50], mem[50], alm[50], col[50];
                int prec;
                printf("Marca: "); fgets(mar, sizeof(mar), stdin); mar[strcspn(mar, "\n")] = 0;
                printf("Modelo: "); fgets(mod, sizeof(mod), stdin); mod[strcspn(mod, "\n")] = 0;
                printf("Procesador: "); fgets(proc, sizeof(proc), stdin); proc[strcspn(proc, "\n")] = 0;
                printf("RAM: "); fgets(mem, sizeof(mem), stdin); mem[strcspn(mem, "\n")] = 0;
                printf("Almacenamiento: "); fgets(alm, sizeof(alm), stdin); alm[strcspn(alm, "\n")] = 0;
                printf("Color: "); fgets(col, sizeof(col), stdin); col[strcspn(col, "\n")] = 0;
                printf("Precio: "); scanf("%d", &prec); getchar();

                insertar_info(mar, mod, proc, mem, alm, col, prec);
                break;
            }

            case 2:
                printf("ID\tMarca\t\tModelo\t\tProcesador\tRAM\tAlmacenamiento\t\tColor\t\tPrecio\n");
                leer_datos();
                break;

            case 3: {
                leer_poco();
                int id;
                printf("ID a eliminar: ");
                scanf("%d", &id);
                eliminar_dato(id);
                break;
            }

            case 4: {
                int id, precio;
                char color[50];
                printf("ID a actualizar: ");
                scanf("%d", &id);
                printf("Nuevo precio: ");
                scanf("%d", &precio);
                getchar();
                printf("Nuevo color: ");
                fgets(color, sizeof(color), stdin);
                color[strcspn(color, "\n")] = 0;
                actualizar_datos(id, color, precio);
                break;
            }

            case 5: {
                int id, duracion;
                char tipo[50], proveedor[50];
                printf("ID de la computadora: ");
                scanf("%d", &id); getchar();
                printf("Tipo de garantía: "); fgets(tipo, sizeof(tipo), stdin); tipo[strcspn(tipo, "\n")] = 0;
                printf("Duración (meses): "); scanf("%d", &duracion); getchar();
                printf("Proveedor: "); fgets(proveedor, sizeof(proveedor), stdin); proveedor[strcspn(proveedor, "\n")] = 0;
                insertar_garantia(id, tipo, duracion, proveedor);
                break;
            }

            case 6: {
                int id;
                char nombre[50], tipo[50], marca[50];
                printf("ID de la computadora: ");
                scanf("%d", &id); getchar();
                printf("Nombre del accesorio: "); fgets(nombre, sizeof(nombre), stdin); nombre[strcspn(nombre, "\n")] = 0;
                printf("Tipo: "); fgets(tipo, sizeof(tipo), stdin); tipo[strcspn(tipo, "\n")] = 0;
                printf("Marca: "); fgets(marca, sizeof(marca), stdin); marca[strcspn(marca, "\n")] = 0;
                insertar_accesorio(id, nombre, tipo, marca);
                break;
            }

            case 7: {
                int id;
                char nombre[50], correo[50], ciudad[50];
                printf("ID de la computadora: ");
                scanf("%d", &id); getchar();
                printf("Nombre de usuario: "); fgets(nombre, sizeof(nombre), stdin); nombre[strcspn(nombre, "\n")] = 0;
                printf("Correo: "); fgets(correo, sizeof(correo), stdin); correo[strcspn(correo, "\n")] = 0;
                printf("Ciudad: "); fgets(ciudad, sizeof(ciudad), stdin); ciudad[strcspn(ciudad, "\n")] = 0;
                insertar_usuario(nombre, correo, ciudad, id);
                break;
            }

            case 8:
                mostrar_computadoras_y_usuarios();
                break;

            case 0:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 0);

    mysql_close(con);
    return 0;
}
