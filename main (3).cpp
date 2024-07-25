#include<iostream>
#include<vector>
#include<cstdlib>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <ranges>
#include <iterator>
using namespace std;

class User {
protected:
    vector<string> username; //vector to store user ids
    vector<string> password; // vector to store passwords
    vector<long> cardDetail; // store credit card detail
    string adminUserName = "admin1";
    string adminPassword = "pass123";
    int userloggedin;
    string discountcode;
    static int registrations;

public:
    void Register(string a, string b, long c) {
        username.push_back(a);
        password.push_back(b);
        cardDetail.push_back(c);
        registrations++;
    }

    void login() {
        cout << "Admin or User\n";
        string acc;
        cin >> acc;
        string d, e;

        if (acc == "admin" || acc == "Admin") {
            cout << "Enter your username: ";
            cin >> d;
            cout << "Enter your password: ";
            cin >> e;

            if (d == adminUserName && e == adminPassword) {
                cout << "SUCCESS!!" << endl;
                cout << "WELCOME " << d << endl;
            } else {
                throw runtime_error("INVALID ADMIN CREDENTIALS");
            }
        } else if (acc == "student" || acc == "Student") {
            cout << "ALREADY HAVE AN ACCOUNT? ENTER 1\n";
            cout << "TO CREATE ONE ENTER 0\n";
            int a;
            cin >> a;

            if (a == 1) {
                cout << "Enter your username: \n";
                cin >> d;
                cout << "Enter your password: \n";
                cin >> e;

                bool found = false;
                for (int i = 0; i < registrations; i++) {
                    if (username[i] == d) {
                        if (password[i] == e) {
                            cout << "SUCCESS!!" << endl;
                            cout << "WELCOME " << username[i] << endl;
                            found = true;
                            userloggedin = i;
                            break;
                        } else {
                            cout << "WRONG PASSWORD " << endl;
                            found = true;
                            throw runtime_error("INVALID PASSWORD");
                        }
                    }
                }
                if (!found) {
                    throw runtime_error("ACCOUNT NOT FOUND");
                }
            } else if (a == 0) {
                string u, p;
                long ccd;
                cout << "ENTER A USERNAME\n";
                cin >> u;
                cout << "ENTER A PASSWORD\n";
                cin >> p;
                cout << "ENTER YOUR CREDIT CARD NUMBER\n";
                cin >> ccd;

                Register(u, p, ccd);
                cout << "LOG IN NOW\n";
                cout << "Enter your username: \n";
                cin >> d;
                cout << "Enter your password: \n";
                cin >> e;

                bool found = false;
                for (int i = 0; i < registrations; i++) {
                    if (username[i] == d) {
                        if (password[i] == e) {
                            cout << "SUCCESS!!" << endl;
                            cout << "WELCOME " << username[i] << endl;
                            found = true;
                            userloggedin = i;
                            break;
                        } else {
                            cout << "WRONG PASSWORD " << endl;
                            throw runtime_error("INVALID PASSWORD");
                        }
                    }
                }
                if (!found) {
                    throw runtime_error("ACCOUNT NOT FOUND");
                }
            } else {
                throw runtime_error("INVALID INPUT");
            }
        } else {
            throw runtime_error("INVALID INPUT");
        }
    }
};
class Student : public User {
protected:
    struct bookhist{
        vector <string> issued;
        vector<string>bought;
    };
    vector<bookhist> history;
  int index=getuserloggedin();
public:
    ifstream &inputFile() {
        ifstream file("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");
        if (!file.is_open()) {
            throw runtime_error("ERROR :File Not Found!! ");
        }
        return file;
    };

