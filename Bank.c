// correct version 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

// Structure to store user data
struct UserData 
{
    char username[50];
    char password[50];
    char firstName[20];
    char lastName[20];
    char fatherName[20];
    char motherName[20];
    char address[50];
    char accountType[20];
    int dateOfBirth;
    char adharNumber[20];
    char phoneNumber[15];
    long int accountBalance;
    struct UserData* next;
};

// Structure to store money transfer data
struct MoneyTransfer 
{
    char fromUser[50];
    char toUser[50];
    long int amount;
    struct MoneyTransfer* next;
};

// Function prototypes
void checkBalance(const char* username);
void transferMoney(const char* username);
void displayloginboard(const char* username);
void createAccount();
void login();
void loginsu();
void accountCreated();
void logout();
void saveUserDataToFile(const struct UserData* user);
void printUserDataFromFile(const char* username);
void loadUserDataFromFile();
void addMoney(const char* username);
void withdrawMoney(const char* username);
void TransactionHistory(const char* username, long int amount, const char* transactionType, const char* touser);
void ViewTransaction(const char* username);
void Displayuserdata(const char* username);

// Global linked list for user data
struct UserData* userList = NULL;

// Global linked list for money transfer data
struct MoneyTransfer* transferList = NULL;

int main() 
{
    loadUserDataFromFile();
    int choice;

    printf("WELCOME TO Reshma Global Banking\n\n");
    printf("**********************************\n");
    printf("1. CREATE A BANK ACCOUNT\n");
    printf("2. ALREADY A USER? SIGN IN\n");
    printf("3. EXIT\n\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            system("cls");
            printf("\n\n USERNAME 50 CHARACTERS MAX!!");
            printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
            createAccount();
            break;
        case 2:
            login();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
            printf("Retry Again");
            exit(0);
    }

    getch();
}

void createAccount() 
{
    struct UserData* newUser = (struct UserData*)malloc(sizeof(struct UserData));

    printf("\n\n!!!!!CREATE ACCOUNT!!!!!\n");
    printf("\nFIRST NAME: ");
    scanf("%s", newUser->firstName);
    printf("\nLAST NAME: ");
    scanf("%s", newUser->lastName);
    printf("\nFATHER's NAME: ");
    scanf("%s", newUser->fatherName);
    printf("\nMOTHER's NAME: ");
    scanf("%s", newUser->motherName);
    printf("\nADDRESS: ");
    scanf("%s", newUser->address);
    printf("\nACCOUNT TYPE: ");
    scanf("%s", newUser->accountType);
    printf("\nDATE OF BIRTH (DDMMYYYY): ");
    scanf("%d", &newUser->dateOfBirth);
    printf("\nADHAR NUMBER: ");
    scanf("%s", newUser->adharNumber);
    printf("\nPHONE NUMBER: ");
    scanf("%s", newUser->phoneNumber);
    printf("\nUSERNAME: ");
    scanf("%s", newUser->username);
    printf("\nPASSWORD: ");
    scanf("%s", newUser->password);

    newUser->accountBalance = 0;
    newUser->next = userList;
    userList = newUser;

    saveUserDataToFile(newUser);

    accountCreated();
}

void saveUserDataToFile(const struct UserData* user) 
{
    FILE* file = fopen("user_data.txt", "a");
        
    if (file == NULL) 
    {
        printf("Error: Could not open the file for writing.\n");
        return;
    }

    fprintf(file, "Username: %s\n", user->username);
    fprintf(file, "Password: %s\n", user->password);
    fprintf(file, "First Name: %s\n", user->firstName);
    fprintf(file, "Last Name: %s\n", user->lastName);
    fprintf(file, "Father's Name: %s\n", user->fatherName);
    fprintf(file, "Mother's Name: %s\n", user->motherName);
    fprintf(file, "Address: %s\n", user->address);
    fprintf(file, "Account Type: %s\n", user->accountType);
    fprintf(file, "Date of Birth: %d\n", user->dateOfBirth);
    fprintf(file, "Adhar Number: %s\n", user->adharNumber);
    fprintf(file, "Phone Number: %s\n", user->phoneNumber);
    fprintf(file, "Account Balance: %ld\n", user->accountBalance);
    fprintf(file, "\n");

    fclose(file);
}

