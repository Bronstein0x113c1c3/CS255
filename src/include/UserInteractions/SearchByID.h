#ifndef SEARCHBYID_H
#define SEARCHBYID_H

#include <atomic>
#include <thread>
#include "../UserLib/Human.h"
#include "../UserLib/Corporation.h"

//! SET STOP FLAG
std::atomic<bool> isContinueSearching = true;

//! SET GLOBAL FLAG
Human *human_to_find = nullptr;

bool isIDMatch(const unsigned short human_ID, const unsigned short ID_to_find)
{
    return human_ID == ID_to_find;
}

void searchIDInDepartment(Department *department_to_search, const int ID_to_find)
{
    //? CHECK MANAGER
    Manager *manager = department_to_search->getManager();
    if (manager != nullptr)
    {
        if (isIDMatch(manager->getID(), ID_to_find))
        {
            isContinueSearching = false;
            delete human_to_find;
            human_to_find = manager;
            return;
        }
    }

    //? CHECK DEPUTY MANAGER
    Queue<DeputyManager *> *deputy_manager_list = department_to_search->getDeputyManagerList();
    for (auto iter = deputy_manager_list->begin(); iter != deputy_manager_list->end(); ++iter)
    {
        DeputyManager *deputy_manager = (*iter).getValue();
        if (deputy_manager != nullptr)
        {
            if (isIDMatch(deputy_manager->getID(), ID_to_find))
            {
                isContinueSearching = false;
                delete human_to_find;
                human_to_find = deputy_manager;
                return;
            }
        }
    }

    //? CHECK EMPLOYEE
    std::map<unsigned short, Employee *> *employees_list = department_to_search->getEmployeeList();

    if (employees_list->count(ID_to_find) == 1) // IF EXIST
    {
        isContinueSearching = false;
        delete human_to_find;
        human_to_find = employees_list->at(ID_to_find);
    }
}

void searchIDInCompany(Company *company_to_search, const unsigned short ID_to_find)
{
    //? CHECK DIRECTOR
    Director *director = company_to_search->getDirector();
    if (director != nullptr)
    {
        if (isIDMatch(director->getID(), ID_to_find))
        {
            isContinueSearching = false;
            delete human_to_find;
            human_to_find = director;
            return;
        }
    }

    //? CHECK VICE DIRECTOR
    Queue<ViceDirector *> *vice_director_list = company_to_search->getViceDirectorList();
    for (auto iter = vice_director_list->begin(); iter != vice_director_list->end(); ++iter)
    {
        ViceDirector *vice_director = (*iter).getValue();
        if (vice_director != nullptr)
        {
            if (isIDMatch(vice_director->getID(), ID_to_find))
            {
                isContinueSearching = false;
                delete human_to_find;
                human_to_find = vice_director;
                return;
            }
        }
    }

    //! DIVIDE THREAD BASED ON THE LENGTH OF THE MAP<DEPARTMENT>
    // TO GROUP ALL THE COMPANY THREAD
    std::queue<std::thread> all_department_thread;

    std::map<std::string, Department *> *department_list = company_to_search->getDepartmentList();

    for (auto iter = department_list->begin(); iter != department_list->end(); ++iter)
    {
        //? RUN MULTITHREADING IN EACH DEPARTMENT
        if (isContinueSearching) //? IF STILL DIDN'T FIND THAT VALUE -> CONTINUE SEARCHING
        {
            all_department_thread.push(std::thread(searchIDInDepartment, iter->second, ID_to_find));
        }
    }

    //! JOIN ALL THE THREAD BEFORE RETURN
    while (!all_department_thread.empty())
    {
        all_department_thread.front().join();
        all_department_thread.pop();
    }
}

Human *searchByID(Corporation *corporation, const int ID_to_find)
{
    //? CHECK PRESIDENT
    President *president = corporation->getPresident();
    if (president != nullptr)
    {
        if (isIDMatch(president->getID(), ID_to_find))
        {
            isContinueSearching = false;
            delete human_to_find;
            human_to_find = president;
            return human_to_find;
        }
    }

    //? CHECK VICE PRESIDENT
    Queue<VicePresident *> *vice_president_list = corporation->getPointerofVicePresidentList();
    for (auto current = vice_president_list->begin(); current != vice_president_list->end(); ++current)
    {
        VicePresident *vice_president = (*current).getValue();
        if (vice_president != nullptr)
        {
            if (isIDMatch(vice_president->getID(), ID_to_find))
            {
                isContinueSearching = false;
                delete human_to_find;
                human_to_find = vice_president;
                return human_to_find;
            }
        }
    }

    //! DIVIDE THREAD BASED ON THE LENGTH OF THE MAP<COMPANY>
    std::queue<std::thread> all_company_thread;

    std::map<std::string, Company *> *company_list = corporation->getPointerofCompanyList();

    for (auto iter = company_list->begin(); iter != company_list->end(); ++iter)
    {
        if (isContinueSearching) //? IF STILL DIDN'T FIND THAT VALUE -> CONTINUE SEARCHING
        {
            //? RUN MULTITHREADING IN EACH COMPANY
            all_company_thread.push(std::thread(searchIDInCompany, iter->second, ID_to_find));
        }
    }

    //! JOIN ALL THE THREAD BEFORE RETURN
    while (!all_company_thread.empty())
    {
        all_company_thread.front().join();
        all_company_thread.pop();
    }

    //! RETURN THE SEARCH BASKET
    return human_to_find;
}

#endif