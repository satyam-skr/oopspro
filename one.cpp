#include<bits/stdc++.h>
using namespace std;


class HeadOffice{
    vector<Bank> allBanks;
    vector<HeadEmployee> allHeadEmployees;
public:
    void addBank();
    void addHeadEmployee();

    void displayAllBanks()
    {
        cout << "Displaying All Banks:" << endl;
        cout << "--------------------------" << endl;
        for (auto& bank : allBanks) {
            bank.display();
        }
    }

    void displayAllHeadEmployees()
    {
        cout << "Displaying All Head Employees:" << endl;
        cout << "--------------------------" << endl;
        for (auto& employee : allHeadEmployees)
        {
            employee.display();
        }
    }


                                                 
};

class Bank{
    string branch;
    string IFSC;
    int minBalCurrent;
    int minBalSavings;
    int rateOfInterest;
    vector<BranchEmployee> allBranchEmployees;
    vector<SavingsAccount> allSavingsAccounts;
    vector<CurrentAccount> allCurrentAccounts;
    
public:

    void display()
    {
        cout << "--------------------------" << endl;
        cout << "Branch Name: " << branch << endl;
        cout << "IFSC Code: " << IFSC << endl;
        cout << "Minimum Balance (Current): " << minBalCurrent << endl;
        cout << "Minimum Balance (Savings): " << minBalSavings << endl;
        cout << "Rate of Interest: " << rateOfInterest << "%" << endl;
        cout << "Number of Branch Employees: " << allBranchEmployees.size() << endl;
        cout << "Number of Savings Accounts: " << allSavingsAccounts.size() << endl;
        cout << "Number of Current Accounts: " << allCurrentAccounts.size() << endl;
        cout << "--------------------------" << endl;
    }
    void addBranchEmployee();
    void displayAllBranchEmployees()
    {
        cout << "Displaying All Branch Employees:" << endl;
        cout << "--------------------------" << endl;
        for (auto& employee : allBranchEmployees)
        {
            employee.display();
        }
    }
    

    void openSavingsAccount();
    void openCurrentAccount();
    void displayAllAccounts();

    bool deposit(int accountNumber, int amount);
    bool withdraw(int accountNumber, int amount);



    friend class HeadOffice;
    
};


class Employee{
protected:
    string name;
    int dob;        //ddmmyy
    string post;
    int salary;
public:
    Employee(string name="", int dob=0, string post="", int salary=0)
    {

    }



};
class BranchEmployee : public Employee{
    string branch;
    int doj;
public:

    void display() 
    {
        cout << "--------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Branch: "<<branch<<endl;
        cout << "Post: " << post << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date of Joining: " << doj << endl;
        cout << "--------------------------" << endl;
    }

    friend class Bank;
};
class HeadEmployee : public Employee{
    int doj;
public:

    void display() 
    {
        cout << "--------------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Post: " << post << endl;
        cout << "Salary: " << salary << endl;
        cout << "Date of Joining: " << doj << endl;
        cout << "--------------------------" << endl;
    }

    friend class HeadOffice;
};

class Account{
protected:
    int accountnumber;
    string password;
    string holdername;
    string branch;
    int balance;
public:


    int getBalance();
    string getHolderName();
    int getAccountNumber();

    virtual bool deposit(int amount);
    virtual bool withdraw(int amount);

    void displayAccountDetails();

    
};

class SavingsAccount : public Account{
    int minBal;
    bool overdraft;
    int rateOfInterest;
public:
    SavingsAccount(int mb=0, bool od=false, int roi = 6)
    {
        minBal = mb;
        overdraft = false;
        rateOfInterest = roi;
    }
    
    friend class Bank;
};
class CurrentAccount : public Account{
    int minBal;
    bool overdraft;
public:

    friend class Bank;
};



int Bank::openCurrentAccount(CurrentAccount& account) {
    allCurrentAccounts.push_back(account);
    return account.getAccountNumber();
}

