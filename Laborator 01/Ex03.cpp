#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#define TEXT_SIZE 250
#define ARRAY_SIZE 100

void custom_swap(char textOne[], char textTwo[])
{
    char textAux[TEXT_SIZE];
    strcpy(textAux, textOne);
    strcpy(textOne, textTwo);
    strcpy(textTwo, textAux);
}

int main()
{
    char text[TEXT_SIZE], arr[ARRAY_SIZE][TEXT_SIZE];
    int size = 0;
    scanf("%[^\n]s", text);
    char* pointer = strtok(text, " ");

    while (pointer != NULL)
    {
        strcpy(arr[size++], pointer);
        pointer = strtok(NULL, " ");
    }

    for (int i = 0;i < size-1;i++)
    {
        for (int j = i + 1;j < size;j++)
        {
            if (strlen(arr[i]) < strlen(arr[j]))
                custom_swap(arr[i], arr[j]);
            else if (strlen(arr[i]) == strlen(arr[j])) {
                for (int k = 0; k < strlen(arr[i]); k++)
                    if (arr[i][k] < arr[j][k]) {
                        break;
                    } else if (arr[i][k] > arr[j][k]) {
                        custom_swap(arr[i], arr[j]);
                        break;
                    }
            }
        }
    }

    for (int i = 0; i < size; i++)
        printf("%s \n", arr[i]);

}
