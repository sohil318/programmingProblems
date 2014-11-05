#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    void *data;
    int datasize;
    int length;
    int top;
    void *topelem;
}stack;

void initStack(stack *s, int datasize, int len)
{
    s->length = len;
    s->datasize = datasize;
    s->data = malloc(datasize * len);
    s->top = -1;
    s->topelem = s->data;
}

void push(stack *s, const void* elem)
{
    if (s->top + 1  >= s->length)
    {
        printf("\nStack FULL !!! Need to pop elements. !!! ");
        return;
    }
    
    if(s->top != -1)
        s->topelem += s->datasize;
    
    memcpy(s->topelem, elem, s->datasize);
    s->top++;
    //printf("\nLoaded Element : %d\n", *((int *)s->topelem));

}

void pop(stack *s, void *temp)    
{
    if (s->top == -1)
    {
        printf("\nNo Element to pop \n");
        return;
    }

    memcpy(temp, s->topelem, s->datasize);
    s->topelem -= s->datasize;
    s->top--;
    
}

void printElems(stack *s)
{
    void *c;
    void *elem = s->topelem;
    printf ("\nContents of stack : \t");
    for (int i = s->top; i >= 0; i--)
    {
        memcpy(c, elem, s->datasize);
        elem -= s->datasize;
        printf("\t%d", *(int *)c);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    stack s;
    initStack(&s, sizeof(int), 5);
    for (int i = 1; i < 6; i++)
        push(&s, &i);
    
    printElems(&s);
   
    int num;
    pop(&s, &num);
    printf("Element that is popped : %d\n", num);

    pop(&s, &num);
    printf("Element that is popped : %d\n", num);

    stack s1;
    float x = 1.0;
    initStack(&s1, sizeof(float), 3);
    push(&s1, &x);
    x += 1.0;
    push(&s1, &x);
    x += 1.0;
    push(&s1, &x);
    
    //printElems(&s);
   
    float n;
    pop(&s1, &n);
    printf("Element that is popped : %f\n", n);

    pop(&s1, &n);
    printf("Element that is popped : %f\n", n);
    return 0;
}
