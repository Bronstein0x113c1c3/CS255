#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

struct Human {
    int ID;
    string name;
    string company;
    string position;
    string birth;
    string address;
    string mail;
    string phone;
};

vector<Human> readObjectsFromFile(const string& filename, string delimeter) {
    vector<Human> objects;
    ifstream file("filename.txt");

    if (!file.is_open()) {
        cout << "Cannot open the file." << endl;
        return objects;
    }

    string line;
    while (getline(file, line)) {
        // Assuming each line contains all fields separated by commas
        size_t pos1 = 0, pos2, deli_length = delimeter.length();
        pos2 = line.find(';', pos1);
        int ID;
        try {
            ID = stoi(line.substr(pos1, pos2 - pos1));
        } catch (invalid_argument e) {
            // Ignore invalid IDs
            continue;
        }
        //start from pos1, search ';'. After that return new string from position 0 to after ';'
        pos1 = pos2 + deli_length;
        pos2 = line.find(';', pos1);
        string name = line.substr(pos1, pos2 - pos1);

        pos1 = pos2 + deli_length;
        pos2 = line.find(';', pos1);
        string company = line.substr(pos1, pos2 - pos1);

        pos1 = pos2 + deli_length;
        pos2 = line.find(';', pos1);
        string position = line.substr(pos1, pos2 - pos1);

        pos1 = pos2 + deli_length;
        pos2 = line.find(';', pos1);
        string birth = line.substr(pos1, pos2 - pos1);

        pos1 = pos2 + deli_length;
        pos2 = line.find(';', pos1);
        string address = line.substr(pos1, pos2 - pos1);

        pos1 = pos2 + deli_length;
        pos2 = line.find(';', pos1);
        string mail = line.substr(pos1, pos2 - pos1);

        string phone = line.substr(pos1);

        // Create a Person object and add it to the vector
        objects.push_back({ID, name, company, position, birth, address, mail, phone});
    }

    file.close();
    return objects;
}
void writeObjectToFile(const string& filename, const Human& Human) {
    ofstream file(filename, ios::app); // Open the file in append mode

    if (!file.is_open()) {
        cout << "Cannot open the file." << endl;
        return;
    }

    // Write the new person's information to the file
    file << Human.ID << "; " << Human.name << "; " << Human.company << "; " << Human.position << "; "
         << Human.birth << "; " << Human.address << "; " << Human.mail << "; " << Human.phone << "\n";

    file.close();
}
Human createHumanFromInput(const vector<Human>& objects) {
    Human newHuman;
    bool isDuplicate;
    
    do {
        isDuplicate = false;
        cout << "Enter ID: ";
        cin >> newHuman.ID;

        for (const auto& Human : objects) {
            if (Human.ID == newHuman.ID) {
                isDuplicate = true;
                cout << "ID already exists. Please enter a different ID." << endl;
                break;
            }
        }
    } while (isDuplicate);

    cout << "Enter Name: ";
    cin.ignore(); // Ignore the newline character in the input buffer
    getline(cin, newHuman.name);

    cout << "Enter Company: ";
    getline(cin, newHuman.company);

    cout << "Enter Position: ";
    getline(cin, newHuman.position);

    cout << "Enter Birth: ";
    getline(cin, newHuman.birth);

    cout << "Enter Address: ";
    getline(cin, newHuman.address);

    cout << "Enter Mail: ";
    getline(cin, newHuman.mail);

    cout << "Enter Phone: ";
    getline(cin, newHuman.phone);

    return newHuman;
}
void PrintFullData(const vector<Human>& objects){
    cout << "----------FULL DATA----------" << endl;
    for (const auto& Human : objects) {
        cout << "ID: " << Human.ID << endl;
        cout << "Name: " << Human.name << endl;
        cout << "Company: " << Human.company << endl;
        cout << "Position: " << Human.position << endl;
        cout << "Birth: " << Human.birth << endl;
        cout << "Address: " << Human.address << endl;
        cout << "Mail: " << Human.mail << endl;
        cout << "Phone: " << Human.phone << endl;
        cout << "-----------------------------" << endl;
    }
}

int main() {
    const string filename = "filename.txt";
    std::string delimiter = ";"; // the delimiter
    vector<Human> objects = readObjectsFromFile(filename, delimiter);
    //Add New Human to file
    Human newHuman = createHumanFromInput(objects);
    writeObjectToFile(filename, newHuman);
    cout << "New person has been added to the file." << endl;
 
    vector<Human> updatedObjects = readObjectsFromFile(filename, delimiter);
    PrintFullData(updatedObjects);

    return 0;
}
