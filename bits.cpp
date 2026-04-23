#include <iostream>
#include <bitset>
using namespace std;

unsigned char rotarIzquierda(unsigned char c, int n) {
    return (c << n) | (c >> (8 - n));
}

unsigned char rotarDerecha(unsigned char c, int n) {
    return (c >> n) | (c << (8 - n));
}

unsigned char aplicarXOR(unsigned char c, unsigned char k) {
    return c ^ k;
}

void encriptar(unsigned char* data, int size, int n, unsigned char clave) {
    cout << "\n--- ENCRIPTACION BITS ---\n";
    for (int i = 0; i < size; i++) {
        unsigned char original = data[i];
        unsigned char rotado = rotarIzquierda(original, n);
        unsigned char xoreado = aplicarXOR(rotado, clave);
        if (i < 20) cout << "Byte " << i << ": " << bitset<8>(original) << " -> " << bitset<8>(xoreado) << endl;
        data[i] = xoreado;
    }
}

void desencriptar(unsigned char* data, int size, int n, unsigned char clave) {
    cout << "\n--- DESENCRIPTACION BITS ---\n";
    for (int i = 0; i < size; i++) {
        unsigned char encriptado = data[i];
        unsigned char xoreado = aplicarXOR(encriptado, clave);
        unsigned char original = rotarDerecha(xoreado, n);
        if (i < 20) cout << "Byte " << i << ": " << bitset<8>(encriptado) << " -> " << bitset<8>(original) << endl;
        data[i] = original;
    }
}
