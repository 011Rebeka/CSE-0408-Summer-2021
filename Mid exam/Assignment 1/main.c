#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include<time.h>

#define r 3
#define c 3

char matrix[r][c];

char new[r][c];

int count;

char final[r][c] = {{'1','2','3'},{'4','5','6'},{'7','8',' '}};

int i,j;

char z ;

int p,q,x,y;

int t =0;

int result = 0;

void load()

{

for(i=0;i<3;i++)

{

for(j=0;j<3;j++)

{

if(new[i][j] == '0')

{

matrix[i][j]= ' ';

continue;

}

matrix[i][j]= new[i][j];

}

}

}

void blank()

{

for(i=0;i<3;i++)

{

for(j=0;j<3;j++)

{

new[i][j]= ' ';

}

}

}

int main()

{

time_t T= time(NULL);

struct tm tm = *localtime(&T);

char f[4];

int rsl ;

int random,t;

int randvalues[9];

main:

count = 0;

blank();

T= time(NULL);

tm = *localtime(&T);

srand(tm.tm_sec);

while(count!=9)

{

rsl=rand()%9;

sprintf(f,"%d",rsl);

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

if((new[i][j]) == f[0])

{

i = 4; j = 4;

continue;

}else if((new[i][j]) == ' ')

{

new[i][j] = f[0];

i = 4; j = 4;

count++;

}

}

}

}

load();

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

printf("|%c|",matrix[i][j]);

}

printf("\n");

}

while(1)

{

printf("enter value to change its position to blank space\n");

scanf(" %c",&z);

if(z=='q')

{

printf("\n*****You Quit*****\n");

goto main;

// break;

}

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

if((matrix[i][j])== z)

{

p = i;

q = j;

}else if((matrix[i][j])== ' ')

{

x = i;

y = j;

}

}

}

t =0;

int m , n ;

m = p - 1;

n = q ;

if(m>=0)

{

if((matrix[m][n])== ' ')t=1;

}

m = p + 1;

if(m<=2)

{

if((matrix[m][n])== ' ')t=1;

}

m = p;

n = q - 1 ;

if(n>=0)

{

if((matrix[m][n])== ' ')t=1;

}

n = q + 1 ;

if(n<=2)

{

if((matrix[m][n])== ' ')t=1;

}

if(t==1)

{

matrix[x][y] = z;

matrix[p][q] = ' ';

}

t = 0;

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

if((matrix[i][j])== final[i][j])

{

t++;

}

}

}

system("clear");

for(i=0;i<r;i++)

{

for(j=0;j<c;j++)

{

printf("|%c|",matrix[i][j]);

}

printf("\n");

}

if(t==9)

{

printf("\n****you Win****\n");

break;

}

}

return 1;

}
