#include <stdio.h>

// Function to calculate total marks
float calculateTotal(float marks[], int n) {
    float total = 0;
    for(int i = 0; i < n; i++) {
        total += marks[i];
    }
    return total;
}

// Function to calculate percentage
float calculatePercentage(float total, int maxMarks) {
    return (total / maxMarks) * 100;
}

// Function to determine grade
char determineGrade(float percentage) {
    if(percentage >= 90) return 'A';
    else if(percentage >= 80) return 'B';
    else if(percentage >= 70) return 'C';
    else if(percentage >= 60) return 'D';
    else if(percentage >= 40) return 'E';
    else return 'F';
}

// Function to display result
void displayResult(float marks[], float total, float percentage, char grade) {
    printf("\n======== RESULT ========\n");
    for(int i = 0; i < 5; i++) {
        printf("Subject %d: %.2f\n", i+1, marks[i]);
    }
    printf("-------------------------\n");
    printf("Total Marks: %.2f/500\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade: %c\n", grade);
    printf("=========================\n");
}

int main() {
    float marks[5];
    float total, percentage;
    char grade;
    
    // Input marks
    printf("Enter marks for 5 subjects (each out of 100):\n");
    for(int i = 0; i < 5; i++) {
        printf("Subject %d: ", i+1);
        scanf("%f", &marks[i]);
        
        // Input validation
        if(marks[i] < 0 || marks[i] > 100) {
            printf("Invalid marks! Please enter between 0-100.\n");
            i--; // Decrement to re-enter for same subject
        }
    }
    
    // Calculate results
    total = calculateTotal(marks, 5);
    percentage = calculatePercentage(total, 500);
    grade = determineGrade(percentage);
    
    // Display results
    displayResult(marks, total, percentage, grade);
    
    return 0;
}