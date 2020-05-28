#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// argc and string argv[] determine nature of items inside the command prompt
int main(int argc, string argv[])
{
    //  argv[1] stands for the input in the command prompt. argv[0] stands for the ./caesar command
    string key_str = argv[1];
    
    // Check that there are only 2 items in the command prompt. The first is the ./caesar command, the second one is the input
    if (argc == 2)
    {
        for (int i = 0; i < strlen(key_str); i++)
        {
            if (isdigit(key_str[i]) == 0)
            {
                
            }
            else 
            {
                printf("Usage: ./caesar keyword\n");
                // return 1, indicates that there is an error and ends the program. Very useful
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar keyword\n");
        // return 1, indicates that there is an error and ends the program. Very useful
        return 1;
    }
    
    // Creating a lowercase and uppercase alphabet:
    // Creating the 2 alphabet arrays 
    char alphalower[27];
    char alphaupper[27];
    
    // Run through the lower case alphabet values in ASCII and add them into the lower case array
    for (int i = 0; i < 26; i++)
    {
        // Adding process
        alphalower[i] = 97 + i;
    }
  
    // Remove the last value in the array as it is invalid
    alphalower[26] = '\0';
    
    // Run through the upper case alphabet values in ASCII and add them into the upper case array
    for (int i = 0; i < 26; i++)
    {
        // Adding process
        alphaupper[i] = 65 + i;
    }
    
    // Remove the last value in the array as it is invalid
    alphaupper[26] = '\0';
    
    // Getting the string input from the user
    string plain = get_string("Plaintext: ");
    
    // Print "Ciphertext: " here, not in the loop to avoid its repeatance
    printf("Ciphertext: ");
    
    // Transforming the key word into integers resembling its positions in the alphabet
    // Creating a key array
    int key[strlen(plain)];
    // Running through each character in key_str
    for (int i = 0; i < strlen(key_str); i++)
    {
        // Running through each letter in lower case alphabet and find the one that matches the key's letter
        for (int j = 0; j < strlen(alphalower); j++)
        {
            // If it matches, add the position of the letter in the alphabet to the corresponding position in key array
            if (key_str[i] == alphalower[j])
            {
                // Adding letter's position in alpha to key array
                key[i] = j;
            }
        }
        // Same function as above, only this time, it is adding upper case letter's positions to key array
        for (int l = 0; l < strlen(alphaupper); l++)
        {
            if (key_str[i] == alphaupper[l])
            {
                key[i] = l;
            }
        }
    }
    
    // Main encryption part:
    
    // Arrays to store characters must be created and assigned into a character variable from the start
    char cipher[strlen(plain)];
    
    // k resembles the new letter for lower case alpha. k2 resembles the same thing for upper case alpha
    int k;
    int k2;
    
    // Outer loop will run through each letter of the input (plaintext) one by one individually, i is used for this
    // e is used to get the correct key's character
    for (int i = 0, e = 0; i < strlen(plain); i++)
    {
        //Only i++ and NOT e++ to prevent e iteration when the loop reaches unwanted characters
        
        // IMPORTANT FORMULA! Used to get the correct key's characters corresponding to the length of the plaintext and key
        int f = e % strlen(key_str);
        // islower checks if the letter is lower case
        if (islower(plain[i]) != 0)
        {
            // Runs through the entire lower case alphabet and check for the letter that matches the letter in the input
            for (int j = 0; j < strlen(alphalower); j++)
            {
                // When the letters matched
                if (alphalower[j] == plain[i])
                {
                    // Apply this formula to shift the letter by the key's character
                    k = (j + key[f]) % 26;
                    // Add the new letter into the cipher array
                    cipher[i] = alphalower[k];
                    // Print out the cipher 
                    printf("%c", cipher[i]);
                }
            }
            // Iterate e manually
            e++;
        }
        else if (isupper(plain[i]) != 0)
        {
            // Run through every letter in the upper case alphabet
            for (int l = 0; l < strlen(alphaupper); l++)
            {
                // When the letter in the upper alphabet matches the letter in the input
                if (alphaupper[l] == plain[i])
                {
                    // Apply the same formula as before to shift the letter by key's character
                    k2 = (l + key[f]) % 26;
                    // Add the new letter to cipher array
                    cipher[i] = alphaupper[k2];
                    // Print out cipher
                    printf("%c", cipher[i]);
                }
            }
            // Iterate e manually
            e++;
        }   
        // If the character is NOT a letter, then just add the input into cipher array to keep it unchanged
        // NO e++ here because we want to avoid unwanted characters inteferring with the next letter's shift
        else
        {
            cipher[i] = plain[i];
            printf("%c", cipher[i]);
        }
    }
    
    
    // This will move the prompt($) sign below the output
    printf("\n");
    
    // return 0 indicates NO error and ends the program. Done!
    return 0;
}
