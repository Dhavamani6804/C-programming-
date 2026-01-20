#include <stdio.h>
//preprocessor directives and other includes can go here
// Macro
// include
// Conditional compilation
//  undefine
// pragma
 
#define ARRAY_SIZE 10
 
#if ARRAY_SIZE > 0
    #define VALID_SIZE 1
#elif ARRAY_SIZE == 0
    #define VALID_SIZE 0
#else
    #define VALID_SIZE 0
#endif
 
#ifdef ARRAY_SIZE
    #define ARRAY_DEFINED 1
#else
    #define ARRAY_DEFINED 0
    #define ARRAY_SIZE 5
#endif
 
int main() {
    int Array[ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i++) {
        Array[i] = i * i; // Initialize array with square of index
    }
    #undef ARRAY_SIZE
    if(VALID_SIZE) {
        printf("Array elements:\n");
        for(int i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", Array[i]);
        }
        printf("\n");
    } else {
        printf("Invalid array size.\n");
    }
    return 0;
}
 
#include <stdio.h>
// File Handing in  C
// 1. fopen()
//  2. fclose()
//  3. fread()
//  4. fwrite()
//  5. fprintf()
 
int main() {
    FILE *MyFilePtr = NULL;
    MyFilePtr  = fopen("SampleFile.txt","w"); // w = write mode
    if (MyFilePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }    
    fprintf(MyFilePtr, "This is third time writting.\n");
    printf("File written successfully.\n");
    printf("Closing the file.\n");
    fclose(MyFilePtr);
    MyFilePtr = fopen("SampleFile.txt","r+"); // r+ = read and write mode
    if (MyFilePtr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fseek(MyFilePtr, 10, SEEK_SET); // Move file pointer to the beginning of the file
    fseek(MyFilePtr, 5, SEEK_CUR); // Move file pointer to the end of the file
    // SEEK_SET - Beginning of file
    // SEEK_CUR - Current position of the file pointer
    // SEEK_END - End of file
 
    char buffer[50];
    fgets(buffer, sizeof(buffer), MyFilePtr);
    printf("Data read from file: %s\n", buffer);
    fseek(MyFilePtr, -5, SEEK_END); // Move file pointer to the end of the file
    char buffer2[6];
    fgets(buffer2, sizeof(buffer2), MyFilePtr);
    printf("Data read from end of file: %s\n", buffer2);
 
    return 0;
}
 