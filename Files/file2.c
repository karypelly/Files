#include <stdio.h>
#include <string.h>
  
int main()
{
    FILE *fp;
    int count = 0;  // Line counter (result)

    char c;  // To store a character read from file
  
  
    // Open the file
    fp = fopen("file.txt", "r");
  
    char line[300];
    int emptyLine = 0;
    while(fgets(line, 300, fp)) {
        int i = 0;
        int len = strlen(line);
        emptyLine++;
        for (i = 0; i < len; i++) {
            if (line[i] != '\n' && line[i] != '\t' && line[i] != ' ') {
                emptyLine--;
                break;
            }
        }
    }



  
    // Close the file
    fclose(fp);
    printf("The file has %d empty lines\n ", emptyLine);
  
    return 0;
}