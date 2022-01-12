#include <stdio.h>
#include <string.h>


int main() {
    FILE *fp;
    struct record {
        char fn[20];
        char ln[20];
        char email[20];
        float t1;
        float t2;
        float t3;
    } 
    r;

    char command[20];
    char data[20];

    fp = fopen("txt.txt", "r");
    
    while (fread(&r, sizeof(r), 1, fp) == 1) {
        scanf("%s %s", command, data);
        if (strcmp(command, "T1") == 0){
            printf("%s, %s, %.2f", r.fn, r.ln, r.t1);
        }
        if (strcmp(command, "T2") == 0){
            printf("%s, %s, %.2f", r.fn, r.ln, r.t2);
        }
        if (strcmp(command, "T1") == 0){
            printf("%s, %s, %.2f", r.fn, r.ln, r.t3);
        }
        

    }
    fclose(fp);
}