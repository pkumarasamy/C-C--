// Packing of structure and print the address location and value of variable

#include <stdio.h>
#include <string.h>

typedef struct {
    char a;
    int x;
    char b;
    int y;
} MYSTRUCT ;

typedef struct __attribute__((__packed__)) {
    char a;
    int x;
    char b;
    int y;
} MYSTRUCT_A ;

void print_mystruct(MYSTRUCT a)
{
    int i = 0;
    void *ptr = NULL ;

    ptr = &a ;

    printf("\n");
    printf("A = %c X = 0x%x B = %c Y = 0x%x\n", 
            a.a, a.x, a.b, a.y );

    for( i=0; i<=sizeof(MYSTRUCT) ; ++i )
    {
        printf("%2d Address = 0x%p Value = 0x%x\n", (i+1), (ptr+i), *((unsigned char *)(ptr+i)) );
    }
    printf("\n");

    return ;
}

void print_mystruct_A(MYSTRUCT_A a)
{
    int i = 0;
    void *ptr = NULL ;

    ptr = &a ;

    printf("\n");
    printf("A = %c X = 0x%x B = %c Y = 0x%x\n", 
            a.a, a.x, a.b, a.y );

    for( i=0; i<=sizeof(MYSTRUCT_A) ; ++i )
    {
        printf("%2d Address = 0x%p Value = 0x%x\n", (i+1), (ptr+i), *((unsigned char *)(ptr+i)) );
    }
    printf("\n");

    return ;
}

int main(void)
{
    MYSTRUCT a ;
    MYSTRUCT_A b ;

    memset ( &a, 0XFF, sizeof(MYSTRUCT));
    memset ( &b, 0XFF, sizeof(MYSTRUCT));

    print_mystruct(a);
    print_mystruct_A(b);

}
