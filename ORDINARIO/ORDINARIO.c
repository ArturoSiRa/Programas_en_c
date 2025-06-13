#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "12345"
#define DATABASE "ordi_prog"
#define MAX_QUERY_LEN 512
#define MAX_STRING_LEN 100

MYSQL *con;

// FUNCIONES GENERALES

void finish_with_error() {
    fprintf(stderr, "Error: %s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void conectar() {
    con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, SERVER, USER, PASSWORD, DATABASE, 3306, NULL, 0) == NULL) {
        finish_with_error();
    }
}

void gotoxy(short x, short y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

void setcolor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void limpiarPantalla() {
    system("cls");
}

int leerEnteroSeguro(const char *mensaje) {
    char buffer[50];
    int numero;
    while (1) {
        printf("%s", mensaje);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &numero) == 1 && numero >= 0) {
            return numero;
        } else {
            printf("Error: Ingresa un número entero válido.\n");
        }
    }
}


float leerFlotanteSeguro(const char *mensaje) {
    char buffer[50];
    float numero;
    while (1) {
        printf("%s", mensaje);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%f", &numero) == 1 && numero >= 0) {
            return numero;
        } else {
            printf("Error: Ingresa un número válido (positivo).\n");
        }
    }
}


void leerCadenaSegura(const char *mensaje, char *cadena, int max_len) {
    while (1) {
        printf("%s", mensaje);
        fgets(cadena, max_len, stdin);
        cadena[strcspn(cadena, "\n")] = 0; 


        if (strlen(cadena) == 0) {
            printf("Error: El campo no puede estar vacío.\n");
        } else {
            break;
        }
    }
}




