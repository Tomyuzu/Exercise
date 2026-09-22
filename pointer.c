#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void swap_by_pointer(int *a, int *b);
void input_array_ptr(int *arr, int n);
void print_array_ptr(const int *arr, int n);
void basic_pointer_demo(void);
void size_via_void_pointer_demo(void);
void array_pointer_demo(void);
int count_chars_ptr(const char *str);
void modify_value_by_pointer(int *value);
void compare_pointer_addresses_demo(void);
void copy_string_ptr(char *dest, const char *src);
void malloc_array_demo(void);
int *find_max_ptr(int *arr, int n);
void reverse_string_ptr(char *str);
void input_matrix_ptr(int *matrix, int rows, int cols);
void print_matrix_ptr(const int *matrix, int rows, int cols);
void add_matrices_ptr(const int *a, const int *b, int *result, int rows, int cols);
int add_int(int a, int b);
int sub_int(int a, int b);
int mul_int(int a, int b);
int div_int(int a, int b);
int calculate_with_op(int a, int b, int (*op)(int, int));
void generic_swap(void *a, void *b, size_t size);
Node *create_node(int value);
void append_node(Node **head, int value);
void print_list(const Node *head);
void free_list(Node *head);
int **create_matrix(int rows, int cols);
void free_matrix(int **matrix, int rows);
void fill_matrix(int **matrix, int rows, int cols);
void print_matrix_2d(int **matrix, int rows, int cols);

