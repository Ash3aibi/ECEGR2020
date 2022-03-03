#include <stdio.h>
#include <stdlib.h>

void ReverseArray(){
	printf("\n-------- Func A --------\n\n");
	int theArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	for(int i=0,j=9;i<5;++i,j--){
		int temp=theArray[i];
		theArray[i]=theArray[j];
		theArray[j]=temp;
	}

	for(int i=0;i<10;++i){
		printf("%d ",theArray[i]);
	}
	printf("\n");
}


typedef struct student
	{
		int ID;
		char firstName[30];
		char lastName[30];
		float GPA;
	} Student;


void studentInfo(){
	
	printf("\n-------- Func B --------\n\n");

	int num=0;
	printf("Enter number of students in class: ");
	scanf("%d",&num);


	Student *(array[num]);

	for(int i=0;i<num;++i){
		array[i] = (Student*) malloc(sizeof(Student));

		//get input
		printf("Enter id: ");
		scanf("%d",&array[i]->ID);

		printf("Enter firstName: ");
		scanf("%s",array[i]->firstName);

		printf("Enter lastName: ");
		scanf("%s",array[i]->lastName);

		printf("Enter GPA: ");
		scanf("%f",&array[i]->GPA);

		printf("\n");
	}

	//sort array

	int i, j;
   	for (i = 0; i < num-1; i++){
   		// Last i elements are already in place   
       for (j = 0; j < num-i-1; j++){

           if (array[j]->GPA < array[j+1]->GPA){

              Student* temp=array[j];
              array[j]=array[j+1];
              array[j+1]=temp;

           }
       }
   	}      
  
    //print   
   	for(int i=0;i<num;++i){
   		printf("ID %d\n",array[i]->ID);
   		printf("firstName %s\n",array[i]->firstName);
   		printf("lastName %s\n",array[i]->lastName);
   		printf("GPA %.2f\n",array[i]->GPA);
   		printf("\n");
   	}


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

    for(int i=0;i<num;++i){
    	fwrite (array[i], sizeof(Student), 1, outfile);
    }

    if(fwrite != 0)
        printf("contents to file written successfully !\n");
    else
        printf("error writing file !\n");
 
    // close file
    fclose (outfile);
}


void readStudentFile(){
	printf("\n-------- Func C --------\n\n");
	FILE *infile;
    Student st;
     
    // Open person.dat for reading
    infile = fopen ("students.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    int num=0;
    fread(&num,sizeof(num),1,infile);
    
  	//create array
  	Student *(array[num]);

  	printf("\nNumber of students: %d\n",num);

	for(int i=0;i<num;++i){
		array[i] = (Student*) malloc(sizeof(Student));

		fread(array[i], sizeof(Student), 1, infile);

		printf ("\nID = %d\nfirstName = %s\nlastName %s\nGPA %.2f\n", array[i]->ID,
        array[i]->firstName, array[i]->lastName,array[i]->GPA);
	}

	//find avg
	float sum=0;
	for(int i=0;i<num;++i){
		sum+=array[i]->GPA;
	}
	float avg=sum/num;

	printf("\nAverage GPA: %.2f\n",avg);
 
    // close file
    fclose (infile);
}


void displayMenu(){
   printf("\nA) Count the number of vowels in the string\n");
   printf("B) Count the number of consonants in the string\n");
   printf("C) Convert the string into uppercase\n");
   printf("D) Convert the string to lowercase\n");
   printf("E) Display the string\n");
   printf("F) Enter another string\n");
   printf("M) Display this menu\n");
   printf("R) Reverse words in string\n");
   printf("X) Exit the program\n");
}


void countVowels(char str[]){

	int vowels=0;

	for(int i=0;i<100;++i){

		str[i]=tolower(str[i]);

		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
	        str[i] == 'o' || str[i] == 'u') {

		      // increment value of vowels by 1
		      ++vowels;
	    }
	}

	printf("\nVowels count : %d\n",vowels);
}

void countConsonats(char str[]){

	int consonats=0;

	for(int i=0;i<100;++i){

		str[i]=tolower(str[i]);

		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
	        str[i] == 'o' || str[i] == 'u') {

	    }else if(str[i]>='a' && str[i]<='z'){
	    	consonats++;
	    }
	}

	printf("\nConsonats count : %d\n",consonats);
}

void convertLower(char str[]){
	for(int i=0;i<100;++i){
		str[i]=tolower(str[i]);
	}
}

void convertUpper(char str[]){
	for(int i=0;i<100;++i){
		str[i]=toupper(str[i]);
	}
}

void displarString(char str[]){
	printf("\n%s\n",str);
}
void enterString(char str[]){
   printf("\nEnter string: ");

   gets(str);

}


void reverseWord(char str[], int start, int end){
	char temp;
    while(start<end)
    {
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
}

void reverseString(char str[]){
	int start, end;
    end=0;
    start=0;

    while(str[end])
    {
        for(end=start;str[end]&&str[end]!=' ';end++);
        reverseWord(str, start, end-1);
        start=end+1;
    }
    printf("\n%s\n",str);
}

void stringOps(){

   
   printf("\n-------- Func D & E --------\n\n");
   printf("\nEnter string: ");

   char str[100];
   gets(str);


   displayMenu();

   int exit=0;
   while(exit!=1){
   		char ch;
   		printf("\nSelect >> ");
   		scanf("%c",&ch);

   		while ((getchar()) != '\n');

   		if(ch=='A' || ch=='a'){
   			countVowels(str);
   		}else if(ch=='B' || ch=='b'){
   			countConsonats(str);
   		}else if(ch=='C' || ch=='c'){
   			convertLower(str);
   		}else if(ch=='D' || ch=='d'){
   			convertUpper(str);
   		}else if(ch=='E' || ch=='e'){
   			displarString(str);
   		}else if(ch=='F' || ch=='f'){
   			enterString(str);
   		}else if(ch=='M' || ch=='m'){
   			displayMenu();
   		}else if(ch=='R' || ch=='r'){
   			reverseString(str);
   		}
   		else if(ch=='X' || ch=='x'){
   			exit=1;
   		}
   }
  


}


int main(){

	ReverseArray(); //fucntion A

	studentInfo(); //function B
 
	readStudentFile(); //fucntion C

	while ((getchar()) != '\n'); //clear the input buffer
	
	stringOps(); //function D and E

	return 0;
}