// --- PANTALLA DE BIENVENIDA ---
void pantalla_bienvenida() {
    limpiarPantalla();
    setcolor(11);

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@********@@********@@@@@@@@@@@@@@@@@@@@@@@@***@**+@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@@@@@***@@@@@@@@@@@@@**@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@********@@*******+@@@@@@@@@@@@@@@@@@@@@@@**+@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@@@@@@@@@@@@@**@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@*******@@********@@@@@@@@@@@@@@@@@@@@@@@**+@***@@*****@@@@**@@***@**@@@****@@@*****@@***@@@@***@@@+****@@@****@@@@****@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@********@@********@@@@@@@@@@@@@@@@@@@@@@**+@***@@*****@@@@**@@***@**@@***@**@@*****@*****@@@***@@@*****@@@****@@@@****@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@********@@********@@@@@@@@@@@@@@@@@@@@@**+@***@@**@**@@@@**@@@**@**@@******@@**@@@@**@**@@@***@@**@***@@@@***@@@**@**@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@********@@*******@@@@@@@@@@@@@@@@@@@@@*******@@**@**@@@@**@@@****@@@**@@@@@@**@@@@@***@@@@***@@**@***@@@****@@@**@**@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@********@@********@@@@@@@@@@@@@@@@@@@@@******+@@**@**@@@@**@@@****@@@***@**@@**@@@@*@@**@@@***@@******@@@**@*@@@*****@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@********@@******@@*@@@@@@@@@@@@@@@@@@@@@****@@@@**@**@@@@**@@@@**@@@@@****#@@**@@@@+***+@@@***@@@*****@@@****@@@@****@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@********@@******@@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@********@@*******@@****@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@*******@@*******@@*****@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@*******@@********@@******@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*****@@****@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@*******@@*******@@*******@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@****@@@@@@@@@@@@@@@@@*****@@****@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@*******@@********@@********@@@@@@@@@@@@@@@@*****@@@@@@@@@@@@@@@@@@@@@@@@@@@*********@@@@@@@@@@@@@@@*****@@****@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@*******@@********@@********@@@@@@@@@@@@@@@@*****@@@@@@@@@@@@@@@@@@@@@@@@@@**********@@@@@@@@@@@@@@@*****@@****@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@*******@@*******@@**@@*******@@@@@@@@@@@@@@@*****@@@@@@@@@@@@@@@@@@@@@@@@@***********@@@@@@@@@@@@@@@*****@@****@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@********@@*******@@**@@*******@@@@@@@@@@@@@@@*****@@@@@@@@@@@@@@@@@@@@@@@@*******@+***@@@@@@@@@@@@@@@*****@@****@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@*******@@*******@@****@@*******@@@@@@@@@@@@@@*****@@@@@@@@@@@@@@@@@@@@@@@@*****@@@@@@*@@@@@@@@@@@@@@@*****@@****@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@*******@@********@@****@@********@@@@@@@@@@@@@*****@@@@@@@@@*********@@@@@@*****@@@@@@@@@@*********@@@*****@@****@@@@@********@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@*******@@*******@@******@@********@@@@@@@@@@@@*****@@@@@@@@@**********@@@@@******@@@@@@@@@**********@@*****@@****@@@@**********@@@@@@@@@@@@\n");
    printf("@@@@@@@@*******@@********@@******@@*********@@@@@@@@@@@*****@@@@@@@@@***********@@@@+******+@@@@@@@***********@*****@@****@@@@***********@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@********@@*********@@@@@@@@@@*****@@@@@@@@@****+******@@@@@********@@@@@@*++********@*****@@****@@@*****@@******@@@@@@@@@@\n");
    printf("@@@@@@*******************@@*******@@***************@@@@*****@@@@@@@@@@@@@@@*****@@@@@@*********@@@@@@@@@@*****@*****@@****@@@****@@@@******@@@@@@@@@\n");
    printf("@@@@@@*******************@@********@@**************@@@@*****@@@@@@@@@@@@@@@@****@@@@@@@@********@@@@@@@@@*****@*****@@****@@*****@@@*******@@@@@@@@@\n");
    printf("@@@@@@********************@@*******@@*************@@@@@*****@@@@@@@@@@@@********@@@@@@@@@+*******@@@@@********@*****@@****@@***************@@@@@@@@@\n");
    printf("@@@@@**********************@@*******@@************@@@@@*****@@@@@@@@@+**********@@@@@@@@@@@@*****@@***********@*****@@****@@***************@@@@@@@@@\n");
    printf("@@@@************************@@******@@***********@@@@@@*****@@@@@@@@@*****@@****@@@@@@@@@@@@*****@+*****@*****@*****@@****@@*****@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@************************@@*******@@**********@@@@@@*****@@@@@@@@*****@@@****@@@@@@@@@@@@*****@*****@@*****@*****@@****@@+****@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@**************************@@*******@@********@@@@@@@*****@@@@@@@@*****@@@****@@@@***@@@@@*****@*****@@*****@*****@@****@@@*****@@@@@@@****@@@@@@@\n");
    printf("@@@********@@@@@@@@@@@@@@@@@@@@********@@@@@@@@@@@@@@@@************@************@@@@************@@************@*****@@****@@@@******@@***+**@@@@@@@@\n");
    printf("@@@@******@@******************@@**************+@@@@@@@@************@************@@@@************@@************@*****@@****@@@@************@@@@@@@@@@\n");
    printf("@@@@******@@*******************@@*************@@@@@@@@@************@@***********@@@@***********@@@@***********@*****@@****@@@@@@@******@@@@@@@@@@@@@\n");
    printf("@@@@@@***@@********************@@*************@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@***@@*********************@@***********@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@**@@***********************@@**********@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@+*@@************************@@********@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@*********q@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*****+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@********@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*******@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@******@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@***@@****@***@+**@***@@@@***@#***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@*****@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+***@@**@******+*****+*****@@****@*****@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@****@@**@@*****@****@@@****@**@@@@*****@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@**@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@***@@**@******@****@@*****@***@@@*****@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*******@**@***#**@**@**@**@****@***@***@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*****+@*********@********@@***@*******@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n");
    printf("\n");

    printf("************************************************\n");
    printf("*                                              *\n");
    printf("*     SISTEMA DE GESTION DE PARQUES NATURALES  *\n");
    printf("*                                              *\n");
    printf("************************************************\n");

    printf("Proyecto de Programacion Estructurada en C + MySQL\n");
    printf("Alumno: Arturo Silva Rampirez\n");
    printf("Materia: Fundamentos de Programacion Estructurada\n");


    printf("Presione ENTER para continuar...");
    getchar();  
    limpiarPantalla();
}

// --- CRUD COMUNIDAD ---

void insertar_comunidad() {
    int id_ca = leerEnteroSeguro("ID de la comunidad: ");  // PEDIR id_ca
    char nombre[MAX_STRING_LEN];
    leerCadenaSegura("Nombre de la comunidad: ", nombre, MAX_STRING_LEN);

    char query[MAX_QUERY_LEN];
    snprintf(query, sizeof(query),
        "INSERT INTO comunidad (id_ca, canombre) VALUES(%d, '%s')", id_ca, nombre);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("  Comunidad registrada correctamente.\n");
    }
}


void leer_comunidades() {
    if (mysql_query(con, "SELECT id_ca, canombre FROM comunidad")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay comunidades registradas.\n");
    } else {
        printf("\n%-5s %-50s\n", "ID", "Nombre");
        printf("----------------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-5s %-50s\n", row[0], row[1]);
        }
    }

    mysql_free_result(result);
}

void modificar_comunidad() {
    int id_ca = leerEnteroSeguro("ID de la comunidad a modificar: ");
    char nuevo_nombre[MAX_STRING_LEN];
    leerCadenaSegura("Nuevo nombre de la comunidad: ", nuevo_nombre, MAX_STRING_LEN);

    char query[MAX_QUERY_LEN];
    snprintf(query, sizeof(query),
        "UPDATE comunidad SET canombre='%s' WHERE id_ca=%d",
        nuevo_nombre, id_ca);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        if (mysql_affected_rows(con) == 0) {
            printf("  No existe una comunidad con el ID proporcionado.\n");
        } else {
            printf("  Comunidad modificada correctamente.\n");
        }
    }
}

