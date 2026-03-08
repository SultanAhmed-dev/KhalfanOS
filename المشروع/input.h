#ifndef IO_H
#define IO_H

#include "sultan_screen.h"

char keyboard_map[128] = {
0,27,'1','2','3','4','5','6','7','8','9','0','-','=', 
'\b','\t',
'q','w','e','r','t','y','u','i','o','p','[',']','\n',
0,
'a','s','d','f','g','h','j','k','l',';','\'','`',
0,
'\\',
'z','x','c','v','b','n','m',',','.','/',
0,'*',0,' '
};

static inline unsigned char inb(unsigned short port){
    unsigned char result;
    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

void k_input(char* buffer, int max){
    
    int i = 0;

    while(i < max-1){

        unsigned char scancode = inb(0x60);

        if(scancode > 0 && scancode < 128){

            char c = keyboard_map[scancode];

            if(c == '\n')
                break;

            buffer[i++] = c;

            char s[2];
            s[0] = c;
            s[1] = '\0';

            k_print(s);
        }
    }

    buffer[i] = '\0';
}

#endif