#define _CRT_SECURE_NO_WARNINGS
#define N 100
#include <stdio.h>
#include <locale.h>
int find_min_greater(double *a, int n, double A)
{
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > A)
            if (pos == -1 || a[i] < a[pos])
                pos = i;
    }
    if (pos == -1)
        return -1;
    return pos + 1;
}
int main(void)
{
    setlocale(LC_ALL, "Russian");
    double array[N], A;
    int n, number;
    printf("Введите n (1-100): ");
    scanf("%d", &n);
    if (n < 1 || n > N)
    {
        printf("Неверный размер массива.\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%lf", &array[i]);
    }
    printf("Введите A: ");
    scanf("%lf", &A);
    number = find_min_greater(array, n, A);
    if (number == -1)
        printf("Подходящих элементов нет.\n");
    else
        printf("Номер элемента: %d\nЗначение: %.2f\n", number, array[number - 1]);
    return 0;
}