void eliminar_comunidad() {
    int id_ca = leerEnteroSeguro("ID de la comunidad a eliminar: ");

    char query[MAX_QUERY_LEN];
    snprintf(query, sizeof(query),
        "DELETE FROM comunidad WHERE id_ca=%d", id_ca);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        if (mysql_affected_rows(con) == 0) {
            printf("  No existe una comunidad con el ID proporcionado.\n");
        } else {
            printf("  Comunidad eliminada correctamente.\n");
        }
    }
}
// --- SUBMENU COMUNIDAD ---
void menu_comunidad() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU COMUNIDAD ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar comunidad");
        gotoxy(20, 6); printf("2) Ver comunidades");
        gotoxy(20, 7); printf("3) Modificar comunidad");
        gotoxy(20, 8); printf("4) Eliminar comunidad");
        gotoxy(20, 9); printf("0) Volver al menu principal");

        gotoxy(20, 11); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_comunidad();
                system("pause");
                break;
            case 2:
                leer_comunidades();
                system("pause");
                break;
            case 3:
                modificar_comunidad();
                system("pause");
                break;
            case 4:
                eliminar_comunidad();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD PARQUE ---

void insertar_parque() {
    int id_parque;  // PEDIMOS ID PARQUE
    char nombre[MAX_STRING_LEN], fecha[20];
    float superficie;
    int id_ca;

    id_parque = leerEnteroSeguro("ID del parque: ");  // NUEVO paso: pedir id_parque
    leerCadenaSegura("Nombre del parque: ", nombre, MAX_STRING_LEN);
    leerCadenaSegura("Fecha de declaracion (YYYY-MM-DD): ", fecha, 20);
    superficie = leerFlotanteSeguro("Superficie (ha): ");
    id_ca = leerEnteroSeguro("ID de la comunidad autonoma a la que pertenece: ");

    // Verificar que exista la comunidad
    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_ca FROM comunidad WHERE id_ca=%d", id_ca);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe una comunidad con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    // INSERT con id_parque incluido
    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO parque (id_parque, pnombre, fec_declaracion, superficie, id_ca) "
        "VALUES(%d, '%s', '%s', %.2f, %d)",
        id_parque, nombre, fecha, superficie, id_ca);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Parque registrado correctamente.\n");
    }
}


void leer_parques() {
    if (mysql_query(con, "SELECT id_parque, pnombre, fec_declaracion, superficie, id_ca FROM parque")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay parques registrados.\n");
    } else {
        printf("\n%-5s %-30s %-15s %-12s %-5s\n", "ID", "Nombre", "Fecha Declaracion", "Superficie", "Com.");
        printf("-----------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-5s %-30s %-15s %-12s %-5s\n", row[0], row[1], row[2], row[3], row[4]);
        }
    }

    mysql_free_result(result);
}

void modificar_parque() {
    int id_parque = leerEnteroSeguro("ID del parque a modificar: ");

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_parque FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un parque con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char nombre[MAX_STRING_LEN], fecha[20];
    float superficie;
    int id_ca;

    leerCadenaSegura("Nuevo nombre del parque: ", nombre, MAX_STRING_LEN);
    leerCadenaSegura("Nueva fecha de declaracion (YYYY-MM-DD): ", fecha, 20);
    superficie = leerFlotanteSeguro("Nueva superficie (ha): ");
    id_ca = leerEnteroSeguro("Nuevo ID de la comunidad autonoma: ");

    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_ca FROM comunidad WHERE id_ca=%d", id_ca);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    result = mysql_store_result(con);
    row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe una comunidad con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_update[MAX_QUERY_LEN];
    snprintf(query_update, sizeof(query_update),
        "UPDATE parque SET pnombre='%s', fec_declaracion='%s', superficie=%.2f, id_ca=%d WHERE id_parque=%d",
        nombre, fecha, superficie, id_ca, id_parque);

    if (mysql_query(con, query_update)) {
        finish_with_error();
    } else {
        printf("  Parque modificado correctamente.\n");
    }
}

void eliminar_parque() {
    int id_parque = leerEnteroSeguro("ID del parque a eliminar: ");

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_parque FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un parque con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        printf("  Parque eliminado correctamente.\n");
    }
}
// --- SUBMENU PARQUE ---
void menu_parque() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU PARQUE ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar parque");
        gotoxy(20, 6); printf("2) Ver parques");
        gotoxy(20, 7); printf("3) Modificar parque");
        gotoxy(20, 8); printf("4) Eliminar parque");
        gotoxy(20, 9); printf("0) Volver al menu principal");

        gotoxy(20, 11); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_parque();
                system("pause");
                break;
            case 2:
                leer_parques();
                system("pause");
                break;
            case 3:
                modificar_parque();
                system("pause");
                break;
            case 4:
                eliminar_parque();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD AREA ---

