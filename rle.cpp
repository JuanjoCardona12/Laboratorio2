
#include <iostream>
#include <string>
using namespace std;

string comprimirRLE(const string& texto) {
    string resultado = "";
    int n = texto.length();
    cout << "\n--- DETALLE COMPRESION RLE ---\n";

    for (int i = 0; i < n; i++) {
        int contador = 1;
        while (i + 1 < n && texto[i] == texto[i + 1]) {
            contador++;
            i++;
        }
        cout << "Procesando: '" << texto[i] << "' repetido " << contador << " veces." << endl;
        resultado += to_string(contador);
        resultado += texto[i];
    }
    return resultado;
}

string descomprimirRLE(const string& texto) {
    string resultado = "";
    int n = texto.length();
    cout << "\n--- DETALLE DESCOMPRESION RLE ---\n";

    for (int i = 0; i < n; i++) {
        int num = 0;
        while (i < n && isdigit(texto[i])) {
            num = num * 10 + (texto[i] - '0');
            i++;
        }
        cout << "Expandiendo: " << num << " veces el caracter '" << texto[i] << "'" << endl;
        for (int j = 0; j < num; j++) {
            resultado += texto[i];
        }
    }
    return resultado;
}
