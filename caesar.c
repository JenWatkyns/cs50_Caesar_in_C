#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    bool flag = false;
    // Check command-line argument
    if (argc == 2)
    {
        int answer = 0;
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            int num = argv[1][i];
            if (num >= '0' && num <= '9')
            {
                num = num - '0';
            }
            else
            {
                flag = true;
                break;
            }
            
            // Convert string to ints and formulate the correct integer implied for the key
            int power_of = len - i - 1;
            int number = pow(10, power_of);
            
            number *= num;
            answer += number;
        }
        
        // No command-line arguments or more than one command-line argument, program prints an error message
        if (flag)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        // Get plaintext from the user
        string plain = get_string("plaintext: ");
        
        // Use the key to cipher the plaintext
        int cipher;
        printf("ciphertext:");
        for (int i = 0, leng = strlen(plain); i < leng; i++)
        {
            if (isupper(plain[i]) || islower(plain[i]))
            {
                cipher = plain[i] + answer;
                if (isupper(plain[i]))
                {
                    while (cipher > 90)
                    {
                        cipher = cipher - 26;
                    }
                }
            
                if (islower(plain[i]))
                {
                    while (cipher > 122)
                    {
                        cipher = cipher - 26;
                    }
                }
                printf("%c", cipher);
            } 
            // Print characters that are not alphabetic as plaintext that have not been ciphered
            else 
            {
                printf("%c", plain[i]);
            }
        }
        printf("\n");
    }
    // Print error message and exit program
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // After running program successfully, exit with 0
    return 0;
}
