#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int list[MAX_SIZE];
    int menu, size = 0;

    while (1) {
        printf("\nMenu\n");
        printf("(1) Insert\n");
        printf("(2) Delete\n");
        printf("(3) Print\n");
        printf("(0) Exit\n");
        printf("Enter the menu: ");
        scanf_s("%d", &menu);

        switch (menu) {
        case 0:
            printf("Exit the Program\n");
            exit(0);
        case 1: {
            int num, position;
            printf("Enter the number and position: ");
            scanf_s("%d %d", &num, &position);

            if (position < 0 || position > size) {
                printf("List size is zero. please enter again(number position):");
                scanf_s("%d %d", &num, &position);
                break;
            }

            // 데이터 이동 횟수 출력
            int i;
            for (i = size - 1; i >= position; i--) {
                list[i + 1] = list[i];
            }
            list[position] = num;
            size++;
            printf("Move: %d\n", size - position);
            break;
        }
        case 2: {
            int position;
            printf("Enter the position to delete: ");
            scanf_s("%d", &position);

            if (position < 0 || position >= size) {
                printf("Invalid Menu. Please select again.\n");
                break;
            }

            // 데이터 이동 횟수 출력
            int i;
            for (i = position; i < size - 1; i++) {
                list[i] = list[i + 1];
            }

            size--;

            printf("Delete: %d\n", size - position + 1);
            break;
        }
        case 3:
            if (size == 0) {
                printf("List is empty.\n");
                break;
            }

            int i;
            for (i = 0; i < size; i++) {
                printf("%d->", list[i]);
            }
            printf("\n");
            break;
        default:
            printf("Invalid Menu. Please select again.\n");
            break;
        }
    }

    return 0;
}

