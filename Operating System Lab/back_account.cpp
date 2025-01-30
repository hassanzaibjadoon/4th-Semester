#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class account {
    int acno;
    char name[50];
    int deposit;
    char type;
public:
    void create_account();
    void show_account() const;
    void modify();
    void dep(int);
    void draw(int);
    int retacno() const;
    int retdeposit() const;
};

void account::create_account() {
    cout << "\nEnter the Account No. : ";
    cin >> acno;
    cout << "\nEnter the Name of the Account holder: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nEnter Type of the Account (C/S): ";
    cin >> type;
    type = toupper(type);
    cout << "\nEnter The Initial amount: ";
    cin >> deposit;
    cout << "\nAccount Created..";
}

void account::show_account() const {
    cout << "\nAccount No. : " << acno;
    cout << "\nAccount Holder Name : " << name;
    cout << "\nType of Account : " << type;
    cout << "\nBalance amount : " << deposit;
}

void account::modify() {
    cout << "\nModify Account Holder Name: ";
    cin.ignore();
    cin.getline(name, 50);
    cout << "\nModify Type of Account: ";
    cin >> type;
    type = toupper(type);
    cout << "\nModify Balance amount: ";
    cin >> deposit;
}

void account::dep(int x) {
    deposit += x;
}

void account::draw(int x) {
    deposit -= x;
}

int account::retacno() const {
    return acno;
}

int account::retdeposit() const {
    return deposit;
}

// BST Node
struct BSTNode {
    account data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(account acc) : data(acc), left(NULL), right(NULL) {}
};

// BST Class
class BST {
    BSTNode* root;
    BSTNode* insert(BSTNode* node, account acc);
    BSTNode* search(BSTNode* node, int acno);
public:
    BST() : root(NULL) {}
    void insert(account acc);
    account* search(int acno);
};

BSTNode* BST::insert(BSTNode* node, account acc) {
    if (node == NULL) {
        return new BSTNode(acc);
    }
    if (acc.retacno() < node->data.retacno()) {
        node->left = insert(node->left, acc);
    } else {
        node->right = insert(node->right, acc);
    }
    return node;
}

void BST::insert(account acc) {
    root = insert(root, acc);
}

BSTNode* BST::search(BSTNode* node, int acno) {
    if (node == NULL || node->data.retacno() == acno) {
        return node;
    }
    if (acno < node->data.retacno()) {
        return search(node->left, acno);
    }
    return search(node->right, acno);
}

account* BST::search(int acno) {
    BSTNode* node = search(root, acno);
    if (node != NULL) {
        return &node->data;
    }
    return NULL;
}

// Global BST object
BST bst;

void write_account();
void display_sp(int);
void modify_account(int);
void deposit_withdraw(int, int);

int main() {
    char ch;
    int num;
    do {
        system("CLS");
        cout << "\n\n\t\t\t\t======================\n";
        cout << "\t\t\t\tBANK MANAGEMENT SYSTEM";
        cout << "\n\t\t\t\t======================\n";

        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t\t\t1. NEW ACCOUNT";
        cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
        cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
        cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t\t\t5. MODIFY AN ACCOUNT";
        cout << "\n\t\t\t\t6. EXIT";
        cout << "\n\n\t\t\t\tSelect Your Option (1-6): ";
        cin >> ch;

        switch (ch) {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            display_sp(num);
            break;
        case '5':
            cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
            modify_account(num);
            break;
        case '6':
            cout << "\n\n\t\t\tThank you for using BANK MANAGEMENT SYSTEM";
            break;
        default:
            cout << "\a";
        }
        cin.ignore();
        cin.get();
    } while (ch != '6');
    return 0;
}

void write_account() {
    account ac;
    ofstream outFile;
    outFile.open("account.dat", ios::binary | ios::app);
    ac.create_account();
    outFile.write(reinterpret_cast<char*>(&ac), sizeof(account));
    outFile.close();
    bst.insert(ac); // Insert into BST
}

void display_sp(int n) {
    account* ac = bst.search(n);
    if (ac != NULL) {
        cout << "\n\t\t\tBALANCE DETAILS\n";
        ac->show_account();
    } else {
        cout << "\n\n\t\t\tAccount number does not exist";
    }
}

void modify_account(int n) {
    account* ac = bst.search(n);
    if (ac != NULL) {
        cout << "\n\t\t\tAccount No. : " << ac->retacno();
        ac->show_account();
        cout << "\n\n\t\t\tEnter The New Details of account" << endl;
        ac->modify();
        // Rewrite the file with updated account information
        fstream File;
        File.open("account.dat", ios::binary | ios::in | ios::out);
        while (!File.eof()) {
            account temp;
            int pos = File.tellg();
            File.read(reinterpret_cast<char*>(&temp), sizeof(account));
            if (temp.retacno() == n) {
                File.seekp(pos);
                File.write(reinterpret_cast<char*>(ac), sizeof(account));
                break;
            }
        }
        File.close();
        cout << "\n\n\t\t\tRecord Updated";
    } else {
        cout << "\n\n\t\t\tRecord Not Found";
    }
}

void deposit_withdraw(int n, int option) {
    int amt;
    account* ac = bst.search(n);
    if (ac != NULL) {
        ac->show_account();
        if (option == 1) {
            cout << "\n\n\t\t\tTO DEPOSIT AMOUNT";
            cout << "\n\n\t\t\tEnter The amount to be deposited: ";
            cin >> amt;
            ac->dep(amt);
        } else if (option == 2) {
            cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
            cout << "\n\n\t\t\tEnter The amount to be withdraw: ";
            cin >> amt;
            int bal = ac->retdeposit() - amt;
            if (bal < 0) {
                cout << "Insufficient balance";
            } else {
                ac->draw(amt);
            }
        }
        // Rewrite the file with updated account information
        fstream File;
        File.open("account.dat", ios::binary | ios::in | ios::out);
        while (!File.eof()) {
            account temp;
            int pos = File.tellg();
            File.read(reinterpret_cast<char*>(&temp), sizeof(account));
            if (temp.retacno() == n) {
                File.seekp(pos);
                File.write(reinterpret_cast<char*>(ac), sizeof(account));
                break;
            }
        }
        File.close();
        cout << "\n\n\t\t\tRecord Updated";
    } else {
        cout << "\n\n\t\t\tRecord Not Found";
    }
}
