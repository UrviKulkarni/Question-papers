#include <stdio.h>
#include <string.h>

int main()
{
    int choice, subject, qp;
    FILE *fp;
    char line[200];

    while (1)
    {
        printf("\n--- What do you want to study? ---\n");
        printf("1. Practice\n2. Notes\n3. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            while(getchar() != '\n'); // clear buffer
            continue;
        }
        getchar(); // clear newline after choice

        switch (choice)
        {
        case 1: // Practice
            printf("\nEnter Subject:\n1. English\n2. Maths\n3. Physics\n4. Chemistry\n5. Biology\n");
            printf("Enter Choice: ");
            if (scanf("%d", &subject) != 1)
            {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                continue;
            }
            getchar();

            printf("\nSelect Question Paper:\n1. Question Paper 1\n2. Question Paper 2\n");
            printf("Enter Choice: ");
            if (scanf("%d", &qp) != 1)
            {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                continue;
            }
            getchar();

            switch (subject)
            {
            case 1: fp = fopen((qp == 1) ? "English QP 1.txt" : "English QP 2.txt", "a"); break;
            case 2: fp = fopen((qp == 1) ? "Maths QP 1.txt" : "Maths QP 2.txt", "a"); break;
            case 3: fp = fopen((qp == 1) ? "Physics QP 1.txt" : "Physics QP 2.txt", "a"); break;
            case 4: fp = fopen((qp == 1) ? "Chemistry QP 1.txt" : "Chemistry QP 2.txt", "a"); break;
            case 5: fp = fopen((qp == 1) ? "Biology QP 1.txt" : "Biology QP 2.txt", "a"); break;
            default: printf("Invalid subject.\n"); continue;
            }

            if (!fp) { printf("Error opening file.\n"); break; }

            fprintf(fp, "%d %d\n", subject, qp); // placeholder
            fclose(fp);
            break;

        case 2: // Notes
            printf("\nEnter Subject for Notes:\n1. English\n2. Maths\n3. Physics\n4. Chemistry\n5. Biology\n");
            printf("Enter Choice: ");
            if (scanf("%d", &subject) != 1)
            {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                continue;
            }
            getchar();

            printf("\nSelect Question Paper for Notes:\n1. Question Paper 1\n2. Question Paper 2\n");
            printf("Enter Choice: ");
            if (scanf("%d", &qp) != 1)
            {
                printf("Invalid input.\n");
                while(getchar() != '\n');
                continue;
            }
            getchar();

            switch (subject)
            {
            case 1: fp = fopen((qp == 1) ? "English QP 1.txt" : "English QP 2.txt", "a"); break;
            case 2: fp = fopen((qp == 1) ? "Maths QP 1.txt" : "Maths QP 2.txt", "a"); break;
            case 3: fp = fopen((qp == 1) ? "Physics QP 1.txt" : "Physics QP 2.txt", "a"); break;
            case 4: fp = fopen((qp == 1) ? "Chemistry QP 1.txt" : "Chemistry QP 2.txt", "a"); break;
            case 5: fp = fopen((qp == 1) ? "Biology QP 1.txt" : "Biology QP 2.txt", "a"); break;
            default: printf("Invalid subject.\n"); continue;
            }

            if (!fp) { printf("Error opening file.\n"); break; }

            printf("Enter your notes (type 'END' on a new line to stop):\n");
            while(1)
            {
                fgets(line, sizeof(line), stdin);
                if (strncmp(line, "END", 3) == 0) break;
                fprintf(fp, "%s", line);
            }

            fclose(fp);
            break;

        case 3:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
