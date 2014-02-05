#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long int ccnum = 0;
int modu = 0;
int digits = 0;
int ccarray[15];
int rema = 0;
int added = 0;
int flag = 0;

int main()
{
printf("Enter a CC number to check if valid\n");
ccnum = GetLongLong();
digits = log10(ccnum) + 1;

  for(int i = digits; i>=0; i--)
    {
    modu = ccnum % 10;
    ccarray[i] = modu;
    ccnum = ccnum / 10;
    }

    if(ccarray[1] == 3 && digits == 15){
        if((ccarray[2] == 4) || (ccarray[2] == 7))
            flag = 3;
    }

    if(ccarray[1] == 4){
        if(digits == 16)
            flag = 4;
    } 

    if(ccarray[1] == 5){ 
        if(digits == 16 && ((ccarray[2] == 1) || (ccarray[2] == 2) || (ccarray[2] == 3) || (ccarray[2] == 4)))
        flag = 5;
    }

    if(flag == 0){
        printf("INVALID\n");
        return 0;
        }


for(int k = digits - 1; k>=1; k-=2)
{
rema = ccarray[k] * 2;
if(rema > 9){
added = added + (rema % 10);
added = added + 1;
}
if(rema <= 9){
added = added + rema;
}
}

if(digits == 16)
{
for(int l = 2; l<= digits; l+=2)
{
added = added + ccarray[l];
}
}

if(digits == 15)
{
for(int m = 1; m<= digits; m+=2)
{
added = added + ccarray[m];
}
}

if(added % 10 == 0)
{
if(flag == 3)
printf("AMEX\n");

if(flag == 4)
printf("VISA\n");

if(flag == 5)
printf("MASTERCARD\n");
}

else{
printf("INVALID\n");
}
}