void insertar_area() {
    int id_area;  // NUEVO: pedir id_area
    char nombre[MAX_STRING_LEN];
    float extension;
    int id_parque;

    id_area = leerEnteroSeguro("ID del area: ");  // Pedir id_area
    leerCadenaSegura("Nombre del area: ", nombre, MAX_STRING_LEN);
    extension = leerFlotanteSeguro("Extension del area (ha): ");
    id_parque = leerEnteroSeguro("ID del parque al que pertenece: ");

    // Verificar que exista el parque
    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_parque FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un parque con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    // INSERT con id_area incluido
    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO area (id_area, anombre, extension, id_parque) "
        "VALUES(%d, '%s', %.2f, %d)", id_area, nombre, extension, id_parque);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Area registrada correctamente.\n");
    }
}


void leer_areas() {
    if (mysql_query(con, "SELECT id_area, anombre, extension, id_parque FROM area")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay areas registradas.\n");
    } else {
        printf("\n%-5s %-30s %-12s %-5s\n", "ID", "Nombre", "Extension", "Parque");
        printf("---------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-5s %-30s %-12s %-5s\n", row[0], row[1], row[2], row[3]);
        }
    }

    mysql_free_result(result);
}

void modificar_area() {
    int id_area = leerEnteroSeguro("ID del area a modificar: ");

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_area FROM area WHERE id_area=%d", id_area);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un area con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char nombre[MAX_STRING_LEN];
    float extension;
    int id_parque;

    leerCadenaSegura("Nuevo nombre del area: ", nombre, MAX_STRING_LEN);
    extension = leerFlotanteSeguro("Nueva extension del area (ha): ");
    id_parque = leerEnteroSeguro("Nuevo ID del parque: ");

    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_parque FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    result = mysql_store_result(con);
    row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un parque con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_update[MAX_QUERY_LEN];
    snprintf(query_update, sizeof(query_update),
        "UPDATE area SET anombre='%s', extension=%.2f, id_parque=%d WHERE id_area=%d",
        nombre, extension, id_parque, id_area);

    if (mysql_query(con, query_update)) {
        finish_with_error();
    } else {
        printf("  Area modificada correctamente.\n");
    }
}

void eliminar_area() {
    int id_area = leerEnteroSeguro("ID del area a eliminar: ");

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_area FROM area WHERE id_area=%d", id_area);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un area con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM area WHERE id_area=%d", id_area);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        printf("  Area eliminada correctamente.\n");
    }
}
// --- SUBMENU AREA ---
void menu_area() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU AREA ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar area");
        gotoxy(20, 6); printf("2) Ver areas");
        gotoxy(20, 7); printf("3) Modificar area");
        gotoxy(20, 8); printf("4) Eliminar area");
        gotoxy(20, 9); printf("0) Volver al menu principal");

        gotoxy(20, 11); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_area();
                system("pause");
                break;
            case 2:
                leer_areas();
                system("pause");
                break;
            case 3:
                modificar_area();
                system("pause");
                break;
            case 4:
                eliminar_area();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD PERSONAL ---

void insertar_personal() {
    char dni[20], nombre[MAX_STRING_LEN], social[20], movil[20], domicilio[MAX_STRING_LEN];
    float sueldo;
    int id_parque;

    leerCadenaSegura("DNI del personal: ", dni, 20);
    leerCadenaSegura("Nombre del personal: ", nombre, MAX_STRING_LEN);
    leerCadenaSegura("Numero de seguridad social: ", social, 20);
    sueldo = leerFlotanteSeguro("Sueldo ($): ");
    leerCadenaSegura("Telefono movil: ", movil, 20);
    leerCadenaSegura("Telefono domicilio: ", domicilio, MAX_STRING_LEN);
    id_parque = leerEnteroSeguro("ID del parque al que pertenece: ");


    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_parque FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un parque con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO personal (p_dni, p_nombre, s_social, sueldo, tel_movil, tel_domicilio, id_parque) "
        "VALUES('%s', '%s', '%s', %.2f, '%s', '%s', %d)",
        dni, nombre, social, sueldo, movil, domicilio, id_parque);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Personal registrado correctamente.\n");
    }
}

void leer_personal() {
    if (mysql_query(con, "SELECT p_dni, p_nombre, s_social, sueldo, tel_movil, tel_domicilio, id_parque FROM personal")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay personal registrado.\n");
    } else {
        printf("\n%-20s %-25s %-15s %-10s %-15s %-15s %-5s\n", "DNI", "Nombre", "Seg. Social", "Sueldo", "Movil", "Domicilio", "Parque");
        printf("--------------------------------------------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-20s %-25s %-15s %-10s %-15s %-15s %-5s\n",
                row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
        }
    }

    mysql_free_result(result);
}

