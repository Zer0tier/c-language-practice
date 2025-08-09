#include <stdio.h>
int main(int argc, char **argv) {
    
    char *strings[5] = {"abc","def","chicken","tree","1234"};
    
    printf("The outcome is: %c\n", *(*(strings+1)+2));// This would be f? ✌
    printf("The outcome is: %s\n", strings[4]);// This would be 1234? 
    printf("The outcome is: %c\n", strings[2][3]);// This would be c?
  
    printf("%s\n", *strings); //outcome: abc
    printf("%c\n", **strings);//outcome: a
    printf("%s\n", *(strings+1));//outcome: def
    printf("%s\n", strings[3]);//outcome: tree
    printf("%c\n", *strings[3]);//outcome: t
    printf("%c\n", *(strings[2]+1));//outcome: h
    printf("%c\n", *(*(strings+4)+3));//outcome: 4
    printf("%c\n", strings[2][3]);;//outcome: c
    printf("%c\n", *(*strings+2));//outcome: c
    printf("%c\n", **strings+4);//This would cause some bugs im pretty sure?
    //So for this one it actually would not gonna cause any bugs
    //Since "abc" has only 3 elements. **strings+4 would point to the second char of the second element.
    printf("%c\n", *(char *) (((int *) strings[2])+1));// h × its actually k.
    //(int *) make the pointer to point at int instead of char.
    //In that case, sizeof(int) = 4, which makes the pointer pointing at k.

    
    printf("%p\n", strings);// pointer address for the first element.
    printf("%p\n", strings+3);// pointer address for the 4th element.
}