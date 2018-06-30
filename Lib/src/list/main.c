#include <gtlist.h>
int main()
{
    List_t *list =  ExampleList(); 
    if(NULL == list)
        printf("failed\n");
    PrintList(list);
}