bool Bank::deposit(int accountNumber, int amount) {
    for (auto& account : allSavingsAccounts) {
        if (account.getAccountNumber() == accountNumber) {
            return account.deposit(amount);
        }
    }
    for (auto& account : allCurrentAccounts) {
        if (account.getAccountNumber() == accountNumber) {
            return account.deposit(amount);
        }
    }
    return false; // Account not found
}

bool Bank::withdraw(int accountNumber, int amount) {
    for (auto& account : allSavingsAccounts) {
        if (account.getAccountNumber() == accountNumber) {
            return account.withdraw(amount);
        }
    }
    for (auto& account : allCurrentAccounts) {
        if (account.getAccountNumber() == accountNumber) {
            return account.withdraw(amount);
        }
    }
    return false; // Account not found
}

void Account::displayAccountDetails() {
    cout << "Account Number: " << accountnumber << endl;
    cout << "Holder Name: " << holdername << endl;
    cout << "Balance: " << balance << endl;
    cout << "Branch: " << branch << endl;
}


void HeadOffice :: addBank(){
    Bank newBank;
    cout<<"\n---------Enter details of new Bank-----------\n";
    cout<<"Enter Branch Name : ";
    cin>>newBank.branch;
    cout<<"Enter IFSC code : ";
    cin>>newBank.IFSC;
    cout<<"Enter minimum Balance for savings account : ";
    cin>>newBank.minBalSavings;
    cout<<"Enter minimum Balance for current account : ";
    cin>>newBank.minBalCurrent;
    cout<<"Enter rate of interest in savings account : ";
    cin>>newBank.rateOfInterest;
    

    vector<Bank> allbanklist = wowbank.allBanks;
    int alreadypresent = 0;
    for(auto &x : allbanklist)
    {
        if(x.IFSC == newBank.IFSC)
        {
            alreadypresent = 1;
            break;
        }
    }
    if(alreadypresent){
        cout<<"\nThis Branch is already there\n";
        return;
    }
    else
        wowbank.allBanks.push_back(newBank);
        cout<<"\nBank added successfully\n";
}
void HeadOffice :: addHeadEmployee()
{
    HeadEmployee newheademp;
    cout<<"\n---------Enter details of new Head Employee-----------\n";
    cout<<"Enter Name : ";
    cin>>newheademp.name;
    cout<<"Enter Date of Birth : ";
    cin>>newheademp.dob;
    cout<<"Enter post : ";
    cin>>newheademp.post;
    cout<<"Enter Date of Joining : ";
    cin>>newheademp.doj;
    cout<<"Enter Salary : ";
    cin>>newheademp.salary;
    wowbank.allHeadEmployees.push_back(newheademp);
    cout<<"\n----------Employee added successfully----------\n";

}
void Bank :: addBranchEmployee()
{
    BranchEmployee newbranchemp;
    cout<<"\n---------Enter details of new Branch Employee-----------\n";
    cout<<"Enter Name : ";
    cin>>newbranchemp.name;
    cout<<"Enter Date of Birth : ";
    cin>>newbranchemp.dob;
    cout<<"Enter Branch : ";
    cin>>newbranchemp.branch;
    cout<<"Enter post : ";
    cin>>newbranchemp.post;
    cout<<"Enter Date of Joining : ";
    cin>>newbranchemp.doj;
    cout<<"Enter Salary : ";
    cin>>newbranchemp.salary;
    // kahipe.push_back(newbranchemp);
    cout<<"\n----------Employee added successfully----------\n";

}

void Bank::openSavingsAccount() {
    SavingsAccount newsavacc;
    cout<<"\n---------------Enter the details to open account-----------\n";
    cout<<"Enter account number : ";
    cin>>newsavacc.accountnumber;
    cout<<"Enter password : ";
    cin>>newsavacc.password;
    cout<<"Enter Account Holder name: ";
    cin>>newsavacc.holdername;
    cout<<"Enter Branch : ";
    cin>>newsavacc.branch;
    newsavacc.balance = 0;
    // kuchme.push_back(newsavacc);
    
}

HeadOffice wowbank;



int main() {
    

    return 0;
}
