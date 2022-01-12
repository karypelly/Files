#include <stdio.h>
#define MAX_FILE_NAME 100
  
int main()
{
    FILE *fp;
    int count = 0;  // Line counter (result)

    char c;  // To store a character read from file
  
  
    // Open the file
    fp = fopen("file.txt", "r");
  
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
  
    // Close the file
    fclose(fp);
    printf("The file has %d lines\n ", count);
  
    return 0;
}