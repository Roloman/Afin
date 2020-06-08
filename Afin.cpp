// Afin.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Afin.h"



Afin::Afin()
{
    srand(time(NULL));
    clave_b = 1 + modulo(ZZ(rand()), tam_alfa);
    clave_a = 1 + modulo(ZZ (rand()),tam_alfa);
    while (ejer1(clave_a, tam_alfa) != 1) {
        clave_a = 1 + modulo(ZZ(rand()), tam_alfa);
    }
}

Afin::Afin(string Receeptor)
{
    clave_inversa = Inversa(clave_a, clave_b);
}

Afin::~Afin()
{
    //dtor
}


ZZ Afin::Valor_Absoluto(ZZ a)
{
    if (a < 0)
        return a * -1;
    else
    {
        return a;
    }
}

ZZ Afin::modulo(ZZ a, ZZ b)
{
    return a - ((a / b) * b);
}

ZZ Afin::ejer1(ZZ a, ZZ b)
{
    ZZ r = modulo(a, b);
    while (r != 0)
    {
        //cout << a << " = " << a / b << " (" << b << ") + " << a - (b * (a / b)) << endl;
        a = b;
        b = r;
        r = modulo(a, b);
    }
    //cout << a << " = " << a / b << " (" << b << ") + " << a - (b * (a / b)) << endl;
    return b;
}

ZZ Afin::Extendido_Euclides(ZZ a, ZZ b)
{
    ZZ q;
    ZZ r, r1, r2;
    ZZ s, s1, s2;
    ZZ t, t1, t2;

    r1 = a;
    r2 = b;
    s1 = ZZ(1);
    s2 = ZZ(0);
    t1 = ZZ(0);
    t2 = ZZ(1);

    while (r2 > 0) {

        q = r1 / r2;
        r = r1 - (q * r2);
        r1 = r2;
        r2 = r;

        s = s1 - (q * s2);
        s1 = s2;
        s2 = s;

        t = t1 - (q * t2);
        t1 = t2;
        t2 = t;
    }
    r = r1;
    s = s1;
    t = t1;
    if (s < 0)
        s = s % b;
    if (t < 0)
        t = t % a;
    cout << a << "(" << s << ") + " << b << "(" << t << ") = " << r << endl;
    return s;
}

ZZ Afin::Inversa(ZZ a, ZZ b) {

    ZZ r = ZZ(0);
    ZZ c;
    if (ejer1(a, b) == 1) {

        c = Extendido_Euclides(a, b);
        if (c < 0)
            c = modulo(c, b);

    }
    else
    {
        cout << a << " No tiene inversa" << endl;
        return r;
    }
    return c;
}

string Afin::cifrar(string mensaje)
{
    string cifrado;
    ZZ pos_letra, n;
    int a = 0;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);

        n = modulo(clave_a * pos_letra + clave_b, tam_alfa);
        if (n >= tam_alfa)
        {
            n = modulo(n, tam_alfa);
        }
        while (n > 0) {
            a++;
            n--;
        }
        cifrado += alfabeto[a];
    }
    return cifrado;
}

string Afin::descifrar(string mensaje)
{
    string decifrado;
    ZZ pos_letra, n;
    int a = 0;
    for (int i = 0; i < mensaje.size(); i++)
    {
        pos_letra = alfabeto.find(mensaje[i]);
        
        n = modulo(clave_inversa * (pos_letra - clave_b),tam_alfa);
        if (n < 0)
        {
            n += tam_alfa;
        }
        while (n > 0) {
            a++;
            n--;
        }
        decifrado += alfabeto[a];
    }
    return decifrado;
}

int main()
{
    string emisor;
    Afin a;
    ZZ b;
    cin >> b;
    //cout << a.Valor_Absoluto(b) << endl;

    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
