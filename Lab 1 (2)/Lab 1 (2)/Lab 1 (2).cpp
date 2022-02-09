﻿#include <windows.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct table
{
    char name[12];
    char sc;
    char cnt[12];
    float sq;
}
arr[10];

void input(int N, table arr[])
{
    
   
    for (int i = 0; i < N; i++)
    {
        cout << i + 1 << ") " << "Введите: вещество, тип, влажность, коеффициент >" << endl;
        cin >> arr[i].name >> arr[i].sc >> arr[i].cnt >> arr[i].sq;
    }
    
}
void random(int N, table arr[])
{
     srand(time(0));

    char let[3]={ 'T','М','Д'};
    for (int i = 0; i < N; i++)
    {
        int k = rand() % 100 - 1;
        if(k>=0 && k<25)
            strcpy_s(arr[i].name, "Аллюминий");
        else if(k>=25 && k<50)
            strcpy_s(arr[i].name, "Медь");
        else if(k>=50 && k<75)
            strcpy_s(arr[i].name, "Олово");
        else if(k>=75 && k<=100)
            strcpy_s(arr[i].name, "Сталь");

        int p = rand() % 100 - 1;
        if (p >= 0 && p < 25)
             strcpy_s(arr[i].cnt, "0-100");
        else if (p >= 25 && p < 50)
            strcpy_s(arr[i].cnt, "0-10");
        else if (p >= 50 && p < 75)
            strcpy_s(arr[i].cnt, "10-35");
        else if (p >= 75 && p <= 100)
            strcpy_s(arr[i].cnt, "80-100");

        arr[i].sc = let[rand()%4-1];
        arr[i].sq = (double)(rand()) / RAND_MAX * 100;
        
    }
}

void print(int N, table arr[])
{
    cout << "---------------------------------------------------\n";
    cout << "|   Коэффициенты теплопроводимости материаллов    |\n";
    cout << "|-------------------------------------------------|\n";
    cout << "| Вещество    | Тип | Влажность (%)  | Коэффициент|\n";
    cout << "|             |     |                |            |\n";
    cout << "|-------------|-----|----------------|------------|\n";

    for (int i = 0; i < N; i++)
    {
        printf("| %-11s | %-3c | %-14s | %-10.3f |\n", arr[i].name, arr[i].sc, arr[i].cnt, arr[i].sq);
    }
    cout << "---------------------------------------------------\n";
    cout << "|-------------------------------------------------|\n";
    cout << "|  Примечание: М - металлы,                       |\n";
    cout << "|              Т - термоизоляционные материалы,   |\n";
    cout << "|              Д - другие материалы               |\n";
    cout << "---------------------------------------------------\n";
}

void sort(int N, table arr[])
{
    struct table x;
    for (int i = 0; i < N - 1; i++)
    {
        int m = i;
        for (int j = i + 1; j < N; j++)
        {
            /* если текущий элемент > минимального, он становится минимальным */
            if (strcmp(arr[m].name, arr[j].name) > 0) m = j;
        }
        if (m > i)
        {
            /* перестановка элементов */
            strcpy_s(x.name, arr[i].name);
            x.sc = arr[i].sc;
            strcpy_s(  x.cnt,arr[i].cnt);
            x.sq = arr[i].sq;

            strcpy_s(arr[i].name, arr[m].name);
            arr[i].sc = arr[m].sc;
            strcpy_s (arr[i].cnt,arr[m].cnt);
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
    bool answer;
    int N;
    
    cout << "Как заполнять?" << endl;
    cout << "1 - Вручную, 0 - Рандом --> ";
    cin >> answer;
    
    if (answer == true)
    {
        cout << "Сколько строк заполнять? --> ";
        cin >> N;
        input(N,arr);
    }
        
    else
    {
        cout << "Сколько строк заполнять? --> ";
        cin >> N;
        random(N,arr);
    }
        

    sort(N,arr);
    print(N,arr);

    return 0;
}