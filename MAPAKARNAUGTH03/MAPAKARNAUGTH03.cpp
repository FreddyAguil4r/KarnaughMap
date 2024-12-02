// MAPAKARNAUGTH03.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <math.h>

using namespace System;
using namespace std;

//int tipo;

void IngresarTérminos(string **&ArrFuncion, int NumeroDeTerminos, int
	NumeroDeVariables) {
	ArrFuncion = new string *[NumeroDeTerminos];
	cout << "Terminos de la funcion:" << endl;
	for (int i = 0; i < NumeroDeTerminos; i++)
	{
		ArrFuncion[i] = new string[NumeroDeVariables];
		cout << "Ingrese el termino " << i + 1 << ": ";
		for (int j = 0; j < NumeroDeVariables; j++)
			cin >> ArrFuncion[i][j];
	}
	cout << endl;
}
void MostrarFuncion(string **&ArrFuncion, int NumeroDeTerminos, int NumeroDeVariables)
{
	cout << "Funcion booleana a simplificar:" << endl;
	if (NumeroDeVariables == 3) cout << "F(A,B,C)= ";
	if (NumeroDeVariables == 4) cout << "F(A,B,C,D)= ";
	for (int i = 0; i < NumeroDeTerminos; i++)
	{
		for (int j = 0; j < NumeroDeVariables; j++)
			cout << ArrFuncion[i][j];
		if (i<NumeroDeTerminos - 1)cout << " + ";
	}
	cout << endl;
}
void TerminosDeLaFuncionABooleanos(string **&ArrFuncion, int **&ArrMatriz, int
	NumeroDeTerminos, int NumeroDeVariables) {
	int N = pow(2, NumeroDeVariables) / 4;
	ArrMatriz = new int *[N];
	string A = "A", A1 = "A'", B = "B", B1 = "B'", C = "C", C1 = "C'", D = "D", D1 = "D'";

	for (int i = 0; i < N; i++)
	{
		ArrMatriz[i] = new int[4];
		for (int j = 0; j < 4; j++)
			ArrMatriz[i][j] = 0;
	}
	for (int i = 0; i < NumeroDeTerminos; i++)
	{
			if (NumeroDeVariables == 3)
			{
				if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B && ArrFuncion[i][2] == C) ArrMatriz[1][2] = 1;
				if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B &&
					ArrFuncion[i][2] == C1) ArrMatriz[0][2] = 1;
				if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B1 &&
					ArrFuncion[i][2] == C) ArrMatriz[1][3] = 1;
				if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B1 &&
					ArrFuncion[i][2] == C1) ArrMatriz[0][3] = 1;
				if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B &&
					ArrFuncion[i][2] == C) ArrMatriz[1][1] = 1;
				if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B &&
					ArrFuncion[i][2] == C1) ArrMatriz[0][1] = 1;
				if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B1 &&
					ArrFuncion[i][2] == C) ArrMatriz[1][0] = 1;
				if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B1 &&
					ArrFuncion[i][2] == C1) ArrMatriz[0][0] = 1;
			}
		if (NumeroDeVariables == 4)
		{
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D) ArrMatriz[2][2] = 1;
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D1) ArrMatriz[3][2] = 1;
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D) ArrMatriz[1][2] = 1;
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D1) ArrMatriz[0][2] = 1;
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D) ArrMatriz[2][3] = 1;
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D1) ArrMatriz[3][3] = 1;
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D) ArrMatriz[1][3] = 1;
			if (ArrFuncion[i][0] == A && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D1) ArrMatriz[0][3] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D) ArrMatriz[2][1] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D1) ArrMatriz[3][1] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D) ArrMatriz[1][1] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D1) ArrMatriz[0][1] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D) ArrMatriz[2][0] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C && ArrFuncion[i][3] == D1)ArrMatriz[3][0] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D) ArrMatriz[1][0] = 1;
			if (ArrFuncion[i][0] == A1 && ArrFuncion[i][1] == B1 &&
				ArrFuncion[i][2] == C1 && ArrFuncion[i][3] == D1) ArrMatriz[0][0] = 1;
		}
	}
	cout << endl;
}
void MostrarMatrizBoleana(int **&ArrMatriz, int NumeroDeVariables) {
	cout << "Mapa de Karnaugh:" << endl;
	int N = pow(2, NumeroDeVariables) / 4;
	if (NumeroDeVariables == 3) {
		cout << "C/AB|";
		cout << " 00 01 11 10" << endl;
		cout << "----|------------" << endl;
	}
	if (NumeroDeVariables == 4) {
		cout << "CD/AB|";
		cout << " 00 01 11 10" << endl;
		cout << "-----|------------" << endl;
	}
	for (int i = 0; i < N; i++)
	{
		if (NumeroDeVariables == 3) cout << "   " << i << "|";
		if (NumeroDeVariables == 4) {
			switch (i)
			{
			case 0: cout << "   00" << "|"; break;
			case 1: cout << "   01" << "|"; break;
			case 2: cout << "   11" << "|"; break;
			case 3: cout << "   10" << "|"; break;
			}
		}
		for (int j = 0; j < 4; j++)
			cout << " " << ArrMatriz[i][j] << " ";
		cout << endl;
	}
}

