#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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

    if (mysql_real_connect(con, "localhost", "root", "12345", "tu_basededatos", 
    3306, NULL, 0) == NULL) {
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

// FUNCIONES COMUNIDAD
void insertar_comunidad(const char *nombre) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO comunidad (canombre) VALUES('%s')", nombre);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Comunidad registrada.\n");
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

    printf("ID\tNombre\n-------------------\n");
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        printf("%s\t%s\n", row[0], row[1]);
    }

    mysql_free_result(result);
}

// FUNCIONES PARQUE
void insertar_parque(const char *nombre, const char *fecha, float superficie, int id_ca) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO parque (pnombre, fec_declaracion, superficie, id_ca) "
        "VALUES('%s', '%s', %.2f, %d)",
        nombre, fecha, superficie, id_ca);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Parque registrado.\n");
    }
}

// FUNCIONES AREA
void insertar_area(const char *nombre, float extension, int id_parque) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO area (anombre, extension, id_parque) "
        "VALUES('%s', %.2f, %d)", nombre, extension, id_parque);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Área registrada.\n");
    }
}

// FUNCIONES PERSONAL
void insertar_personal(const char *dni, const char *nombre, const char *social, float sueldo, const char *movil, const char *domicilio, int id_parque) {
    char query[512];
    snprintf(query, sizeof(query),
        "INSERT INTO personal (p_dni, p_nombre, s_social, sueldo, tel_movil, tel_domicilio, id_parque) "
        "VALUES('%s', '%s', '%s', %.2f, '%s', '%s', %d)",
        dni, nombre, social, sueldo, movil, domicilio, id_parque);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Personal registrado.\n");
    }
}

// FUNCIONES p_gestion
void insertar_p_gestion(int id_pg, int num_entrada, const char *dni) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO p_gestion (id_pg, num_entrada, p_dni) "
        "VALUES(%d, %d, '%s')", id_pg, num_entrada, dni);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Personal de gestión registrado.\n");
    }
}

// FUNCIONES p_investigador
void insertar_p_investigador(int id_pi, const char *titulacion, const char *dni) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO p_investigador (id_pi, titulacion, p_dni) "
        "VALUES(%d, '%s', '%s')", id_pi, titulacion, dni);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Personal investigador registrado.\n");
    }
}

// FUNCIONES p_conservacion
void insertar_p_conservacion(int id_pc, const char *especialidad, const char *dni) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO p_conservacion (id_pc, espec, p_dni) "
        "VALUES(%d, '%s', '%s')", id_pc, especialidad, dni);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Personal de conservación registrado.\n");
    }
}

// FUNCIONES p_vigilancia
void insertar_p_vigilancia(int id_pv, const char *tipo, const char *matricula, const char *dni) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO p_vigilancia (id_pv, pv_tipo, matricula, p_dni) "
        "VALUES(%d, '%s', '%s', '%s')", id_pv, tipo, matricula, dni);

    if (mysql_query(con, query)) {
        finish_with_error();
    } else {
        printf("Personal de vigilancia registrado.\n");
    }
}

