# Student Academic Record Management System

Description:
This C program manages student academic records using a singly linked list. It allows inserting, deleting, searching, displaying, reverse displaying, cloning, and calculating the average GPA of students. Each student record contains ID, Name, Department, and GPA.

Features:
1. Insert Student – Add a student with ID, Name, Department, and GPA.
2. Delete Student by ID – Remove a student record by ID.
3. Search Student (by ID/Name) – Search records using ID or Name.
4. Display All Students – View all student records.
5. Display Students in Reverse Order – Show records from last to first using recursion.
6. Clone List (Backup) – Create a backup copy of the student list.
7. Calculate Average GPA – Compute the average GPA of all students.
8. Exit – Close the program.

How it Works:
- Uses a struct Student with fields: ID, Name, Department, GPA, and a pointer to the next node.
- Linked list dynamically stores records.
- Menu-driven interface allows easy operation.
- Recursive function is used for reverse display.

Compilation and Execution:
gcc studentsrecord.c -o studentsrecord
./studentsrecord

Sample Input/Output:
Enter your choice: 1
Enter ID: 101
Enter Name: Alice
Enter Department: CSE
Enter GPA: 9.1
Student record inserted successfully.

Enter your choice: 4
Student Records:
ID: 101 | Name: Alice | Dept: CSE | GPA: 9.10