string P2cuadrosFilas(int **&ArrMatriz, int NumeroDeVariables)
{
	
	string Funcion;
	int px1, py1, px2, py2;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (ArrMatriz[i][j] == 1 && ArrMatriz[i][j + 1] == 1) {
				
				//cout << "fila en h: (" << i << "); Columna en h: (" << j << ")" << endl;
				px1 = i; py1 = j; px2 = i; py2 = j+1;
				if (px1 == 0 && py1 == 0 && px2 == 0 && py2 == 1) 
					Funcion += "+ A'C'D'";
				if (px1 == 0 && py1 == 1 && px2 == 0 && py2 == 2)
					Funcion +="+ BC'D'";
				if (px1 == 0 && py1 == 2 && px2 == 0 && py2 == 3)
					Funcion += "+ AC'D'";
				////////////////////////////////////////////////
				if (px1 == 1 && py1 == 0 && px2 == 1 && py2 == 1)
					Funcion += "+ A'C'D";
				if (px1 == 1 && py1 == 1 && px2 == 1 && py2 == 2)
					Funcion += "+ BC'D";
				if (px1 == 1 && py1 == 2 && px2 == 1 && py2 == 3)
					Funcion += "+ AC'D";
				/////////////////////////////////////////////////
				if (px1 == 2 && py1 == 0 && px2 == 2 && py2 == 1)
					Funcion += "+ A'CD";
				if (px1 == 2 && py1 == 1 && px2 == 1 && py2 == 2)
					Funcion += "+ BCD";
				if (px1 == 2 && py1 == 2 && px2 == 2 && py2 == 3)
					Funcion += "+ ACD";
				/////////////////////////////////////////////////
				if (px1 == 3 && py1 == 0 && px2 == 3 && py2 == 1)
					Funcion += "+ A'CD'";
				if (px1 == 3 && py1 == 1 && px2 == 3 && py2 == 2)
					Funcion += "+ BCD'";
				if (px1 == 3 && py1 == 2 && px2 == 3 && py2 == 3)
					Funcion += "+ ACD'" ;

			}//fin primer if
		}
	}
	//tipo = 1;
	return Funcion;
}

string P2cuadrosColumnas(int **&ArrMatriz, int NumeroDeVariables)
{
	int tipo = 0;
	string Funcion2;
	int px1, py1, px2, py2;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ArrMatriz[i][j] == 1 && ArrMatriz[i + 1][j] == 1) {
				//cout << "fila en v: " << i << "; Columna en v: " << j;
				tipo = 2;
				px1 = i; py1 = j; px2 = i+1; py2 = j;
				if (px1 == 0 && py1 == 0 && px2 == 1 && py2 == 0)
					Funcion2 += "+ A'B'C'";
				if (px1 == 0 && py1 == 1 && px2 == 1 && py2 == 1)
					Funcion2 += "+ A'BC'";
				if (px1 == 0 && py1 == 2 && px2 == 1 && py2 == 2)
					Funcion2 += "+ ABC'";
				if (px1 == 0 && py1 == 3 && px2 == 1 && py2 == 3)
					Funcion2 += "+ AB'C'";
				/////////////////////////////////////////////////////////
				if (px1 == 1 && py1 == 0 && px2 == 2 && py2 == 0)
					Funcion2 += "+ A'B'D";
				if (px1 == 1 && py1 == 1 && px2 == 2 && py2 == 1)
					Funcion2 += "+ A'BD";
				if (px1 == 1 && py1 == 2 && px2 == 2 && py2 == 2)
					Funcion2 += "+ ABD";
				if (px1 == 1 && py1 == 3 && px2 == 2 && py2 == 3)
					Funcion2 += "+ AB'D";
				///////////////////////////////////////////////////////
				if (px1 == 2 && py1 == 0 && px2 == 3 && py2 == 0)
					Funcion2 += "+ A'B'C";
				if (px1 == 2 && py1 == 1 && px2 == 3 && py2 == 1)
					Funcion2 += "+ A'BC";
				if (px1 == 2 && py1 == 2 && px2 == 3 && py2 == 2)
					Funcion2 += "+ ABC";
				if (px1 == 2 && py1 == 3 && px2 == 3 && py2 == 3)
					Funcion2 += "+ AB'C";
				}
		}
	}
	return Funcion2;
}

