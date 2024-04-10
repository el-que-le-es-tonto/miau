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
using namespace std;

// Definición de constantes para el número máximo de meses y sucursales
const int MAX_MESES = 12, MAX_SUCURSALES = 15;

// Contraseñas para operador y directivo
const string CONTRASENA_OPERADOR = "operador123", CONTRASENA_DIRECTIVO = "directivo456";

// Clase Mes para almacenar las ventas de cada sucursal en cada mes
class Mes {
private:
    float ventas[MAX_SUCURSALES]; // Array para almacenar las ventas de cada sucursal

public:
    // Método para establecer las ventas de una sucursal en un mes específico
    void setVentas(int sucursal, float monto) {
        ventas[sucursal - 1] = monto; // Se resta 1 para ajustar el índice del array
    }

    // Método para obtener las ventas de una sucursal en un mes específico
    float getVentas(int sucursal) const {
        return ventas[sucursal - 1]; // Se resta 1 para ajustar el índice del array
    }
};

// Clase Sistema para gestionar las ventas
class Sistema {
protected:
    int M; // Número de meses
    int N; // Número de sucursales
    Mes meses[MAX_MESES]; // Array de objetos Mes para almacenar las ventas

public:
    // Constructor que inicializa el número de meses y sucursales
    Sistema(int meses, int sucursales) : M(meses), N(sucursales) {}

    // Método para ingresar las ventas de cada sucursal en cada mes
    void ingresarVentas() {
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                float monto;
                cout << "Ingrese ventas de la sucursal " << j + 1 << " en el mes " << i + 1 << ": ";
                cin >> monto;
                meses[i].setVentas(j + 1, monto); // Se llama al método setVentas de la clase Mes
            }
        }
    }

    // Método para mostrar las ventas de cada sucursal en cada mes
    void mostrarVentas() const {
        cout << "\nMontos de ventas de " << N << " sucursales en " << M << " meses" << endl;
        cout << setw(10) << "Sucursales";
        for (int i = 0; i < M; ++i) {
            cout << setw(10) << "Mes " << i + 1;
        }
        cout << endl;
        for (int j = 0; j < N; ++j) {
            cout << setw(10) << "Sucursal " << j + 1;
            for (int i = 0; i < M; ++i) {
                cout << setw(10) << meses[i].getVentas(j + 1); // Se llama al método getVentas de la clase Mes
            }
            cout << endl;
        }
    }

    // Método para respaldar los datos de ventas en un archivo
    void respaldarDatos(const string& nombreArchivo) const {
        ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            archivo << "Montos de ventas de " << N << " sucursales en " << M << " meses" << endl;
            for (int j = 0; j < N; ++j) {
                archivo << "Sucursal " << j + 1 << ": ";
                for (int i = 0; i < M; ++i) {
                    archivo << meses[i].getVentas(j + 1) << " "; // Se llama al método getVentas de la clase Mes
                }
                archivo << endl;
            }
            archivo.close();
            cout << "Datos respaldados en archivo: " << nombreArchivo << endl;
        } else {
            cerr << "No se pudo abrir el archivo para respaldar datos." << endl;
        }
    }
};

// Función para limpiar el búfer de entrada de cin
// Esto se utiliza para eliminar cualquier entrada adicional en el búfer de entrada después de leer datos de cin,
// permitiendo que el programa continúe su ejecución sin problemas.
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int M, N; // Variables para el número de meses y sucursales
    int opcion;

    cout << "Cosmeticos gatito: Sistema de gestion de ventas." << endl;

    do {
        // Menú principal para seleccionar el tipo de usuario
        cout << "\nSeleccione el tipo de usuario:" << endl;
        cout << "1. Operador" << endl;
        cout << "2. Directivo" << endl;
        cout << "3. Salir del programa" << endl;
        cin >> opcion;

        clearInputBuffer();

        if (opcion == 1) { // Opción para operador
            string contrasena;
            cout << "\nIngrese la clave de operador: ";
            cin >> contrasena;

            if (contrasena == CONTRASENA_OPERADOR) { // Verificación de la contraseña del operador
                do {
                    cout << "\nIngrese el numero de sucursales (maximo 15): ";
                    cin >> N;
                    if (N < 1 || N > MAX_SUCURSALES) {
                        cout << "El numero de sucursales debe estar entre 1 y 15!!!" << endl;
                    }
                } while (N < 1 || N > MAX_SUCURSALES);

                do {
                    cout << "Ingrese el numero de meses (maximo 12): ";
                    cin >> M;
                    if (M < 1 || M > MAX_MESES) {
                        cout << "El numero de meses debe estar entre 1 y 12!!!" << endl;
                    }
                } while (M < 1 || M > MAX_MESES);

                Sistema sistema(M, N);
                sistema.ingresarVentas();
                sistema.mostrarVentas();

                string nombreArchivo;
                cout << "\nDesea respaldar los datos en un archivo? (S/N): ";
                char respuesta;
                cin >> respuesta;
                if (respuesta == 'S' || respuesta == 's') {
                    cout << "Ingrese el nombre del archivo para respaldar los datos: ";
                    cin >> nombreArchivo;
                    sistema.respaldarDatos(nombreArchivo);
                }
            } else {
                cout << "\nINCORRECTO, ACCESO DENEGADO." << endl;
            }
        } else if (opcion == 2) { // Opción para directivo
            string contrasena;
            cout << "\nIngrese la clave de directivo: ";
            cin >> contrasena;

            if (contrasena == CONTRASENA_DIRECTIVO) { // Verificación de la contraseña del directivo
                cout << "\nFuncionalidad del Directivo aun no implementada miau :33" << endl;
            } else {
                cout << "\nINCORRECTO, ACCESO DENEGADO." << endl;
            }
        } else if (opcion != 3) { // Opción para salir del programa
            cout << "\nOpcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 3); // El bucle continúa hasta que se selecciona la opción de salir del programa

    return 0;
}
