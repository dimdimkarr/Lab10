#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double area_triangle(double a);
char triangle_symbol(int row, int col, int a, char sym);

int main(void)
{
    char sym, c;
    int a;
    int choice;
    int row, col;
    double s;

    setlocale(LC_ALL, "");

    printf("Фигура: равносторонний треугольник\n");

    printf("Введите символ для рисования: ");

    if (scanf(" %c", &sym) != 1)
    {
        printf("Ошибка ввода.\n");
        return 1;
    }

    printf("Введите сторону треугольника: ");

    if (scanf("%d", &a) != 1)
    {
        printf("Ошибка ввода.\n");
        return 1;
    }

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

            if (scanf("%d", &choice) != 1)
            {
                printf("Ошибка ввода.\n");
                return 1;
            }

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
                for (row = 1; row <= a; row++)
                {
                    for (col = 1; col <= a - row; col++)
                    {
                        putchar(' ');
                    }

                    for (col = 1; col <= 2 * row - 1; col++)
                    {
                        c = triangle_symbol(row, col, a, sym);
                        putchar(c);
                    }

                    printf("\n");
                }
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

// Вычисление площади равностороннего треугольника
double area_triangle(double a)
{
    double s;

    s = a * a * sqrt(3.0) / 4;

    return s;
}

// Определение символа для заданной позиции
char triangle_symbol(int row, int col, int a, char sym)
{
    char result;

    if (col == 1 || col == 2 * row - 1 || row == a)
    {
        result = sym;
    }
    else
    {
        result = ' ';
    }

    return result;
}