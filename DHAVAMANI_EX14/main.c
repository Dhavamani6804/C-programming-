#include <stdio.h>

int main() {
    FILE *source, *destination;
    char sourceFile[100], destFile[100];
    char ch;
    
    printf("Enter source filename: ");
    scanf("%s", sourceFile);
    printf("Enter destination filename: ");
    scanf("%s", destFile);
    
    // Open source file
    source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Error: Cannot open source file '%s'\n", sourceFile);
        return 1;
    }
    
    // Open destination file
    destination = fopen(destFile, "w");
    if (destination == NULL) {
        printf("Error: Cannot create destination file '%s'\n", destFile);
        fclose(source);
        return 1;
    }
    
    // Copy contents character by character
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    
    printf("File copied successfully!\n");
    
    // Close files
    fclose(source);
    fclose(destination);
    
    return 0;
}