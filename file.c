#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char name[100];
    int roll;
    float marks;
};

void addstudent();
void displaystudents();

void addstudent() {
    struct student s;
    FILE *ptr;
    ptr = fopen("students.text", "a");

    if (ptr == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", s.name);   // Read full name with spaces

    printf("Enter Roll number: ");
    scanf("%d", &s.roll);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(ptr , "%s\n%d\n%.2f\n", s.name,s.roll, s.marks);
    fclose(ptr);

    printf("Student Record Added sucessfully!\n");

    // clear input buffer
    while (getchar() != '\n');
    
}

void displaystudents() {
    struct student s;
    FILE *ptr;
    ptr = fopen("students.text", "r");
    
    if (ptr == NULL){
        printf("No Records found!\n");
    }

    printf("\nstudent Records:\n");

    while(1) {
        //Read name (with spaces)
         if(fgets(s.name, 100, ptr) == NULL) break;
         s.name [strcspn(s.name, "\n")] = '\0';   // remove new line
    
        //Read marks
        char roll_str[20];
        if(fgets(roll_str, 20, ptr) == NULL) break;
        s.marks = atoi(roll_str);

        printf("name = %s\n", s.name);
        printf("Roll number = %d\n", s.roll);
        printf("Marks = %.2f\n\n", s.marks);
    }

    fclose(ptr); 
}

int main() {
    int choice;
    
    while (1)
    {
        printf("\nstudent management system\n");
        printf("1. Add students\n");
        printf("2. Display students records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //clear input buffer
        while (getchar() != '\n');

        switch (choice)
        {
            case 1:
               addstudent();
            break;

            case 2:
               displaystudents();
            break;

            case 3:
               printf("END PROGRAM. Thank You!\n");
              exit(0);

        default:
     printf("Invalid Your choice! please try again.\n");
        }
    }
   return 0; 
}
