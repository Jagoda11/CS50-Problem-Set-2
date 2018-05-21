#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void caesar_encrypt(string text, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR: wrong number ");
        return 1;
    }

    //string k = argv[1];
    int k = atoi(argv[1]);

    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    caesar_encrypt(text, k);
    printf("\n");

    return 0;
}

void caesar_encrypt(string text, int k)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if islower(text[i])
            {
                printf("%c", (((text[i] + k) - 97) % 26) + 97);
                if isupper(text[i])
                {
                    printf("%c", (((text[i] + k) - 65) % 26) + 65);
                }
            }
            char l = text[i] + k;
            printf("%c", l);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}