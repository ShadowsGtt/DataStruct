/*  
*  C语言实现多态和继承 
*
*  */


#include <stdlib.h>
#include <stdio.h>
typedef struct animal animal_t; 
typedef struct appearance appearance_t; 
typedef void *(*func_t)(void *);

/* 对动物的定义 */
struct animal 
{
    char *name;
    appearance_t *appearance;
};

struct appearance 
{
    
};


int main()
{

}
