#include <stdio.h>
int main() {
    int a = 0;
    printf("Hello, World! I am Ocean Tuna\n");
    scanf("%d", &a);
    printf("You entered: %d\n", a);
    printf("Now enter your choice (1-13):\n");
    printf("1. Set bit at a particular position\n");
    printf("2. Clear bit at a particular position\n");
    printf("3. Toggle bit at a particular position\n");
    printf("4. Check bit at a particular position\n");
    printf("5. Count number of set bits in the integer\n");
    printf("6. Check if the integer is a power of two\n");
    printf("7. Find 2's complement of the integer\n");
    printf("8. Check if the integer is even or odd\n");
    printf("9. Find the most significant bit set in the integer\n");
    printf("10. Find the least significant bit set in the integer\n");
    printf("11. Clear the rightmost set bit in the integer\n");
    printf("12. Get the rightmost set bit in the integer\n");
    printf("13. Check if the integer has 8 as a factor\n");
    int choice, position;
    int new_operation = 1;
    scanf("%d", &choice);
    printf("Enter the position (0-31): ");
    scanf("%d", &position);
    while (1 == new_operation)
    {
        switch (choice) 
        {
            case 1:
            {
                a |= (1 << position);
                printf("After setting bit at position %d: %d\n", position, a);
            }
            break;
                
            case 2:
            {
                a &= ~(1 << position);
                printf("After clearing bit at position %d: %d\n", position, a);
            }
            break;

            case 3:
            {
                a ^= (1 << position);
                printf("After toggling bit at position %d: %d\n", position, a);
            }
            break;

            case 4:
            {
                if (0 != (a & (1 << position)))
                    printf("Bit at position %d is set\n", position);
                else
                    printf("Bit at position %d is not set\n", position);
            }
            break;

            case 5: 
            {
                int count = 0;
                for (int i = 0; i < 32; i++) 
                {
                    if (a & (1 << i)) 
                    {
                        count++;
                    }
                }
                printf("Number of set bits in %d: %d\n", a, count);
            }
            default:
                printf("Invalid choice\n");
        }
        printf("Do you want to perform another operation? (1 for yes, 0 for no): ");
        scanf("%d", &new_operation);
    }
    
    return 0;
}