// MENU PRINCIPAL
void menu() {
    int opcion;
    do {
        limpiarPantalla();
        setcolor(11);
        gotoxy(20, 3); printf("==== MENU DE PARQUES NATURALES ====");
        setcolor(15);
        gotoxy(20, 5); printf("1) Insertar comunidad");
        gotoxy(20, 6); printf("2) Ver comunidades");
        gotoxy(20, 7); printf("3) Insertar parque");
        gotoxy(20, 8); printf("4) Insertar área");
        gotoxy(20, 9); printf("5) Insertar personal");
        gotoxy(20,10); printf("6) Insertar personal gestion");
        gotoxy(20,11); printf("7) Insertar personal investigador");
        gotoxy(20,12); printf("8) Insertar personal conservacion");
        gotoxy(20,13); printf("9) Insertar personal vigilancia");
        gotoxy(20,14); printf("0) Salir");

        gotoxy(20,16); printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: {
                char nombre[100];
                printf("Nombre de la comunidad: ");
                fgets(nombre, sizeof(nombre), stdin);
                nombre[strcspn(nombre, "\n")] = 0;
                insertar_comunidad(nombre);
                system("pause");
                break;
            }
            case 2:
                leer_comunidades();
                system("pause");
                break;
            case 3: {
                char nombre[100], fecha[20];
                float superficie;
                int id_ca;
                printf("Nombre del parque: ");
                fgets(nombre, sizeof(nombre), stdin); nombre[strcspn(nombre, "\n")] = 0;
                printf("Fecha de declaracion (YYYY-MM-DD): ");
                fgets(fecha, sizeof(fecha), stdin); fecha[strcspn(fecha, "\n")] = 0;
                printf("Superficie: ");
                scanf("%f", &superficie); getchar();
                printf("ID comunidad: ");
                scanf("%d", &id_ca); getchar();

                insertar_parque(nombre, fecha, superficie, id_ca);
                system("pause");
                break;
            }
            case 4: {
                char nombre[100];
                float extension;
                int id_parque;
                printf("Nombre del área: ");
                fgets(nombre, sizeof(nombre), stdin); nombre[strcspn(nombre, "\n")] = 0;
                printf("Extension: ");
                scanf("%f", &extension); getchar();
                printf("ID parque: ");
                scanf("%d", &id_parque); getchar();

                insertar_area(nombre, extension, id_parque);
                system("pause");
                break;
            }
            case 5: {
                char dni[20], nombre[100], social[20], movil[20], domicilio[100];
                float sueldo;
                int id_parque;
                printf("DNI: "); fgets(dni, sizeof(dni), stdin); dni[strcspn(dni, "\n")] = 0;
                printf("Nombre: "); fgets(nombre, sizeof(nombre), stdin); nombre[strcspn(nombre, "\n")] = 0;
                printf("Seguridad Social: "); fgets(social, sizeof(social), stdin); social[strcspn(social, "\n")] = 0;
                printf("Sueldo: "); scanf("%f", &sueldo); getchar();
                printf("Teléfono movil: "); fgets(movil, sizeof(movil), stdin); movil[strcspn(movil, "\n")] = 0;
                printf("Domicilio: "); fgets(domicilio, sizeof(domicilio), stdin); domicilio[strcspn(domicilio, "\n")] = 0;
                printf("ID del parque: "); scanf("%d", &id_parque); getchar();

                insertar_personal(dni, nombre, social, sueldo, movil, domicilio, id_parque);
                system("pause");
                break;
            }
            case 6: {
                int id_pg, num_entrada;
                char dni[20];
                printf("ID p_gestion: "); scanf("%d", &id_pg); getchar();
                printf("Número de entrada: "); scanf("%d", &num_entrada); getchar();
                printf("DNI personal: "); fgets(dni, sizeof(dni), stdin); dni[strcspn(dni, "\n")] = 0;

                insertar_p_gestion(id_pg, num_entrada, dni);
                system("pause");
                break;
            }
            case 7: {
                int id_pi;
                char titulacion[100], dni[20];
                printf("ID p_investigador: "); scanf("%d", &id_pi); getchar();
                printf("Titulación: "); fgets(titulacion, sizeof(titulacion), stdin); titulacion[strcspn(titulacion, "\n")] = 0;
                printf("DNI personal: "); fgets(dni, sizeof(dni), stdin); dni[strcspn(dni, "\n")] = 0;

                insertar_p_investigador(id_pi, titulacion, dni);
                system("pause");
                break;
            }
            case 8: {
                int id_pc;
                char especialidad[100], dni[20];
                printf("ID p_conservacion: "); scanf("%d", &id_pc); getchar();
                printf("Especialidad: "); fgets(especialidad, sizeof(especialidad), stdin); especialidad[strcspn(especialidad, "\n")] = 0;
                printf("DNI personal: "); fgets(dni, sizeof(dni), stdin); dni[strcspn(dni, "\n")] = 0;

                insertar_p_conservacion(id_pc, especialidad, dni);
                system("pause");
                break;
            }
            case 9: {
                int id_pv;
                char tipo[50], matricula[50], dni[20];
                printf("ID p_vigilancia: "); scanf("%d", &id_pv); getchar();
                printf("Tipo de vigilancia: "); fgets(tipo, sizeof(tipo), stdin); tipo[strcspn(tipo, "\n")] = 0;
                printf("Matrícula: "); fgets(matricula, sizeof(matricula), stdin); matricula[strcspn(matricula, "\n")] = 0;
                printf("DNI personal: "); fgets(dni, sizeof(dni), stdin); dni[strcspn(dni, "\n")] = 0;

                insertar_p_vigilancia(id_pv, tipo, matricula, dni);
                system("pause");
                break;
            }
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida.\n");
                system("pause");
                break;
        }

    } while (opcion != 0);
}

int main() {
    conectar();
    menu();
    mysql_close(con);
    return 0;
}
