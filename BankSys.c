#include <stdio.h> 
#include <string.h>
#define MAX_ACCOUNTS 100
struct Account { 
int accountNumber; 
char username[20];
char password[20];
float balance;
 };
struct Account accounts[MAX_ACCOUNTS]; 
int accountCount = 0;
int loggedInIndex = -1;

void createAccount() {
if (accountCount >= MAX_ACCOUNTS) { 
printf("Cannot create more accounts.\n");
 return;
} printf("Enter Account Number: ");
scanf("%d", &accounts[accountCount].accountNumber); 
printf("Enter Username: ");
scanf("%s", accounts[accountCount].username); 
printf("Enter Password: ");
scanf("%s", accounts[accountCount].password);
printf("Enter Initial Deposit: ");
scanf("%f", &accounts[accountCount].balance);
printf("Account created successfully!\n");
 accountCount++;
} 
void login() {
char uname[20], pass[20]; 
printf("Enter Username: "); 
scanf("%s", uname); 
printf("Enter Password: "); 
scanf("%s", pass);

for (int i = 0; i < accountCount; i++) {
if (strcmp(accounts[i].username, uname) == 0 && strcmp(accounts[i].password, pass) == 0) {
loggedInIndex = i; 
printf("Login successful!\n"); 
return;
}
 }
 printf("Invalid username or password.\n");
 } 
void checkBalance() {
if (loggedInIndex == -1) { 
printf("Please login first.\n"); 
return;
} printf("Current Balance: %.2f\n", accounts[loggedInIndex].balance); } 

void transferMoney() {

if (loggedInIndex == -1)
{ printf("Please login first.\n");
return;
} 
int targetAcc; 
float amount;
printf("Enter target Account Number: "); 
scanf("%d", &targetAcc);
printf("Enter amount to transfer: "); 
scanf("%f", &amount);
if (amount > accounts[loggedInIndex].balance) { 
printf("Insufficient balance.\n");
return; 
} 
for (int i = 0; i < accountCount; i++) {
if (accounts[i].accountNumber == targetAcc) { 
accounts[loggedInIndex].balance -= amount; 
accounts[i].balance += amount;
printf("Transfer successful! Your new balance: %.2f\n", accounts[loggedInIndex].balance);
return;

} 
} 
printf("Target account not found.\n"); } 

int main() { int choice;
while (1) {
printf("\n--- Bank Management System ---\n"); 
printf("1. Create Account\n");
printf("2. Login\n"); 
printf("3. Check Balance\n"); 
printf("4. Transfer Money\n"); 
printf("5. Exit\n"); 
printf("Enter your choice: "); scanf("%d", &choice);

switch (choice) {
case 1: createAccount(); break; 
case 2: login(); break;
case 3: checkBalance(); break; 
case 4: transferMoney(); break; 
case 5: return 0;
default: printf("Invalid choice. Try again.\n"); 
 }
}
 return 0; }
