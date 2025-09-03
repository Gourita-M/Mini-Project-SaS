#include <stdio.h>

int main(){

        int choice;
        // for Adding a book
        char titles[100][50];
        char authors[100][30];
        float prices[100];
        int quantities[100];
        int bookCount = 0;

    do
        {
            printf("##########  BookStore  ##########");
            printf("\n");
            printf("1.Add a book to stock.\n");
            printf("2.Show all available books.\n");
            printf("3.Update the Quantity of a Book.\n");
            printf("4.Remove a Book from Stock.\n");
            printf("5.Show Total Number of Books in Stock.\n");
            printf("0.Exit\n");
            printf("#################################\n");
            printf("Enter Your Choice(0-5): ");
                scanf("%d",&choice);
            
    switch (choice)
            {
            case 1: //Addiding a Book to Shop
                   
                   if (bookCount >= 100) {
                       printf("Stock is full!\n");
                    }
                          else {
                                printf("##########  BookStore  ##########\n");
                                printf("\n");
                                printf("Adding a book to stock.\n");
                                printf("\n");
                                printf("Enter book title: ");
                                       scanf(" %[^\n]", titles[bookCount]);
                                printf("Enter author name: ");
                                       scanf(" %[^\n]", authors[bookCount]);

                                printf("Enter book price: ");
                                       scanf("%f", &prices[bookCount]);

                                printf("Enter quantity: ");
                                       scanf("%d", &quantities[bookCount]);
            
                                printf("#################################\n");
                                printf("Book added successfully!\n");

                       bookCount++;
                    }                      
            break;
            case 2:   // Showing All Available Books

               
                    if (bookCount == 0){
                        printf("\nBook Shop is Empty\n");
                    }
                        else {
                             printf("##########  BookStore  ##########\n");
                             printf("\nShowing All Available Books");
                             printf("\nBooks Shop List\n");

                                   for (int i = 0 ; i < bookCount ; i++){
                                        printf("\n");
                                        printf("Book Name: %s\n",titles[i]);
                                        printf("Book Authors: %s\n",authors[i]);
                                        printf("Book Price: $%.2f\n",prices[i]);
                                        printf("Book Quantite: %d\n",quantities[i]);
                                        printf("___________________________________\n");
                                    }
                             }

            break;
            case 3:// Update Quantity
                if (bookCount == 0) {
                    printf("Book Shop is Empty\n");
                    break;
                }

                {
                    char search[50];
                    printf("Enter the title of the book to update: ");
                    scanf(" %[^\n]", search);

                    int found = -1;
                    for (int i = 0; i < bookCount; i++) {
                        int match = 1;
                        int j = 0;
                        while (titles[i][j] != '\0' || search[j] != '\0') {
                            if (titles[i][j] != search[j]) {
                                match = 0;
                                break;
                            }
                            j++;
                        }
                        if (match) {
                            found = i;
                            break;
                        }
                    }

                    if (found != -1) {
                        printf("Current quantity of '%s': %d\n", titles[found], quantities[found]);
                        printf("Enter new quantity: ");
                        scanf("%d", &quantities[found]);
                        printf("Quantity updated successfully!\n");
                    } else {
                        printf("Book not found!\n");
                    }
                }
                 
                
                break;
            case 4:
                    if (bookCount == 0) {
        printf("Book Shop is Empty\n");
        break;
    }

    {
        char search[50];
        printf("Enter the title of the book to remove: ");
        scanf(" %[^\n]", search);

        int found = -1;
        for (int i = 0; i < bookCount; i++) {
            int match = 1;
            int j = 0;
            while (titles[i][j] != '\0' || search[j] != '\0') {
                if (titles[i][j] != search[j]) {
                    match = 0;
                    break;
                }
                j++;
            }
            if (match) {
                found = i;
                break;
            }
        }

        if (found != -1) {
            // Shift all books after the removed one
            for (int i = found; i < bookCount - 1; i++) {
                // Move title
                int j = 0;
                while (titles[i + 1][j] != '\0') {
                    titles[i][j] = titles[i + 1][j];
                    j++;
                }
                titles[i][j] = '\0';

                // Move author
                j = 0;
                while (authors[i + 1][j] != '\0') {
                    authors[i][j] = authors[i + 1][j];
                    j++;
                }
                authors[i][j] = '\0';

                // Move price and quantity
                prices[i] = prices[i + 1];
                quantities[i] = quantities[i + 1];
            }
            bookCount--;
            printf("Book removed successfully!\n");
        } else {
            printf("Book not found!\n");
        }
    }
    break;
            case 5:
                
                break;
            default:
                        if(choice == 0)
                             printf("Thank U for Using Our BootStore");
                                   else
                                       printf("Wrong Choice Must be (0 - 5) Please Try Again\n");
                break;
            }
        } 
           while (choice != 0);




    return 0;
}