void modificar_personal() {
    char dni[20];
    leerCadenaSegura("DNI del personal a modificar: ", dni, 20);

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char nombre[MAX_STRING_LEN], social[20], movil[20], domicilio[MAX_STRING_LEN];
    float sueldo;
    int id_parque;

    leerCadenaSegura("Nuevo nombre del personal: ", nombre, MAX_STRING_LEN);
    leerCadenaSegura("Nuevo numero de seguridad social: ", social, 20);
    sueldo = leerFlotanteSeguro("Nuevo sueldo ($): ");
    leerCadenaSegura("Nuevo telefono movil: ", movil, 20);
    leerCadenaSegura("Nuevo telefono domicilio: ", domicilio, MAX_STRING_LEN);
    id_parque = leerEnteroSeguro("Nuevo ID del parque: ");


    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_parque FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    result = mysql_store_result(con);
    row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un parque con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_update[MAX_QUERY_LEN];
    snprintf(query_update, sizeof(query_update),
        "UPDATE personal SET p_nombre='%s', s_social='%s', sueldo=%.2f, tel_movil='%s', tel_domicilio='%s', id_parque=%d WHERE p_dni='%s'",
        nombre, social, sueldo, movil, domicilio, id_parque, dni);

    if (mysql_query(con, query_update)) {
        finish_with_error();
    } else {
        printf("  Personal modificado correctamente.\n");
    }
}

void eliminar_personal() {
    char dni[20];
    leerCadenaSegura("DNI del personal a eliminar: ", dni, 20);


    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        printf("  Personal eliminado correctamente.\n");
    }
}
// --- SUBMENU PERSONAL ---
void menu_personal() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU PERSONAL ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar personal");
        gotoxy(20, 6); printf("2) Ver personal");
        gotoxy(20, 7); printf("3) Modificar personal");
        gotoxy(20, 8); printf("4) Eliminar personal");
        gotoxy(20, 9); printf("0) Volver al menu principal");

        gotoxy(20, 11); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_personal();
                system("pause");
                break;
            case 2:
                leer_personal();
                system("pause");
                break;
            case 3:
                modificar_personal();
                system("pause");
                break;
            case 4:
                eliminar_personal();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD P_GESTION ---

void insertar_p_gestion() {
    int id_pg, num_entrada;
    char dni[20];

    id_pg = leerEnteroSeguro("ID de p_gestion: ");
    num_entrada = leerEnteroSeguro("Numero de entradas: ");
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO p_gestion (id_pg, num_entrada, p_dni) VALUES (%d, %d, '%s')",
        id_pg, num_entrada, dni);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Personal de gestion registrado correctamente.\n");
    }
}

void leer_p_gestion() {
    if (mysql_query(con, "SELECT id_pg, num_entrada, p_dni FROM p_gestion")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay personal de gestion registrado.\n");
    } else {
        printf("\n%-5s %-15s %-20s\n", "ID", "Num. Entrada", "DNI");
        printf("-------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-5s %-15s %-20s\n", row[0], row[1], row[2]);
        }
    }

    mysql_free_result(result);
}

void eliminar_p_gestion() {
    int id_pg = leerEnteroSeguro("ID de p_gestion a eliminar: ");


    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_pg FROM p_gestion WHERE id_pg=%d", id_pg);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe p_gestion con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM p_gestion WHERE id_pg=%d", id_pg);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        printf("  Personal de gestion eliminado correctamente.\n");
    }
}

// --- SUBMENU P_GESTION ---
void menu_p_gestion() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU PERSONAL GESTION ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar personal gestion");
        gotoxy(20, 6); printf("2) Ver personal gestion");
        gotoxy(20, 7); printf("3) Eliminar personal gestion");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_p_gestion();
                system("pause");
                break;
            case 2:
                leer_p_gestion();
                system("pause");
                break;
            case 3:
                eliminar_p_gestion();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD P_INVESTIGADOR ---

void insertar_p_investigador() {
    int id_pi;
    char titulacion[MAX_STRING_LEN], dni[20];

    id_pi = leerEnteroSeguro("ID de p_investigador: ");
    leerCadenaSegura("Titulacion: ", titulacion, MAX_STRING_LEN);
    leerCadenaSegura("DNI del personal: ", dni, 20);


    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO p_investigador (id_pi, titulacion, p_dni) VALUES (%d, '%s', '%s')",
        id_pi, titulacion, dni);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Personal investigador registrado correctamente.\n");
    }
}

void leer_p_investigador() {
    if (mysql_query(con, "SELECT id_pi, titulacion, p_dni FROM p_investigador")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay personal investigador registrado.\n");
    } else {
        printf("\n%-5s %-30s %-20s\n", "ID", "Titulacion", "DNI");
        printf("---------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-5s %-30s %-20s\n", row[0], row[1], row[2]);
        }
    }

    mysql_free_result(result);
}

