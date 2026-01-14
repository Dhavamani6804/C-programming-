#include <stdio.h>

// Function to find string length
int str_len(char s[]) {
    int i = 0;
    while(s[i] != '\0') i++;
    return i;
}

// Function to copy string
void str_copy(char d[], char s[]) {
    int i = 0;
    while(s[i] != '\0') {
        d[i] = s[i];
        i++;
    }
    d[i] = '\0';
}

// Function to compare strings
int str_compare(char s1[], char s2[]) {
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0') {
        if(s1[i] != s2[i]) return s1[i] - s2[i];
        i++;
    }
    return s1[i] - s2[i];
}

// Function to reverse string
void str_reverse(char s[]) {
    int len = str_len(s);
    int i = 0, j = len - 1;
    char temp;
    while(i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

// Function to remove spaces
void remove_space(char s[]) {
    int i = 0, j = 0;
    while(s[i] != '\0') {
        if(s[i] != ' ') {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';
}

int main() {
    char str[100], str2[100];
    int choice;
    
    printf("STRING OPERATIONS PROGRAM\n");
    printf("1. Copy string\n");
    printf("2. Compare strings\n");
    printf("3. Reverse string\n");
    printf("4. Remove spaces\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    // Clear input buffer
    while(getchar() != '\n');
    
    switch(choice) {
        case 1:  // Copy
            printf("Enter string: ");
            fgets(str, 100, stdin);
            // Remove newline
            for(int i = 0; str[i] != '\0'; i++)
                if(str[i] == '\n') str[i] = '\0';
            
            str_copy(str2, str);
            printf("Original: %s\n", str);
            printf("Copied: %s\n", str2);
            break;
            
        case 2:  // Compare
            printf("Enter string 1: ");
            fgets(str, 100, stdin);
            for(int i = 0; str[i] != '\0'; i++)
                if(str[i] == '\n') str[i] = '\0';
            
            printf("Enter string 2: ");
            fgets(str2, 100, stdin);
            for(int i = 0; str2[i] != '\0'; i++)
                if(str2[i] == '\n') str2[i] = '\0';
            
            int cmp = str_compare(str, str2);
            printf("Compare result: ");
            if(cmp == 0) printf("Equal\n");
            else if(cmp < 0) printf("First is smaller\n");
            else printf("First is larger\n");
            break;
            
        case 3:  // Reverse
            printf("Enter string: ");
            fgets(str, 100, stdin);
            for(int i = 0; str[i] != '\0'; i++)
                if(str[i] == '\n') str[i] = '\0';
            
            str_copy(str2, str); 
            str_reverse(str2);
            printf("Original: %s\n", str);
            printf("Reversed: %s\n", str2);
            break;
            
        case 4:  // Remove spaces
            printf("Enter string: ");
            fgets(str, 100, stdin);
            for(int i = 0; str[i] != '\0'; i++)
                if(str[i] == '\n') str[i] = '\0';
            
            str_copy(str2, str);  
            remove_space(str2);
            printf("Original: %s\n", str);
            printf("No spaces: %s\n", str2);
            break;
            
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}