void printUserDataFromFile(const char* username) 
{
    FILE* file = fopen("user_data.txt", "r");

    if (file == NULL) 
    {
        printf("Error: Could not open the file for reading.\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (strstr(line, "Username: ") == line && strstr(line, username) != NULL) 
        {
            printf("%s", line);
            for (int i = 0; i < 10; i++) 
            {
                fgets(line, sizeof(line), file);
                printf("%s", line);
            }
            break;
        }
    }

    fclose(file);
}

void accountCreated() 
{
    printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....\n");

    // Simulate a delay
    for (int i = 0; i < 200000000; i++) 
    {
        i++;
        i--;
    }

    printf("ACCOUNT CREATED SUCCESSFULLY....\n");
    printf("Press enter to login\n");
    getch();
    login();
}

void login() 
{
    char username[50];
    char password[50];
    struct UserData* currentUser = userList;

    printf("ACCOUNT LOGIN\n");
    printf("USERNAME: ");
    scanf("%s", username);
    printf("PASSWORD: ");

    char ch;
    int passwordLength = 0;

    while (1) 
    {
        ch = getch();
        if (ch != 13) 
        {
            password[passwordLength] = ch;
            ch = '*';
            printf("%c", ch);
            passwordLength++;
        } 
        else 
        {
            break;
        }
    }
    password[passwordLength] = '\0';

    while (currentUser != NULL) 
    {
        if (strcmp(currentUser->username, username) == 0 && strcmp(currentUser->password, password) == 0) 
        {
            loginsu();
            displayloginboard(username);
            return;
        }
        currentUser = currentUser->next;
    }

    printf("Login failed. Invalid username or password.\n");
}

void loginsu() 
{
    printf("\nFetching account details...\n");

    // Simulate a delay
    for (int i = 0; i < 200000000; i++) 
    {
        i++;
        i--;
    }

    printf("LOGIN SUCCESSFUL....\n");
    printf("Press enter to continue\n");
    getch();
}

void Displayuserdata(const char* username)
{
    struct UserData* currentUser = userList;

    while (currentUser != NULL) 
    {
        if (strcmp(currentUser->username, username) == 0) 
        {
            printf("WELCOME, %s %s\n", currentUser->firstName, currentUser->lastName);
            printf("Name: %s %s\n", currentUser->firstName, currentUser->lastName);
            printf("Father's Name: %s %s\n", currentUser->fatherName, currentUser->lastName);
            printf("Mother's Name: %s\n", currentUser->motherName);
            printf("Adhar Card Number: %s\n", currentUser->adharNumber);
            printf("Mobile Number: %s\n", currentUser->phoneNumber);
            printf("Date of Birth: %d\n", currentUser->dateOfBirth);
            printf("Address: %s\n", currentUser->address);
            printf("Account Type: %s\n", currentUser->accountType);
            break;
        }
        currentUser = currentUser->next;
    }
    printf("Press Enter key to continue...\n");
    getch();
    displayloginboard(username);
}

void displayloginboard(const char* username) 
{
    int choice;

    printf("\nHOME\n");
    printf("1. CHECK USER DETAILS\n");
    printf("2. CHECK BALANCE\n");
    printf("3. ADD MONEY\n");
    printf("4. WITHDRAW MONEY\n");
    printf("5. TRANSFER MONEY\n"); 
    printf("6. TRANSACTION DETAILS\n");
    printf("7. LOG OUT\n");
    printf("8. EXIT\n");
    printf("ENTER YOUR CHOICE=");
    scanf("%d", &choice);
    printf("\n");

    switch (choice) 
    {
        case 1:
            Displayuserdata(username);
            break;
        case 2:
            checkBalance(username);
            break;
        case 3:
            addMoney(username); 
            break;
        case 4:
            withdrawMoney(username);
            break;
        case 5:
            transferMoney(username);
            break;
        case 6:
            ViewTransaction(username);
            break;
        case 7:
            logout();
            main();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice.\n");
            main();
            break;
    }
}

void checkBalance(const char* username) 
{
    struct UserData* currentUser = userList;
    long int balance = 0; 

    while (currentUser != NULL) 
    {
        if (strcmp(currentUser->username, username) == 0) 
        {
            // If the username matches, update the balance
            balance = currentUser->accountBalance;
            break;
        }
        currentUser = currentUser->next;
    }

    printf("BALANCE DASHBOARD\n");
    printf("Total Balance: %ld\n", balance);
    printf("Press Enter key to continue...\n");
    getch();
    displayloginboard(username);
}


void transferMoney(const char* username) 
{
    char toUser[50];
    struct UserData* currentUser = userList;
    long int money;
    printf("TRANSFER MONEY\n");
    printf("FROM (your username): %s\n", username);

    while (currentUser != NULL) 
    {
        if (strcmp(currentUser->username, username) == 0) 
        {
            printf("Your current balance: %ld\n", currentUser->accountBalance);
            printf("TO (username of the receiver): ");
            scanf("%s", toUser);

            struct UserData* receiverUser = userList;

            while (receiverUser != NULL) 
            {
                if (strcmp(receiverUser->username, toUser) == 0) 
                {
                    long int amountToTransfer;
                    printf("Enter the amount to transfer: ");
                    scanf("%ld", &amountToTransfer);
                    money=amountToTransfer;

                    if (amountToTransfer <= 0) 
                    {
                        printf("Invalid amount to transfer.\n");
                        return;
                    }

                    if (currentUser->accountBalance < amountToTransfer) 
                    {
                        printf("Insufficient balance for the transfer.\n");
                        return;
                    }

                    // Deduct the amount from the sender's account
                    currentUser->accountBalance -= amountToTransfer;
                    TransactionHistory(username,money,"-",toUser);

                    // Add the amount to the receiver's account
                    receiverUser->accountBalance += amountToTransfer;

                    FILE* file = fopen("user_data.txt", "r");
                    FILE* tempFile = fopen("temp_user_data.txt", "w");

                    if (file == NULL || tempFile == NULL) 
                    {
                        printf("Error: Could not open files for reading/writing.\n");
                        return;
                    }

                    int userFound = 0;

                    struct UserData* userToUpdate = userList;

                    while (userToUpdate != NULL) 
                    {
                        fprintf(tempFile, "Username: %s\n", userToUpdate->username);
                        fprintf(tempFile, "Password: %s\n", userToUpdate->password);
                        fprintf(tempFile, "First Name: %s\n", userToUpdate->firstName);
                        fprintf(tempFile, "Last Name: %s\n", userToUpdate->lastName);
                        fprintf(tempFile, "Father's Name: %s\n", userToUpdate->fatherName);
                        fprintf(tempFile, "Mother's Name: %s\n", userToUpdate->motherName);
                        fprintf(tempFile, "Address: %s\n", userToUpdate->address);
                        fprintf(tempFile, "Account Type: %s\n", userToUpdate->accountType);
                        fprintf(tempFile, "Date of Birth: %d\n", userToUpdate->dateOfBirth);
                        fprintf(tempFile, "Adhar Number: %s\n", userToUpdate->adharNumber);
                        fprintf(tempFile, "Phone Number: %s\n", userToUpdate->phoneNumber);
                        fprintf(tempFile, "Account Balance: %ld\n", userToUpdate->accountBalance);
                        fprintf(tempFile, "\n");

                        if (strcmp(userToUpdate->username, currentUser->username) == 0) 
                        {
                            userToUpdate->accountBalance = currentUser->accountBalance;
                        } 
                        
                        else if (strcmp(userToUpdate->username, receiverUser->username) == 0) 
                        {
                            userToUpdate->accountBalance = receiverUser->accountBalance;
                        }

                        userToUpdate = userToUpdate->next;
                    }

                    fclose(file);
                    fclose(tempFile);

                    remove("user_data.txt");
                    rename("temp_user_data.txt", "user_data.txt");
                    printf("Amount transferred successfully.\n");
                    TransactionHistory(toUser,money,"+",username);
                    printf("Press Enter key to continue...\n");
                    getch();
                    displayloginboard(username);
                    return;
                }

                receiverUser = receiverUser->next;
            }

            printf("Receiver username not found.\n");
            printf("Press Enter key to continue...\n");
            getch();
            displayloginboard(username);
            return;
        }

        currentUser = currentUser->next;
    }

    printf("Sender username not found.\n");
}


void logout() 
{
    printf("Please wait, logging out...\n");

    // Simulate a delay
    for (int i = 0; i < 700000000; i++) 
    {
        i++;
        i--;
    }

    printf("Sign out successfully..\n");
    printf("Press any key to continue...\n");
    getch();
}



void loadUserDataFromFile() 
{
    FILE* file = fopen("user_data.txt", "r");
    if (file == NULL) 
    {
        printf("Error: Could not open the file for reading.\n");
        return;
    }

    struct UserData* newUser = NULL;
    char line[100];

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (strstr(line, "Username: ") == line) 
        {
            newUser = (struct UserData*)malloc(sizeof(struct UserData));
            sscanf(line, "Username: %s", newUser->username);
            fgets(line, sizeof(line), file);
            sscanf(line, "Password: %s", newUser->password);
            fgets(line, sizeof(line), file);
            sscanf(line, "First Name: %s", newUser->firstName);
            fgets(line, sizeof(line), file);
            sscanf(line, "Last Name: %s", newUser->lastName);
            fgets(line, sizeof(line), file);
            sscanf(line, "Father's Name: %s", newUser->fatherName);
            fgets(line, sizeof(line), file);
            sscanf(line, "Mother's Name: %s", newUser->motherName);
            fgets(line, sizeof(line), file);
            sscanf(line, "Address: %s", newUser->address);
            fgets(line, sizeof(line), file);
            sscanf(line, "Account Type: %s", newUser->accountType);
            fgets(line, sizeof(line), file);
            sscanf(line, "Date of Birth: %d", &newUser->dateOfBirth);
            fgets(line, sizeof(line), file);
            sscanf(line, "Adhar Number: %s", newUser->adharNumber);
            fgets(line, sizeof(line), file);
            sscanf(line, "Phone Number: %s", newUser->phoneNumber);
            fgets(line, sizeof(line), file);
            sscanf(line, "Account Balance: %ld", &newUser->accountBalance);

            newUser->next = userList;
            userList = newUser;
        }
    }

    fclose(file);
}


