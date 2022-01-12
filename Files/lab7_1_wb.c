#include <stdio.h>

int main()
{
    FILE *fp;
    char another = 'Y';
    struct record
    {
        int id;
        unsigned char enc;
        char name[20];
        float bal;
        
    };
    struct record e;
    fp = fopen("dd.bin", "wb");
    if (fp == NULL)
    {
        puts("Cannot open the file.");
        return 1;
    }
    while(another == 'Y')
    {
        printf("Enter the ID, encrypted, name, balance: ");
        scanf("%d %s %s %f", &e.id, &e.enc, e.name, &e.bal);
        if (e.enc != 'E'){
            for (int i = 0; i < sizeof(e.name) + 1; i++){
                e.name[i] = ~e.name[i];
            }
            
        }
        while(getchar() != '\n');
        fwrite(&e, sizeof(e), 1, fp);
        printf("Add another record? (Y/N)");

        another = getchar();
    }
    fclose(fp);
    return 0;
}