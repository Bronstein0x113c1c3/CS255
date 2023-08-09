#include <UserInteractions/UserInteractions.h>

using namespace std;
string get_string(const string &prompt)
{
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
};

void menu(Corporation *corporation)
{
    char option;
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
    case '1':
        // displayCorporationInfo(corporation);
        std::cout << corporation << std::endl;
        break;
    case '2':
    {
        string search_string = get_string("Enter the name of the human to search for: ");
        Stack<Human *> *stack_human = searchByName(corporation, search_string);
        std::cout << *stack_human << std::endl;
        break;
    }
    case '3':
    {
        cout << "Enter the ID of the human to search for: ";

        // STRING TO VALIDATTE
        int ID_to_find = 0;
        string string_ID_to_find = "";
        std::getline(cin, string_ID_to_find);

        // VALIDATE ID
        string_ID_to_find = getValueAfterValidate(string_ID_to_find, validateNum);
        ID_to_find = std::stoi(string_ID_to_find);

        Human *human = searchByID(corporation, ID_to_find);
        cout << human << endl;
        break;
    }
    case '4':
    {
        addAndUpdateHuman(corporation);
        break;
    }
    case '5':
    {
        string ID;
        int id;
        cout << "Enter employees ID: ";
        cin >> ID;
        id = std::stoi(getValueAfterValidate(ID, validateNum));
        Human *human = searchByID(corporation, id);
        if (human != nullptr) {addDaysWorked(human);}
        else {cout << "ID not exist!";};
        break;
    }
    case '6':
    {
        writeToTheFile(corporation, "output.txt");
        cout << "Information Updated!!!" << endl;
        cout << "Thanks for using!" << endl;;
        exitProgram();
        break;
    }
    default:
        cout << "Invalid option!" << endl;
        break;
    }
}

void WrongFormat(string &option){
    cout << "Wrong Format!!!" << endl;
    cout << "Enter again: ";
    getline(cin, option);
}

int main(int argc, char *argv[])
{
    // SDL_Init(SDL_INIT_EVERYTHING);
    // SDL_Quit();

    // FILE PATH
    string filename = "";
    string option;

    // ATTRIBUTES
    Corporation *corporation = nullptr;
    Company *company = nullptr;
    Department *department = nullptr;
    Human *human = nullptr;
    string search_string = "";

    // ASK INPUT 
    cout << "Load corporation from file(1) or create new corporation from terminal(2)? ";
    std::getline(std::cin, option);
    while (!(option == "1" ||option == "2"))
    {
        WrongFormat(option);
    }
    //Do File Path
    if (option == "1")
    {
        //ASK PEOPLE FILE PATH
        cout << "Enter file Path: ";
        std::getline(std::cin, filename);

        //! VAILIDATE FILE PATH
        filename = getValueAfterValidate(filename, validateFileTxt);
         
        // Load data from file
        corporation = makeCorporation(filename);       
    }
    //Do Terminal
    else if (option == "2")
    {
        corporation = makeCorporation();
    }
    do{
        menu(corporation);
    }while(1);

    return 0;
}
