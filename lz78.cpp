#include <iostream>
#include <cstring>
using namespace std;

struct Nodo {
    int prefijo;
    char caracter;
};

int buscar(Nodo* dic, int tam, int prefijo, char c) {
    for (int i = 0; i < tam; i++) {
        if (dic[i].prefijo == prefijo && dic[i].caracter == c) {
            return i + 1;
        }
    }
    return 0;
}

void comprimirLZ78(const char* texto, Nodo*& salida, int& tamSalida) {
    int n = strlen(texto);
    Nodo* dic = new Nodo[n];
    salida = new Nodo[n];
    int tamDic = 0;
    int i = 0;

    cout << "\n--- COMPRESION LZ78 (PREVISUALIZACION) ---\n";

    while (i < n) {
        int prefijo = 0;
        int j = i;
        while (j < n) {
            int encontrado = buscar(dic, tamDic, prefijo, texto[j]);
            if (encontrado == 0) break;
            prefijo = encontrado;
            j++;
        }
        char c = texto[j];
        cout << "Salida encontrada: (" << prefijo << ", " << c << ")\n";
        salida[tamSalida].prefijo = prefijo;
        salida[tamSalida].caracter = c;
        tamSalida++;
        dic[tamDic].prefijo = prefijo;
        dic[tamDic].caracter = c;
        tamDic++;
        i = j + 1;
    }
    delete[] dic;
}

char* descomprimirLZ78(Nodo* entrada, int tam) {
    Nodo* dic = new Nodo[tam];
    char* resultado = new char[100000];
    int pos = 0;
    int tamDic = 0;
    cout << "\n--- DESCOMPRESION LZ78 (PREVISUALIZACION) ---\n";
    for (int i = 0; i < tam; i++) {
        int prefijo = entrada[i].prefijo;
        char c = entrada[i].caracter;
        cout << "Reconstruyendo: (" << prefijo << ", " << c << ")\n";
        char temp[1000];
        int k = 0;
        int p = prefijo;
        while (p != 0) {
            temp[k++] = dic[p - 1].caracter;
            p = dic[p - 1].prefijo;
        }
        for (int j = k - 1; j >= 0; j--) {
            resultado[pos++] = temp[j];
        }
        resultado[pos++] = c;
        dic[tamDic].prefijo = prefijo;
        dic[tamDic].caracter = c;
        tamDic++;
    }
    resultado[pos] = '\0';
    delete[] dic;
    return resultado;
}
