
#include <stdio.h>
 /* 
long factorial(long num)     
{
  int i;
  long fact = 1;
  for (i = 1; i <= num; i++)
    fact = fact * i;
 return fact;       
}
  
int main()         
{
  long num;
  printf("Enter a number to calculate its factorial = ");
  scanf("%ld", &num);
  if(num<0) 
  {
   printf("Factorial is not defined for negative numbers.");
   }
  printf("Factorial of %ld = %ld", num, factorial(num));                                
   return 0;
}
*/
/*
int IsPalidrome(long value);

int main()
{
    int i;
    long value;
    for(i = 0; i < 5; i++)
    {
        printf("Enter the value: ");
        scanf("%ld", &value);
        if(IsPalidrome(value))
        {
            printf("Value = %ld and it is a palindrome\n", value);
        }
        else
        {
            printf("Value = %ld and it is not a palindrome\n", value);
        }
    }
    return 0;
}
int IsPalidrome(long value)
{
    long reversed_value = 0, original_value;
    int div_remainder;
    original_value = value;
    while(value != 0)
    {
        div_remainder = value % 10;
        reversed_value = reversed_value * 10 + div_remainder;
        value = value / 10;
    }
    if(original_value == reversed_value)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
*/
/*
int HighestBitSet(int value);

int main()
{
    int i, value, position;
    for(i = 0; i < 5; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &value);
        printf("Value = %d ", value);
        position = HighestBitSet(value);
        if(position == -1)
        {
            printf("No bit is set\n");
        }
        else
        {
            printf("Highest bit set = %d\n", position);
        }
    }

    return 0;
}
int HighestBitSet(int value)
{
    long long binary_number = 0;
    int div_remainder, position = -1, place = 1, i = 0;
    while(value != 0)
    {
        div_remainder = value % 2;
        if(div_remainder == 1)
        {
            position = i;
        }
        binary_number = binary_number + div_remainder * place;
        place = place * 10;
        value = value / 2;
        i++;
    }
    printf("Binary = %lld ", binary_number);
    return position;
}
*/

void ReverseIt( void ){
        float arr[5];
        int i;  
        FILE *fptr; 
        fptr = fopen("Hello.txt", "w"); 
        if (fptr == NULL) 
        {
    printf("Failed to create the file.\n");  
        }
        printf("Enter 5 Floating point numbers :\n");
        for(i=0;i<5;i++){
                scanf("%f",&arr[i]); 
                fprintf(fptr,"%f ",arr[i]);  
        }
        printf("Floating point numbers in reverse order\n");
        for(i=4;i>=0;i--){
                printf("%f ",arr[i]); 
                fprintf(fptr,"%f ",arr[i]); 

        }
        printf("\nData successfully entered into file\n");
        fclose(fptr); 
}

void ReverseItAgain( void ){
        float num;   
        FILE *fptr; 
        fptr = fopen("Hello.txt", "r"); 
    printf("\nReading the Data from file:\n");
        while(!feof(fptr))
    {    
      fscanf(fptr,"%f",&num);
      printf("%f\n",num);      
    }
        fclose(fptr); 
}

void Pyramid( int lines ){
        int i,k,s; 
        for (i = 1; i <= lines; ++i, k = 0)   
        {
      for (s = 1; s <= lines - i; ++s)
          {
         printf("  ");
      }
      while (k != 2 * i - 1)
          {
         printf("* ");
         ++k;
      }
      printf("\n"); 
   }
}

int main(){
        Pyramid(5);
}