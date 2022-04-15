#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

struct Range {
    int min;
    int max;
};

struct InputError {
    int limit_error ;
    int symbol_error;
};

struct InputError check_limit(struct Range range, int value);

int get_natural_number(struct Range range, char message[]);

void get_matrix(int row_count, int column_count, int matrix[row_count][column_count]);

void print_matrix(int row_count, int column_count, int matrix[row_count][column_count]);

char *to_array(int number, int length);

void get_column_sum(int row_count, int column_count, int matrix[row_count][column_count], int sum_matrix[1][column_count]);

#endif // HELPER_H_INCLUDED
