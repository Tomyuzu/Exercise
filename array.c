#include <stdio.h>
#include <stdlib.h>

static void print_array(const int *array, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int length;
    printf("Enter the array length: ");
    if (scanf("%d", &length) != 1 || length <= 0)
    {
        printf("Invalid array length.\n");
        return 1;
    }

    int *array = malloc((size_t)length * sizeof(*array));
    if (array == NULL)
    {
        printf("Unable to allocate memory.\n");
        return 1;
    }

    printf("Enter %d integers: ", length);
    for (int i = 0; i < length; i++)
        scanf("%d", &array[i]);
    printf("You entered: ");
    print_array(array, length);

    int choice;
    int continue_operations = 1;
    while (continue_operations == 1)
    {
        printf("Now enter your choice (1-20):\n");
        printf("1. Get the sum of 5 integers \n");
        printf("2. Find the max in a dynamic array \n");
        printf("3. Count the odd and even numbers among 5 integers \n");
        printf("4. Reverse the array\n");
        printf("5. Get the max integer and its position in the array \n");
        printf("6. Check if the integer exists in the array \n");
        printf("7. Get the average of all elements in the array \n");
        printf("8. Merge two arrays into a third array \n");
        printf("9. Arrange the array in ascending order \n");
        printf("10. Delete an element at a given position from the array\n");
        printf("11. Insert an element at a given position in the array\n");
        printf("12. Get the element that exists most frequently \n");
        printf("13. Eliminate all repeats from the array\n");
        printf("14. Reverse elements for each 3-element-chunk \n");
        printf("15. Get the sum of the elements at even indices \n");
        printf("16. Get the sum of elements on the main diagonal of a square 3x3 matrix \n");
        printf("17. Get the sum of elements on the anti-diagonal of a square 3x3 matrix \n");
        printf("18. Check if the given matrix is an asymmetric matrix \n");
        printf("19. Add two square 3x3 matrices \n");
        printf("20. Multiply two square 3x3 matrices \n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                int sum = 0;
                for (int i = 0; i < length; i++) sum += array[i];
                printf("Sum: %d\n", sum);
                break;
            }
            case 2:
            {
                int maximum = array[0];
                for (int i = 1; i < length; i++)
                    if (array[i] > maximum) maximum = array[i];
                printf("Maximum: %d\n", maximum);
                break;
            }
            case 3:
            {
                int odd = 0, even = 0;
                for (int i = 0; i < length; i++)
                    if (array[i] % 2 == 0) even++; else odd++;
                printf("Odd: %d, even: %d\n", odd, even);
                break;
            }
            case 4:
                for (int i = 0; i < length / 2; i++)
                {
                    int temporary = array[i];
                    array[i] = array[length - 1 - i];
                    array[length - 1 - i] = temporary;
                }
                printf("Reversed: "); print_array(array, length);
                break;
            case 5:
            {
                int position = 0;
                for (int i = 1; i < length; i++)
                    if (array[i] > array[position]) position = i;
                printf("Maximum: %d at position %d\n", array[position], position);
                break;
            }
            case 6:
            {
                int target, found = 0;
                printf("Target: "); scanf("%d", &target);
                for (int i = 0; i < length; i++)
                    if (array[i] == target) { printf("Found at %d\n", i); found = 1; }
                if (!found) printf("Not found\n");
                break;
            }
            case 7:
            {
                int sum = 0;
                for (int i = 0; i < length; i++) sum += array[i];
                printf("Average: %.2f\n", (double)sum / length);
                break;
            }
            case 8:
            {
                int *second = malloc((size_t)length * sizeof(*second));
                int *merged = malloc((size_t)length * 2 * sizeof(*merged));
                if (second == NULL || merged == NULL)
                {
                    printf("Unable to allocate memory.\n");
                    free(second); free(merged); break;
                }
                printf("Enter %d integers for the second array: ", length);
                for (int i = 0; i < length; i++) scanf("%d", &second[i]);
                for (int i = 0; i < length; i++)
                { merged[i] = array[i]; merged[length + i] = second[i]; }
                printf("Merged: "); print_array(merged, length * 2);
                free(second); free(merged);
                break;
            }
            case 9:
                for (int i = 0; i < length - 1; i++)
                    for (int j = i + 1; j < length; j++)
                        if (array[i] > array[j])
                        { int temporary = array[i]; array[i] = array[j]; array[j] = temporary; }
                printf("Sorted: "); print_array(array, length);
                break;
            case 10:
            {
                int position;
                if (length == 1)
                {
                    printf("The array must contain at least one element.\n");
                    break;
                }
                printf("Position to delete (0-%d): ", length - 1); scanf("%d", &position);
                if (position < 0 || position >= length) { printf("Invalid position\n"); break; }
                for (int i = position; i < length - 1; i++) array[i] = array[i + 1];
                length--;
                int *resized = realloc(array, (size_t)length * sizeof(*array));
                if (resized != NULL) array = resized;
                printf("After deletion: "); print_array(array, length);
                break;
            }
            case 11:
            {
                int position, value;
                printf("Position to insert (0-%d): ", length); scanf("%d", &position);
                if (position < 0 || position > length) { printf("Invalid position\n"); break; }
                printf("Value: "); scanf("%d", &value);
                int *resized = realloc(array, (size_t)(length + 1) * sizeof(*array));
                if (resized == NULL) { printf("Unable to allocate memory.\n"); break; }
                array = resized;
                for (int i = length; i > position; i--) array[i] = array[i - 1];
                array[position] = value; length++;
                printf("After insertion: "); print_array(array, length);
                break;
            }
            case 12:
            {
                int value = array[0], best_frequency = 0;
                for (int i = 0; i < length; i++)
                {
                    int frequency = 0;
                    for (int j = 0; j < length; j++) if (array[i] == array[j]) frequency++;
                    if (frequency > best_frequency) { best_frequency = frequency; value = array[i]; }
                }
                printf("Most frequent: %d (%d times)\n", value, best_frequency);
                break;
            }
            case 13:
            {
                int unique_length = 0;
                for (int i = 0; i < length; i++)
                {
                    int duplicate = 0;
                    for (int j = 0; j < unique_length; j++) if (array[i] == array[j]) duplicate = 1;
                    if (!duplicate) array[unique_length++] = array[i];
                }
                length = unique_length;
                int *resized = realloc(array, (size_t)length * sizeof(*array));
                if (resized != NULL) array = resized;
                printf("Without repeats: "); print_array(array, length);
                break;
            }
            case 14:
                for (int start = 0; start < length; start += 3)
                {
                    int end = start + 2 < length ? start + 2 : length - 1;
                    for (int left = start; left < end; left++, end--)
                    { int temporary = array[left]; array[left] = array[end]; array[end] = temporary; }
                }
                printf("Reversed chunks: "); print_array(array, length);
                break;
            case 15:
            {
                int sum = 0;
                for (int i = 0; i < length; i += 2) sum += array[i];
                printf("Even-index sum: %d\n", sum);
                break;
            }
            default: printf("Invalid choice\n");
        }
        printf("Another operation? (1 yes, 0 no): ");
        scanf("%d", &continue_operations);
    }

    free(array);
    return 0;
}