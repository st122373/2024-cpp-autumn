#include "string.h"

int main() {
    String str = String("abcdefghijklmnopqrstuvwxyz");
    String str1 = str[0][5]; 
    //String str2 = str[11][16]; 
    str1.print(); 
    //str2.print();
    return 0;
}