#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Hello, world\n");
    string name = get_string("What's your name?\n");
    printf("Hey, %s !\n", name);
}