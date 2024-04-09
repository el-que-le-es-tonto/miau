/*
Nombre de la asignatura: Paradigmas de programacion
NRC: 8150 / Seccion: 558

Leve descripcion: miau

Nombres autores: Maximiliano Cantillana [AGREGAR RUT]
                  Catalina Gamonal [AGREGAR RUT]
                  Valeria apellidoxd [AGREGAR RUT]
                  Liliana Valverde 21.438.525.2
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>

// Definici�n de constantes para el n�mero m�ximo de meses y sucursales
const int MAX_MESES = 12;
const int MAX_SUCURSALES = 15;

// Contrase�as para operador y directivo
const std::string CONTRASENA_OPERADOR = "operador123";
const std::string CONTRASENA_DIRECTIVO = "directivo456";

// Clase Mes para almacenar las ventas de cada sucursal en cada mes
class Mes {
private:
    float ventas[MAX_SUCURSALES]; // Array para almacenar las ventas de cada sucursal

public:
    // M�todo para establecer las ventas de una sucursal en un mes espec�fico
    void setVentas(int sucursal, float monto) {
        ventas[sucursal - 1] = monto; // Se resta 1 para ajustar el �ndice del array
    }

    // M�todo para obtener las ventas de una sucursal en un mes espec�fico
    float getVentas(int sucursal) const {
        return ventas[sucursal - 1]; // Se resta 1 para ajustar el �ndice del array
    }
};

// Clase Sistema para gestionar las ventas
class Sistema {
protected:
    int M; // N�mero de meses
    int N; // N�mero de sucursales
    Mes meses[MAX_MESES]; // Array de objetos Mes para almacenar las ventas

public:
    // Constructor que inicializa el n�mero de meses y sucursales
    Sistema(int meses, int sucursales) : M(meses), N(sucursales) {}

    // M�todo para ingresar las ventas de cada sucursal en cada mes
    void ingresarVentas() {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                float monto;
                std::cout << "Ingrese ventas de la sucursal " << j + 1 << " en el mes " << i + 1 << ": ";
                std::cin >> monto;
                meses[i].setVentas(j + 1, monto); // Se llama al m�todo setVentas de la clase Mes
            }
        }
    }

    // M�todo para mostrar las ventas de cada sucursal en cada mes
    void mostrarVentas() const {
        std::cout << "\nMontos de ventas de " << N << " sucursales en " << M << " meses" << std::endl;
        std::cout << std::setw(10) << "Sucursales";
        for (int i = 0; i < M; ++i) {
            std::cout << std::setw(10) << "Mes " << i + 1;
        }
        std::cout << std::endl;
        for (int j = 0; j < N; ++j) {
            std::cout << std::setw(10) << "Sucursal " << j + 1;
            for (int i = 0; i < M; ++i) {
                std::cout << std::setw(10) << meses[i].getVentas(j + 1); // Se llama al m�todo getVentas de la clase Mes
            }
            std::cout << std::endl;
        }
    }

    // M�todo para respaldar los datos de ventas en un archivo
    void respaldarDatos(const std::string& nombreArchivo) const {
        std::ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            archivo << "Montos de ventas de " << N << " sucursales en " << M << " meses" << std::endl;
            for (int j = 0; j < N; ++j) {
                archivo << "Sucursal " << j + 1 << ": ";
                for (int i = 0; i < M; ++i) {
                    archivo << meses[i].getVentas(j + 1) << " "; // Se llama al m�todo getVentas de la clase Mes
                }
                archivo << std::endl;
            }
            archivo.close();
            std::cout << "Datos respaldados en archivo: " << nombreArchivo << std::endl;
        } else {
            std::cerr << "No se pudo abrir el archivo para respaldar datos." << std::endl;
        }
    }
};

// Funci�n para limpiar el b�fer de entrada de cin
// Esto se utiliza para eliminar cualquier entrada adicional en el b�fer de entrada despu�s de leer datos de cin,
// permitiendo que el programa contin�e su ejecuci�n sin problemas.
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int M, N; // Variables para el n�mero de meses y sucursales
    int opcion;

    std::cout << "Cosmeticos gatito: Sistema de gestion de ventas." << std::endl;

    do {
        // Men� principal para seleccionar el tipo de usuario
        std::cout << "\nSeleccione el tipo de usuario:" << std::endl;
        std::cout << "1. Operador" << std::endl;
        std::cout << "2. Directivo" << std::endl;
        std::cout << "3. Salir del programa" << std::endl;
        std::cin >> opcion;

        clearInputBuffer();

        if (opcion == 1) { // Opci�n para operador
            std::string contrasena;
            std::cout << "\nIngrese la clave de operador: ";
            std::cin >> contrasena;

            if (contrasena == CONTRASENA_OPERADOR) { // Verificaci�n de la contrase�a del operador
                do {
                    std::cout << "\nIngrese el numero de sucursales (maximo 15): ";
                    std::cin >> N;
                    if (N < 1 || N > MAX_SUCURSALES) {
                        std::cout << "El numero de sucursales debe estar entre 1 y 15!!!" << std::endl;
                    }
                } while (N < 1 || N > MAX_SUCURSALES);

                do {
                    std::cout << "Ingrese el numero de meses (maximo 12): ";
                    std::cin >> M;
                    if (M < 1 || M > MAX_MESES) {
                        std::cout << "El numero de meses debe estar entre 1 y 12!!!" << std::endl;
                    }
                } while (M < 1 || M > MAX_MESES);

                Sistema sistema(M, N);
                sistema.ingresarVentas();
                sistema.mostrarVentas();

                std::string nombreArchivo;
                std::cout << "\nDesea respaldar los datos en un archivo? (S/N): ";
                char respuesta;
                std::cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    std::cout << "Ingrese el nombre del archivo para respaldar los datos: ";
                    std::cin >> nombreArchivo;
                    sistema.respaldarDatos(nombreArchivo);
                }
            } else {
                std::cout << "\nINCORRECTO, ACCESO DENEGADO." << std::endl;
            }
        } else if (opcion == 2) { // Opci�n para directivo
            std::string contrasena;
            std::cout << "\nIngrese la clave de directivo: ";
            std::cin >> contrasena;

            if (contrasena == CONTRASENA_DIRECTIVO) { // Verificaci�n de la contrase�a del directivo
                std::cout << "\nFuncionalidad del Directivo aun no implementada miau :33" << std::endl;
            } else {
                std::cout << "\nINCORRECTO, ACCESO DENEGADO." << std::endl;
            }
        } else if (opcion != 3) { // Opci�n para salir del programa
            std::cout << "\nOpcion invalida. Por favor, seleccione una opcion valida." << std::endl;
        }
    } while (opcion != 3); // El bucle contin�a hasta que se selecciona la opci�n de salir del programa

    return 0;
}