string P4cuadrosFilas(int **&ArrMatriz, int NumeroDeVariables)
{
	
	string Funcion;
	int px1, py1, px2, py2,px3,py3,px4,py4;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 1; j++)
		{

			if (ArrMatriz[i][j] == 1 && ArrMatriz[i][j + 1] == 1 && ArrMatriz[i][j + 2] == 1 && ArrMatriz[i][j + 3]) {
				px1 = i; py1 = j;  px2 = i;  py2 = j + 1;  px3 = i;  py3 = j + 2;  px4 = i;  py4 = j + 3;
				if (px1 == 0 && py1 == 0 && px2 == 0 && py2 == 1 && px3 ==0 && py3 == 2 && px4 ==0 && py4 ==3)
					Funcion += "+ C'D'";
				if (px1 == 1 && py1 == 0 && px2 == 1 && py2 == 1 && px3 == 1 && py3 == 2 && px4 == 1 && py4 == 3)
					Funcion += "+ C'D";
				if (px1 == 2 && py1 == 0 && px2 == 2 && py2 == 1 && px3 == 2 && py3 == 2 && px4 == 2 && py4 == 3)
					Funcion += "+ CD";
				if (px1 == 3 && py1 == 0 && px2 == 3 && py2 == 1 && px3 == 3 && py3 == 2 && px4 == 3 && py4 == 3)
					Funcion += "+ CD'";
     		}
		}
	}
	//tipo = 3;
	return Funcion;
}

string P4cuadrosColumnas(int **&ArrMatriz, int NumeroDeVariables)
{
	string Funcion;
	int px1, py1, px2, py2, px3, py3, px4, py4;
	for (int i = 0; i < 1; i++)
		{
		for (int j = 0; j < 4; j++)
		{
			if (ArrMatriz[i][j] == 1 && ArrMatriz[i + 1][j] == 1 && ArrMatriz[i + 2][j] == 1 && ArrMatriz[i + 3][j]) {
				px1 = i; py1 = j;  px2 = i+1;  py2 = j;  px3 = i+2;  py3 = j;  px4 = i +3;  py4 = j;
				if (px1 == 0 && py1 == 0 && px2 == 1 && py2 == 0 && px3 == 2 && py3 == 0 && px4 == 3 && py4 == 0)
					Funcion += "+ A'B'";
				if (px1 == 0 && py1 == 1 && px2 == 1 && py2 == 1 && px3 == 2 && py3 == 1 && px4 == 3 && py4 == 1)
					Funcion += "+ A'B";
				if (px1 == 0 && py1 == 2 && px2 == 1 && py2 == 2 && px3 == 2 && py3 == 2 && px4 == 3 && py4 == 2)
					Funcion += "+ AB";
				if (px1 == 0 && py1 == 3 && px2 == 1 && py2 == 3 && px3 == 2 && py3 == 3 && px4 == 3 && py4 == 3)
					Funcion += "+ AB'";
			 }
		  }
		}
	return Funcion;
}

string P8DobleFila(int **&ArrMatriz, int NumeroDeVariables)
{
	string Funcion;
	int px1, py1, px2, py2, px3, py3, px4, py4,px5,py5,px6,py6,px7,py7,px8,py8;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (ArrMatriz[i][j] == 1 && ArrMatriz[i][j + 1] == 1 && ArrMatriz[i][j + 2] == 1 && ArrMatriz[i][j + 3] == 1 && ArrMatriz[i + 1][j] == 1 && ArrMatriz[i + 1][j + 1] == 1 && ArrMatriz[i + 1][j + 2] == 1 && ArrMatriz[i + 1][j + 3] == 1) {
				px1 = i; py1 = j;  px2 = i;  py2 = j + 1;  px3 = i;  py3 = j + 2;  px4 = i;  py4 = j + 3; px5 = i + 1; py5 = j; px6 = i + 1; py6 = j + 1; px7 = i + 1; py7 = j + 2; px8 = i + 1; py8 = j + 3;
				if (px1 == 0 && py1 == 0 && px2 == 0 && py2 == 1 && px3 == 0 && py3 == 2 && px4 == 0 && py4 == 3 && px5==1 && py5==0 && px6==1 && py6==1 && px7==1 && py7==2 && px8==1 && py8==3)
					Funcion += "+ C'";
				if (px1 == 1 && py1 == 0 && px2 == 1 && py2 == 1 && px3 == 1 && py3 == 2 && px4 == 1 && py4 == 3 && px5 == 2 && py5 == 0 && px6 == 2 && py6 == 1 && px7 == 2 && py7 == 2 && px8 == 2 && py8 == 3)
					Funcion += "+ D";
				if (px1 == 2 && py1 == 0 && px2 == 2 && py2 == 1 && px3 == 2 && py3 == 2 && px4 == 2 && py4 == 3 && px5 == 3 && py5 == 0 && px6 == 3 && py6 == 1 && px7 == 3 && py7 == 2 && px8 == 3 && py8 == 3)
					Funcion += "+ C";
			}
		}
	}
	return Funcion;
}

