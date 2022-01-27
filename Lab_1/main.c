#include<stdio.h>


void SizeOfVariables(){
    char c;
    short s;
    int i;
    unsigned int ui;
    unsigned long int ul;
    float f;
    double d;
    long double ld;
    void *ptr;

    printf("Size of char c: %ld Bytes.\n",sizeof(c));
    printf("Size of short s: %ld Bytes.\n",sizeof(s));
    printf("Size of int i: %ld Bytes.\n",sizeof(i));
    printf("Size of unsigned int ui: %ld Bytes.\n",sizeof(ui));
    printf("Size of unsigned long int ul: %ld Bytes.\n",sizeof(ul));
    printf("Size of float f: %ld Bytes.\n",sizeof(f));
    printf("Size of long double ld: %ld Bytes.\n",sizeof(ld));
    printf("Size of void *ptr: %ld Bytes.\n",sizeof(ptr));

}

int IsLeapYear(int aYear){

    if(aYear>=1752){
        //maybe a leap year
        if(aYear%400 == 0){

            //leap year 
            printf("%d is a leap Year\n",aYear);
            return 1;

        }else{
            if(aYear%100 == 0){
                //not a leap year
                printf("%d is not a leap Year\n",aYear);
            return 0;

            }else if(aYear%4 == 0){
                //leap year
                printf("%d is a leap Year\n",aYear);
            return 1;

            }else{
                //not a leap year
                printf("%d is not a leap Year\n",aYear);
            return 0;
            }
        }

    }else{
        //not a leap year
        printf("%d is not a leap Year\n",aYear);
        return 0;
    }
}


int IsVowel( char aLetter ){
    int ascii=aLetter;

    if((ascii>=97 && ascii<=122) || (ascii>=65 && ascii<=90)){
        //valid letter

        if(ascii==97 || ascii==65 || ascii==101 || ascii==69 || ascii==73 || ascii==105 || ascii==79 || ascii==111 || ascii==85 || ascii==117){
            //vowel
            printf("%c is Vowel\n",aLetter);
            return 1;
        }else{
            //consonant
            printf("%c is Consonant\n",aLetter);
            return 0;
        }

    }else{
        printf("%c is not a valid Vowel nor Consonant\n",aLetter);
        return 0;
    }
}


void ReverseNumber( long aNumber ){

    printf("Original number %ld\n",aNumber);

    int remainder=0;
    long reversedNumber=0;

    while(aNumber != 0) {
        remainder = aNumber%10;
        reversedNumber = reversedNumber*10 + remainder;
        aNumber /= 10;
    }

    
    printf("Reversed number %ld\n\n",reversedNumber);

}

int main()
{


    printf("\nFunction 1: SizeOfVariables\n\n");
    SizeOfVariables();

    printf("----------------------------------------------------------");
    printf("\nFunction 2: IsLeapYear\n\n");
    IsLeapYear(1700);
    IsLeapYear(2020);
    IsLeapYear(2021);
    IsLeapYear(2019);
    IsLeapYear(1800);
    IsLeapYear(1900);
    IsLeapYear(2000);
    IsLeapYear(1904);
    IsLeapYear(1908);
    IsLeapYear(1996);

    printf("----------------------------------------------------------");
    printf("\nFunction 3: IsVowel\n\n");
    IsVowel('a');
    IsVowel('z');
    IsVowel('.');
    IsVowel('1');
    IsVowel('B');
    IsVowel('E');
    IsVowel('i');
    IsVowel('8');
    IsVowel('o');
    IsVowel('U');
    IsVowel('?');


    printf("----------------------------------------------------------");
    printf("\nFunction 4: ReverseNumber\n\n");
    ReverseNumber(1234);
    ReverseNumber(-4391);
    ReverseNumber(1920);
    ReverseNumber(-8765);
    ReverseNumber(9837);

    printf("----------------------------------------------------------\n");
    
    /*int num1, num2;  
    float fraction;     
    char character;
    char str[50];   // char array of size 50

    printf("Enter two numbers\n");
    
    // Taking integer as input from user
    scanf(" %d%i", &num1, &num2);
    printf("\n\nThe two numbers You have entered are %d and %i\n\n", num1, num2);

    // Taking float or fraction as input from the user
    printf("\n\nEnter a Decimal number\n");
    scanf(" %f", &fraction); 
    printf("\n\nThe float or fraction that you have entered is %f", fraction);

    // Taking Character as input from the user
    printf("\n\nEnter a Character\n");
    scanf(" %c",&character);
    printf("\n\nThe character that you have entered is %c and the ASCII number is %d", character, character);
    getchar();

    printf("\n\nEnter your complete name:\n\n\n");

    gets(str);
    printf("\n\nWelcome to ECEGR 2020  %s\n\n\n", str);

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    
    printf("Press Enter to quit");
    scanf("%c",&character);
    */
    return 0;
}