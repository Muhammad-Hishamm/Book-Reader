#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define TEKA ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

class the_book {
private:
    string book_name, book_author;
public:

    the_book() {} // default constructor
    the_book(string name, string book_author) : book_name(name),
                                                book_author(book_author) {
        cout << "Book is created\n";
    }

    string get_book_name() {
        return this->book_name;
    }
};

class customer {
private:
    //int id;
    string password, name;
    bool login_status, signUp_status;
    vector<string> list;
public:
    customer() : login_status(0), signUp_status(0) { list.clear(); } // default constructor Using initailizer List

    void signUp() { // This fn. enteres the user;
        cout << "signUp:\n";
        cout << "Enter Your name:\n";
        cin >> name;
        cout << "Enter a password :\n";
        cin >> this->password;
        cout << "Enter pass again to Confirm your password\n";
        while (true) {
            string temp_pass;
            cin >> temp_pass;
            if (temp_pass == this->password) break;
            cout << "Passwords don't match , enter it again\n";
        }
        cout << "Welcome To The online book reader\n";
        login_status = signUp_status = 1;
    }

    bool CheckLoginOrNot() {
        return login_status;
    }

    void login() {
        if(login_status)return;
        if (!signUp_status) {
            cout << "You must SignUp first\n";
            signUp();
            return;
        }
        cout << "Login:\n";
        string name2 = "", pass2 = "";
        while (true) {
            cout << "Enter Your name:\n";
            cin >> name2;
            cout << "Enter a password :\n";
            cin >> pass2;
            if (pass2 == this->password && name2 == this->name) break;
            cout << "Name or Password is not valid , please try again\n";
        }

        cout << "Welcome To The online book reader\n";
        login_status = 1;
    }

    void logOut() {
        cout << "now,You are logged out\n";
        login_status = 0;
    }

    void CheckBook() {}

    /* void viewProfile() {}   TO BE IMPLMENTED */
    void startToRead(string book_name) { // For choosing a book
        list.push_back(book_name);
    }

    void viewReadingList() {
        cout << "Your Reading List :\n";
        for (auto book: this->list) {
            cout << book << " ";
        }
    }


};


class admin {
public:
    bool isAdmin() {

        cout << "Enter the Admin code please\n";
        string entryCode;
        cin >> entryCode;
        if(entryCode!="1212ad")cout<<entryCode<<"\n"<<"the admin entry code isn't correct\n ";
        return entryCode == "1212ad";
    }

    map<int, the_book> mp; // put a static to the object
    void add_book(string name, string book_author) {
        int generated_id = mp.size() + 1;
        the_book bo(name, book_author);
        mp[generated_id] = bo; //
        cout << "Your book is added Successfully and its id = " << generated_id << "\n";
    }

    void remove_book(int id) {
        cout << "so, You want to remove specific book\n";
        while (true) {
            if (isAdmin()) {
                if (mp.count(id) != 0) {
                    mp.erase(id);
                    cout << "Your book is Deleted Successfully\n";
                } else {
                    cout << "There's no book with this id\n";
                }
                break;
            }
            cout << "are you an admin ?,Please Try again\n";
        }
    }

    void viewAllBooks() {
        for (auto i: mp) {
            cout << i.first << " " << i.second.get_book_name() << "\n";
        }
    }
};

string  ask() {
    cout << "choose admin or customer or exit?\n";
    string ans;
    cin >> ans;
    return ans;
}
int main() {
    admin ad;
    customer cu;
    while (1) {
        string ans=ask();
        while (ans == "admin") {
            if(!ad.isAdmin())break;
            cout << "choose a number from :\n 1-add book \n 2-remove book\n 3-view All Books\n 4-back\n";
            int a;
            cin >> a;
            if (a == 1 ) {
                string name, author;
                const int N=1000;
                cout << "enter the book name\n";
                cin.ignore();
                getline(cin,name,'\n');
                cout << "enter the book author\n";
                cin.ignore();
                getline(cin, author,'\n');
                ad.add_book(name, author);
            } else if (a == 2 ) {
                int id;
                cout << "Enter the book id to remove it\n";
                cin >> id;
                ad.remove_book(id);
            } else if (a == 3 ) {
                ad.viewAllBooks();
            } else
                break;
        }


        while (ans == "customer") {

            cu.login();
            cout << "Choose one of these options\n";
            int num;
            cout << "1-view my reading list \n 2-start reading\n 3-view All Books\n 4-exit\n";
            cin >> num;
            if (num == 1) {
                cu.viewReadingList();
            } else if (num == 2) {
                cout << "Choose book from the current list:\n";
                ad.viewAllBooks();
                cout << "-------------------------------------\n";
                string name;
                cout << "Enter the bookName\n";
                cin >> name;
                cu.startToRead(name);
            } else if (num == 3) {
                ad.viewAllBooks();
            }else  break;
        }
        if (ans == "Exit"||ans =="exit")break;

    }


}



