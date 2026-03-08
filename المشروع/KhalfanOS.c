#include "input.h"
#include "sultan_screen.h"


int strcmp(char* s1, char* s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}


void clear_buffer(char* buf, int size) {
    for (int i = 0; i < size; i++) buf[i] = '\0';
}

void kernel_main() {
    char input_buffer[128]; 
    int x = 1; 

    k_print("Welcome to KhalfanOS.\n");
    k_print("If you want help write \"help\".\n");

    while (x > 0) {
        k_print("> "); 
        

        clear_buffer(input_buffer, 128);

        k_input(input_buffer, 128); 

        if (input_buffer[0] == '\0') {
            continue; 
        }

        if (strcmp(input_buffer, "help") == 0) {
            k_print("info: information for this OS.\n");
            k_print("off : off the PC and shut down.\n");
        } 
        else if (strcmp(input_buffer, "info") == 0) {
            k_print("KhalfanOS version 0.1.\n");
            k_print("Built by Sultan.\n");
        } 
        else if (strcmp(input_buffer, "off") == 0) {
            k_print("Shutting down KhalfanOS...\n");
            

            __asm__ volatile ("outw %1, %0" : : "dN" ((unsigned short)0x604), "a" ((unsigned short)0x2000));

            
            x = 0; 
        } 
        else {
            k_print("Aaam, sorry command \"");
            k_print(input_buffer);
            k_print("\" is not found.\n");
        }
    }
}
