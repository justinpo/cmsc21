// Collaborators: Po, Justin Andre
//                Manzanares, Gabriel John

#include <stdio.h>

// main program
int main() {
    int choice, i, count = 0;
    char person1[100], person2[100];
    int error = 0, unique = 1, uniqueChars1 = 0, uniqueChars2 = 0, uniqueChars;
    char str[100];
    int space = 1;
    int words = 0;

    do {
        // menu
        printf("\nMenu: \n\n [1] Count Words\n [2] FLAMES \n [3] Exit\n\nChoose one: ");
        scanf("%i", &choice);
        if (choice <= 0 || choice >= 4) {
            printf("\nPlease choose only from the numbers on the menu.\n");
        }
    } while (choice <= 0 || choice >= 4);

    switch (choice) {

        case 1: {
            do {
                printf("Enter your string: ");
                scanf(" %[^\n]s", str);
                
                error = 0;

                for (i = 0; str[i] != '\0'; i++) {
                    if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == ' ')) {
                        error = 1;
                        break;
                    }
                }
                if (error) {
                    printf("You have entered an invalid input\n");
                    printf("\n");
                }
            } while (error);

            for (i = 0; str[i] != '\0'; i++) {
                if (str[i] == ' ') {
                    space = 1;
                }
                if (space == 1 && str[i] != ' ') {
                    words += 1;
                    space = 0;
                }
            }

            if (words != 1) {
                printf("There are %i words in the string.\n", words);
            } else {
                printf("There is only 1 word in the string\n");
            }

            printf("\n");

            break;
        }


        case 2: {
            do {
                printf("\nPlease enter the first person's name\n> ");
                scanf(" %[^\n]s", person1);
                error = 0;
                for (i = 0; person1[i] != '\0'; i++) {
                    if (!((person1[i] >= 'A' && person1[i] <= 'Z') || (person1[i] >= 'a' && person1[i] <= 'z') || person1[i] == ' ')) {
                        error = 1;
                    }
                }
                if (error) {
                    printf("You have entered an invalid input\n");
                }
            } while (error);

            do {
                printf("\nPlease enter the second person's name\n> ");
                scanf(" %[^\n]s", person2);
                error = 0;
                for (i = 0; person2[i] != '\0'; i++) {
                    if (!((person2[i] >= 'A' && person2[i] <= 'Z') || (person2[i] >= 'a' && person2[i] <= 'z') || person2[i] == ' ')) {
                        error = 1;
                    }
                }
                if (error) {
                    printf("You have entered an invalid input\n");
                }
            } while (error);

            for (i = 0; person1[i] != '\0'; i++) {
                if (person1[i] >= 'A' && person1[i] <= 'Z') {
                    person1[i] += ('a' - 'A');
                }
            }

            for (i = 0; person2[i] != '\0'; i++) {
                if (person2[i] >= 'A' && person2[i] <= 'Z') {
                    person2[i] += ('a' - 'A');
                }
            }

            for (i = 0; person1[i] != '\0'; i++) {
                unique = 1;
                if (person1[i] != '*' && person1[i] != ' ') {
                    for (int j = 0; person2[j] != '\0'; j++) {
                        if (person1[i] == person2[j]) {
                            person2[j] = '*';
                            unique = 0;
                        }
                    }
                    if (!unique) {
                        for (int k = i + 1; person1[k] != '\0'; k++) {
                            if (person1[i] == person1[k]) {
                                person1[k] = '*';
                            }
                        }

                        person1[i] = '*';
                    }
                }
            }

            for (i = 0; person1[i] != '\0'; i++) {
                if (person1[i] == '*' && person1[i] != ' ') {
                    uniqueChars1++;
                }
            }

            for (i = 0; person2[i] != '\0'; i++) {
                if (person2[i] == '*' && person2[i] != ' ') {
                    uniqueChars2++;
                }
            }

            uniqueChars = uniqueChars1 + uniqueChars2;
            printf("\n");

            if (uniqueChars == 0) {
                printf("Person 1: Walay future :(\n");
                printf("Person 2: Walay future :(\n");
                printf("Overall: Walay future :(\n");
            }
            else {
                uniqueChars1 %= 6;
                printf("Person 1: ");
                switch (uniqueChars1) {
                    case 0:
                        printf("Sweethearts\n");
                        break;
                    case 1:
                        printf("Friends\n");
                        break;
                    case 2:
                        printf("Lovers\n");
                        break;
                    case 3:
                        printf("Acceptance\n");
                        break;
                    case 4:
                        printf("Marriage\n");
                        break;
                    case 5:
                        printf("Engagement\n");
                        break;
                    default:
                        printf("Impossible Error");
                        break;
                }

                uniqueChars2 %= 6;
                printf("Person 2: ");
                switch (uniqueChars2) {
                    case 0:
                        printf("Sweethearts\n");
                        break;
                    case 1:
                        printf("Friends\n");
                        break;
                    case 2:
                        printf("Lovers\n");
                        break;
                    case 3:
                        printf("Acceptance\n");
                        break;
                    case 4:
                        printf("Marriage\n");
                        break;
                    case 5:
                        printf("Engagement\n");
                        break;
                    default:
                        printf("Impossible Error");
                        break;
                }

                uniqueChars %= 6;
                printf("Overall: ");
                switch (uniqueChars) {
                    case 0:
                        printf("Sweethearts\n");
                        break;
                    case 1:
                        printf("Friends\n");
                        break;
                    case 2:
                        printf("Lovers\n");
                        break;
                    case 3:
                        printf("Acceptance\n");
                        break;
                    case 4:
                        printf("Marriage\n");
                        break;
                    case 5:
                        printf("Engagement\n");
                        break;
                    default:
                        printf("Impossible Error");
                        break;
                }
            }
            
            printf("\n");

            break;
        }
        case 3:
            printf("Thank you for using our program!\n");
            printf("\n");
            break;
    }
}