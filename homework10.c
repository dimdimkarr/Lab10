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