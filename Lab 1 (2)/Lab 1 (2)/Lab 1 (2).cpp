﻿#include <windows.h>
#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct table
{
    char name[12];
    char sc;
    char cnt[6];
    double sq;
}
arr[10];

int input()
{
    int n;
    for (n = 0; n < 5; n++)
    {
        cout << n + 1 << ") " << "Введите: вещество, тип, влажность, коеффициент >" << endl;
        cin >> arr[n].name >> arr[n].sc >> arr[n].cnt >> arr[n].sq;
    }
    return n;
}

void print(int n)
{
    cout << "---------------------------------------------------\n";
    cout << "|   Коэффициенты теплопроводимости материаллов    |\n";
    cout << "|-------------------------------------------------|\n";
    cout << "| Вещество    | Тип | Влажность (%)  | Коэффициент|\n";
    cout << "|             |     |                |            |\n";
    cout << "|-------------|-----|----------------|------------|\n";

    for (int i = 0; i < n; i++)
    {
        printf("| %-11s | %-3c | %-14s | %-10.1f |\n", arr[i].name, arr[i].sc, arr[i].cnt, arr[i].sq);
    }
    cout << "---------------------------------------------------\n";
    cout << "|-------------------------------------------------|\n";
    cout << "|  Примечание: М - металлы,                       |\n";
    cout << "|              Т - термоизоляционные материалы,   |\n";
    cout << "|              Д - другие материалы               |\n";
    cout << "---------------------------------------------------\n";
}

void sort(int n)
{
    struct table x;
    for (int i = 0; i < n - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            /* если текущий элемент > минимального, он становится минимальным */
            if (strcmp(arr[m].name, arr[j].name) > 0) m = j;
        }
        if (m > i)
        {
            /* перестановка элементов */
            strcpy_s(x.name, arr[i].name);
            x.sc = arr[i].sc;
            strcpy_s(x.cnt, arr[i].cnt);
            x.sq = arr[i].sq;

            strcpy_s(arr[i].name, arr[m].name);
            arr[i].sc = arr[m].sc;
            strcpy_s(arr[i].cnt, arr[m].cnt);
            arr[i].sq = arr[m].sq;


            strcpy_s(arr[m].name, x.name);
            arr[m].sc = x.sc;
            strcpy_s(arr[m].cnt, x.cnt);
            arr[m].sq = x.sq;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;

    n = input();
    sort(n);
    print(n);

    return 0;
}