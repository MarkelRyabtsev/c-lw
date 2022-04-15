#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "helper.h"

struct InputError check_limit(struct Range range, int value) {
    struct InputError error = {0, 0};
    int min_limit = range.min;
    int max_limit = range.max;
    if (value >= min_limit) {
        if (value <= max_limit) {
            return error;
        }
        error.limit_error = 1;
    } else if (value == 0) {
        error.symbol_error = 1;
    } else {
        error.limit_error = 1;
    }
    return error;
}

int get_natural_number(struct Range range, char message[]) {

    int is_correct = 0;
    char str[16], *endp;
    int value;

    do
    {
        printf("%s ", message);
        fgets(str, sizeof(str), stdin);
        value = strtol(str, &endp, 0);
        if(*endp == '\n' || *endp == '\0'){
            struct InputError error = check_limit(range, value);
            if (error.limit_error == 1) {
                printf("Значение должно быть от %d до %d\n", range.min, range.max);
            } else if (error.symbol_error == 1) {
                printf("Не верное значение, повторите\n");
            } else {
                is_correct = 1;
            }
        } else {
            printf("Не верное значение, повторите\n");
        }
    }while(is_correct == 0);

    return value;
}

void get_matrix(int row_count, int column_count, int matrix[row_count][column_count]) {

    struct Range value_range = {-100, 100};

    for (int i = 0; i < row_count; i++) {
        printf("Введите %d эл. %d строки:\n", column_count, i + 1);
        for (int j = 0; j < column_count; j++) {
            char message[] = "\[%d\]\[%d\]";
            char formatted_message[1000];
            sprintf(formatted_message, message, i + 1, j + 1);
            matrix[i][j] = get_natural_number(value_range, formatted_message);
        }
    }
}

void get_column_sum(int row_count, int column_count, int matrix[row_count][column_count], int sum_matrix[1][column_count]) {
    for (int i = 0; i < column_count; i++) {
        int column_sum = 0;
        for (int j = 0; j < row_count; j++) {
            column_sum += matrix[j][i];
        }
        sum_matrix[0][i] = column_sum;
    }
}

void print_matrix(int row_count, int column_count, int matrix[row_count][column_count]) {
    int max_length = 0;

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            int value = matrix[i][j];

            int count = log10(abs(value)) + 1;
            if (value < 0) {
                count++;
            }

            if (count > max_length) {
                max_length = count;
            }
        }
    }

    char char_array[row_count][column_count];

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            printf("\[%s\] ", to_array(matrix[i][j], max_length));
        }
        printf("\n");
    }
}

char *to_array(int number, int length) {
    int n = 1;
    if (number != 0) {
        n = log10(abs(number)) + 1;
    }

    if (number < 0) {
        n++;
    }
    char *numberArray = calloc(length, sizeof(char));

    for (int i = 0; i < length - n; i++) {
        numberArray[i] = ' ';
    }

    if (number < 0) {
        numberArray[length - n] = '-';
    }
    int limit = length - n;
    if (number < 0) {
        limit++;
    }
    for (int i = length - 1; i >= limit; i--, number /= 10) {
        if (number == 0) {
            numberArray[i] = '0';
            continue;
        }
        numberArray[i] = (abs(number) % 10) + '0';
    }

    return numberArray;
}

int count_items(char *array) {
    int count = 0;
    for(int i = 0; i < sizeof(array); i++) {
        if (array[i] != '«') {
            count += 1;
        }
    }
    return count;
}

