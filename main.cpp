#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int op;

    do {

        cout << "1. Cambio dinero\n";
        cout << "3. Comparar cadenas\n";
        cout << "5. Entero a string\n";
        cout << "7. Eliminar repetidos\n";
        cout << "9. Sumar bloques\n";
        cout << "11. Cine\n";
        cout << "13. Estrellas\n";
        cout << "15. Rectangulos\n";
        cout << "17. Numeros amigables\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";

        cin >> op;
        cin.ignore();
        //me presentaba error y era por datos residuales en la memoria temporal de entrada y buacando como solucionar use  cin.ignore() para limpiar la entrada

        switch (op) {

        case 1: {
            int x;
            cout << "Cantidad: ";
            cin >> x;
            cambioDinero(x);
            break;
        }

        case 3: {
            char a[100], b[100];

            cout << "Cadena 1: ";
            cin.getline(a, 100);

            cout << "Cadena 2: ";
            cin.getline(b, 100);

            if (compararCadenas(a, b))
                cout << "Iguales\n";
            else
                cout << "Diferentes\n";
            break;
        }

        case 5: {
            int n;
            char cad[100];

            cout << "Ingrese numero: ";
            cin >> n;
            enteroAString(n, cad);

            cout << "Resultado: " << cad << endl;
            break;
        }

        case 7: {
            char cad[100];

            cout << "Ingrese cadena: ";
            cin.getline(cad, 100);

            eliminarRepetidos(cad);
            cout << "Sin repetidos: " << cad << endl;
            break;
        }

        case 9: {
            char cad[100];
            int n;

            cout << "Cadena numerica: ";
            cin.getline(cad, 100);

            cout << "Tamano de bloque: ";
            cin >> n;

            cout << "Suma: " << sumarBloques(cad, n) << endl;
            break;
        }

        case 11: {
            cine();
            break;
        }

        case 13: {
            int mat[6][8] = {
                {0,3,4,0,0,0,6,8},
                {5,13,6,0,0,0,2,3},
                {2,6,2,7,3,0,10,0},
                {0,0,4,15,4,1,6,0},
                {0,0,7,12,6,9,10,4},
                {5,0,6,10,6,4,8,0}
            };

            cout << "Estrellas: "
                 << contarEstrellas((int*)mat, 6, 8) << endl;
            break;
        }

        case 15: {
            int A[4], B[4], C[4];

            cout << "Rectangulo A (x y w h): ";
            for (int i = 0; i < 4; i++) cin >> A[i];

            cout << "Rectangulo B (x y w h): ";
            for (int i = 0; i < 4; i++) cin >> B[i];

            interseccionRect(A, B, C);

            cout << "Interseccion: ";
            for (int i = 0; i < 4; i++) cout << C[i] << " ";
            cout << endl;
            break;
        }

        case 17: {
            int n;
            cout << "Ingrese numero: ";
            cin >> n;

            cout << "Suma amigables: " << sumaAmigables(n) << endl;
            break;
        }

        case 0:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (op != 0);

    return 0;
}
