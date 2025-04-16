#pragma once

#include<iostream>
#include<stdexcept>
#include <limits>
#include <string>


using namespace std;

#define MAX_SIZE 10

void matriceMenu();
int GetChoice();
void MatriceOperation(int operation);

void OutputMatrice(int stroki, int stolbcy, int matrice[MAX_SIZE][MAX_SIZE]);
void InputSingleMatrice(int stroki, int stolbcy, int matrice[MAX_SIZE][MAX_SIZE]);
void InputTwoMatrice(int stroki1, int stolbcy1, int matrice1[MAX_SIZE][MAX_SIZE], int stroki2, int stolbcy2, int matrice2[MAX_SIZE][MAX_SIZE]);
void InputMatriceAndNumber(int stroki, int stolbcy, int matrice[MAX_SIZE][MAX_SIZE], int& chislo);
void ShabloMatrice(int stroki, int stolbcy);

void PlusMatrice(int stroki, int stolbcy, int matrice1[MAX_SIZE][MAX_SIZE], int matrice2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void MinusMatrice(int stroki, int stolbcy, int matrice1[MAX_SIZE][MAX_SIZE], int matrice2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void ymnozhenieMatrice(int stroki1, int stolbcy1, int matrice1[MAX_SIZE][MAX_SIZE],int stroki2, int stolbcy2, int matrice2[MAX_SIZE][MAX_SIZE],int result[MAX_SIZE][MAX_SIZE]);
void ymnozhenieMatriceNaChislo(int stroki, int stolbcy, int matrice[MAX_SIZE][MAX_SIZE], int chislo, int result[MAX_SIZE][MAX_SIZE]);
void PlusNumMatrice(int stroki, int stolbcy, int matrice[MAX_SIZE][MAX_SIZE], int chislo, int result[MAX_SIZE][MAX_SIZE]);
void MinusNumMatrice(int stroki, int stolbcy, int matrice[MAX_SIZE][MAX_SIZE], int chislo, int result[MAX_SIZE][MAX_SIZE]);
void TransponentMatrice(int stroki, int stolbcy, int matrice[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
int Opredelitel(int n, int matrice[MAX_SIZE][MAX_SIZE]);
void PodMatrice(int n, int matrice[MAX_SIZE][MAX_SIZE], int podmatrice[MAX_SIZE][MAX_SIZE],int strokaremove, int stolbecremove);
void MatriceDop(int size, int matrice[MAX_SIZE][MAX_SIZE], int dop[MAX_SIZE][MAX_SIZE]);
bool ObratMatrice(int n, int matrice[MAX_SIZE][MAX_SIZE], double obr[MAX_SIZE][MAX_SIZE]);
bool GetYesOrNo();