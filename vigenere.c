/* Vigenere.c by Eduardo F. Carr-Gaona
This program will encipher any text
using Vigenere's cipher by prompting 
the user at the command line for the
encryption keyword. */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])   /* prompts the user at the command line for the encryption keyword */

{
    if (argc != 2)  /* validates the number of command line arguments */
        {
            printf("Invalid number of arguments!\n");
            return 1; 
        }
    if (isdigit(*argv[1]))  /* key can only contain letters of the alphabet */
        {
            printf("Key must be alpha!\n");
            return 1;
        }
    string plainText = GetString(); /* gets the text to encypher from the user */
    if (plainText != NULL)
        {
            string key = argv[1];
            int i, n = strlen(plainText), keyIndex = 0, keyLength = strlen(key);
            for (i = 0; i < n; i++)
                {
                    if (isalpha(plainText[i]))  /* ensures that the punctuation and spaces do not get encyphered */  
                        {
                            if (islower(plainText[i]) && isupper(key[keyIndex]))    /* encyphers the text by converting the plaintext & key from ascii values to an alphabetical index so that caesars cypher can be used */                        
                                {                                                                               
                                    int cypherText = (((plainText[i] - 97) + (key[keyIndex] - 65)) % 26) + 97;    
                                    printf("%c",cypherText);                          
                                }                                           
                            if (isupper(plainText[i]) && isupper(key[keyIndex]))                              
                                {
                                    int cypherText = (((plainText[i] - 65) + (key[keyIndex] - 65)) % 26) + 65;
                                    printf("%c",cypherText);
                                }
                            if (islower(plainText[i]) && islower(key[keyIndex]))  
                                {   
                                    int cypherText = (((plainText[i] - 97) + (key[keyIndex] - 97)) % 26) + 97;  
                                    printf("%c",cypherText);                         
                                }                                           
                            if (isupper(plainText[i]) && islower(key[keyIndex]))                              
                                {
                                    int cypherText = (((plainText[i] - 65) + (key[keyIndex] - 97)) % 26) + 65;
                                    printf("%c",cypherText);
                                }
                            if (keyIndex == keyLength - 1)  /* key loops through the plaintext */ 
                                {
                                    keyIndex = 0;
                                }
                            else
                                {
                                    keyIndex++;
                                }
                        }
                    else 
                        {              
                            int cypherText = plainText[i];  /* prints the non-alpha characters in the plainText */   
                            printf("%c",cypherText);
                        }
                }  
        }
    printf("\n");
    return 0;       
}