int main(void)
{
    printf("=== Exercise 1: Declare a pointer to an int and print its address and value ===\n");
    basic_pointer_demo();

    printf("\n=== Exercise 2: Use a pointer to swap two numbers ===\n");
    int x = 10, y = 20;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap_by_pointer(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);

    printf("\n=== Exercise 3: Use a pointer to sum array elements ===\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += *(arr + i);
    printf("Array sum = %d\n", sum);

    printf("\n=== Exercise 4: Function to input and print an array using pointers ===\n");
    int numbers[5];
    input_array_ptr(numbers, 5);
    print_array_ptr(numbers, 5);

    printf("\n=== Exercise 5: Print the size of a data type through a void pointer ===\n");
    size_via_void_pointer_demo();

    printf("\n=== Exercise 6: Assign pointer p to array a[5] and print values using p ===\n");
    array_pointer_demo();

    printf("\n=== Exercise 7: Count characters in a string using a pointer ===\n");
    char text[] = "Hello World";
    printf("Length of string '%s' = %d\n", text, count_chars_ptr(text));

    printf("\n=== Exercise 8: Pass a pointer to a function to change the original variable value ===\n");
    int value = 100;
    printf("Before modification: value = %d\n", value);
    modify_value_by_pointer(&value);
    printf("After modification: value = %d\n", value);

    printf("\n=== Exercise 9: Compare addresses of two pointers in the same array ===\n");
    compare_pointer_addresses_demo();

    printf("\n=== Exercise 10: Copy a string using a pointer without strcpy ===\n");
    char source[] = "C Programming";
    char destination[50];
    copy_string_ptr(destination, source);
    printf("Source: %s\nDestination: %s\n", source, destination);

    printf("\n=== Exercise 11: Use malloc to allocate an array of 10 int elements and print them ===\n");
    malloc_array_demo();

    printf("\n=== Exercise 12: Function returns a pointer to the largest element in the array ===\n");
    int max_arr[7] = {4, 9, 2, 17, 12, 7, 5};
    int *max_ptr = find_max_ptr(max_arr, 7);
    printf("Largest element is %d at index %ld\n", *max_ptr, (long)(max_ptr - max_arr));

    printf("\n=== Exercise 13: Use a pointer to reverse a string ===\n");
    char reverse_text[] = "programming";
    printf("Before reversing: %s\n", reverse_text);
    reverse_string_ptr(reverse_text);
    printf("After reversing: %s\n", reverse_text);

    printf("\n=== Exercise 14: Function to input a 2D matrix using a pointer ===\n");
    int matrix[2][3] = {{0, 0, 0}, {0, 0, 0}};
    printf("Enter a 2x3 matrix:\n");
    input_matrix_ptr(&matrix[0][0], 2, 3);
    print_matrix_ptr(&matrix[0][0], 2, 3);

    printf("\n=== Exercise 15: Use a pointer to add two matrices ===\n");
    int a1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int b1[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int result[2][3];
    add_matrices_ptr(&a1[0][0], &b1[0][0], &result[0][0], 2, 3);
    print_matrix_ptr(&result[0][0], 2, 3);

    printf("\n=== Exercise 16: Function pointer to select an operation (+, -, *, /) ===\n");
    int a2 = 20, b2 = 5;
    printf("%d + %d = %d\n", a2, b2, calculate_with_op(a2, b2, add_int));
    printf("%d - %d = %d\n", a2, b2, calculate_with_op(a2, b2, sub_int));
    printf("%d * %d = %d\n", a2, b2, calculate_with_op(a2, b2, mul_int));
    printf("%d / %d = %d\n", a2, b2, calculate_with_op(a2, b2, div_int));

    printf("\n=== Exercise 17: Program using function pointers to simulate a simple calculator ===\n");
    int left = 30, right = 6;
    int (*func_ptr)(int, int);
    func_ptr = add_int;
    printf("30 + 6 = %d\n", func_ptr(left, right));
    func_ptr = sub_int;
    printf("30 - 6 = %d\n", func_ptr(left, right));
    func_ptr = mul_int;
    printf("30 * 6 = %d\n", func_ptr(left, right));
    func_ptr = div_int;
    printf("30 / 6 = %d\n", func_ptr(left, right));

    printf("\n=== Exercise 18: Basic linked list using pointers ===\n");
    Node *head = NULL;
    append_node(&head, 10);
    append_node(&head, 20);
    append_node(&head, 30);
    print_list(head);
    free_list(head);

    printf("\n=== Exercise 19: Handle a dynamic NxM matrix using pointers ===\n");
    int rows = 2, cols = 3;
    int **matrix_dyn = create_matrix(rows, cols);
    fill_matrix(matrix_dyn, rows, cols);
    print_matrix_2d(matrix_dyn, rows, cols);
    free_matrix(matrix_dyn, rows);

    printf("\n=== Exercise 20: Use void pointer to write a generic swap function for all types ===\n");
    int int_a = 5, int_b = 9;
    double double_a = 1.5, double_b = 2.5;
    generic_swap(&int_a, &int_b, sizeof(int));
    generic_swap(&double_a, &double_b, sizeof(double));
    printf("int swap: %d, %d\n", int_a, int_b);
    printf("double swap: %.2f, %.2f\n", double_a, double_b);

    return 0;
}

void swap_by_pointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void input_array_ptr(int *arr, int n)
{
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}

void print_array_ptr(const int *arr, int n)
{
    printf("Array entered: ");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

void basic_pointer_demo(void)
{
    int a = 0;
    int *ptr = &a;
    *ptr = 10;
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", (void *)&a);
    printf("Value of ptr: %p\n", (void *)ptr);
}

void size_via_void_pointer_demo(void)
{
    int i = 5;
    double d = 3.14;
    char c = 'A';

    void *vp = &i;
    printf("Size of int via void*: %zu bytes\n", sizeof(*(int *)vp));

    vp = &d;
    printf("Size of double via void*: %zu bytes\n", sizeof(*(double *)vp));

    vp = &c;
    printf("Size of char via void*: %zu bytes\n", sizeof(*(char *)vp));
}

void array_pointer_demo(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a;
    printf("p[0] = %d, p[2] = %d, p[4] = %d\n", p[0], p[2], p[4]);
    for (int i = 0; i < 5; i++)
        printf("a[%d] = %d, *(p + %d) = %d\n", i, a[i], i, *(p + i));
}

int count_chars_ptr(const char *str)
{
    int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

void modify_value_by_pointer(int *value)
{
    *value = 250;
}

void compare_pointer_addresses_demo(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = &arr[1];
    int *q = &arr[4];

    printf("Address of p = %p, address of q = %p\n", (void *)p, (void *)q);
    printf("Check p < q: %s\n", p < q ? "True" : "False");
    printf("Check p == q: %s\n", p == q ? "True" : "False");
}

void copy_string_ptr(char *dest, const char *src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void malloc_array_demo(void)
{
    int *arr = (int *)malloc(10 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    for (int i = 0; i < 10; i++)
        arr[i] = i * 10;

    printf("Allocated array: ");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
}

int *find_max_ptr(int *arr, int n)
{
    int *max = arr;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *max)
            max = arr + i;
    }
    return max;
}

void reverse_string_ptr(char *str)
{
    size_t len = strlen(str);
    char *start = str;
    char *end = str + len - 1;

    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void input_matrix_ptr(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", matrix + i * cols + j);
        }
    }
}

void print_matrix_ptr(const int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", *(matrix + i * cols + j));
        printf("\n");
    }
}

void add_matrices_ptr(const int *a, const int *b, int *result, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(result + i * cols + j) = *(a + i * cols + j) + *(b + i * cols + j);
        }
    }
}

int add_int(int a, int b)
{
    return a + b;
}

int sub_int(int a, int b)
{
    return a - b;
}

int mul_int(int a, int b)
{
    return a * b;
}

int div_int(int a, int b)
{
    if (b == 0) {
        printf("Error: division by zero\n");
        return 0;
    }
    return a / b;
}

int calculate_with_op(int a, int b, int (*op)(int, int))
{
    return op(a, b);
}

void generic_swap(void *a, void *b, size_t size)
{
    unsigned char *pa = (unsigned char *)a;
    unsigned char *pb = (unsigned char *)b;
    unsigned char temp;

    for (size_t i = 0; i < size; i++) {
        temp = pa[i];
        pa[i] = pb[i];
        pb[i] = temp;
    }
}

Node *create_node(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Node allocation failed\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

void append_node(Node **head, int value)
{
    Node *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

void print_list(const Node *head)
{
    const Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(Node *head)
{
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int **create_matrix(int rows, int cols)
{
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Row allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Column allocation failed\n");
            exit(1);
        }
    }
    return matrix;
}

void fill_matrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            matrix[i][j] = (i + 1) * (j + 1);
    }
}

void print_matrix_2d(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void free_matrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}