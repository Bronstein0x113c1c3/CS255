#include <SDL2/SDL.h>
#include <mysql.h>
#include <UserInteractions/UserInteractions.h>
#include <stdlib.h>
#include <stdio.h>
#include <SQL_Utilities/Connection.h>
#include <SQL_Utilities/Command.h>



using namespace std;

void menu(Corporation *corporation)
{
    int option;
    cout << "--------------------MENU--------------------" << endl;
    cout << "1. Display Corporation Info" << endl;
    cout << "2. Search Human by Name" << endl;
    cout << "3. Search Human by ID" << endl;
    cout << "4. Add and Upate Human by ID" << endl;
    cout << "5. Add Days Work by ID" << endl;
    cout << "6. Delete Human by ID" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your Option: ";
    cin >> option;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (option)
    {
    case 1:
        std::cout << corporation << std::endl;
        break;
    case 2:
    {
        std::string search_string = "";
        // ASK USER INPUT
        std::cout << "Enter the name of the human to search for: ";
        std::getline(std::cin, search_string);

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

        // VALIDATE ID
        string_ID_to_find = getValueAfterValidate(string_ID_to_find, validateNum);
        ID_to_find = std::stoi(string_ID_to_find);

        Human *human = searchByID(corporation, ID_to_find);
        cout << human << endl;

        //! TO RESET SEARCHING
        isContinueSearching = true;
        human_to_find = nullptr;
        break;
    }
    case 4:
    {
        addAndUpdateHuman(corporation);
        break;
    }
    case 5:
    {
        string ID;
        int id;
        cout << "Enter employees ID: ";
        cin >> ID;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        id = std::stoi(getValueAfterValidate(ID, validateNum));
        Human *human = searchByID(corporation, id);
        if (human != nullptr)
        {
            addDaysWorked(human);

            //! TO RESET SEARCHING
            isContinueSearching = true;
            human_to_find = nullptr;
        }
        else
        {
            cout << "ID not exist!";
        };
        break;
    }
    case 6:
    {
        string string_ID = "";
        int ID = 0;
        cout << "Enter employees ID: ";
        cin >> string_ID;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //! VALIDATE VALUE
        string_ID = getValueAfterValidate(string_ID, validateNum);
        ID = std::stoi(string_ID);

        Human *human = searchByID(corporation, ID);
        if (human != nullptr)
        {
            deleteHuman(corporation, human);

            //! TO RESET SEARCHING
            isContinueSearching = true;
            human_to_find = nullptr;

            //! TO RESET DELETING
            isContinueDeleting = true;
        }
        else
        {
            cout << "ID not exist!";
        };
        break;
    }
    case 7:
    {
        writeToTheFile(corporation, "output.txt");
        cout << "Information Updated!!!" << endl;
        cout << "Thanks for using!" << endl;

        // TO CLEAN UP MEMORY
        delete corporation;
        exitProgram();
        break;
    }
    default:
        cout << "Invalid option!" << endl;
        break;
    }
}
bool validate_file_name(std::string name)
{
    ifstream fs;
    fs.open(name);
    if (fs)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    // SDL_Init(SDL_INIT_EVERYTHING);
    // SDL_Quit();

    //! STEP 1: CONNECT TO MYSQL using C
    //* STEP 2: LOAD txt OR LOAD DATABASE

    //? LOAD DATABASE:
    // PUll data from MySQL -> Program -> CREATE OBJ

    //? ADD AND UPDATE HUMAN
    // Change from Terminal -> Approve -> MYSQL database (employee)

    //? DELETE HUMAN
    // Change from Terminal -> Approve -> MySQL database (employee)

    //? ADD DAYS WORK
    // Change from Terminal -> Approve -> MySQL database (record)

    //? SOME SPECIAL METHODS
    // USE QUERIES in MySQL

    //? BEFORE END
    // Write to employee.txt
    // mysql_close(connection)

    // OLD PATH
    //--------------------------------------------------------------------
    // FILE PATH
    string filename = "";
    int option;

    // ATTRIBUTES
    Corporation *corporation = nullptr;

    // ASK INPUT
    cout << "Load corporation from file(1) or create new corporation from terminal(2)? ";
    std::cin >> option;
    while (!(option == 1 || option == 2))
    {
        std::cout << "Enter the option again!!!!!!" << endl;
        std::cin >> option;
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Do File Path
    if (option == 1)
    {
        // ASK PEOPLE FILE PATH
        cout << "Enter file Path: ";
        std::cin >> filename;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (!validate_file_name(filename))
        {
            cout << "Enter file Path Again: ";
            std::getline(std::cin, filename);
        }
        //! VAILIDATE FILE PATH
        filename = getValueAfterValidate(filename, validateFileTxt);

        delete corporation; //! PREVENT MEMORY LEAK
        // Load data from file
        corporation = makeCorporation(filename);
    }
    // Do Terminal
    else if (option == 2)
    {
        delete corporation; //! PREVENT MEMORY LEAK
        corporation = makeCorporation();
    }
    do
    {
        menu(corporation);
    } while (true);

    // Human *human = new Human(1, "Sad", "Nguyen", "Ha Tay", "Manager", "21/02/2003", "Trang Tien", "nguyen@gmai.com", "0903486634", "21/10/2023");
    // MYSQL *conn = init();
    // char corporation[] = "corporation";
    // MYSQL *initialized_conn = connectToDB(conn, HOST, USER, PASS, corporation, PORT);

    // char employee[] = "employee";
    // // deleteHumanFromMySQL(conn, "employee", "record", 3);
    // addHumanToMySQL(conn, "employee", human);
    // Date* date1 = new Date("21/07/2003");
    // Time* time1 = new Time("12:20");
    // Time* time2 = new Time("13:30");
    // Record* record1 = new Record(date1, time1, time2);
    // addRecordToMySQL(conn, "record", 1, record1);
    return 0;
}
