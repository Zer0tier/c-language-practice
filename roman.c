#include <stdio.h>
#include <string.h>


int getValue(char a){
    switch(a){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char* s) {
   int result = 0;
   int length = strlen(s);

   for(int i = 0; i < length; i++){
    int value1 = getValue(s[i]);
    if(i+1<length){
        int value2 = getValue(s[i+1]);
        if(value1 < value2){
            result += value2 - value1;
            i++;
        }else{
            result += value1;
        }
    }else{
        result+=value1;
    }
   }

   return result;
}