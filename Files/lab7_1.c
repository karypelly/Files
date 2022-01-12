#include <stdio.h>
#include <string.h>


int main() {
    FILE *fp;
    struct record {
        int ID;
        char Encrypted;
        char Name[20];
        float Balance;
    } 
    r;
    fp = fopen("dd.bin", "rb");
    while (fread(&r, sizeof(r), 1, fp) == 1) {
        if (r.Encrypted == 'E'){
            for (int i = 0; i < sizeof(r.Name); i++){
                r.Name[i] = ~r.Name[i];
            }
        }
        r.Name[strcspn(r.Name, "\n")] = 0;
        printf("%d\t%s\t%.1f\n", r.ID, r.Name, r.Balance);

    }
    fclose(fp);
}