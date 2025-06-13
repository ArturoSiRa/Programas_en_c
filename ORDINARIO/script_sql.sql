CREATE DATABASE IF NOT EXISTS  ordi_prog;
USE ordi_prog;

SET FOREIGN_KEY_CHECKS = 0;

CREATE TABLE comunidad (
    id_ca INT PRIMARY KEY,
    canombre VARCHAR(100) NOT NULL
);

CREATE TABLE parque (
    id_parque INT PRIMARY KEY,
    pnombre VARCHAR(100) NOT NULL,
    fec_declaracion DATE,
    superficie DECIMAL(10,2),
    id_ca INT,
    FOREIGN KEY (id_ca) REFERENCES comunidad(id_ca)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE area (
    id_area INT PRIMARY KEY,
    anombre VARCHAR(100),
    extension DECIMAL(10,2),
    id_parque INT,
    FOREIGN KEY (id_parque) REFERENCES parque(id_parque)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE especies (
    id_especie INT PRIMARY KEY,
    ncmbr_cien VARCHAR(100) NOT NULL,
    ncmbr_com VARCHAR(100)
);

CREATE TABLE animal (
    id_animal INT PRIMARY KEY,
    p_celo VARCHAR(50),
    tipo_alimentacion ENUM('herbivoro','carnivoro','omnivoro') NOT NULL,
    id_especie INT NOT NULL,
    FOREIGN KEY (id_especie) REFERENCES especies(id_especie)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE vegetal (
    id_vegetal INT PRIMARY KEY,
    floracion VARCHAR(50),
    id_especie INT NOT NULL,
    FOREIGN KEY (id_especie) REFERENCES especies(id_especie)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE mineral (
    id_mineral INT PRIMARY KEY,
    tipo_mineral VARCHAR(50),
    id_especie INT NOT NULL,
    FOREIGN KEY (id_especie) REFERENCES especies(id_especie)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE visitante (
    v_dni VARCHAR(20) PRIMARY KEY,
    v_nombre VARCHAR(100),
    domicilio VARCHAR(150),
    profesion VARCHAR(50)
);

CREATE TABLE alojamiento (
    id_alojamiento INT PRIMARY KEY,
    capacidad INT CHECK (capacidad > 0),
    categoria ENUM('1 estrella','2 estrellas','3 estrellas','4 estrellas','5 estrellas'),
    id_parque INT,
    FOREIGN KEY (id_parque) REFERENCES parque(id_parque)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE excursiones (
    id_excursion INT PRIMARY KEY,
    tipo ENUM('vehiculo','a pie') NOT NULL,
    fecha DATE,
    hora TIME,
    id_alojamiento INT,
    FOREIGN KEY (id_alojamiento) REFERENCES alojamiento(id_alojamiento)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE personal (
    p_dni VARCHAR(20) PRIMARY KEY,
    p_nombre VARCHAR(100),
    s_social VARCHAR(20),
    sueldo DECIMAL(10,2) CHECK (sueldo >= 0),
    tel_movil VARCHAR(20),
    tel_domicilio VARCHAR(20),
    id_parque INT,
    FOREIGN KEY (id_parque) REFERENCES parque(id_parque)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE p_gestion (
    id_pg INT PRIMARY KEY,
    num_entrada INT CHECK (num_entrada >= 0),
    p_dni VARCHAR(20),
    FOREIGN KEY (p_dni) REFERENCES personal(p_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE p_conservacion (
    id_pc INT PRIMARY KEY,
    espec VARCHAR(100),
    p_dni VARCHAR(20),
    FOREIGN KEY (p_dni) REFERENCES personal(p_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE p_investigador (
    id_pi INT PRIMARY KEY,
    titulacion VARCHAR(100),
    p_dni VARCHAR(20),
    FOREIGN KEY (p_dni) REFERENCES personal(p_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE p_vigilancia (
    id_pv INT PRIMARY KEY,
    pv_tipo VARCHAR(50),
    matricula VARCHAR(50),
    p_dni VARCHAR(20),
    FOREIGN KEY (p_dni) REFERENCES personal(p_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE proyecto_investigacion (
    id_investigacion INT PRIMARY KEY,
    presupuesto DECIMAL(12,2) CHECK (presupuesto >= 0),
    periodo VARCHAR(50)
);

-- RELACIONES N:M

CREATE TABLE contiene (
    id_parque INT,
    id_alojamiento INT,
    PRIMARY KEY (id_parque, id_alojamiento),
    FOREIGN KEY (id_parque) REFERENCES parque(id_parque)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_alojamiento) REFERENCES alojamiento(id_alojamiento)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE aloja (
    v_dni VARCHAR(20),
    id_alojamiento INT,
    PRIMARY KEY (v_dni, id_alojamiento),
    FOREIGN KEY (v_dni) REFERENCES visitante(v_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_alojamiento) REFERENCES alojamiento(id_alojamiento)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE paga (
    v_dni VARCHAR(20),
    id_excursion INT,
    PRIMARY KEY (v_dni, id_excursion),
    FOREIGN KEY (v_dni) REFERENCES visitante(v_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_excursion) REFERENCES excursiones(id_excursion)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE organizan (
    id_excursion INT,
    id_alojamiento INT,
    PRIMARY KEY (id_excursion, id_alojamiento),
    FOREIGN KEY (id_excursion) REFERENCES excursiones(id_excursion)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_alojamiento) REFERENCES alojamiento(id_alojamiento)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE contrata (
    id_parque INT,
    p_dni VARCHAR(20),
    PRIMARY KEY (id_parque, p_dni),
    FOREIGN KEY (id_parque) REFERENCES parque(id_parque)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (p_dni) REFERENCES personal(p_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE vigila (
    id_area INT,
    p_dni VARCHAR(20),
    PRIMARY KEY (id_area, p_dni),
    FOREIGN KEY (id_area) REFERENCES area(id_area)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (p_dni) REFERENCES personal(p_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE mantiene (
    id_area INT,
    p_dni VARCHAR(20),
    PRIMARY KEY (id_area, p_dni),
    FOREIGN KEY (id_area) REFERENCES area(id_area)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (p_dni) REFERENCES personal(p_dni)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE realizan (
    id_pi INT,
    id_investigacion INT,
    PRIMARY KEY (id_pi, id_investigacion),
    FOREIGN KEY (id_pi) REFERENCES p_investigador(id_pi)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_investigacion) REFERENCES proyecto_investigacion(id_investigacion)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE alberga (
    id_area INT,
    id_especie INT,
    PRIMARY KEY (id_area, id_especie),
    FOREIGN KEY (id_area) REFERENCES area(id_area)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_especie) REFERENCES especies(id_especie)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE alimentan (
    id_animal INT,
    id_especie INT,
    PRIMARY KEY (id_animal, id_especie),
    FOREIGN KEY (id_animal) REFERENCES animal(id_animal)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_especie) REFERENCES especies(id_especie)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE estudia (
    id_investigacion INT,
    id_especie INT,
    PRIMARY KEY (id_investigacion, id_especie),
    FOREIGN KEY (id_investigacion) REFERENCES proyecto_investigacion(id_investigacion)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    FOREIGN KEY (id_especie) REFERENCES especies(id_especie)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);


SET FOREIGN_KEY_CHECKS = 1;