void addMoney(const char* username) 
{
    long int add;
    struct UserData* currentUser = userList;
    FILE* file = fopen("user_data.txt", "r");
    FILE* tempFile = fopen("temp_user_data.txt", "w");

    if (file == NULL || tempFile == NULL) 
    {
        printf("Error: Could not open files for reading/writing.\n");
        return;
    }

    int userFound = 0;

    while (currentUser != NULL) 
    {
        if (strcmp(currentUser->username, username) == 0) 
        {
            long int amountToAdd;
            printf("Enter the amount to add to your account: ");
            scanf("%ld", &amountToAdd);

            // Update the account balance
            currentUser->accountBalance += amountToAdd;
            add=amountToAdd;
            userFound = 1;
        }

        fprintf(tempFile, "Username: %s\n", currentUser->username);
        fprintf(tempFile, "Password: %s\n", currentUser->password);
        fprintf(tempFile, "First Name: %s\n", currentUser->firstName);
        fprintf(tempFile, "Last Name: %s\n", currentUser->lastName);
        fprintf(tempFile, "Father's Name: %s\n", currentUser->fatherName);
        fprintf(tempFile, "Mother's Name: %s\n", currentUser->motherName);
        fprintf(tempFile, "Address: %s\n", currentUser->address);
        fprintf(tempFile, "Account Type: %s\n", currentUser->accountType);
        fprintf(tempFile, "Date of Birth: %d\n", currentUser->dateOfBirth);
        fprintf(tempFile, "Adhar Number: %s\n", currentUser->adharNumber);
        fprintf(tempFile, "Phone Number: %s\n", currentUser->phoneNumber);
        fprintf(tempFile, "Account Balance: %ld\n", currentUser->accountBalance);
        fprintf(tempFile, "\n");

        currentUser = currentUser->next;
    }

    fclose(file);
    fclose(tempFile);
    remove("user_data.txt");
    rename("temp_user_data.txt", "user_data.txt");
    printf("Amount added successfully.\n");
    TransactionHistory(username,add,"+",username);
    printf("Press Enter key to continue...\n");
    getch();
    displayloginboard(username);
    
}


