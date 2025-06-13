/**

CREATE TABLE personas (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100),
    edad INT
);

CREATE TABLE cursos (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100)
);

CREATE TABLE persona_curso (
    persona_id INT,
    curso_id INT,
    PRIMARY KEY (persona_id, curso_id),
    FOREIGN KEY (persona_id) REFERENCES personas(id) ON DELETE CASCADE,
    FOREIGN KEY (curso_id) REFERENCES cursos(id) ON DELETE CASCADE
);

SELECT c.id, c.nombre, p.nombre, p.edad
FROM cursos c
JOIN persona_curso pc ON c.id = pc.curso_id
JOIN personas p ON p.id = pc.persona_id
ORDER BY c.id;

SELECT c.id, c.nombre, p.nombre, p.edad
FROM cursos c
JOIN persona_curso pc ON c.id = pc.curso_id
JOIN personas p ON p.id = pc.persona_id
ORDER BY c.id;


gcc -o 5ManyToMany 5ManyToMany.c \
-I/usr/local/opt/mysql-client/include \
-L/usr/local/opt/mysql-client/lib \
-lmysqlclient

./5ManyToMany
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Program Files\MySQL\MySQL Server 8.0\include\mysql.h>

typedef struct {
    int id;
    char nombre[100];
    int edad;
} Persona;

typedef struct {
    int id;
    char nombre[100];
} Curso;

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

    if (mysql_real_connect(con, "localhost", "root", "12345", "basedatos",
        3306, NULL, 0) == NULL) {
        finish_with_error();
    }
}

int crear_persona(const Persona *persona) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO personas(nombre, edad) VALUES('%s', %d)",
        persona->nombre, persona->edad);

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    return mysql_insert_id(con);
}

int crear_curso(const char *nombre) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO cursos(nombre) VALUES('%s')", nombre);

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    return mysql_insert_id(con);
}

void inscribir_persona_en_curso(int persona_id, int curso_id) {
    char query[256];
    snprintf(query, sizeof(query),
        "INSERT INTO persona_curso(persona_id, curso_id) VALUES(%d, %d)",
        persona_id, curso_id);

    if (mysql_query(con, query)) {
        finish_with_error();
    }
}

void leer_personas_y_cursos() {
    const char *query =
        "SELECT p.id, p.nombre, p.edad, c.nombre "
        "FROM personas p "
        "JOIN persona_curso pc ON p.id = pc.persona_id "
        "JOIN cursos c ON c.id = pc.curso_id "
        "ORDER BY p.id";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_id = -1;

    while ((row = mysql_fetch_row(result))) {
        int persona_id = atoi(row[0]);
        const char *nombre = row[1];
        int edad = atoi(row[2]);
        const char *curso = row[3];

        if (persona_id != last_id) {
            printf("\nPersona ID: %d, Nombre: %s, Edad: %d\n", persona_id, nombre, edad);
            printf("Cursos:\n");
            last_id = persona_id;
        }

        printf(" - %s\n", curso);
    }

    mysql_free_result(result);
}

void leer_cursos_y_alumnos() {
    const char *query =
        "SELECT c.id, c.nombre, p.nombre, p.edad "
        "FROM cursos c "
        "JOIN persona_curso pc ON c.id = pc.curso_id "
        "JOIN personas p ON p.id = pc.persona_id "
        "ORDER BY c.id";

    if (mysql_query(con, query)) {
        finish_with_error();
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        finish_with_error();
    }

    MYSQL_ROW row;
    int last_curso_id = -1;

    while ((row = mysql_fetch_row(result))) {
        int curso_id = atoi(row[0]);
        const char *curso_nombre = row[1];
        const char *alumno_nombre = row[2];
        int alumno_edad = atoi(row[3]);

        if (curso_id != last_curso_id) {
            printf("\nCurso ID: %d, Nombre: %s\n", curso_id, curso_nombre);
            printf("Alumnos:\n");
            last_curso_id = curso_id;
        }

        printf(" - %s (Edad: %d)\n", alumno_nombre, alumno_edad);
    }

    mysql_free_result(result);
}

int main() {
    conectar();

    Persona persona = {0, "María", 30};
    int persona_id = crear_persona(&persona);

    int curso1 = crear_curso("Programación en C");
    int curso2 = crear_curso("Bases de Datos");

    inscribir_persona_en_curso(persona_id, curso1);
    inscribir_persona_en_curso(persona_id, curso2);

    printf("\n== Personas con sus cursos ==\n");
    leer_personas_y_cursos();

    printf("\n== Cursos con sus alumnos ==\n");
    leer_cursos_y_alumnos();

    mysql_close(con);
    return 0;
}