void eliminar_p_investigador() {
    int id_pi = leerEnteroSeguro("ID de p_investigador a eliminar: ");


    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_pi FROM p_investigador WHERE id_pi=%d", id_pi);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe p_investigador con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM p_investigador WHERE id_pi=%d", id_pi);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        printf("  Personal investigador eliminado correctamente.\n");
    }
}
// --- SUBMENU P_INVESTIGADOR ---
void menu_p_investigador() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU PERSONAL INVESTIGADOR ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar personal investigador");
        gotoxy(20, 6); printf("2) Ver personal investigador");
        gotoxy(20, 7); printf("3) Eliminar personal investigador");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_p_investigador();
                system("pause");
                break;
            case 2:
                leer_p_investigador();
                system("pause");
                break;
            case 3:
                eliminar_p_investigador();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD P_CONSERVACION ---

void insertar_p_conservacion() {
    int id_pc;
    char espec[MAX_STRING_LEN], dni[20];

    id_pc = leerEnteroSeguro("ID de p_conservacion: ");
    leerCadenaSegura("Especialidad: ", espec, MAX_STRING_LEN);
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO p_conservacion (id_pc, espec, p_dni) VALUES (%d, '%s', '%s')",
        id_pc, espec, dni);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Personal de conservacion registrado correctamente.\n");
    }
}

void leer_p_conservacion() {
    if (mysql_query(con, "SELECT id_pc, espec, p_dni FROM p_conservacion")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay personal de conservacion registrado.\n");
    } else {
        printf("\n%-5s %-30s %-20s\n", "ID", "Especialidad", "DNI");
        printf("---------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-5s %-30s %-20s\n", row[0], row[1], row[2]);
        }
    }

    mysql_free_result(result);
}

void eliminar_p_conservacion() {
    int id_pc = leerEnteroSeguro("ID de p_conservacion a eliminar: ");

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_pc FROM p_conservacion WHERE id_pc=%d", id_pc);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe p_conservacion con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM p_conservacion WHERE id_pc=%d", id_pc);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        printf("  Personal de conservacion eliminado correctamente.\n");
    }
}
// --- SUBMENU P_CONSERVACION ---
void menu_p_conservacion() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU PERSONAL CONSERVACION ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar personal conservacion");
        gotoxy(20, 6); printf("2) Ver personal conservacion");
        gotoxy(20, 7); printf("3) Eliminar personal conservacion");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_p_conservacion();
                system("pause");
                break;
            case 2:
                leer_p_conservacion();
                system("pause");
                break;
            case 3:
                eliminar_p_conservacion();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD P_VIGILANCIA ---

void insertar_p_vigilancia() {
    int id_pv;
    char tipo[MAX_STRING_LEN], matricula[50], dni[20];

    id_pv = leerEnteroSeguro("ID de p_vigilancia: ");
    leerCadenaSegura("Tipo de vigilancia: ", tipo, MAX_STRING_LEN);
    leerCadenaSegura("Matricula: ", matricula, 50);
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO p_vigilancia (id_pv, pv_tipo, matricula, p_dni) "
        "VALUES (%d, '%s', '%s', '%s')",
        id_pv, tipo, matricula, dni);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Personal de vigilancia registrado correctamente.\n");
    }
}

void leer_p_vigilancia() {
    if (mysql_query(con, "SELECT id_pv, pv_tipo, matricula, p_dni FROM p_vigilancia")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay personal de vigilancia registrado.\n");
    } else {
        printf("\n%-5s %-20s %-15s %-20s\n", "ID", "Tipo", "Matricula", "DNI");
        printf("------------------------------------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-5s %-20s %-15s %-20s\n", row[0], row[1], row[2], row[3]);
        }
    }

    mysql_free_result(result);
}

void eliminar_p_vigilancia() {
    int id_pv = leerEnteroSeguro("ID de p_vigilancia a eliminar: ");

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_pv FROM p_vigilancia WHERE id_pv=%d", id_pv);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe p_vigilancia con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM p_vigilancia WHERE id_pv=%d", id_pv);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        printf("  Personal de vigilancia eliminado correctamente.\n");
    }
}
// --- SUBMENU P_VIGILANCIA ---
void menu_p_vigilancia() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU PERSONAL VIGILANCIA ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar personal vigilancia");
        gotoxy(20, 6); printf("2) Ver personal vigilancia");
        gotoxy(20, 7); printf("3) Eliminar personal vigilancia");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_p_vigilancia();
                system("pause");
                break;
            case 2:
                leer_p_vigilancia();
                system("pause");
                break;
            case 3:
                eliminar_p_vigilancia();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD CONTRATA ---

void insertar_contrata() {
    int id_parque;
    char dni[20];

    id_parque = leerEnteroSeguro("ID del parque: ");
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_parque FROM parque WHERE id_parque=%d", id_parque);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un parque con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    result = mysql_store_result(con);
    row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO contrata (id_parque, p_dni) VALUES (%d, '%s')",
        id_parque, dni);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Relacion contrata insertada correctamente.\n");
    }
}

void leer_contrata() {
    if (mysql_query(con, "SELECT id_parque, p_dni FROM contrata")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay registros en contrata.\n");
    } else {
        printf("\n%-10s %-20s\n", "Parque", "DNI Personal");
        printf("-------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-10s %-20s\n", row[0], row[1]);
        }
    }

    mysql_free_result(result);
}

