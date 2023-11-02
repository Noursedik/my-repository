/*Question 2*/
/*Pre-Processor Directives*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define numOfSubjects 3
#define numOfStudents 10
/*Data structure definition*/
typedef struct {
    char FirstName[20];
    char LastName[20];
    int StudentID;
    float SubjectMarks[numOfSubjects];
    int AggregateMarks;
    char Grade[10];
} StudentRecord;
/*An array declared with size equal to number of students, for each element has the data structure StudentRecord */
StudentRecord studentList[numOfStudents];
/*Functions prototypes*/
void enrol();
void searchUpdate();
void topStudents();

/*Main function*/
int main() {
    int choice;
    printf("Welcome to Year2 Univerity system\n");
    printf("1. Enrol\n2. Search/Update\n3. Top Students\n4. Exit\n");
    scanf("%d", &choice);
/*Checking user choice to know which process he/she are wiling to do*/
    switch (choice) {
        case 1:
            enrol();
            main();
            break;   
        case 2:
            searchUpdate();
            main();
            break;
        case 3:
            topStudents();
            main();
            break;
        case 4:
            printf("Thank you for using our system\n");
            return(1);
        default:
            printf("Invalid Choice.\n");
            main();
    }
}

/*Enrol Funtcion*/
void enrol() {
    int id;
    printf("Enter Student ID: ");//allowing user to enter student Id
    scanf("%d", &id);
    int found = -1;
    //Check in the student Id aray if this student already exists
    for (int i = 0; i < numOfStudents; i++) {
        if (studentList[i].StudentID == id) {
            found = i;
            break;
        }
    }
    //If student doesn't exist allow user to enter student details as per the data structure
    if (found == -1) {
        for (int i = 0; i < numOfStudents; i++) {
            if (studentList[i].StudentID == 0) {
                found = i;
                studentList[i].StudentID = id;
                printf("Enter First Name: ");
                scanf("%s", studentList[i].FirstName);
                printf("Enter Last Name: ");
                scanf("%s", studentList[i].LastName);
                for (int j = 0; j < numOfSubjects; j++) {
                    printf("Enter Subject %d Mark (or -1 to skip): ", j);
                    scanf("%f", &studentList[i].SubjectMarks[j]);//allowing the user to inpt each subject mark for the student
                    //checking if the mark entered is within the accepted mark range
                    if(studentList[i].SubjectMarks[j]<-1 || studentList[i].SubjectMarks[j]>100){
                        printf("Invalid subject mark, please re-enter a valid mark from 0-100\n");//if mark is invalid, allow user to re-enter the mark for the subject
                        printf("Enter Subject %d Mark (or -1 to skip): ", j);
                        scanf("%f", &studentList[i].SubjectMarks[j]);
                    }
                }
                /*Calculating the total marks if all subject marks are inputed*/
                float total = 0;
                for (int j = 0; j < numOfSubjects; j++) {
                    if (studentList[i].SubjectMarks[j] == -1) {
                        total=-1;
                        break;
                    }
                    else {
                        total += studentList[i].SubjectMarks[j];
                    }
                }
                /*Printing the grade for the student depending on their Average Mark*/
                if (total ==-1) {
                    studentList[i].AggregateMarks = -1;
                    strcpy(studentList[i].Grade, "undefined");
                }else {
                    studentList[i].AggregateMarks = (int)(total/numOfSubjects);
                    if ((total/numOfSubjects) >= 85) {
                        strcpy(studentList[i].Grade, "HD");
                    } else if ((total/numOfSubjects) >= 75) {
                        strcpy(studentList[i].Grade, "D");
                    } else if ((total/numOfSubjects) >= 65) {
                        strcpy(studentList[i].Grade, "C");
                    } else if ((total/numOfSubjects) >= 50) {
                        strcpy(studentList[i].Grade, "P");
                    } else {
                        strcpy(studentList[i].Grade, "F");
                    }
                }
                 break;   
            }
        }
    }
    else {
        printf("Student ID already exists.\n");
    }
}


