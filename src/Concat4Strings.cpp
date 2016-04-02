/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	char *s;
	int len1, len2, len3, len4;
	if (s1==NULL||s2==NULL||s3==NULL||s4==NULL)
	return NULL;
	len1 = strlen(s1);
	len2 = strlen(s2);
	len3 = strlen(s3);
	len4 = strlen(s4);
	s = (char *)malloc(sizeof(char)*(len1+len2+len3,len4));
	/*if (strstr(s1, s2))
		strcat(s, s1);
	else strcat(s, s1);
	if (strstr(s, s2))
		strcat(s, s2);
	if (strstr(s, s3))
		strcat(s, s3);*/
	if (s1[0] == s2[len1 - 1])
	{
		strcat(s, s2);
		s1++;
		strcat(s, s1);
	}
	if (strstr(s, s3)==NULL)
		strcat(s, s3);
	if (strstr(s, s4)==NULL)
		strcat(s, s4);
	return s;
}