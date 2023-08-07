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

void menu(Corporation *corporation, Human *human, string search_string)
{
    int option;
    cout << "--------------------MENU--------------------" << endl;
    cout << "1. Display Corporation Info" << endl;
    cout << "2. Search Human by Name" << endl;
    cout << "3. Search Human by ID" << endl;
    cout << "4. Add and Upate Human" << endl;
    cout << "5. Add Days Work" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your Option: ";
    cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option)
    {
    case 1:
        // displayCorporationInfo(corporation);
        std::cout << corporation << std::endl;
        break;
    case 2:
    {
        search_string = get_string("Enter the name of the human to search for: ");
        Stack<Human *> *stack_human = searchByName(corporation, search_string);
        std::cout << *stack_human << std::endl;
        break;
    }
    case 3:
    {
        cout << "Enter the ID of the human to search for: ";

        // STRING TO VALIDATTE
        int ID_to_find = 0;
        string string_ID_to_find = "";
        std::getline(cin, string_ID_to_find);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // VALIDATE ID
        string_ID_to_find = getValueAfterValidate(string_ID_to_find, validateNum);
        ID_to_find = std::stoi(string_ID_to_find);

        Human *human = searchByID(corporation, ID_to_find);
        cout << human << endl;
        break;
    }
    case 4:
    {
        addAndUpdateHuman(corporation);
        break;
    }
    case 5:
    {
        addDaysWorked(human);
        break;
    }
    case 6:
    {
        cout << "Thanks for using!";
        exitProgram();
        break;
    }
    default:
        cout << "Invalid option!" << endl;
        break;
    }
}

int main(int argc, char *argv[])
{
    // SDL_Init(SDL_INIT_EVERYTHING);
    // SDL_Quit();

    // FILE PATH
    string isFile = "";
    string filename = "";

    // ATTRIBUTES
    Corporation *corporation = nullptr;
    Company *company = nullptr;
    Department *department = nullptr;
    Human *human = nullptr;
    string search_string = "";

    // ASK INPUT 
    cout << "Do you want to load data from a file? (y/n): ";
    std::getline(std::cin, isFile);

    while (!(isFile == "y" || isFile == "n"))
    {
        cout << "Wrong Format!!" << endl;
        cout << "Enter again(y/n): ";
        getline(cin, isFile);
    }
    
    if (isFile == "y")
    {
        //ASK PEOPLE FILE PATH
        cout << "File Path: ";
        cin >> filename;
        std::getline(std::cin, isFile);

        //! VAILIDATE FILE PATH
        filename = getValueAfterValidate(filename, validateFileTxt);
         
        // Load data from file
        corporation = makeCorporation(filename);
    }
    else if (isFile == "n")
    {
        corporation = makeCorporation();
        addAndUpdateHuman(corporation);
        addDaysWorked(human);
    }
    do{
        menu(corporation, human, search_string);
        cout << "Run again(y/n): " ;
        getline(cin, isFile);
        if (isFile == "n")
            {
                cout << "Thanks for using!";
                return 0;
            }
        else if (!(isFile == "y" || isFile == "n"))
            {
                cout << "Invalid Format!!!" << endl;
                cout << "Enter again(y/n): ";
                getline(cin, isFile);
            }
    }while(isFile == "y");

    return 0;
}
