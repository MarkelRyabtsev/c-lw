#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include "constants.h"
#include "helper.h"

int do_task_1() {
    printf("--------------------------------------------Задание 1--------------------------------------------\n");
    printf("Написать программу вычисления площади треугольника, если известна длина основания и высота."
           "\nВвод данных производится с клавиатуры. Предусмотреть приглашение к вводу данных и читабельность"
           "\nрезультатов выполнения программы\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range length_range = {1, 100};
    struct Range height_range = {1, 100};
    unsigned short length = get_natural_number(length_range, "Введите длину основания: ");
    unsigned short height = get_natural_number(height_range, "Введите высоту: ");
    printf("-------------------------------------------------------------------------------------------------\n");
    double area = (double)(length * height) / 2;
    printf("Площадь треугольника = %g", area);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}

int do_task_2() {
    printf("--------------------------------------------Задание 2--------------------------------------------\n");
    printf("Написать программу, которая запрашивает у пользователя номер месяца, а затем выводит\n"
           "соответствующее название времени года. В случае, если пользователь введет недопустимое число, программа"
           "\nдолжна вывести сообщение “Ошибка ввода данных”. Использовать структуру выбора if-else. Использовать"
           "\nформатированный ввод/вывод данных.");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range month_range = {1, 12};
    unsigned short month_number = get_natural_number(month_range, "Введите номер месяца: ");
    printf("-------------------------------------------------------------------------------------------------\n");
    char *month_name;
    switch (month_number) {
        case 1:
            month_name = "Январь";
            break;
        case 2:
            month_name = "Февраль";
            break;
        case 3:
            month_name = "Март";
            break;
        case 4:
            month_name = "Апрель";
            break;
        case 5:
            month_name = "Май";
            break;
        case 6:
            month_name = "Июнь";
            break;
        case 7:
            month_name = "Июль";
            break;
        case 8:
            month_name = "Август";
            break;
        case 9:
            month_name = "Сентябрь";
            break;
        case 10:
            month_name = "Октябрь";
            break;
        case 11:
            month_name = "Ноябрь";
            break;
        case 12:
            month_name = "Декабрь";
            break;
        default:
            month_name = "Ошибка";
            break;
    }
    printf("Месяц под номером %d - %s", month_number, month_name);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}

int do_task_3() {
    printf("--------------------------------------------Задание 3--------------------------------------------\n");
    printf("Написать программу, которая вводит по строкам с клавиатуры двумерный массив и вычисляет сумму"
           "\nего элементов по столбцам. Использовать форматированный ввод-вывод данных");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range row_range = {1, 20};
    struct Range column_range = {1, 20};
    unsigned short row_count = get_natural_number(row_range, "Введите кол-во строк: ");
    unsigned short column_count = get_natural_number(column_range, "Введите кол-во столбцов: ");
    printf("-------------------------------------------------------------------------------------------------\n");
    int matrix[row_count][column_count];
    get_matrix(row_count, column_count, matrix);
    printf("-------------------------------------------------------------------------------------------------\n");
    print_matrix(row_count, column_count, matrix);
    printf("Сумма по столбцам:\n");
    int sum_column[1][column_count];
    get_column_sum(row_count, column_count, matrix, sum_column);
    print_matrix(1, column_count, sum_column);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}

int do_task_4() {

    double function(double value) {
        return value*value*value - 18 * value - 83;
    }

    printf("--------------------------------------------Задание 4--------------------------------------------\n");
    printf("Написать программу, в которой необходимо найти корень уравнения, используя метод хорд."
           "\nПредусмотреть использование указателя на функцию  и прототипа функции. Вывести на экран корень"
           "\nуравнения и количество итераций\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range range = {-100, 100};
    printf("Введите пределы хорды:\n");
    unsigned short a = get_natural_number(range, "a: ");
    unsigned short b = get_natural_number(range, "b: ");
    double eps = 0.001;
    double sup = (double)a;
    double inf = (double)b;
    printf("Погрешность = %g\n", eps);
    int counter = 0;
    printf("-------------------------------------------------------------------------------------------------\n");
    while(fabs(inf - sup) > eps) {
        sup = inf - (inf - sup) * function(inf) / (function(inf) - function(sup));
        inf = sup - (sup - inf) * function(sup) / (function(sup) - function(inf));
        counter++;
    }
    printf("Корень уравнения, с точностью = %g, приближенно равен = %f\n", eps, sup);
    printf("Количество итераций = %d", counter);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}

void select_task() {
    struct Range task_number_range = {1, 4};


    while (1) {
        int task_number = get_natural_number(task_number_range, "Введите номер задания:");

        int result = 0;
        switch (task_number) {
            case 1:
                result = do_task_1();
                break;
            case 2:
                result = do_task_2();
                break;
            case 3:
                result = do_task_3();
                break;
            case 4:
                result = do_task_4();
                break;
            default:
                break;
        }

        if (result == 1) {
            break;
        }
    }
}

void print_student_info() {
    printf("\n---------------------------------Лабораторная работа (вариант %s)---------------------------------\n",
           STUDENT_VARIANT);
    printf("%s\n", STUDENT_NAME);
    printf("МИДО %s\n", STUDENT_GROUP);
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Осуществить построение простой программы на языке C++ по варианту условия, определенному\n"
           "номером подгруппы. Предусмотреть объявление основных типов переменных и организацию ввода/вывода"
           "\nс помощью операторов cin и cout, а также реализовать необходимые операции, указанные в задании."
           "\nПредусмотреть комментарии в написанной программе\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    system("pause");
}

int main() {
    setlocale(0, "Russian");
    print_student_info();
    select_task();

    return 0;
}
