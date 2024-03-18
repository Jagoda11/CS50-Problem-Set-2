#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function declaration for Caesar encryption 🛡️
void caesar_encrypt(string text, int k);

int main(int argc, string argv[])
{
    // Ensure the correct usage with one command-line argument 📝
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the key from string to integer 🔄
    int k = atoi(argv[1]);

    // Prompt user for plaintext 📃
    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    // Encrypt and print the ciphertext 🔒
    caesar_encrypt(text, k);
    printf("\n");

    return 0;
}

// Function to encrypt text using Caesar cipher 🔐
void caesar_encrypt(string text, int k)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i])) // Check if the character is alphabetic 🏷️
        {
            char base = islower(text[i]) ? 'a' : 'A';
            // Encrypt and print the character 🖨️
            printf("%c", (text[i] - base + k) % 26 + base);
        }
        else
        {
            // Print the non-alphabetic character as it is 📤
            printf("%c", text[i]);
        }
    }
}
