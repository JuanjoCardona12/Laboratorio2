#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// ---------- PUNTO 1 ----------
void cambioDinero(int cantidad) {
    int valores[] = {50000,20000,10000,5000,2000,1000,500,200,100,50};
    int *p = valores;

    for(int i = 0; i < 10; i++){
        cout << *(p+i) << ": " << cantidad / *(p+i) << endl;
        cantidad %= *(p+i);
    }

    if(cantidad > 0)
        cout << "Faltante: " << cantidad << endl;
}

// ---------- PUNTO 3 ----------
bool compararCadenas(char *a, char *b){
    int i = 0;

    while(*(a+i) != '\0' && *(b+i) != '\0'){
        if(*(a+i) != *(b+i))
            return false;
        i++;
    }

    return *(a+i) == *(b+i);
}

// ---------- PUNTO 5 ----------
void enteroAString(int num, char *cad){
    int i = 0;

    if(num == 0){
        *(cad+i) = '0';
        *(cad+i+1) = '\0';
        return;
    }

    int temp = num;

    while(temp > 0){
        *(cad+i) = (temp % 10) + '0';
        temp /= 10;
        i++;
    }

    *(cad+i) = '\0';

    // invertir usando punteros
    for(int j = 0; j < i/2; j++){
        char t = *(cad+j);
        *(cad+j) = *(cad+i-j-1);
        *(cad+i-j-1) = t;
    }
}

// ---------- PUNTO 7 ----------
void eliminarRepetidos(char *cad){
    int len = strlen(cad);

    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(*(cad+i) == *(cad+j)){
                for(int k = j; k < len; k++){
                    *(cad+k) = *(cad+k+1);
                }
                len--;
                j--;
            }
        }
    }
}

// ---------- PUNTO 9 ----------
int sumarBloques(char *cad, int n){
    int len = strlen(cad);
    int suma = 0;

    for(int i = 0; i < len; i += n){
        int num = 0;

        for(int j = 0; j < n && (i+j) < len; j++){
            num = num*10 + (*(cad+i+j) - '0');
        }

        suma += num;
    }

    return suma;
}

// ---------- PUNTO 11 ----------
void cine(){
    int filas = 15, cols = 20;

    int **sala = new int*[filas];

    for(int i = 0; i < filas; i++){
        *(sala+i) = new int[cols];
    }

    // inicializar
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            *(*(sala+i)+j) = 0;
        }
    }

    int fila, asiento;

    cout << "Fila (0-14): ";
    cin >> fila;

    cout << "Asiento (0-19): ";
    cin >> asiento;

    *(*(sala+fila)+asiento) = 1;

    // mostrar
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < cols; j++){
            cout << (*(*(sala+i)+j) ? "+ " : "- ");
        }
        cout << endl;
    }

    // liberar memoria
    for(int i = 0; i < filas; i++){
        delete[] *(sala+i);
    }
    delete[] sala;
}

// ---------- PUNTO 13 ----------
int contarEstrellas(int *mat, int f, int c){
    int cont = 0;

    for(int i = 1; i < f-1; i++){
        for(int j = 1; j < c-1; j++){
            int val = *(mat + i*c + j)
            + *(mat + i*c + j - 1)
                + *(mat + i*c + j + 1)
                + *(mat + (i-1)*c + j)
                + *(mat + (i+1)*c + j);

            if(val/5 > 6)
                cont++;
        }
    }

    return cont;
}

// ---------- PUNTO 15 ----------
void interseccionRect(int *A, int *B, int *C){
    int x1 = (*(A) > *(B)) ? *(A) : *(B);
    int y1 = (*(A+1) > *(B+1)) ? *(A+1) : *(B+1);

    int x2 = (*(A)+*(A+2) < *(B)+*(B+2)) ? *(A)+*(A+2) : *(B)+*(B+2);
    int y2 = (*(A+1)+*(A+3) < *(B+1)+*(B+3)) ? *(A+1)+*(A+3) : *(B+1)+*(B+3);

    *(C) = x1;
    *(C+1) = y1;
    *(C+2) = x2 - x1;
    *(C+3) = y2 - y1;
}

// ---------- PUNTO 17 ----------
int sumaDiv(int n){
    int suma = 0;

    for(int i = 1; i < n; i++){
        if(n % i == 0)
            suma += i;
    }

    return suma;
}

int sumaAmigables(int n){
    int suma = 0;

    for(int i = 1; i < n; i++){
        int b = sumaDiv(i);

        if(b != i && sumaDiv(b) == i){
            suma += i;
        }
    }

    return suma;
}
