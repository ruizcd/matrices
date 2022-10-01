/*
SUMAR MATRICES
MULTIPLICAR MATRICES
*/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <windows.h>

using namespace std;

int i, j, k, Escalar;
int MatrizA[3][3], MatrizB[3][3], MatrizR[3][3];

void llenarA();
void llenarB();
void mostrarA();
void mostrarB();
void mostrarR();
void multi();
void inicio();
void limpiar();
void pausa();
void errorOP();
bool entero(char* a);
int validar(string a);
void resta();
void suma();
char nuS[100];
ostringstream msj;

int main() {
    int op;
    do {
        limpiar();
        cout << "Menu" << endl;
        cout << "1-Suma A+B" << endl;
        cout << "2-Resta A-B" << endl;
        cout << "3-Multiplicacion A*B" << endl;
        cout << "4-Salir" << endl;
        op = validar("\tOpcion: ");
        switch (op) {
        case 1:
            //suma
            limpiar();
            inicio();
            llenarA();
            llenarB();
            limpiar();
            mostrarA();
            mostrarB();
            suma();
            mostrarR();
            pausa();
            break;
        case 2:
            //resta
            limpiar();
            inicio();
            llenarA();
            llenarB();
            limpiar();
            mostrarA();
            mostrarB();
            resta();
            mostrarR();
            pausa();
            break;
        case 3:
            //multiplicacion 
            limpiar();
            inicio();
            llenarA();
            llenarB();
            limpiar();
            mostrarA();
            mostrarB();
            multi();
            mostrarR();
            pausa();
            break;
        case 4:
            limpiar();
            cout << "Programa Finalizado" << endl;
            break;
        default:
            errorOP(); pausa();
            break;
        }
    } while (op != 5);
    return 0;
}

void llenarA() {
    cout << "MATRIZ A." << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            msj.str("");
            msj << "Introduzca el valor del elemento [" << i << "][" << j << "]: ";
            MatrizA[i][j] = validar(msj.str());
        }
    }
    cout << endl;
}

void mostrarA() {
    cout << "MATRIZ A." << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << MatrizA[i][j] << " ";
            if (j == 2) cout << endl;
        }
    }
    cout << endl;
}

void llenarB() {
    cout << "MATRIZ B." << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            msj.str("");
            msj << "Introduzca el valor del elemento [" << i << "][" << j << "]: ";
            MatrizB[i][j] = validar(msj.str());
        }
    }
    cout << endl;
}
void mostrarB() {
    cout << "MATRIZ B." << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << MatrizB[i][j] << " ";
            if (j == 2) cout << endl;
        }
    }
    cout << endl;
}

void mostrarR() {
    cout << endl << "MATRIZ RESULTADO" << endl;
    cout << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << MatrizR[i][j] << " ";
            if (j == 2) cout << endl;
        }
    }
    cout << endl;
}

void inicio() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            MatrizA[i][j] = 0;
            MatrizB[i][j] = 0;
            MatrizR[i][j] = 0;
        }
    }
}

void multi() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            MatrizR[i][j] = 0;
            for (k = 0; k < 3; k++) {
                MatrizR[i][j] = MatrizR[i][j] + (MatrizA[i][k] * MatrizB[k][j]);
            }
        }
    }
}

void suma() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            MatrizR[i][j] = MatrizA[i][j] + MatrizB[i][j];
        }
    }
}

void resta() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            MatrizR[i][j] = MatrizA[i][j] - MatrizB[i][j];
        }
    }
}

void limpiar() {
    system("cls");
}

void pausa() {
    cout << "Presione una tecla para continuar...";
    cin.get();
    cin.get();
}

bool entero(char* a) {
    for (int i = 0; i < strlen(a); i++) {
        if (!isdigit(a[i])) {
            return false;
        }
    }
    return true;
}

int validar(string a) {
    do {
        cin.clear(); fflush(stdin);
        cout << a;
        cin >> nuS;
        if (!entero(nuS)) {
            errorOP();
        }
    } while (!entero(nuS));
    return atoi(nuS);
}

void errorOP() {
    cout << "Dato no valido, verifique.." << endl;
}