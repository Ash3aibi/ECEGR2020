#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num=0;

struct Student
{
	int ID;
	char firstName[30];
	char lastName[30];
	float GPA;
	struct Student * next;
}*head;

void FeedRecords(){
    //write to a file
   	FILE *outfile;
     
    // open file for writing
    outfile = fopen ("students.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit (1);
    }

    putw(num,outfile);
    struct Student * cur=head;
    while(cur){
    	fwrite (cur, sizeof(struct Student), 1, outfile);
        cur=cur->next;
    }

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
 
    // close file
    fclose (outfile);
}


void AddStudent(int id,char*fn,char*ln,float GPA){
	struct Student* temp = (struct Student*) malloc(sizeof(struct Student));
    temp->ID=id;
    strcpy(temp->firstName, fn);
    strcpy(temp->lastName, ln);
    temp->GPA=GPA;


    // printf("Enter id: ");
    // scanf("%d",&temp->ID);

    // printf("Enter firstName: ");
    // scanf("%s",temp->firstName);

    // printf("Enter lastName: ");
    // scanf("%s",temp->lastName);

    // printf("Enter GPA: ");
    // scanf("%f",&temp->GPA);

	printf ("\nID = %d\nfirstName = %s\nlastName %s\nGPA %.2f\n", temp->ID,
	temp->firstName, temp->lastName,temp->GPA);

	if (head==NULL || head->GPA<temp->GPA){
		temp->next=head;
		head=temp;
	}
	else{
		struct Student* current=head;
		while (current->next != NULL && current->next->GPA < temp->GPA){
			current=current->next;
		}
		temp->next = temp->next;
		current->next = temp;
	}	
    printf("Added");
    num++;
    FeedRecords();
}

void RemoveStudent(int id){
	struct Student * temp1 = head;
	struct Student * temp2 = head; 
	while(temp1!=NULL){
		
		if(temp1->ID==id){
			
			printf("Record with ID %d Found !!!\n", id);
			
			if(temp1==temp2){
				head = head->next;
				free(temp1);
			}
			else{
				temp2->next = temp1->next;
				free(temp1); 
			}
			
			printf("Record Successfully Deleted !!!\n");
            num--;
            FeedRecords();
			return;
			
		}
		temp2 = temp1;
		temp1 = temp1->next;
		
	}
	printf("Student with ID %d is not found !!!\n", id);
}

void Update_Student_Info(int id){
	struct Student * temp = head;
	while(temp!=NULL){
		
		if(temp->ID==id){
			printf("Record with ID %d Found !!!\n", id);
			printf("Enter new  first name: ");
			scanf("%s", temp->firstName);
			printf("Enter new  last name: ");
			scanf("%s", temp->lastName);
			printf("Enter new GPA: ");
			scanf("%f",&temp->GPA);
			printf("Updation Successful!!!\n");
            FeedRecords();
			return;
		}
		temp = temp->next;
		
	}
	printf("Student with roll number %d is not found !!!\n", id);
}

void DisplayStudents(){
	struct Student * temp = head;
	while(temp!=NULL){
		
		printf("Roll Number: %d\n", temp->ID);
		printf("First Name: %s\n", temp->firstName);
		printf("Last Name: %s\n", temp->lastName);
		printf("GPA: %s\n", temp->GPA);
		temp = temp->next;
		
	}
}

void studentInfo(){
	
	printf("\n-------- Func B --------\n\n");

	printf("Enter number of students in class: ");
	scanf("%d",&num);
	int i;
	for(i=0;i<num;++i){
		struct Student* temp = (struct Student*) malloc(sizeof(struct Student));

		//get input
		printf("Enter id: ");
		scanf("%d",&temp->ID);

		printf("Enter firstName: ");
		scanf("%s",temp->firstName);

		printf("Enter lastName: ");
		scanf("%s",temp->lastName);

		printf("Enter GPA: ");
		scanf("%f",&temp->GPA);

        AddStudent(temp->ID,temp->firstName,temp->lastName,temp->GPA);

		printf("\n");
	}
    FeedRecords();

   	
}



void readStudentFile(){
	printf("\n-------- Func C --------\n\n");
	FILE *infile;
    struct Student st;
     
    // Open person.dat for reading
    infile = fopen ("students.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    int num=0,i=0;
    fread(&num,sizeof(num),1,infile);
    
  	//create linked list
  	head=NULL;

  	printf("\nNumber of students: %d\n",num);

	for(i=0;i<num;++i){
		struct Student* temp = (struct Student*) malloc(sizeof(struct Student));

		fread(temp, sizeof(struct Student), 1, infile);

		printf ("\nID = %d\nfirstName = %s\nlastName %s\nGPA %.2f\n", temp->ID,
        temp->firstName, temp->lastName,temp->GPA);



		AddStudent(temp->ID,temp->firstName,temp->lastName,temp->GPA);
        free(temp);
	}

	//find avg
	float sum=0;
	struct Student* cur=head;
	while(cur){
		sum+=cur->GPA;
		cur=cur->next;
	}
	float avg=sum/num;

	printf("\nAverage GPA: %.2f\n",avg);
 
    // close file
    fclose (infile);
}


void displayMenu(){
	
   printf("\n1) List all Students\n");
   printf("2) Add Student\n");
   printf("3) Remove Student\n");
   printf("4) Update Student\n");
   printf("5) Quit\n");
}

void Student_Controller(){

    // studentInfo();

    readStudentFile();

    displayMenu();

    int exit=0;
    while(exit!=1){
   		int ch;
   		printf("\nSelect >> ");
   		scanf("%d",&ch);

   		while ((getchar()) != '\n');

   		if(ch==1){
   			DisplayStudents();
   		}
        if(ch==2){
            int id;
            char fn[100];
            char ln[100];
            float gpa;
            printf("Enter id: ");
            scanf("%d",&id);

            printf("Enter firstName: ");
            scanf("%s",fn);
            // gets(fn);

            printf("Enter lastName: ");
            // gets(ln);
            scanf("%s",ln);

            printf("Enter GPA: ");
            scanf("%f",&gpa);
   			AddStudent(id,fn,ln,gpa);
   		}
        if(ch==3){
            int id;
            printf("Enter Student Id to remove: ");
		    scanf("%d",&id);
   			RemoveStudent(id);
   		}
        if(ch==4){
            int id;
            printf("Enter Student Id to update: ");
            scanf("%d",&id);
            Update_Student_Info(id);
        }
   		else if(ch==5){
   			exit=1;
   		}
   }
}



int main(){

    while ((getchar()) != '\n'); //clear the input buffer
	Student_Controller();
	   // stringOps();
	return 0;
}