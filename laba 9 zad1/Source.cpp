/*Компоненты файла f – целые числа. Получить файл g, образованный из f исключением повторных вхождений одного и того же числа.*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h> 
#include<locale.h> 

int main()
{
    int m;
    int a[30];
    int n = 0;
    setlocale(LC_ALL, "rus");
    FILE* fp = NULL;
    FILE* g = NULL;

    fp = fopen("f.txt", "a+b");
    if (fp == NULL)
    {
        printf("Файл не открылся.\n");
        return 0;
    };

    while (fscanf(fp, "%d", &m) != EOF)
    {
        a[n] = m;
        n++;
    }

    g = fopen("g.txt", "wb");
    if (g == NULL)
    {
        printf("Файл не открылся.\n");
        return 0;
    }

    int i, j, ifind, number, flag = 0;
    j = 0;
    while (j < n)
    {
        ifind = j;
        number = a[j];
        i = 0;
        while (i < n)
        {
            if (a[i] == number && ifind != i)
            {
                flag = 1;
                n--;
                for (int ij = i; ij < n; ij++)
                    a[ij] = a[ij + 1];
            }
            else i++;
        }
        if (flag)
        {
            flag = 0;
        }
        else j++;
    }

    for (int i = 0; i < n; i++)
        fprintf(g, "%d ", a[i]);

    fclose(fp);
    fclose(g);

    printf("Данные записаны в файл\n");
    return 0;
}