void withdrawMoney(const char* username) 
{
    long int minus;
    struct UserData* currentUser = userList;
    FILE* file = fopen("user_data.txt", "r");
    FILE* tempFile = fopen("temp_user_data.txt", "w");

    if (file == NULL || tempFile == NULL) 
    {
        printf("Error: Could not open files for reading/writing.\n");
        return;
    }

    int userFound = 0;

    while (currentUser != NULL) 
    {
        if (strcmp(currentUser->username, username) == 0) 
        {
            long int amountToMinus;
            printf("Enter the amount to be withdrwan from your account: ");
            scanf("%ld", &amountToMinus);

            currentUser->accountBalance -= amountToMinus;
            minus=amountToMinus;
            userFound = 1;
        }

        fprintf(tempFile, "Username: %s\n", currentUser->username);
        fprintf(tempFile, "Password: %s\n", currentUser->password);
        fprintf(tempFile, "First Name: %s\n", currentUser->firstName);
        fprintf(tempFile, "Last Name: %s\n", currentUser->lastName);
        fprintf(tempFile, "Father's Name: %s\n", currentUser->fatherName);
        fprintf(tempFile, "Mother's Name: %s\n", currentUser->motherName);
        fprintf(tempFile, "Address: %s\n", currentUser->address);
        fprintf(tempFile, "Account Type: %s\n", currentUser->accountType);
        fprintf(tempFile, "Date of Birth: %d\n", currentUser->dateOfBirth);
        fprintf(tempFile, "Adhar Number: %s\n", currentUser->adharNumber);
        fprintf(tempFile, "Phone Number: %s\n", currentUser->phoneNumber);
        fprintf(tempFile, "Account Balance: %ld\n", currentUser->accountBalance);
        fprintf(tempFile, "\n");

        currentUser = currentUser->next;
    }

    fclose(file);
    fclose(tempFile);
    remove("user_data.txt");
    rename("temp_user_data.txt", "user_data.txt");
    printf("Amount withdrawn successfully.\n");
    TransactionHistory(username,minus,"-",username);
    printf("Press Enter key to continue...\n");
    getch();
    displayloginboard(username);
}


