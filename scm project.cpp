#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book 
{
    char title[50];
    char author[50];
    int id;
    int year;
};

void addBook(struct Book books[], int *numBooks);
void deleteBook(struct Book books[], int *numBooks);
void displayBooks(struct Book books[], int numBooks);

int main() {
    struct Book books[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    do {
        printf("\n--- Library Management System ---\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addBook(books, &numBooks);
                break;
            case 2:
                deleteBook(books, &numBooks);
                break;
            case 3:
                displayBooks(books, numBooks);
                break;
            case 4:
                printf("Exiting Library Management System...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void addBook(struct Book books[], int *numBooks) {
    if(*numBooks == MAX_BOOKS) {
        printf("The library is full.\n");
        return;
    }

    printf("Enter book title: );
    scanf("%s", books[*numBooks].title);
    printf("Enter author name: ");
    scanf("%s", books[*numBooks].author);
    printf("Enter book ID: ");
    scanf("%d", &books[*numBooks].id);
    printf("Enter year of publication: ");
    scanf("%d", &books[*numBooks].year);

    (*numBooks)++;
    printf("Book added successfully.\n");
}

void deleteBook(struct Book books[], int *numBooks) {
    int id, i, found = 0;

    printf("Enter book ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < *numBooks; i++) {
        if(books[i].id == id) {
            found = 1;
            break;
        }
    }

    if(found) {
        (*numBooks)--;
        for(; i < *numBooks; i++) {
            books[i] = books[i+1];
        }
        printf("Book deleted successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

void displayBooks(struct Book books[], int numBooks) {
    int i;

    if(numBooks == 0) {
        printf("The library is empty.\n");
        return;
    }

    printf("%-20s %-20s %-10s %-10s\n", "Title", "Author", "ID", "Year");
    for(i = 0; i < numBooks; i++) {
        printf("%-20s %-20s %-10d %-10d\n", books[i].title, books[i].author, books[i].id, books[i].year);
    }
}