/*Search Update Function*/
void searchUpdate() {
    int option;
    printf("Search by:\n1. Student ID\n2. Last Name\n");//allow the user to choose to search by student Id or Last name
    scanf("%d", &option);
    int index = -1;
    if (option == 1) {
        int id;
        printf("Enter Student ID: ");
        scanf("%d", &id);
        /*Checking if the studentId already exists or not*/
        for (int i = 0; i < numOfStudents; i++) {
            if (studentList[i].StudentID == id) {
                index = i;
                break;
            }
        }
    } else if (option == 2) {
        char name[20];
        printf("Enter Last Name: ");
        scanf("%s", name);
        /*Checking if the last name already exists or not*/
        for (int i = 0; i < numOfStudents; i++) {
            if (strcasecmp(studentList[i].LastName, name) == 0) {//not case sensitive
                index = i;
                break;
            }
        }
    }else {
        printf("Invalid number,please try again\n");
        searchUpdate();
    }
    if (index == -1) {
        printf("Student not found.\n");
    } else {
        /*Printing all student information as per the data structure*/
        printf("Student Found:\n");
        printf("First Name: %s\n", studentList[index].FirstName);
        printf("Last Name: %s\n", studentList[index].LastName);
        printf("Student ID: %d\n", studentList[index].StudentID);
        printf("Subject Marks: ");
        for (int i = 0; i < numOfSubjects; i++) {
            printf("%.2f ", studentList[index].SubjectMarks[i]);
        }
        printf("\nAggregate Marks: %d\n", studentList[index].AggregateMarks);
        printf("Grade: %s\n", studentList[index].Grade);
        printf("Update Student Record? (Y/N): ");//allowing the user to update student information
        char update;
        scanf(" %c", &update);
        /*Checking and updating student information*/
        if (update == 'Y' || update == 'y') {
            printf("Enter First Name: ");
            scanf("%s", studentList[index].FirstName);
            printf("Enter Last Name: ");
            scanf("%s", studentList[index].LastName);
            for (int j = 0; j < numOfSubjects; j++) {
                printf("Enter Subject %d Mark (or -1 to skip): ", j);
                scanf("%f", &studentList[index].SubjectMarks[j]);
                if(studentList[index].SubjectMarks[j]<-1 || studentList[index].SubjectMarks[j]>100){
                    printf("Invalid subject mark, please re-enter a valid mark from 0-100\n");
                    printf("Enter Subject %d Mark (or -1 to skip): ", j);
                    scanf("%f", &studentList[index].SubjectMarks[j]);
                }
            }
            /*Calculating the total marks if all subject marks are inputed*/
            float total = 0;
                for (int j = 0; j < numOfSubjects; j++) {
                    if (studentList[index].SubjectMarks[j] == -1) {
                        total=-1;
                        break;
                    }
                    else {
                        total += studentList[index].SubjectMarks[j];
                    }
                }
            /*Printing the grade for the student depending on their Average Mark*/
            if (total == -1) {
                studentList[index].AggregateMarks = -1;
                strcpy(studentList[index].Grade, "undefined");
            } else {
                studentList[index].AggregateMarks = (int)(total/numOfSubjects);
                if ((total/numOfSubjects) >= 85) {
                    strcpy(studentList[index].Grade, "HD");
                } else if ((total/numOfSubjects) >= 75) {
                    strcpy(studentList[index].Grade, "D");
                } else if ((total/numOfSubjects) >= 65) {
                    strcpy(studentList[index].Grade, "C");
                } else if ((total/numOfSubjects) >= 50) {
                    strcpy(studentList[index].Grade, "P");
                } else {
                    strcpy(studentList[index].Grade, "F");
                }
            }
        }
    }
}

/*Top Student Function*/
void topStudents() {
    //searching for the maximum average mark 
    int max_mark = -1;
    for (int i = 0; i < numOfStudents; i++) {
        if (studentList[i].AggregateMarks > max_mark) {
            max_mark = studentList[i].AggregateMarks;
        }
    }
    printf("Top Students:\n");
    //printing all the details of all students who got the maximum average mark
    for (int i = 0; i < numOfStudents; i++) {
        if (studentList[i].AggregateMarks == max_mark) {
            printf("%s %s (ID: %d) - Aggregate Marks: %d, Grade: %s\n", studentList[i].FirstName, studentList[i].LastName, studentList[i].StudentID, studentList[i].AggregateMarks, studentList[i].Grade);
        }
    }
}