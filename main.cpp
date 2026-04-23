#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <bitset>

using namespace std;

// Declaraciones de funciones externas
string comprimirRLE(const string&);
string descomprimirRLE(const string&);
struct Nodo { int prefijo; char caracter; };
void comprimirLZ78(const char*, Nodo*&, int&);
char* descomprimirLZ78(Nodo*, int);
void encriptar(unsigned char*, int, int, unsigned char);
void desencriptar(unsigned char*, int, int, unsigned char);

int main() {
    // 1. Try-Catch: Entrada de datos
    try {
        string texto;
        int tipoEntrada;
        cout << "--- TIPO DE ENTRADA ---\n1. Archivo\n2. Manual\nSeleccione: ";
        cin >> tipoEntrada; cin.ignore();

        if (tipoEntrada == 1) {
            string nombreArchivo; cout << "Archivo: "; cin >> nombreArchivo;
            ifstream archivo(nombreArchivo);
            if (!archivo) throw runtime_error("Error abriendo archivo");
            texto = string((istreambuf_iterator<char>(archivo)), istreambuf_iterator<char>());
            archivo.close();
        } else if (tipoEntrada == 2) {
            cout << "Texto: "; getline(cin, texto);
        } else {
            throw invalid_argument("Opcion invalida");
        }

        // 2. Try-Catch: Configuración
        int opcion, n;
        int claveTemp;
        cout << "\n1. RLE, 2. LZ78, 3. Bits: "; cin >> opcion;
        cout << "Rotacion (1-7): "; cin >> n;
        cout << "Clave (0-255): "; cin >> claveTemp;


        if (n <= 0 || n >= 8) throw invalid_argument("Rotacion invalida (debe ser 1-7)");
        unsigned char clave = (unsigned char)claveTemp;

        string resultadoFinal;

        // 3. Try-Catch: Procesamiento
        try {
            if (opcion == 1) { // RLE
                string comprimido = comprimirRLE(texto);
                unsigned char* data = new unsigned char[comprimido.size()];
                memcpy(data, comprimido.c_str(), comprimido.size());

                cout << "\n--- ENCRIPTANDO (RLE) ---\n";
                encriptar(data, comprimido.size(), n, clave);

                cout << "Texto encriptado (bytes): " << string((char*)data, comprimido.size()) << endl;

                cout << "\n--- DESENCRIPTANDO (RLE) ---\n";
                desencriptar(data, comprimido.size(), n, clave);

                string temp((char*)data, comprimido.size());
                resultadoFinal = descomprimirRLE(temp);
                delete[] data;
            }
            else if (opcion == 2) {
                char textoC[100000]; strncpy(textoC, texto.c_str(), 99999);
                Nodo* salida = nullptr; int tam = 0;
                comprimirLZ78(textoC, salida, tam);

                unsigned char* data = new unsigned char[tam * 2];
                for (int i = 0; i < tam; i++) {
                    data[i * 2] = (unsigned char)salida[i].prefijo;
                    data[i * 2 + 1] = salida[i].caracter;
                }

                cout << "\n--- ENCRIPTANDO (LZ78) ---\n";
                encriptar(data, tam * 2, n, clave);

                cout << "Texto encriptado (bytes): ";
                for(int i=0; i<tam*2; i++) cout << (char)data[i];
                cout << endl;

                cout << "\n--- DESENCRIPTANDO (LZ78) ---\n";
                desencriptar(data, tam * 2, n, clave);

                for (int i = 0; i < tam; i++) {
                    salida[i].prefijo = data[i * 2];
                    salida[i].caracter = data[i * 2 + 1];
                }
                char* descomp = descomprimirLZ78(salida, tam);
                resultadoFinal = string(descomp);
                delete[] data; delete[] salida; delete[] descomp;
            }
            else if (opcion == 3) {
                int size = texto.size();
                unsigned char* data = new unsigned char[size];
                memcpy(data, texto.c_str(), size);

                cout << "\n--- ENCRIPTANDO (BITS) ---\n";
                encriptar(data, size, n, clave);
                cout << "Texto encriptado: " << string((char*)data, size) << endl;

                cout << "\n--- DESENCRIPTANDO (BITS) ---\n";
                desencriptar(data, size, n, clave);
                resultadoFinal = string((char*)data, size);
                delete[] data;
            }
            else throw invalid_argument("Opcion de algoritmo invalida");
        } catch (...) {
            throw runtime_error("Fallo durante el procesamiento del algoritmo");
        }

        // 4. Try-Catch: Verificación final
        if (resultadoFinal != texto) {
            throw runtime_error("Los datos no coinciden tras la descompresion");
        }
        cout << "\n--- TODO CORRECTO ---\nResultado: " << resultadoFinal << endl;

    } catch (const exception& e) {
        cerr << "\nError critico: " << e.what() << endl;
        return 1;
    }
    return 0;
}
