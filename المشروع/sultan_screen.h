#ifndef SULTAN_SCREEN_H
#define SULTAN_SCREEN_H

void k_print(const char* str) {
    unsigned short* video_memory = (unsigned short*)0xB8000;
    static int i = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        video_memory[i] = (video_memory[i] & 0xFF00) | str[j];
        video_memory[i] = (video_memory[i] & 0x00FF) | (0x0F << 8);
        i++;
    }
}



void k_clear_screen() {
    unsigned short* video_memory = (unsigned short*)0xB8000;
    for (int i = 0; i < 80 * 25; i++) {
        video_memory[i] = (video_memory[i] & 0xFF00) | ' ';
    }
}

#endif