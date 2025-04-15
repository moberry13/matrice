#pragma once

#include<iostream>
#include<stdexcept>
#include <limits>
#include <string>


using namespace std;

void matriceMenu();
int GetChoice();
void MatriceOperation(int operation);

void OutputMatrice(int stroki, int stolbcy, int matrice[100][100]);
void InputSingleMatrice(int stroki, int stolbcy, int matrice[100][100]);
void InputTwoMatrice(int stroki1, int stolbcy1, int matrice1[100][100], int stroki2, int stolbcy2, int matrice2[100][100]);
void InputMatriceAndNumber(int stroki, int stolbcy, int matrice[100][100], int& chislo);

void PlusMatrice(int stroki, int stolbcy, int matrice1[100][100], int matrice2[100][100], int result[100][100]);
void MinusMatrice(int stroki, int stolbcy, int matrice1[100][100], int matrice2[100][100], int result[100][100]);
void ymnozhenieMatrice(int stroki1, int stolbcy1, int matrice1[100][100],int stroki2, int stolbcy2, int matrice2[100][100],int result[100][100]);
void ymnozhenieMatriceNaChislo(int stroki, int stolbcy, int matrice[100][100], int chislo, int result[100][100]);
void PlusNumMatrice(int stroki, int stolbcy, int matrice[100][100], int chislo, int result[100][100]);
void MinusNumMatrice(int stroki, int stolbcy, int matrice[100][100], int chislo, int result[100][100]);
void TransponentMatrice(int stroki, int stolbcy, int matrice[100][100], int result[100][100]);
int Opredelitel(int n, int matrice[100][100]);
void PodMatrice(int n, int matrice[100][100], int podmatrice[100][100],int strokaremove, int stolbecremove);
void MatriceDop(int size, int matrice[100][100], int dop[100][100]);
bool ObratMatrice(int n, int matrice[100][100], double obr[100][100]);
bool GetYesOrNo();