#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include "constants.h"
#include "helper.h"

int do_task_1() {
    printf("--------------------------------------------������� 1--------------------------------------------\n");
    printf("�������� ��������� ���������� ������� ������������, ���� �������� ����� ��������� � ������."
           "\n���� ������ ������������ � ����������. ������������� ����������� � ����� ������ � �������������"
           "\n����������� ���������� ���������\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range length_range = {1, 100};
    struct Range height_range = {1, 100};
    unsigned short length = get_natural_number(length_range, "������� ����� ���������: ");
    unsigned short height = get_natural_number(height_range, "������� ������: ");
    printf("-------------------------------------------------------------------------------------------------\n");
    double area = (double)(length * height) / 2;
    printf("������� ������������ = %g", area);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}

int do_task_2() {
    printf("--------------------------------------------������� 2--------------------------------------------\n");
    printf("�������� ���������, ������� ����������� � ������������ ����� ������, � ����� �������\n"
           "��������������� �������� ������� ����. � ������, ���� ������������ ������ ������������ �����, ���������"
           "\n������ ������� ��������� ������� ����� �������. ������������ ��������� ������ if-else. ������������"
           "\n��������������� ����/����� ������.");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range month_range = {1, 12};
    unsigned short month_number = get_natural_number(month_range, "������� ����� ������: ");
    printf("-------------------------------------------------------------------------------------------------\n");
    char *month_name;
    switch (month_number) {
        case 1:
            month_name = "������";
            break;
        case 2:
            month_name = "�������";
            break;
        case 3:
            month_name = "����";
            break;
        case 4:
            month_name = "������";
            break;
        case 5:
            month_name = "���";
            break;
        case 6:
            month_name = "����";
            break;
        case 7:
            month_name = "����";
            break;
        case 8:
            month_name = "������";
            break;
        case 9:
            month_name = "��������";
            break;
        case 10:
            month_name = "�������";
            break;
        case 11:
            month_name = "������";
            break;
        case 12:
            month_name = "�������";
            break;
        default:
            month_name = "������";
            break;
    }
    printf("����� ��� ������� %d - %s", month_number, month_name);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}

int do_task_3() {
    printf("--------------------------------------------������� 3--------------------------------------------\n");
    printf("�������� ���������, ������� ������ �� ������� � ���������� ��������� ������ � ��������� �����"
           "\n��� ��������� �� ��������. ������������ ��������������� ����-����� ������");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range row_range = {1, 20};
    struct Range column_range = {1, 20};
    unsigned short row_count = get_natural_number(row_range, "������� ���-�� �����: ");
    unsigned short column_count = get_natural_number(column_range, "������� ���-�� ��������: ");
    printf("-------------------------------------------------------------------------------------------------\n");
    int matrix[row_count][column_count];
    get_matrix(row_count, column_count, matrix);
    printf("-------------------------------------------------------------------------------------------------\n");
    print_matrix(row_count, column_count, matrix);
    printf("����� �� ��������:\n");
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

    printf("--------------------------------------------������� 4--------------------------------------------\n");
    printf("�������� ���������, � ������� ���������� ����� ������ ���������, ��������� ����� ����."
           "\n������������� ������������� ��������� �� �������  � ��������� �������. ������� �� ����� ������"
           "\n��������� � ���������� ��������\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    struct Range range = {-100, 100};
    printf("������� ������� �����:\n");
    unsigned short a = get_natural_number(range, "a: ");
    unsigned short b = get_natural_number(range, "b: ");
    double eps = 0.001;
    double sup = (double)a;
    double inf = (double)b;
    printf("����������� = %g\n", eps);
    int counter = 0;
    printf("-------------------------------------------------------------------------------------------------\n");
    while(fabs(inf - sup) > eps) {
        sup = inf - (inf - sup) * function(inf) / (function(inf) - function(sup));
        inf = sup - (sup - inf) * function(sup) / (function(sup) - function(inf));
        counter++;
    }
    printf("������ ���������, � ��������� = %g, ����������� ����� = %f\n", eps, sup);
    printf("���������� �������� = %d", counter);
    printf("\n-------------------------------------------------------------------------------------------------\n");
    system("pause");
    return 0;
}

void select_task() {
    struct Range task_number_range = {1, 4};


    while (1) {
        int task_number = get_natural_number(task_number_range, "������� ����� �������:");

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
    printf("\n---------------------------------������������ ������ (������� %s)---------------------------------\n",
           STUDENT_VARIANT);
    printf("%s\n", STUDENT_NAME);
    printf("���� %s\n", STUDENT_GROUP);
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("����������� ���������� ������� ��������� �� ����� C++ �� �������� �������, �������������\n"
           "������� ���������. ������������� ���������� �������� ����� ���������� � ����������� �����/������"
           "\n� ������� ���������� cin � cout, � ����� ����������� ����������� ��������, ��������� � �������."
           "\n������������� ����������� � ���������� ���������\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    system("pause");
}

int main() {
    setlocale(0, "Russian");
    print_student_info();
    select_task();

    return 0;
}
