#pragma once

#include <NTL/ZZ.h>
#include <string>
#include <time.h>
#include <iostream>

using namespace std;
using namespace NTL;

class Afin
{
public:
	Afin();
	Afin(string Receeptor);

	string alfabeto = "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ ";
	ZZ tam_alfa = ZZ(alfabeto.size());
	ZZ clave_b;
	ZZ clave_inversa;

	ZZ Valor_Absoluto(ZZ a);
	ZZ modulo(ZZ a, ZZ b);
	ZZ ejer1(ZZ a, ZZ b);
	ZZ Extendido_Euclides(ZZ a, ZZ b);
	ZZ Inversa(ZZ a, ZZ b);

	string cifrar(string mensaje);
	string descifrar(string mensaje);

	virtual ~Afin();
protected:
private:
	ZZ clave_a;
};