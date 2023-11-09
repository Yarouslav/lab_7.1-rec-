// Lab_7_1.cpp
// Процюк Ярослав
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 23

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** s, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** s, const int rowCount, const int colCount, int i, int j);
void Sort(int** s, const int rowCount, const int colCount);
void RecursiveSort(int** s, const int rowCount, const int colCount, int i1);
void Change(int** s, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int i, int j, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL));

    const int Low = 8;
    const int High = 73;

    const int rowCount = 7;
    const int colCount = 6;

    int** s = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        s[i] = new int[colCount];

    Create(s, rowCount, colCount, Low, High);
    cout << endl;
    Print(s, rowCount, colCount, 0, 0);
    Sort(s, rowCount, colCount);
    cout << endl;
    Print(s, rowCount, colCount, 0, 0);
    int S = 0;
    int k = 0;

 
    Calc(s, rowCount, colCount, 0, 0, S , k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(s, rowCount, colCount,0,0);

    for (int i = 0; i < rowCount; i++)
        delete[] s[i];
    delete[] s;
    return 0;
}

void Create(int** s, const int rowCount, const int colCount, const int Low, const int High)
{
    if (rowCount > 0)
    {
        Create(s, rowCount - 1, colCount, Low, High);
        if (colCount > 0)
        {
            s[rowCount - 1][colCount - 1] = Low + rand() % (High - Low + 1);
            Create(s, rowCount, colCount - 1, Low, High);
        }
    }
}

void Print(int** s, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << s[i][j];
    if (j < colCount - 1)
        Print(s, rowCount, colCount, i, j + 1);
    else
        if (i < rowCount - 1)
        {
            cout << endl;
            Print(s, rowCount, colCount, i + 1, 0);
        }
        else
            cout << endl << endl;
}


void Sort(int** s, const int rowCount, const int colCount)
{
    if (rowCount > 1)
    {
        // Perform a single pass of the sorting algorithm
        RecursiveSort(s, rowCount, colCount, 0);

        // Recursively call Sort with reduced rowCount
        Sort(s, rowCount - 1, colCount);
    }
}

void RecursiveSort(int** s, const int rowCount, const int colCount, int i1)
{
    if (i1 < rowCount - 1)
    {
        if ((s[i1][0] > s[i1 + 1][0]) ||
            (s[i1][0] == s[i1 + 1][0] && s[i1][1] > s[i1 + 1][1]) ||
            (s[i1][0] == s[i1 + 1][0] && s[i1][1] == s[i1 + 1][1] && s[i1][3] < s[i1 + 1][3]))
        {
            Change(s, i1, i1 + 1, colCount);
        }

        // Recursively call RecursiveSort with incremented i1
        RecursiveSort(s, rowCount, colCount, i1 + 1);
    }
}


void Change(int** s, const int row1, const int row2, const int colCount)
{
    if (colCount > 0)
    {
        int tmp = s[row1][colCount - 1];
        s[row1][colCount - 1] = s[row2][colCount - 1];
        s[row2][colCount - 1] = tmp;
        Change(s, row1, row2, colCount - 1);
       
    }
}

void Calc(int** s, const int rowCount, const int colCount, int i, int j, int& S, int& k)
{
    if (s[i][j] % 2 == 0 || !(s[i][j] % 8 == 0))
        S += s[i][j];
            k++;
            s[i][j] = 0;
    if (j < colCount - 1)
        Calc(s, rowCount, colCount, i, j + 1, S, k);
    else
        if (i < rowCount - 1)
            Calc(s, rowCount, colCount, i + 1, 0, S, k);
}
