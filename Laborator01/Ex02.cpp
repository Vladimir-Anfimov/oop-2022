#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define BUFFER_SIZE 100

int custom_atoi(char number[]) {
    int suma = 0;
    for (int i = 0; i < strlen(number); i++)
        suma = suma * 10 + number[i] - '0';
    return suma;
}

void clean_newline(char sir[]) {
    for (int i = 0; i < strlen(sir); i++)
        if (sir[i] == '\n') {
            sir[i] = '\0';
            return;
        }
    return;
}

int main() {
    FILE* file;
    char data[100];
    int suma = 0;

    if ((file = fopen("in.txt", "r")) == NULL) {
        printf("Eroare la deschiderea fisierului.");
        exit(1);
    }

    while (fgets(data, BUFFER_SIZE, file) != NULL) {
        clean_newline(data);
        suma += custom_atoi(data);
    }

    printf("%d", suma);
    fclose(file);
}