void eliminar_contrata() {
    int id_parque;
    char dni[20];

    id_parque = leerEnteroSeguro("ID del parque: ");
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM contrata WHERE id_parque=%d AND p_dni='%s'",
        id_parque, dni);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        if (mysql_affected_rows(con) == 0) {
            printf("  No existe esa relacion en contrata.\n");
        } else {
            printf("  Relacion contrata eliminada correctamente.\n");
        }
    }
}
// --- SUBMENU CONTRATA ---
void menu_contrata() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU RELACION CONTRATA ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar relacion contrata");
        gotoxy(20, 6); printf("2) Ver relaciones contrata");
        gotoxy(20, 7); printf("3) Eliminar relacion contrata");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_contrata();
                system("pause");
                break;
            case 2:
                leer_contrata();
                system("pause");
                break;
            case 3:
                eliminar_contrata();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD VIGILA ---

void insertar_vigila() {
    int id_area;
    char dni[20];

    id_area = leerEnteroSeguro("ID del area: ");
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_area FROM area WHERE id_area=%d", id_area);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un area con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    result = mysql_store_result(con);
    row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO vigila (id_area, p_dni) VALUES (%d, '%s')",
        id_area, dni);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Relacion vigila insertada correctamente.\n");
    }
}

void leer_vigila() {
    if (mysql_query(con, "SELECT id_area, p_dni FROM vigila")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay registros en vigila.\n");
    } else {
        printf("\n%-10s %-20s\n", "Area", "DNI Personal");
        printf("-------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-10s %-20s\n", row[0], row[1]);
        }
    }

    mysql_free_result(result);
}

void eliminar_vigila() {
    int id_area;
    char dni[20];

    id_area = leerEnteroSeguro("ID del area: ");
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM vigila WHERE id_area=%d AND p_dni='%s'",
        id_area, dni);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        if (mysql_affected_rows(con) == 0) {
            printf("  No existe esa relacion en vigila.\n");
        } else {
            printf("  Relacion vigila eliminada correctamente.\n");
        }
    }
}
// --- SUBMENU VIGILA ---
void menu_vigila() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU RELACION VIGILA ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar relacion vigila");
        gotoxy(20, 6); printf("2) Ver relaciones vigila");
        gotoxy(20, 7); printf("3) Eliminar relacion vigila");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_vigila();
                system("pause");
                break;
            case 2:
                leer_vigila();
                system("pause");
                break;
            case 3:
                eliminar_vigila();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD MANTIENE ---

void insertar_mantiene() {
    int id_area;
    char dni[20];

    id_area = leerEnteroSeguro("ID del area: ");
    leerCadenaSegura("DNI del personal: ", dni, 20);


    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_area FROM area WHERE id_area=%d", id_area);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe un area con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT p_dni FROM personal WHERE p_dni='%s'", dni);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    result = mysql_store_result(con);
    row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe personal con el DNI proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO mantiene (id_area, p_dni) VALUES (%d, '%s')",
        id_area, dni);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Relacion mantiene insertada correctamente.\n");
    }
}

void leer_mantiene() {
    if (mysql_query(con, "SELECT id_area, p_dni FROM mantiene")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay registros en mantiene.\n");
    } else {
        printf("\n%-10s %-20s\n", "Area", "DNI Personal");
        printf("-------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-10s %-20s\n", row[0], row[1]);
        }
    }

    mysql_free_result(result);
}

void eliminar_mantiene() {
    int id_area;
    char dni[20];

    id_area = leerEnteroSeguro("ID del area: ");
    leerCadenaSegura("DNI del personal: ", dni, 20);

    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM mantiene WHERE id_area=%d AND p_dni='%s'",
        id_area, dni);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        if (mysql_affected_rows(con) == 0) {
            printf("  No existe esa relacion en mantiene.\n");
        } else {
            printf("  Relacion mantiene eliminada correctamente.\n");
        }
    }
}
// --- SUBMENU MANTIENE ---
void menu_mantiene() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU RELACION MANTIENE ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar relacion mantiene");
        gotoxy(20, 6); printf("2) Ver relaciones mantiene");
        gotoxy(20, 7); printf("3) Eliminar relacion mantiene");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_mantiene();
                system("pause");
                break;
            case 2:
                leer_mantiene();
                system("pause");
                break;
            case 3:
                eliminar_mantiene();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- CRUD REALIZAN ---

