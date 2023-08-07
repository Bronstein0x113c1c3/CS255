#include <SDL2/SDL.h>
#include <UserInteractions/UserInteractions.h>

using namespace std;
string get_string(const string &prompt)
{
    string input;
    cout << prompt;
    cin >> input;
    return input;
};

int main(int argc, char *argv[])
{
    // SDL_Init(SDL_INIT_EVERYTHING);
    // SDL_Quit();
    string file_path;

    cout << "Do you want to load data from a file? (y/n): ";
    cin >> file_path;
    Corporation *corporation;
    Human *human;
    string search_string;
    int ID_to_find;

    if (file_path == "y")
    {
        // Load data from file
        corporation = makeCorporationFromFile("employees.txt");
    }
    else if (file_path == "n")
    {
        // terminal part
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        corporation = makeCorporationFromTerminal();
        addAndUpdateHuman(corporation);
        addDaysWorked(human);
    }
    else
    {
        cout << "Wrong Format!!" << endl;
        return 1;
    }

    int option;
    cout << "--------------------MENU--------------------" << endl;
    cout << "1. Display Corporation Info" << endl;
    cout << "2. Search Human by Name" << endl;
    cout << "3. Search Human by ID" << endl;
    cout << "4. Add and Upate Human" << endl;
    cout << "5. Add Days Work" << endl;
    cout << "Enter your Option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        displayCorporationInfo(corporation);
        break;
    case 2:
    {
        search_string = get_string("Enter the name of the human to search for: ");
        searchByName(corporation, search_string);
    }
    break;
    case 3:
    {
        cout << "Enter the ID of the human to search for: ";
        cin >> ID_to_find;
        searchByID(corporation, ID_to_find);
    }
    break;
    case 4:
        addAndUpdateHuman(corporation);
        break;
    case 5:
        addDaysWorked(human);
        break;
    default:
        cout << "Invalid option!" << endl;
        break;
    }

    exitProgram();

    return 0;
}
