
#include <stdio.h>
#include <string.h>  //for strcat
#include <stdlib.h>
char *replace(const char *s, const char *oldW, const char *newW)
{
    char *result;
    int i, cnt = 0;
    int newWlen = strlen(newW);
    int oldWlen = strlen(oldW);

    // Counting the number of times old word
    // occur in the string
    for (i = 0; s[i] != '\0'; i++)
    {
        if (strstr(&s[i], oldW) == &s[i])
        {
            cnt++;

            // Jumping to index after the old word.
            i += oldWlen - 1;
        }
    }

    // Making new string of enough length
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

    i = 0;
    while (*s)
    {
        // compare the substring with the result
        if (strstr(s, oldW) == s)
        {
            strcpy(&result[i], newW);
            i += newWlen;
            s += oldWlen;
        }
        else
            result[i++] = *s++;
    }

    result[i] = '\0';
    return result;
    free (result);
}
char *chan(char *comm) {
	comm = replace(comm,"w"," ");
	comm = replace(comm,"doa"," -n -f 523");
	comm = replace(comm,"rea"," -n -f 587");
	comm = replace(comm,"mia"," -n -f 659");
	comm = replace(comm,"faa"," -n -f 698");
	comm = replace(comm,"sola"," -n -f 784");
	comm = replace(comm,"laa"," -n -f 880");
	comm = replace(comm,"sia"," -n -f 988");
	comm = replace(comm,"do"," -n -f 262");
	comm = replace(comm,"re"," -n -f 294");
	comm = replace(comm,"mi"," -n -f 330");
	comm = replace(comm,"fa"," -n -f 349");
	comm = replace(comm,"sol"," -n -f 392");
	comm = replace(comm,"la"," -n -f 440");
	comm = replace(comm,"si"," -n -f 494");
	comm = replace(comm,"s"," -l 100");
	comm = replace(comm,"c"," -l 200");
	comm = replace(comm,"-n","-q");
	comm = replace(comm,"n"," -l 400");
	comm = replace(comm,"-q","-n");
	comm = replace(comm,"b"," -l 800");
	return comm;
}
int main(int argc,char * argv[]) {
	int n;
	char ul[1000] = "beep ";
	char *ol = chan(argv[1]);
	ol += 4;
	strcat(ul,ol);
	for(n = 2; n < argc; ++n) {
		strcat(ul,chan(argv[n]));
	}
	system(ul);
	return 0;
}