string P8DobleColumna(int **&ArrMatriz, int NumeroDeVariables)
{
	string Funcion;
	int px1, py1, px2, py2, px3, py3, px4, py4, px5, py5, px6, py6, px7, py7, px8, py8;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (ArrMatriz[i][j] == 1 && ArrMatriz[i][j + 1] == 1 && ArrMatriz[i + 1][j] == 1 && ArrMatriz[i + 1][j + 1] == 1 && ArrMatriz[i + 2][j] == 1 && ArrMatriz[i + 2][j + 1] == 1 && ArrMatriz[i + 1][j] == 1 && ArrMatriz[i + 3][j + 1] == 1) {
				px1 = i; py1 = j;  px2 = i;  py2 = j + 1;  px3 = i+1;  py3 = j;  px4 = i+1;  py4 = j + 1; px5 = i + 2; py5 = j; px6 = i + 2; py6 = j + 1; px7 = i + 1; py7 = j; px8 = i + 3; py8 = j + 1;
				if (px1 == 0 && py1 == 0 && px2 == 1 && py2 == 0 && px3 == 2 && py3 == 0 && px4 == 3 && py4 == 0 && px5 == 0 && py5 == 1 && px6 == 1 && py6 == 1 && px7 == 2 && py7 == 1 && px8 == 3 && py8 == 1)
					Funcion += "+ A'";
				if (px1 == 0 && py1 == 1 && px2 == 1 && py2 == 1 && px3 == 2 && py3 == 1 && px4 == 3 && py4 == 1 && px5 == 0 && py5 == 2 && px6 == 1 && py6 == 2 && px7 == 2 && py7 == 2 && px8 == 3 && py8 == 2)
					Funcion += "+ B";
				if (px1 == 0 && py1 == 2 && px2 == 1 && py2 == 2 && px3 == 2 && py3 == 2 && px4 == 3 && py4 == 2 && px5 == 0 && py5 == 3 && px6 == 1 && py6 == 3 && px7 == 2 && py7 == 3 && px8 == 3 && py8 == 3)
					Funcion += "+ A";
			}
		}
	}
	return Funcion;
}

string P4Cuadrado(int **&ArrMatriz, int NumeroDeVariables) {
	string Funcion;
	int px1, py1, px2, py2, px3, py3, px4,py4;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (ArrMatriz[i][j] == 1 && ArrMatriz[i][j + 1] == 1 && ArrMatriz[i + 1][j] == 1 && ArrMatriz[i + 1][j + 1] == 1) {
				px1 = i; py1 = j;  px2 = i;  py2 = j + 1;  px3 = i + 1;  py3 = j;  px4 = i + 1;  py4 = j+1;
				if (px1 == 0 && py1 == 0 && px2 == 0 && py2 == 1 && px3 == 1 && py3 == 0 && px4 == 1 && py4==1)
					Funcion += "+ A'C'";
				if (px1 == 0 && py1 == 1 && px2 == 0 && py2 == 2 && px3 == 1 && py3 == 1 && px4 == 1 && py4 == 2)
					Funcion += "+ BC'";
				if (px1 == 0 && py1 == 2 && px2 == 0 && py2 == 3 && px3 == 1 && py3 == 2 && px4 == 1 && py4 == 3)
					Funcion += "+ AC'";
				/////////////////////////////////////////////////////////////////////////////////////////////
				if (px1 == 1 && py1 == 0 && px2 == 1 && py2 == 1 && px3 == 2 && py3 == 0 && px4 == 2 && py4 == 1)
					Funcion += "+ A'D";
				if (px1 == 1 && py1 == 1 && px2 == 1 && py2 == 2 && px3 == 2 && py3 == 1 && px4 == 2 && py4 == 2)
					Funcion += "+ BD";
				if (px1 == 1 && py1 == 2 && px2 == 1 && py2 == 3 && px3 == 2 && py3 == 2 && px4 == 2 && py4 == 3)
					Funcion += "+ AD";
				//////////////////////////////////////////////////////////////////////////////////////////////
				if (px1 == 2 && py1 == 0 && px2 == 2 && py2 == 1 && px3 == 3 && py3 == 0 && px4 == 3 && py4 == 1)
					Funcion += "+ A'C";
				if (px1 == 2 && py1 == 1 && px2 == 2 && py2 == 2 && px3 == 3 && py3 == 1 && px4 == 3 && py4 == 2)
					Funcion += "+ BC";
				if (px1 == 2 && py1 == 2 && px2 == 2 && py2 == 3 && px3 == 3 && py3 == 2 && px4 == 3 && py4 == 3)
					Funcion += " AC";
			}
		}
	}
	return Funcion;
}

