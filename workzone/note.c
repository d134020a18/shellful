#include <stdio.h> //To get basic functions
#include <string.h> //To compare strings
#include <stdlib.h> //To get HOME dir
int main(int argc,char * argv[]) {
	//Check if have arguments
	if(argv[1] != NULL) {
		//Declare file
		FILE *fp;
		char line[1000];
		//Get database file path
		char *filepath = strcat(getenv("HOME"), "/.notes.db");
		//Check if arg1 is "-r"
		if(strcmp(argv[1],"-r")==0) {
			char *pattern = argv[2];
			//Convert pattern to syntax
			pattern = strcat(pattern,"#");
			//Get pattern lenght
			int patlenght = strlen(pattern);
			//Open file in read mode
			fp = fopen(filepath,"r");
			
			//Read line by line and comparing each word in line
			while(fscanf(fp , "%[^\n]\n" , line)!=EOF)
           {
				//Check if line match to search
				if(strncmp(line, pattern, patlenght) == 0)
				{
					//Remove pattern of line
					char *out = line;
					out += patlenght;
					//Print that line
					printf("%s\n",out);
				}
				else
				{
					continue;
				}
           }
			//Close file
			fclose(fp);
		}else{
			char *pattern = argv[1];
			//Open file in append mode	
			fp = fopen (filepath,"a");
			char comment[1000];
			printf("Write the note:");
			for(;;) {
				scanf("%[^\n]s", &comment);
				if(strcmp(comment,"breaknote")!=0) {
					//Save to file
					fprintf(fp, "%s#%s\n", pattern,comment);
					//If read breaknote then break
				}else{
					break;
				}
			}
		}
	return 0;
	}
}
