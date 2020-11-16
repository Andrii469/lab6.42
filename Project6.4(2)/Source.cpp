#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

void max_i(int a[], const int SIZE);
long long dobutok(int a[], int null1, int null2);
int null1i(int a[], const int SIZE);
int null2i(int a[], const int SIZE);
void peretvorennya(int a[], const int SIZE);
int max_r(int a[], const int SIZE, int i, int max);
void nomer_r(int a[], const int SIZE, int n, int max);
int null1r(int a[], const int SIZE, int i);
int null2r(int a[], const int SIZE, int i);
void dobutok_r(int a[], int null1, int null2, int d);
void peretvorennya_r(int a[], const int SIZE, int j, int k);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE, D;
    do
    {
        cout << "Введіть розмір масиву a[]:"; cin >> SIZE;
        int* a = new int[SIZE];

        cout << "a[] = ";
        for (int i = 0; i < SIZE; i++)
            a[i] = rand() % SIZE;

        int one = rand() % SIZE;
        int two = rand() % SIZE;    //заміна двох будь яких елементів нулем для 
        a[one] = 0;                 //подальшого розв'язування
        a[two] = 0;

        for (int i = 0; i < SIZE; i++)
            cout << a[i] << " ";


      
        cout << "\\РЕКУРСИВНИЙ СПОСІБ: " << endl; cout << endl;
        cout << "Номер(и) числа: ";
        nomer_r(a, SIZE, 0, max_r(a, SIZE, 0, a[0])); cout << endl;
        cout << "Максимальне число:" << max_r(a, SIZE, 0, a[0]) << endl;
        cout << "\\Номер першого елемента, який дорівнює нулю: " << null1r(a, SIZE, 0) + 1 << endl;
        cout << "Номер другого елемента, який дорівнює нулю: " << null2r(a, SIZE, 0) + 1 << endl;
        cout << "\\Добуток елементів, які задовільняють умову: ";
        dobutok_r(a, null1r(a, SIZE, 0) + 1, null2r(a, SIZE, 0), 1); cout << endl;
        cout << "\nМодифікований масив: ";
        peretvorennya_r(a, SIZE, 0, 0); cout << endl;

        cout << "\\Якщо бажаєте повторити ще раз, введіть 1\nЯкщо ні - будь-який інший символ " << endl;
        cin >> D;

        delete[]a;
    } while (D == 1);
    return 0;
}

//рекурсивний спосіб
int max_r(int a[], const int SIZE, int i, int max)
{
    if (a[i] > max)
        max = a[i];
    if (i < SIZE - 1)
        return max_r(a, SIZE, i + 1, max);
    else
        return max;

}
void nomer_r(int a[], const int SIZE, int n, int max)
{
    if (a[n] == max)
        cout << n + 1 << " ";
    if (n < SIZE)
        return nomer_r(a, SIZE, n + 1, max);
}
int null1r(int a[], const int SIZE, int i)
{
    if (i < SIZE)
        if (a[i] == 0)
            return i;
    return null1r(a, SIZE, i + 1);
}
int null2r(int a[], const int SIZE, int i)
{
    if (i < SIZE)
        if (a[i] == 0)
            if (i != null1r(a, SIZE, 0))
                return i;
    return null2r(a, SIZE, i + 1);
}
void dobutok_r(int a[], int null1, int null2, int d)
{
    if (null1 < null2)
    {
        d *= a[null1];
        return dobutok_r(a, null1 + 1, null2, d);
    }
    else
        cout << d;
}
void peretvorennya_r(int a[], const int SIZE, int j, int k)
{
    if (k <= SIZE - 1)
    {
        if (k % 2 != 0)
            cout << a[k] << " ";
        return peretvorennya_r(a, SIZE, j, k + 1);
    }
    if (!(j % 2 != 0))
        cout << a[j] << " ";
    if (j < SIZE - 1)
        return peretvorennya_r(a, SIZE, j + 1, k);
}