string FuncionResumida(int **&ArrMatriz, int NumeroDeVariables)
{   //string funcionResumida = P2cuadrosFilas(ArrMatriz, NumeroDeVariables) += P2cuadrosColumnas(ArrMatriz, NumeroDeVariables) += P4cuadrosFilas(ArrMatriz, NumeroDeVariables);
	cout << endl;
	int tipo;
	char S;
	string funcionResumida;
	
	while (1) {
		cout << endl;
		cout << "Ingrese tipo agrupacion: ";
		cin >> tipo;
		switch (tipo)
		{

		case 1:
			funcionResumida += P2cuadrosFilas(ArrMatriz, NumeroDeVariables);
			cout << endl;
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			break;

		case 2:
			funcionResumida += P2cuadrosColumnas(ArrMatriz, NumeroDeVariables);
			cout << endl;
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			break;

		case 3:
			funcionResumida +=P4cuadrosFilas(ArrMatriz, NumeroDeVariables);
			cout << endl;
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			break;

		case 4:
			funcionResumida += P4cuadrosColumnas(ArrMatriz, NumeroDeVariables);
			cout << endl;
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			break;

		case 5:
			funcionResumida += P8DobleFila(ArrMatriz, NumeroDeVariables);
			cout << endl;
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			break;

		case 6:
			funcionResumida += P8DobleColumna(ArrMatriz, NumeroDeVariables);
			cout << endl;
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			break;

		case 7:
			funcionResumida += P4Cuadrado(ArrMatriz, NumeroDeVariables);
			cout << endl;
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			break;

		case 8:
			MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);
			cout << endl;
			cout <<"LA FUNCION RESUMIDA ES: "<< funcionResumida;
			getch();
			exit(0);
			break;

		}
		cout << funcionResumida;
	}
	return funcionResumida;
}

int main()
{
	string **ArrFuncion = NULL;
	int **ArrMatriz = NULL;
	int NumeroDeVariables = 0;
	int NumeroDeTerminos = 0;
	cout << "Ingrese el numero de variables a usar: "; cin >> NumeroDeVariables;
	cout << "Ingrese el numero de terminos a usar: "; cin >> NumeroDeTerminos;
	IngresarTérminos(ArrFuncion, NumeroDeTerminos, NumeroDeVariables);
	MostrarFuncion(ArrFuncion, NumeroDeTerminos, NumeroDeVariables);
	TerminosDeLaFuncionABooleanos(ArrFuncion, ArrMatriz, NumeroDeTerminos, NumeroDeVariables);
	Console::ForegroundColor = ConsoleColor::Green;
	MostrarMatrizBoleana(ArrMatriz, NumeroDeVariables);


	//BUSCANDO UNOS EN EL MAPA
	P4cuadrosFilas(ArrMatriz, NumeroDeVariables);
	P4cuadrosColumnas(ArrMatriz, NumeroDeVariables);
	P8DobleFila(ArrMatriz, NumeroDeVariables);
	P8DobleColumna(ArrMatriz, NumeroDeVariables);
	P4Cuadrado(ArrMatriz, NumeroDeVariables);
	P2cuadrosFilas(ArrMatriz, NumeroDeVariables);
	P2cuadrosColumnas(ArrMatriz, NumeroDeVariables);
	
	Console::ForegroundColor = ConsoleColor::Red;
	FuncionResumida(ArrMatriz, NumeroDeVariables);
	_getch();
	
}