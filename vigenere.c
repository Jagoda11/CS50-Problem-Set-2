#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function declaration for Vigenère encryption 🛡️
void vig_encrypt(string text, string k);

int main(int argc, string argv[])
{
    // Ensure the correct usage with one command-line argument 📝
    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }

    string k = argv[1];

    // Check if all characters in the key are letters 🔍
    for (int i = 0, len = strlen(k); i < len; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Key must be alphabetic characters only\n");
            return 1;
        }
    }

    // Prompt user for plaintext 📃
    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    // Encrypt and print the ciphertext 🔒
    vig_encrypt(text, k);
    printf("\n");

    return 0;
}

// Function to encrypt text using Vigenère cipher 🔐
void vig_encrypt(string text, string k)
{
    int key_len = strlen(k);
    
    for (int i = 0, j = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            int letterIndex = islower(text[i]) ? text[i] - 'a' : text[i] - 'A';
            int keyIndex = islower(k[j % key_len]) ? k[j % key_len] - 'a' : k[j % key_len] - 'A';

            // Encrypt and print the character 🖨️
            printf("%c", (letterIndex + keyIndex) % 26 + base);
            j++;
        }
        else
        {
            // Print the non-alphabetic character as it is 📤
            printf("%c", text[i]);
        }
    }
}
