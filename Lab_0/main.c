#include <stdio.h>

int main(int argc, char **argv)
{
	printf("hello world\n");
	 printf(“Now live on GitHub!\n”);
    
    for(int i = 0; i < argc; i++ )
    {
        printf( "%d - %s\n", i, argv[i] );
    }
    return 0;
}
