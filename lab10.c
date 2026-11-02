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