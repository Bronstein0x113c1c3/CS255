#ifndef SEARCHBYNAME_H
#define SEARCHBYNAME_H

#include <queue>
#include <thread>
#include "../DSA/Stack.h"
#include "../UserLib/Corporation.h"
#include "../UserLib/Human.h"

bool isNameMatch(std::string name, std::string search_string)
{
    size_t found = name.find(search_string);
    return found != std::string::npos;
}

void searchNameInDepartment(Department *department_to_search, Stack<Human> *search_basket, std::string search_string)
{
    // CHECK MANAGER
    Manager manager = department_to_search->getManager();
    if (isNameMatch(manager.getFullName(), search_string))
    {
        search_basket->Push(manager);
    }

    // CHECK DEPUTY MANAGER
    Queue<DeputyManager *> deputy_manager_list = department_to_search->getDeputyManagerList();
    for (auto iter = deputy_manager_list.begin(); iter != deputy_manager_list.end(); ++iter)
    {
        DeputyManager *deputy_manager = (*iter).getValue();
        if (isNameMatch(deputy_manager->getFullName(), search_string))
        {
            search_basket->Push(*deputy_manager);
        }
    }

    // CHECK EMPLOYEE
    std::map<int, Employee *> employees_list = department_to_search->getEmployeeList();
    std::map<int, Employee *>::const_iterator iter;

    for (iter = employees_list.begin(); iter != employees_list.end(); ++iter)
    {
        Employee *employee_to_search = iter->second;

        // CHECKING EACH EMPLOYEE
        if (isNameMatch(employee_to_search->getFullName(), search_string))
        {
            search_basket->Push(*employee_to_search);
        }
    }
}

void searchNameInCompany(Company *company_to_search, Stack<Human> *search_basket, std::string search_string)
{
    // CHECK DIRECTOR
    Director director = company_to_search->getDirector();
    if (isNameMatch(director.getFullName(), search_string))
        ;
    {
        search_basket->Push(director);
    }

    // CHECK VICE DIRECTOR
    Queue<ViceDirector *> vice_director_list = company_to_search->getViceDirectorList();
    for (auto iter = vice_director_list.begin(); iter != vice_director_list.end(); ++iter)
    {
        ViceDirector *vice_director = (*iter).getValue();
        if (isNameMatch(vice_director->getFullName(), search_string))
        {
            search_basket->Push(*vice_director);
        }
    }

    //! DIVIDE THREAD BASED ON THE LENGTH OF THE MAP<DEPARTMENT>
    // TO GROUP ALL THE COMPANY THREAD
    std::vector<std::thread> all_department_thread;

    std::map<std::string, Department *> department_list = company_to_search->getDepartmentList();
    std::map<std::string, Department *>::const_iterator iter;

    for (iter = department_list.begin(); iter != department_list.end(); ++iter)
    {
        Department *company_to_search = iter->second;

        //? RUN MULTITHREADING IN EACH DEPARTMENT
        all_department_thread.push_back(std::thread (searchNameInDepartment, iter->second, search_basket, search_string));
    }

    //! JOIN ALL THE THREAD BEFORE RETURN
    for (auto iter = all_department_thread.begin(); iter != all_department_thread.end(); ++iter)
    {
        iter->join();
    }
}

Stack<Human> *searchByName(Corporation *corporation, const std::string search_string)
{
    //! INSTANTIATE MAIN THREAD as the FUNCTION to search CORPORATION
    Stack<Human> *search_basket = new Stack<Human>();

    //? CHECK PRESIDENT
    President president = corporation->getPresident();
    if (isNameMatch(president.getFullName(), search_string))
    {
        search_basket->Push(president);
    }

    //? CHECK VICE PRESIDENT
    Queue<VicePresident *> vice_president_list = corporation->getVicePresidentList();
    for (auto current = vice_president_list.begin(); current != vice_president_list.end(); ++current)
    {
        VicePresident *vice_president = (*current).getValue();
        if (isNameMatch(vice_president->getFullName(), search_string))
        {
            search_basket->Push(*vice_president);
        }
    }

    //! DIVIDE THREAD BASED ON THE LENGTH OF THE MAP<COMPANY>
    std::vector<std::thread> all_company_thread;

    std::map<std::string, Company *> company_list = corporation->getCompanyList();
    std::map<std::string, Company *>::const_iterator iter;

    for (iter = company_list.begin(); iter != company_list.end(); ++iter)
    {
        Company *company_to_search = iter->second;

        //? RUN MULTITHREADING IN EACH COMPANY
        all_company_thread.push_back(std::thread (searchNameInCompany, iter->second, search_basket, search_string));
    }

    //! JOIN ALL THE THREAD BEFORE RETURN
    for (auto iter = all_company_thread.begin(); iter != all_company_thread.end(); ++iter)
    {
        iter->join();
    }

    //! RETURN THE SEARCH BASKET
    return search_basket;
}

#endif