void TransactionHistory(const char* username, long int amount, const char* transactionType, const char* touser) 
{
    FILE* transactionFile = fopen("transaction.txt", "a");

    if (transactionFile == NULL) 
    {
        printf("Error: Could not open the transaction history file.\n");
        return;
    }

    char transactionDetails[100000];
    int money;
    snprintf(transactionDetails, sizeof(transactionDetails), "%s%ld ", transactionType, amount);
    money=atoi(transactionDetails); 
    
    if(strcmp(username,touser)==0)
    {
        if(money>0)
        {
            fprintf(transactionFile, "%s:\nAdded %d\n\n", username, money);
            fclose(transactionFile);
        }

        if(money<0)
        {
            fprintf(transactionFile, "%s:\nWithdrawn %d\n\n", username, -money);
            fclose(transactionFile);
        }

    }

    if(strcmp(username,touser)!=0)
    {
        if(money<0)
        {
            fprintf(transactionFile, "%s:\nTransferred money %d to username %s\n\n", username, -money, touser);
            fclose(transactionFile);
        }

        if(money>0)
        {
            fprintf(transactionFile, "%s:\nReceived money %d from username %s\n\n", username, money, touser);
            fclose(transactionFile);
        }
    }

}


void ViewTransaction(const char* username) 
{
    FILE* transactionFile = fopen("transaction.txt", "r");

    if (transactionFile == NULL) 
    {
        printf("Error: Could not open the transaction history file.\n");
        return;
    }

    char line[100];
    char currentUsername[50];
    int found = 0;

    
    while (fgets(line, sizeof(line), transactionFile) != NULL) 
    {
        if (strstr(line, username) == line) 
        {
            found = 1;
            strncpy(currentUsername, line, sizeof(currentUsername));
            continue;
        }
        if (found) 
        {
            printf("%s", line);
            found = 0;
        }
    }

    fclose(transactionFile);
    printf("Press Enter key to continue...\n");
    getch();
    displayloginboard(username);
}