    ofstream &writefile() {
        ofstream file("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");
        if (!file.is_open()) {
            throw runtime_error("ERROR :File Not Found!! ");
        }
        return file;

    }
           string line;
           int bookcount = 0;
            while (getline(inputFile, line)) {
                student.getcost(line);
            }
        };



    void displayHistory()  {
        if (history[index].issued.empty() && history[index].bought.empty()) {
            cout << "No history found for user: " << username[index] << endl;
        } else {
            cout << "History for user: " << username[index] << endl;
            cout << "Issued books:" << endl;
            for (const string& book : history[index].issued) {
                cout << book << endl;
            }
            cout << "Bought books:" << endl;
            for (const string& book : history[index].bought) {
                cout <<          else {
book << endl;
            }
        }
    }
   

 

   

    string getnoofcopies(string line) {
        int wordnumber = 4;
        int spaces = 0;
        int startPos = 0;
        int endPos = 0;

        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') {
                spaces++;
                if (spaces == wordnumber - 1) {
                    startPos = i + 1;
                } else if (spaces == wordnumber) {
                    endPos = i;
                    break;
                }
            }
        }
        cout << (line.substr(startPos, endPos - startPos));
    }

    string getcost(string line) {

        int spaces, endPos, startPos = 0;
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ') {
                spaces++;
                if (spaces == 4) {
                    startPos = i;
                    endPos = line.length();
                    cout << (line.substr(startPos, endPos - startPos));
                }
            }
        }

    };

    string getgenre1(string line) {
        stringstream ss(line);
        vector<string> words;
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        return words[2];
    }

    void findgenre(const string &genre) {
        ifstream &file = inputFile();
        vector<string> filteredLines;
        string line;
        while (getline(file, line)) {
            string currentGenre = getgenre(line);
            if (currentGenre == genre) {
                filteredLines.push_back(line);
            }
        }
        cout << "   Name  " << "  Auth" << "   Gen" << " Copy " << "$ " << '\n';
        for (const auto &value: filteredLines) {
            cout << value << endl;
        }

    };

    void findbyauthor(const string &author) {
        ifstream &file = inputFile();
        vector<string> filteredLinesbyauthor;
        string line;
        while (getline(file, line)) {
            string currentAuthor = getauthor(line);

            if (currentAuthor == author) {
                filteredLinesbyauthor.push_back(line);

            }
        }
        cout << "   Name  " << "  Auth" << "   Gen" << " Copy " << "$ " << '\n';
        for (const auto &value: filteredLinesbyauthor) {
            cout << value << endl;
        }
    };

    void findbyname(const string &name) {
        ifstream &file = inputFile();
        vector<string> filteredLinesbyname;
        string line;
        while (getline(file, line)) {
            string currentname = getname(line);

            if (currentname == name) {
                filteredLinesbyname.push_back(line);

            }
        }
        cout << "   Name  " << "  Auth" << "   Gen" << " Copy " << "$ " << '\n';
        for (const auto &value: filteredLinesbyname) {
            cout << value << endl;
        }
    }

    //string book=cin>>"taimoorbook mustafa love ";
    void issuebook(string book) {
        ifstream inFile;
        string line;
        vector<string> lines;
        string word;
        inFile.open("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");
        if (!inFile.is_open()) {
            cerr << "Error reading file" << endl;
            return;
        }
        while (getline(inFile, line)) {
            vector<string> words;
            stringstream ss(line);
            while (ss >> word) {
                words.push_back(word);
            }
            if ((words[0] == getname(book)) && (words[1] == getauthor(book)) && (words[2] == getgenre1(book))) {
                int copies = stoi(words[3]) - 1;
                if (copies < 0){
                    cerr<<"Out of stock"<<endl;
                    return;
                }
                words[3] = to_string(copies);
            }
            line = words[0] + " " + words[1] + " " + words[2] + " " + words[3] + " " + words[4];
            lines.push_back(line);
        }
        ofstream file("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");

        for (auto line: lines) {
            file << line << endl;
        }
        inFile.close();

    }
    void returnbook(string book){
        ifstream inFile;
        string line;
        vector<string> lines;
        string word;
        inFile.open("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");
        if (!inFile.is_open()) {
            cerr << "Error reading file" << endl;
            return;
        }
        while (getline(inFile, line)) {
            vector<string> words;
            stringstream ss(line);
            while (ss >> word) {
                words.push_back(word);
            }
            if ((words[0] == getname(book)) && (words[1] == getauthor(book)) && (words[2] == getgenre1(book))) {
                int copies = stoi(words[3]) + 1;
                words[3] = to_string(copies);
            }
            line = words[0] + " " + words[1] + " " + words[2] + " " + words[3] + " " + words[4];
            lines.push_back(line);
        }
        ofstream file("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");

        for (auto line: lines) {
            file << line << endl;
        }
        inFile.close();

    }
    void buybook(string book){
        ifstream inFile;
        string line;
        vector<string> lines;
        string word;
        inFile.open("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");
        if (!inFile.is_open()) {
            cerr << "Error reading file" << endl;
            return;
        }
        while (getline(inFile, line)) {
            vector<string> words;
            stringstream ss(line);
            while (ss >> word) {
                words.push_back(word);
            }
            if ((words[0] == getname(book)) && (words[1] == getauthor(book)) && (words[2] == getgenre1(book))) {
                int copies = stoi(words[3]) - 1;
                if (copies < 0){
                    cerr<<"Out of stock"<<endl;
                    return;
                }
                words[3] = to_string(copies);
            }
            line = words[0] + " " + words[1] + " " + words[2] + " " + words[3] + " " + words[4];
            lines.push_back(line);
        }
        ofstream file("C:\\Users\\UnknOwn\\Desktop\\OOPproject.txt");

        for (auto line: lines) {
            file << line << endl;
        }
        inFile.close();
    }
};

int main() {
    User user;
    try {
        user.login();
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
 }
    Student student;

    string book = "taimoorbook mustafa love";
    student.buybook(book);
}
