#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


void vig_encrypt(string text, string k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR: wrong number ");
        return 1;
    }

    string k = argv[1];

    // check if all char are letters
    for (int i = 0; i < strlen(k); i++)
    {
        if (isalpha(k[i]) == 0)
        {
            printf("use only letters\n");
            return 1;
        }
    }

    string text = get_string("plaintext: ");
    printf("ciphertext: ");
    vig_encrypt(text, k);
    printf("\n");

    return 0;
}

void vig_encrypt(string text, string k)
{
    for (int i = 0, j = 0; i < strlen(text); i++)
    {
        j = j % strlen(k);

        if (isalpha(text[i]))
        {
            if (islower(text[i]) && islower(k[j]))
            {
                printf("%c", (((text[i] - 97) + (k[j] - 97)) % 26) + 97);
            }
            else if (isupper(text[i]) && islower(k[j]))
            {
                printf("%c", (((text[i] - 65) + (k[j] - 97)) % 26) + 65);
            }
            else if (islower(text[i]) && isupper(k[j]))
            {
                printf("%c", (((text[i] - 97) + (k[j] - 65)) % 26) + 97);
            }
            else if (isupper(text[i]) && isupper(k[j]))
            {
                printf("%c", (((text[i] - 65) + (k[j] - 65)) % 26) + 65);
            }
            j++;
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}