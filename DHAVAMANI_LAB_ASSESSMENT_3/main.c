#include <stdio.h>
#include <stdlib.h>

// Structure to store denomination counts
struct Denomination {
    int five_hundred;
    int two_hundred;
    int one_hundred;
    int fifty;
    int total_balance;
};

// Function prototypes
void initialDeposit(struct Denomination *denom);
void displayMenu();
void withdrawMoney(struct Denomination *denom);
void balanceEnquiry(struct Denomination *denom);
int isValidAmount(int amount);
int canDispenseAmount(int amount, struct Denomination *denom);
void dispenseAmount(int amount, struct Denomination *denom);

int main() {
    struct Denomination denom = {0, 0, 0, 0, 0};
    int choice;
    
    printf("===== WELCOME TO ATM =====\n\n");
    
    // Initial deposit (only once)
    initialDeposit(&denom);
    
    // Main menu loop
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                withdrawMoney(&denom);
                break;
            case 2:
                balanceEnquiry(&denom);
                break;
            case 3:
                printf("\nThanks for visiting!\n");
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 3);
    
    return 0;
}

// Function for initial deposit
void initialDeposit(struct Denomination *denom) {
    printf("=== INITIAL DEPOSIT ===\n");
    printf("Enter the number of 500 notes: ");
    scanf("%d", &denom->five_hundred);
    
    printf("Enter the number of 200 notes: ");
    scanf("%d", &denom->two_hundred);
    
    printf("Enter the number of 100 notes: ");
    scanf("%d", &denom->one_hundred);
    
    printf("Enter the number of 50 notes: ");
    scanf("%d", &denom->fifty);
    
    // Calculate total balance
    denom->total_balance = (denom->five_hundred * 500) + 
                           (denom->two_hundred * 200) + 
                           (denom->one_hundred * 100) + 
                           (denom->fifty * 50);
    
    printf("\n=== DEPOSIT SUCCESSFUL ===\n");
    printf("Available Denomination Details:\n");
    printf("500 notes: %d\n", denom->five_hundred);
    printf("200 notes: %d\n", denom->two_hundred);
    printf("100 notes: %d\n", denom->one_hundred);
    printf("50 notes: %d\n", denom->fifty);
    printf("Total Balance: Rs. %d\n\n", denom->total_balance);
}

// Function to display menu
void displayMenu() {
    printf("\n===== ATM MENU =====\n");
    printf("1. Withdraw Money\n");
    printf("2. Balance Enquiry\n");
    printf("3. Exit\n");
}

// Function to check if amount is valid (multiple of 50)
int isValidAmount(int amount) {
    return (amount > 0 && amount % 50 == 0);
}

// Function to check if amount can be dispensed with available denominations
int canDispenseAmount(int amount, struct Denomination *denom) {
    int temp_amount = amount;
    int temp_500 = denom->five_hundred;
    int temp_200 = denom->two_hundred;
    int temp_100 = denom->one_hundred;
    int temp_50 = denom->fifty;
    
    // Try to use 500 notes
    while(temp_amount >= 500 && temp_500 > 0) {
        temp_amount -= 500;
        temp_500--;
    }
    
    // Try to use 200 notes
    while(temp_amount >= 200 && temp_200 > 0) {
        temp_amount -= 200;
        temp_200--;
    }
    
    // Try to use 100 notes
    while(temp_amount >= 100 && temp_100 > 0) {
        temp_amount -= 100;
        temp_100--;
    }
    
    // Try to use 50 notes
    while(temp_amount >= 50 && temp_50 > 0) {
        temp_amount -= 50;
        temp_50--;
    }
    
    return (temp_amount == 0);
}

// Function to dispense amount and update denominations
void dispenseAmount(int amount, struct Denomination *denom) {
    int remaining = amount;
    
    // Dispense 500 notes
    while(remaining >= 500 && denom->five_hundred > 0) {
        remaining -= 500;
        denom->five_hundred--;
        printf("Dispensed 500 note\n");
    }
    
    // Dispense 200 notes
    while(remaining >= 200 && denom->two_hundred > 0) {
        remaining -= 200;
        denom->two_hundred--;
        printf("Dispensed 200 note\n");
    }
    
    // Dispense 100 notes
    while(remaining >= 100 && denom->one_hundred > 0) {
        remaining -= 100;
        denom->one_hundred--;
        printf("Dispensed 100 note\n");
    }
    
    // Dispense 50 notes
    while(remaining >= 50 && denom->fifty > 0) {
        remaining -= 50;
        denom->fifty--;
        printf("Dispensed 50 note\n");
    }
    
    // Update total balance
    denom->total_balance -= amount;
}

// Function for withdrawal
void withdrawMoney(struct Denomination *denom) {
    int amount;
    
    printf("\nEnter amount to withdraw: ");
    scanf("%d", &amount);
    
    // Check if amount is valid
    if(!isValidAmount(amount)) {
        printf("Invalid amount! Amount must be positive and in multiples of 50.\n");
        return;
    }
    
    // Check if sufficient balance exists
    if(amount > denom->total_balance) {
        printf("Insufficient balance! Available balance: Rs. %d\n", denom->total_balance);
        return;
    }
    
    // Check if amount can be dispensed with available denominations
    if(!canDispenseAmount(amount, denom)) {
        printf("Cannot dispense this amount with available denominations.\n");
        printf("Please try a different amount.\n");
        return;
    }
    
    // Dispense the amount
    printf("\nDispensing Rs. %d\n", amount);
    dispenseAmount(amount, denom);
    
    printf("\nWithdrawal successful!\n");
    printf("Remaining Balance: Rs. %d\n", denom->total_balance);
}

// Function for balance enquiry
void balanceEnquiry(struct Denomination *denom) {
    printf("\n=== BALANCE ENQUIRY ===\n");
    printf("500 notes: %d\n", denom->five_hundred);
    printf("200 notes: %d\n", denom->two_hundred);
    printf("100 notes: %d\n", denom->one_hundred);
    printf("50 notes: %d\n", denom->fifty);
    printf("Total Balance: Rs. %d\n", denom->total_balance);
}