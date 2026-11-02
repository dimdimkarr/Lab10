# Lab10
## Условие задачи
Задание 1  
Написать программу с использованием пользовательских функций для вычисления значений функций F1(x) и F2(x), а также выполнения арифметических операций над полученными значениями.  

Функция F1(x):  
* x² − 3x + 9, если x ≤ 3;  
* 1 / (x³ + 3), если x > 3.  

Функция F2(x):  
* x · e^(sin(x²)).  

Программа должна выводить значения функций, их произведение, разность квадратов и удвоенную сумму. Также необходимо реализовать меню выбора операций.

Задание 2  
Вычислить значение заданной функции тремя способами:  
1. С помощью стандартной библиотечной функции.  
2. С помощью собственной функции с заданным количеством членов ряда N.  
3. С помощью собственной функции с заданной точностью eps.  
Вариант 6 — arcsin(x).  

## Реализация программы
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Задание 1
double fa(double x);
double fb(double x);
double arcsin_n(double x, int N);
double arcsin_eps(double x, double eps);

int main(void)
{
    double x, f1, f2;
    double result;
    double eps, standard, sum;
    int choice, N, i;

    setlocale(LC_ALL, "");

    // Задание 1
    printf("=== Задание 1 ===\n");
    printf("Введите значение x: ");
    scanf("%lf", &x);

    f1 = fa(x);
    f2 = fb(x);

    printf("\nF1(x) = %.6lf\n", f1);
    printf("F2(x) = %.6lf\n", f2);
    printf("Произведение = %.6lf\n", f1 * f2);
    printf("Разность квадратов = %.6lf\n", f1 * f1 - f2 * f2);
    printf("Удвоенная сумма = %.6lf\n", 2 * (f1 + f2));

    do
    {
        printf("\n=== МЕНЮ ===\n");
        printf("1 - Значение F1(x)\n");
        printf("2 - Значение F2(x)\n");
        printf("3 - Произведение\n");
        printf("4 - Разность квадратов\n");
        printf("5 - Удвоенная сумма\n");
        printf("6 - Ввести новое значение x\n");
        printf("0 - Выход из меню\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 6)
        {
            printf("Введите новое значение x: ");
            scanf("%lf", &x);

            f1 = fa(x);
            f2 = fb(x);
        }
        else
        {
            switch (choice)
            {
            case 1:
                printf("F1(%.2lf) = %.6lf\n", x, f1);
                break;

            case 2:
                printf("F2(%.2lf) = %.6lf\n", x, f2);
                break;

            case 3:
                result = f1 * f2;
                printf("Произведение = %.6lf\n", result);
                break;

            case 4:
                result = f1 * f1 - f2 * f2;
                printf("Разность квадратов = %.6lf\n", result);
                break;

            case 5:
                result = 2 * (f1 + f2);
                printf("Удвоенная сумма = %.6lf\n", result);
                break;

            case 0:
                printf("Выход из меню.\n");
                break;

            default:
                printf("Неизвестный пункт меню.\n");
                break;
            }
        }

    } while (choice != 0);

    // Задание 2
    printf("\n=== Задание 2. Арксинус ===\n");
    printf("Введите x от -1 до 1: ");
    scanf("%lf", &x);

    if (x < -1 || x > 1)
    {
        printf("Ошибка: x должен находиться в диапазоне [-1; 1].\n");
    }
    else
    {
        printf("Введите количество членов ряда N: ");
        scanf("%d", &N);

        printf("Введите точность eps: ");
        scanf("%lf", &eps);

        if (N < 1 || eps <= 0)
        {
            printf("Ошибка: N должно быть >= 1, eps > 0.\n");
        }
        else
        {
            standard = asin(x);

            printf("\nСтандартное значение asin(x) = %.10lf\n", standard);

            printf("\n  N |   Значение ряда | Отклонение\n");
            printf("----+-----------------+-------------\n");

            for (i = 1; i <= N; i++)
            {
                sum = arcsin_n(x, i);

                printf("%3d | %15.10lf | %+.4e\n",
                    i, sum, sum - standard);
            }

            sum = arcsin_eps(x, eps);

            printf("\nРезультат с точностью eps = %g\n", eps);
            printf("Значение ряда = %.10lf\n", sum);
            printf("Отклонение = %+.4e\n", sum - standard);
        }
    }

    return 0;
}

double fa(double x)
{
    double y;

    if (x <= 3)
        y = x * x - 3 * x + 9;
    else
        y = 1.0 / (x * x * x + 3);

    return y;
}

double fb(double x)
{
    double y;

    y = x * exp(sin(x * x));

    return y;
}

double arcsin_n(double x, int N)
{
    double sum = x;
    double term = x;
    int n;

    for (n = 1; n < N; n++)
    {
        term = term * x * x * (2 * n - 1) * (2 * n - 1)
            / (2 * n * (2 * n + 1));

        sum = sum + term;
    }

    return sum;
}

double arcsin_eps(double x, double eps)
{
    double sum = x;
    double term = x;
    int n = 1;

    do
    {
        term = term * x * x * (2.0 * n - 1.0) * (2.0 * n - 1.0)
            / (2.0 * n * (2.0 * n + 1.0));

        sum = sum + term;
        n++;

    } while (fabs(term) >= eps);

    return sum;
}
```
## Пример работы программы
Задание 1  
Ввод значения x: 2  
Результат:  
* F1(x) = 7.000000  
* F2(x) ≈ 0.938000  
* Произведение ≈ 6.566000  
* Разность квадратов ≈ 48.120000  
* Удвоенная сумма ≈ 15.876000  
После вывода результатов программа предлагает меню для выбора дальнейших операций.

Задание 2  
Ввод данных:  
* x = 0.5  
* N = 10  
* eps = 0.0001   
Стандартное значение arcsin(0.5) ≈ 0.5235987756


#Домашнее задание.Вариант 7.

## Условие задачи  
Написать программу для работы с равносторонним треугольником.  

Программа должна:  
1. Рассчитывать площадь треугольника.  
2. Выводить определение фигуры.  
3. Рисовать контур треугольника с использованием заданного символа.  

## Реализация программы
```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

// Задание 3
double area_triangle(double a);
void draw_triangle(int a, char sym);

int main(void)
{
    int a;
    int choice;
    char sym;
    double s;

    setlocale(LC_ALL, "");

    printf("Фигура: равносторонний треугольник\n");

    printf("Введите символ для рисования: ");
    scanf(" %c", &sym);

    printf("Введите сторону треугольника: ");
    scanf("%d", &a);

    if (a < 2)
    {
        printf("Ошибка: сторона должна быть не меньше 2.\n");
    }
    else
    {
        do
        {
            printf("\n=== МЕНЮ ===\n");
            printf("1 - Рассчитать площадь\n");
            printf("2 - Вывести определение фигуры\n");
            printf("3 - Нарисовать фигуру\n");
            printf("0 - Выход\n");
            printf("Ваш выбор: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                s = area_triangle(a);
                printf("Площадь треугольника = %.2lf\n", s);
                break;

            case 2:
                printf("Равносторонний треугольник - ");
                printf("это треугольник, у которого все три ");
                printf("стороны равны.\n");
                printf("Все углы равны 60 градусам.\n");
                break;

            case 3:
                draw_triangle(a, sym);
                break;

            case 0:
                printf("Выход из программы.\n");
                break;

            default:
                printf("Неизвестный пункт меню.\n");
                break;
            }

        } while (choice != 0);
    }

    return 0;
}

double area_triangle(double a)
{
    double s;

    s = a * a * sqrt(3.0) / 4;

    return s;
}

void draw_triangle(int a, char sym)
{
    int row, col;

    for (row = 1; row < a; row++)
    {
        for (col = 1; col <= a - row; col++)
            putchar(' ');

        putchar(sym);

        if (row > 1)
        {
            for (col = 1; col <= 2 * row - 3; col++)
                putchar(' ');

            putchar(sym);
        }

        printf("\n");
    }

    for (col = 1; col <= 2 * a - 1; col++)
        putchar(sym);

    printf("\n");
}
```
## Пример работы программы

Ввод данных:  
* Символ для рисования: *  
* Сторона треугольника: 5  

Вывод определения:  
Равносторонний треугольник — это треугольник, у которого все три стороны равны. Все углы равны 60 градусам.  

Результат расчёта площади:  
S = 5² · √3 / 4 ≈ 10.83.  

Результат рисования:  
    *  
   * *  
  *   *  
 *     *  
*********  

## Информация о разработчике  
Жукова Дарья, бИД-261