void insertar_realizan() {
    int id_pi, id_investigacion;

    id_pi = leerEnteroSeguro("ID de p_investigador: ");
    id_investigacion = leerEnteroSeguro("ID de proyecto de investigacion: ");


    char query_verifica[MAX_QUERY_LEN];
    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_pi FROM p_investigador WHERE id_pi=%d", id_pi);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe p_investigador con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    snprintf(query_verifica, sizeof(query_verifica),
        "SELECT id_investigacion FROM proyecto_investigacion WHERE id_investigacion=%d", id_investigacion);

    if (mysql_query(con, query_verifica)) {
        finish_with_error();
    }

    result = mysql_store_result(con);
    row = mysql_fetch_row(result);

    if (row == NULL) {
        printf("  No existe proyecto_investigacion con el ID proporcionado.\n");
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);


    char query_insert[MAX_QUERY_LEN];
    snprintf(query_insert, sizeof(query_insert),
        "INSERT INTO realizan (id_pi, id_investigacion) VALUES (%d, %d)",
        id_pi, id_investigacion);

    if (mysql_query(con, query_insert)) {
        finish_with_error();
    } else {
        printf("  Relacion realizan insertada correctamente.\n");
    }
}

void leer_realizan() {
    if (mysql_query(con, "SELECT id_pi, id_investigacion FROM realizan")) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int num_rows = mysql_num_rows(result);

    if (num_rows == 0) {
        printf("\n  No hay registros en realizan.\n");
    } else {
        printf("\n%-10s %-20s\n", "ID Investigador", "ID Investigacion");
        printf("-------------------------------------\n");
        while ((row = mysql_fetch_row(result))) {
            printf("%-10s %-20s\n", row[0], row[1]);
        }
    }

    mysql_free_result(result);
}

void eliminar_realizan() {
    int id_pi, id_investigacion;

    id_pi = leerEnteroSeguro("ID de p_investigador: ");
    id_investigacion = leerEnteroSeguro("ID de proyecto de investigacion: ");

    char query_delete[MAX_QUERY_LEN];
    snprintf(query_delete, sizeof(query_delete),
        "DELETE FROM realizan WHERE id_pi=%d AND id_investigacion=%d",
        id_pi, id_investigacion);

    if (mysql_query(con, query_delete)) {
        finish_with_error();
    } else {
        if (mysql_affected_rows(con) == 0) {
            printf("  No existe esa relacion en realizan.\n");
        } else {
            printf("  Relacion realizan eliminada correctamente.\n");
        }
    }
}
// --- SUBMENU REALIZAN ---
void menu_realizan() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(14);
        gotoxy(20, 3); printf("==== MENU RELACION REALIZAN ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar relacion realizan");
        gotoxy(20, 6); printf("2) Ver relaciones realizan");
        gotoxy(20, 7); printf("3) Eliminar relacion realizan");
        gotoxy(20, 8); printf("0) Volver al menu principal");

        gotoxy(20, 10); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                insertar_realizan();
                system("pause");
                break;
            case 2:
                leer_realizan();
                system("pause");
                break;
            case 3:
                eliminar_realizan();
                system("pause");
                break;
            case 0:
                printf("Volviendo al menu principal.\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
// --- MENU PRINCIPAL ---
void menu() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(11);
        gotoxy(20, 2); printf("======================================");
        gotoxy(20, 3); printf("==== SISTEMA DE PARQUES NATURALES ====");
        gotoxy(20, 4); printf("======================================");
        setcolor(15);
        gotoxy(20, 6); printf("1) Gestionar Comunidad");
        gotoxy(20, 7); printf("2) Gestionar Parque");
        gotoxy(20, 8); printf("3) Gestionar Area");
        gotoxy(20, 9); printf("4) Gestionar Personal");

        gotoxy(20,11); printf("5) Gestionar Personal Gestion");
        gotoxy(20,12); printf("6) Gestionar Personal Investigador");
        gotoxy(20,13); printf("7) Gestionar Personal Conservacion");
        gotoxy(20,14); printf("8) Gestionar Personal Vigilancia");

        gotoxy(20,16); printf("9) Gestionar Relacion Contrata");
        gotoxy(20,17); printf("10) Gestionar Relacion Vigila");
        gotoxy(20,18); printf("11) Gestionar Relacion Mantiene");
        gotoxy(20,19); printf("12) Gestionar Relacion Realizan");

        gotoxy(20,21); printf("0) Salir del programa");

        gotoxy(20,23); printf("Selecciona una opcion: ");
        opcion = leerEnteroSeguro("");

        switch (opcion) {
            case 1:
                menu_comunidad();
                break;
            case 2:
                menu_parque();
                break;
            case 3:
                menu_area();
                break;
            case 4:
                menu_personal();
                break;
            case 5:
                menu_p_gestion();
                break;
            case 6:
                menu_p_investigador();
                break;
            case 7:
                menu_p_conservacion();
                break;
            case 8:
                menu_p_vigilancia();
                break;
            case 9:
                menu_contrata();
                break;
            case 10:
                menu_vigila();
                break;
            case 11:
                menu_mantiene();
                break;
            case 12:
                menu_realizan();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("  Opcion invalida.\n");
                system("pause");
                break;
        }
    } while (opcion != 0);
}
int main() {
    conectar();
    pantalla_bienvenida();
    menu();
    mysql_close(con);
    return 0;
}
