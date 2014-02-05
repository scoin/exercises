#include <stdio.h>
#include <string.h>
#include <cs50.h>

int checkString(string[]);
int checkChar(char);
char runString(string[], int);
void printString(char, char, int, int);
bool isLower(char);

 
int main(int argc, string argv[])
{

int returned = checkString(argv); //checks that an alphanumeric string was entered as argument

if(returned==1)
{
printf("usage: ./vigenere [keyword] \n");
return 1;
}

int whatchar;
int counter = 0;
char c;
char d;

printf("Enter a sentence to encrypt: ");
string toencrypt = GetString();

for(int i = 0, n = strlen(toencrypt); i<=n - 1; i++)
{
    c = toencrypt[i];
    whatchar = checkChar(c); //checks if alphanumeric character or space / symbol in sentence to encrypt
    
        if(whatchar == 0)
        {
            d = runString(argv, counter); // gets the letter to rotate from keyword
            counter = counter + 1;
        }
            
    printString(c, d, i, whatchar); //adds chars and prints the string
}
printf("\n");
}

int checkString(string input[])
{
char c;
if(input[1] == NULL)
return 1;

if(input[2] != NULL)
return 1;

for(int i = 0, n = strlen(input[1]); i<=n - 1; i++)
{   
c = input[1][i];
    if((c < 'A') || ((c > 'Z') && (c < 'a')) || (c > 'z'))
    return 1;
}

return 0;
}

int checkChar(char c)
{
if((c < 'A') || ((c > 'Z') && (c < 'a')) || (c > 'z'))
return 1;

else
return 0;
}


char runString(string input[], int counter)
{
char c;
bool lower;
int n=strlen(input[1]);


if(counter >= n - 1)
counter = counter % (n);

c = input[1][counter];

lower = isLower(c);

if(lower == true)
c = c - 'a';
else
c = c - 'A';

return c;
}

bool isLower(char c)
{
        if((c >= 'a') && (c<= 'z'))
            return true;

        else
            return false;
}


void printString(char c, char d, int i, int whatchar)
{
bool lower;
if(whatchar == 1)
   printf("%c", c);
else
    {
    lower = isLower(c);
    
    if(lower == true)
        c = c - 32;
        
        c = c + d;

            if(c > 'Z')
            {
             c = (c % 'Z') + ('A' -1);
    
                if(lower == true)
                    c = c + 32;
    
              printf("%c",c);
            }
    
            else if(c <= 'Z')
            {
                
                if(lower == true)
                    c = c + 32;
                
                printf("%c", c);
            }



        }
}



