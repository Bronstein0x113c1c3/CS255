#include <SDL2/SDL.h>
#include <UserInteractions/UserInteractions.h>
#include "src/include/UserInteractions/MakeCorporation.h"

using namespace std;
int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();

    // Time timeStart(0, 30);
    // Time timeEnd(0, 20);
    // Time newTime = timeEnd - timeStart;

    // std::cout << newTime << std::endl;

    // print_hello_world();

    // cout << "sdfsdfewrefdsbfdfsefewfsdgdfvwfeqfsefvdfvb" << endl;

    // // Date d1{"-1/9/2002"};
    // // cout << d1 << endl;
    // // cout<<t.tm_hour<<endl<<t.tm_mon<<endl<<t.tm_wday<<endl<<t.tm_yday<<endl<<t.tm_year;

    // std::string time_str = "20 : 10 ";
    // Time time(time_str);
    // std::cout << time << std::endl;

    // cout << "=================================" << endl;
    // // test the record!
    // string record = "24/02/2016,7:45,12:30";
    // for (char &x : record)
    // {
    //     if (x == ',')
    //     {
    //         x = ' ';
    //     }
    // }
    // // stringstream ss(record);
    // // string day_worked, time_start_work, time_go_home;
    // // ss >> day_worked >> time_start_work >> time_go_home;
    // // cout << day_worked << endl
    // //      << time_start_work << endl
    // //      << time_go_home << endl;

    // // Node<int> *node1 = new Node<int>(10);
    // // Node<int> nodeTemp1(20, node1);
    // // Node<int> nodeTemp2 = nodeTemp1;

    // // nodeTemp1.getNextNode()->setValue(30);
    // // std::cout << nodeTemp2.getNextNode()->getValue() << std::endl;
    // // std::cout << nodeTemp1.getNextNode()->getValue() << std::endl;
    // // std::cout << &nodeTemp1 << std::endl;
    // // std::cout << &nodeTemp2 << std::endl;

    // Queue<int> nums1 = {1, 2, 3, 4, 5, 6};
    // nums1.Enqueue(20);
    // nums1.Enqueue(40);

    // Queue<int> nums2(nums1);
    // // nums1.Clear();
    // // nums2.Clear();
    // std::cout << nums1 << std::endl;
    // // std::cout << nums2 << std::endl;
    // // std::cout << nums1.Dequeue() << std::endl;
    // // std::cout << nums1.Dequeue() << std::endl;
    // // std::cout << nums1.Dequeue() << std::endl;
    // // std::cout << nums1.Dequeue() << std::endl;
    // // std::cout << nums1.Dequeue() << std::endl;
    // // std::cout << nums1.Dequeue() << std::endl;
    // // std::cout << nums1.Dequeue() << std::endl;

    // // for (Queue<int>::Iterator current = nums1.begin(); current != nums1.end(); ++current)
    // // {
    // //     std::cout << *current << std::endl;
    // // }

    // HashMap<std::string, int> name_age_map = {
    //     {"Alex", 10},
    //     {"Helen", 20}};
    // name_age_map["Alex"] = 100;
    // name_age_map["Helen"] = 2000;
    // name_age_map["SadNguyen"] = 9999;

    // int alexAge = name_age_map["Alex"];
    // // std::cout << alexAge << std::endl;
    // // std::cout << name_age_map["Helen"] << std::endl;
    // std::cout << name_age_map << std::endl;

    // Record r1 = Record(Date(14, 04, 2003), Time(15, 24), Time(20, 35));
    // Date d2 = Date(14, 04, 2003);
    // Date d1 = Date(14, 02, 2023);
    // cout << (d2 == d1) << endl;

    // cout<<r1<<endl;
    // Stack<int> numsss1 = Stack<int>(30);
    // Stack<int> numStack1 = Stack<int>{10, 20, 30};
    // numStack1.Push(20);

    // std::cout << numStack1 << std::endl;

    // Date d1(10, 12, 1999);
    // Human hm(10, "Alex","Chicken", "ChickenTail", "ViceDirector", "20/12/2003", "Bach Khoa", "nguyentrungson217@gmail.com","09074113456", "20-10-2003");
    // hm.setFirstDayAtWork(d1);

    // Human hm2 = hm;
    // hm2.setID(30);

    // std::cout << hm2 << std:: endl;
    // std::cout << "-------------------------------" << std::endl;
    // std::cout << hm << std::endl;
    // std::cout << std::boolalpha << validatePhoneNum("090756822") << std::endl;
    // Corporation corp = makeCorporationFromFile("employees.txt");

    // Corporation *corpTerm = makeCorporation();
    // addHuman(corpTerm);
    // std::cout << corpTerm << std::endl;

    // Corporation corporation = Corporation();
    // std::map<std::string, Company> company_list = corporation.getCompanyList();

    // HashMap<std::string, int> name_age_map = HashMap<std::string, int>();
    // name_age_map["Alex"] = 1000;
    // // std::cout << name_age_map["Alex"] << std::endl;
    // HashMap<std::string, int> name_age_map_2(name_age_map);
    // cout << name_age_map_2 << std::endl;


    // Corporation *corporation = makeCorporation();
    // displayCorporationInfo(corporation);

    Corporation* corp = makeCorporation("employees.txt");
    displayHumanInfo(corp, 001);
    
    // std::string name = "Duy Tran Corp";
    // President *president = new President();
    // president->setFirstName("Nguyen");
    // president->setLastMidName("Duy");

    // VicePresident *vice_president = new VicePresident();
    // vice_president->setFirstName("Nguyen");
    // vice_president->setLastMidName("Trung Son");

    // Company *company = new Company();
    // company->setName("Duy Tran Comp");

    // Department *department = new Department();
    // department->setName("Duy Tran Dept");

    // company->addDepartment(department);

    // Corporation *corporation = new Corporation();
    // corporation->setName(name);
    // corporation->setPresident(president);
    // corporation->addVicePresident(vice_president);
    // corporation->addCompany(company);

    // // std::cout << corporation << std::endl;
    // // Stack<Human *> *result = searchByName(corporation, "y");
    // Human* human = searchByID(corporation, 0);

    // std::cout << *human << std::endl;

}

