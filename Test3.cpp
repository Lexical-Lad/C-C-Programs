#include <stdio.h>
#include <iostream>

class A
{
public: void sayHello()
{
printf("Hello there!!! \n");
}
};
int main()
{
A* a = 0;
a->sayHello();
}
