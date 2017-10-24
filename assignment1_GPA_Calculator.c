#include <stdio.h>


int main(){
  int size, i, sum, menu;
  float marks[20];
  char restart;
  char classes[20][15]; //two dimensional array, 20 items, 8 pieces long each
  float gpa;
  int weight[20];
  float gwa, weighted_sum;


  sum = 0;
  printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  printf("!  WELCOME TO ASSIGNMENT #1: FANSHAWE GPA CALCULATOR  !\n");
  printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
  do {

    do { // while input is a number but is greater than 4 and not one of the options loop back
      do { // While not a number loop back till number
        printf("\n[+] GPA Calculator Menu:\n");
        printf("\t1. Full Semester (5 courses)\n");
        printf("\t2. Full Year (10 courses)\n");
        printf("\t3. Custom (max 20 courses)\n");
        printf("\t4. Quit\n");
        printf("[+] Please select one of the above options:\n   >> ");
        fflush(stdin);
      } while((scanf(" %i", &menu) !=1));

        switch (menu){
          case 1 : // set course size to 5, exit out and execute program
            printf("*******************************************************\n");
            printf("*     You selected \"Full Semester (5 courses)\"        *\n");
            printf("*******************************************************\n");
            size = 5;
            break;
          case 2 : // set course size to 10, exit out and execute program
            printf("*******************************************************\n");
            printf("*       You selected \"Full Year (10 courses)\"         *\n");
            printf("*******************************************************\n");
            size = 10;
            break;
          case 3: // Allow for custom number of courses to enter up to a max of 20
            printf("*******************************************************\n");
            printf("*    You selected option # 3 \"Custom (max 20)\"        *\n");
            printf("*******************************************************\n");
              do { // Asks for amount of course to calculate, only accepts numbers smaller than 10 and not 0
              printf("\n[+] Enter number of courses to evaluate your GPA:\n  >> ");
              fflush(stdin);
            } while ((scanf(" %d[2]", &size) != 1 || (size > 20) || (size == 0)));
            printf("-------------------------------------------------------\n");
            break;
          case 4: // On selection exit out of program
            printf("Exiting! Thanks for using the GPA Calculator");
            return 0;
            break;
          default : // if input is not an option print and redo loop
            printf("\n-------------------------------------------------------\n");
            printf("\n\t!!!!!!!!  Wrong input  !!!!!!!!\n\a");
            printf("\n-------------------------------------------------------\n");
            break;
          }

    } while (((menu > 4 ) || (menu <= 0)));

        printf("            GPA Calculator for %i Courses             ", size);
// Asks for input based on the amount of courses determined asked for by the user
        for(i = 0; i < size; i++)
        {

          // Asks for each class for the size of the input
          printf("\n-------------------------------------------------------");
          printf("\n[+] Enter a Class/Assignment(ex. INFO1220 or Assignment1): ");
          scanf(" %15s", classes[i]);

          do { // Check to make sure the value entered is a number and not greate than 100
          printf("[+] Enter the GPA weight: ");
          fflush(stdin);
          //repeats prompt for mark if not a number or if number greater than 100
          }while ((scanf(" %d[3]", &weight[i]) != 1) || (weight[i] > 100));

          do { // Check to make sure the value entered is a number and not greate than 100
          printf("[+] Enter the percentage of the grade you recieved: ");
          fflush(stdin);
          //repeats prompt for mark if not a number or if number greater than 100
        }while ((scanf(" %f[3]", &marks[i]) != 1) || (marks[i] > 100));


        }

        printf("\n---------------------------------------------------------\n");
        printf("                Classes Evaluated:                      ");
        printf("\n---------------------------------------------------------\n");
        // Interate through the array, printing out Class[2] with Mark[2]
        for(i = 0; i < size; i++)
        {
          printf("[+] %s = %f\n", classes[i], marks[i]);
        }

        // Set sum to 0 or else we print garbage
        sum = 0;
        // sum the values in mark
        for (i = 0; i < size; i++){
          sum += marks[i];
        }


        gwa = 0;
        for (i = 0; i < size; i++){
           gwa += weight[i] * marks[i];
        }
        // printf("GWA %f", gwa);

        weighted_sum = 0;
        for (i = 0; i < size; i++){
          weighted_sum += weight[i];
        }
        // printf("Credit Sum %f", weighted_sum);
        gpa = gwa / weighted_sum;

        if (gpa >= 90){
          printf("\nYour GPA is 4.2, which is %.2f percent, with a letter grade of 'A+'\n", gpa);
        } else if (gpa >= 80) {
          printf("\nYour GPA is 4.0, which is %.2f percent, with a letter grade of 'A'\n", gpa);
        } else if (gpa >= 75) {
          printf("\nYour GPA is 3.5, which is %.2f percent, with a letter grade of 'B+'\n", gpa);
        } else if (gpa >= 70) {
          printf("\nYour GPA is 3.0, which is %.2f percent, with a letter grade of 'B'\n", gpa);
        } else if (gpa >= 65) {
          printf("\nYour GPA is 2.5, which is %.2f percent, with a letter grade of 'C+'\n", gpa);
        } else if (gpa >= 60){
          printf("\nYour GPA is 2.0, which is %.2f percent, with a letter grade of 'C'\n", gpa);
        } else if (gpa >= 55){
          printf("\nYour GPA is 1.5, which is %.2f percent, with a letter grade of 'D+'\n", gpa);
        } else if (gpa >= 50) {
          printf("\nYour GPA is 1.0, which is %.2f percent, with a letter grade of 'D'\n", gpa);
        } else {
          printf("\nYour average is %.0f and you have failed\n", gpa);
        }

        printf("\nGPA = %.2f\n", gpa);



    do { // evaluate the answer given, if not and variation of Y or N, prompt again.
         printf("====================================\n");
         printf("\n[+] Would you like to continue [Y/N]:\n\n>> ");
         scanf(" %c", &restart);
         printf("====================================\n");

    } while(!(((restart == 'Y') || (restart == 'N')) || ((restart == 'y') || (restart == 'n'))));



  } while (restart == 'Y' || restart == 'y'); //

  return 0;
}
