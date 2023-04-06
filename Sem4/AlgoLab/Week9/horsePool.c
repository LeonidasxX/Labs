#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 256

int tab[SIZE];

void shiftTable(char P[25]){
	int i, m;
	m = strlen(P);
	for (int i = 0; i < SIZE; ++i)
	{
		tab[i] = m;
	}
	for (int i = 0; i <=m-2; ++i)
	{
		tab[P[i]] = m-i-1;
	}
}

int horsePool(char t[100], char p[25]){
	int n,m,k,i;
	n = strlen(t);
	m = strlen(p);
	i = m - 1;
	while(i<=n-1){
		k = 0;
		while((k<m) && (p[m-1-k]==t[i-k]))
			k = k+1;
	if(k==m){
		return i-m+1;
	}
	else{
		i = i+tab[t[i]];
	}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	char t[100], p[25];
	int res;
	printf("Enter text: ");
	scanf(" %[^\n]s", t);
	printf("Enter pattern: ");
	scanf(" %[^\n]s", p);
	shiftTable(p);
	res = horsePool(t,p);
	if (res == -1)
	{
		printf("Pattern not found...\n");
	}
	else{
		printf("Pattern found at position %d", res+1);
	}
	return 0;
}
