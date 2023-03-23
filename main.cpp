#include <iostream>
#include <iomanip>

void ShowBalance(double balance);
double Deposit();
double Withdraw(double balance);
bool Verification(double ammount);
bool FoundsVerification(double balance, double ammount);

int main()
{
    double balance = 0;
    int choice = 0;

    do {
        std::cout << "Enter your choice: \n";
        std::cout << "1. Show your account balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit the program\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        std::cin.clear();
        fflush(stdin);

        switch (choice) {
            case 1:
                ShowBalance(balance);
                std::cout << "********************\n";
                break;
            case 2:
                balance += Deposit();
                ShowBalance(balance);
                std::cout << "********************\n";
                break;
            case 3:
                balance -= Withdraw(balance);
                ShowBalance(balance);
                std::cout << "********************\n";
                break;
            case 4:
                std::cout << "Thank you for using our program!\n";
                std::cout << "********************\n";
                break;
            default:
                std::cout << "Input Error! Please try again!\n";
                std::cout << "********************\n";
                break;
        }
    }while(choice!=4);



}
bool Verification(double ammount)
{
    if(ammount<0)
    {
        return false;
    }
    return true;
}
bool FoundsVerification(double balance, double ammount)
{
    if(balance < ammount)
    {
        return false;
    }
    return true;
}

void ShowBalance(double balance)
{
    std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << "\n";
}
double Deposit()
{
    double ammount = 0;
    std::cout << "Enter the ammount you want to deposit to your account: $";
    std::cin >> ammount;
    if(Verification(ammount))
    {
        return ammount;
    }
    else
    {
        std::cout << "Error! The value you have introduced is invalid! Try again!\n";
        return 0;
    }
}
double Withdraw(double balance)
{
    double ammount = 0;
    std::cout << "Enter the ammount you want to withdraw from your account: $";
    std::cin >> ammount;

    if(FoundsVerification(balance,ammount)) {
        if (Verification(ammount)) {
            return ammount;
        } else {
            std::cout << "Error! The value you have introduced is invalid! Try again!\n";
            return 0;
        }
    }
    else
    {
        std::cout << "Insufficient founds! Make a deposit and try again!";
        return 0;

    }
}
