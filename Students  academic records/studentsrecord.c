#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    char dept[50];
    float gpa;
    struct Student *next;
} Student;

Student *head = NULL;


Student* createStudent(int id, char name[], char dept[], float gpa) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    strcpy(newStudent->dept, dept);
    newStudent->gpa = gpa;
    newStudent->next = NULL;
    return newStudent;
}


void insertStudent(int id, char name[], char dept[], float gpa) {
    Student* newStudent = createStudent(id, name, dept, gpa);
    if (head == NULL) {
        head = newStudent;
        return;
    }
    Student* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
    printf("Student record inserted successfully.\n");
}


void deleteStudent(int id) {
    if (head == NULL) {
        printf("No records to delete.\n");
        return;
    }
    Student *temp = head, *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Student with ID %d deleted successfully.\n", id);
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Student ID %d not found.\n", id);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Student with ID %d deleted successfully.\n", id);
}


void searchStudent(char key[]) {
    Student* temp = head;
    int found = 0;
    while (temp != NULL) {
        char idStr[10];
        sprintf(idStr, "%d", temp->id);
        if (strcmp(temp->name, key) == 0 || strcmp(idStr, key) == 0) {
            printf("\nStudent Found:\n");
            printf("ID: %d | Name: %s | Dept: %s | GPA: %.2f\n", temp->id, temp->name, temp->dept, temp->gpa);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("No student record matches '%s'.\n", key);
}


void displayStudents() {
    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }
    Student* temp = head;
    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Dept: %s | GPA: %.2f\n", temp->id, temp->name, temp->dept, temp->gpa);
        temp = temp->next;
    }
}


void displayReverse(Student* node) {
    if (node == NULL) return;
    displayReverse(node->next);
    printf("ID: %d | Name: %s | Dept: %s | GPA: %.2f\n", node->id, node->name, node->dept, node->gpa);
}


Student* cloneList(Student* srcHead) {
    if (srcHead == NULL) return NULL;
    Student* newHead = createStudent(srcHead->id, srcHead->name, srcHead->dept, srcHead->gpa);
    Student* src = srcHead->next;
    Student* dest = newHead;
    while (src != NULL) {
        dest->next = createStudent(src->id, src->name, src->dept, src->gpa);
        dest = dest->next;
        src = src->next;
    }
    return newHead;
}


void calculateAverageGPA() {
    if (head == NULL) {
        printf("No student records to calculate GPA.\n");
        return;
    }
    Student* temp = head;
    int count = 0;
    float sum = 0;
    while (temp != NULL) {
        sum += temp->gpa;
        count++;
        temp = temp->next;
    }
    printf("Average GPA of %d students: %.2f\n", count, sum / count);
}


int main() {
    int choice, id;
    char name[50], dept[50], key[50];
    float gpa;
    Student* backupList = NULL;

    while (1) {
        printf("\n--- Student Academic Record Management ---\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student by ID\n");
        printf("3. Search Student (by ID/Name)\n");
        printf("4. Display All Students\n");
        printf("5. Display Students in Reverse Order\n");
        printf("6. Clone List (Backup)\n");
        printf("7. Calculate Average GPA\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: "); scanf("%d", &id);
                printf("Enter Name: "); scanf("%s", name);
                printf("Enter Department: "); scanf("%s", dept);
                printf("Enter GPA: "); scanf("%f", &gpa);
                insertStudent(id, name, dept, gpa);
                break;

            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;

            case 3:
                printf("Enter Name or ID to search: ");
                scanf("%s", key);
                searchStudent(key);
                break;

            case 4:
                displayStudents();
                break;

            case 5:
                if (head == NULL) printf("No records to display in reverse.\n");
                else {
                    printf("\nStudents in Reverse Order:\n");
                    displayReverse(head);
                }
                break;

            case 6:
                backupList = cloneList(head);
                if (backupList != NULL)
                    printf("Student records cloned successfully.\n");
                else
                    printf("No records to clone.\n");
                break;

            case 7:
                calculateAverageGPA();
                break;

            case 8:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
