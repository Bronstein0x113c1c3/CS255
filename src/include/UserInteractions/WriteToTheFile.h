#ifndef WRITETOTHEFILE
#define WRITETOTHEFILE

#include <bits/stdc++.h>
#include "../UserLib/Corporation.h"
#include "../DSA/Queue.h"

// write the president
// wirte the vice presidents
// for each company:
// write director
// write the vice directors
// for each department
// write the manager
// write the deputy managers
// write the employees.
std::string filling(unsigned short a)
{
    if (a < 10)
    {
        return "0" + to_string(a);
    }
    else
    {
        return to_string(a);
    }
}
void writeToTheFile(Corporation *corp, std::string file_path)
{
    ofstream fs(file_path);
    // write the president
    // wirte the vice presidents
    // for each company:
    // write director
    // write the vice directors
    // for each department
    // write the manager
    // write the deputy managers
    // write the employees.
    President *p = corp->getPresident();
    std::string name_of_corp = corp->getName();
    fs << p->getID() << "\t" << p->getLastMidName() + " " + p->getFirstName() << "\t" << name_of_corp << "\t" << p->getPosition() << "\t" << p->getDateOfBirth()->getYear() << "-" << filling(p->getDateOfBirth()->getMonth()) << "-" << filling(p->getDateOfBirth()->getDay()) << "\t" << p->getBirthPlace() << "\t" << p->getEmail() << "\t" << p->getPhoneNum() << "\t" << p->getFirstDayAtWork()->getYear() << "-" << filling(p->getFirstDayAtWork()->getMonth()) << "-" << filling(p->getFirstDayAtWork()->getDay()) << "\t" << endl;
    Queue<VicePresident *> *vp_list_pointer = corp->getPointerofVicePresidentList();
    
    for (auto cur = vp_list_pointer->begin(); cur != vp_list_pointer->end(); ++cur)
    {
        VicePresident *vp = (*cur).getValue();
        fs << vp->getID() << "\t" << vp->getLastMidName() + " " + vp->getFirstName() << "\t" << name_of_corp << "\t" << vp->getPosition() << "\t" << vp->getDateOfBirth()->getYear() << "-" << filling(vp->getDateOfBirth()->getMonth()) << "-" << filling(vp->getDateOfBirth()->getDay()) << "\t" << vp->getBirthPlace() << "\t" << vp->getEmail() << "\t" << vp->getPhoneNum() << "\t" << vp->getFirstDayAtWork()->getYear() << "-" << filling(vp->getFirstDayAtWork()->getMonth()) << "-" << filling(vp->getFirstDayAtWork()->getDay()) << "\t" << endl;
    }
    std::map<std::string, Company *> *pointer_of_company_list = corp->getPointerofCompanyList();

    for (auto cur_company = pointer_of_company_list->begin(); cur_company != pointer_of_company_list->end(); ++cur_company)
    {
        std::string company_name = cur_company->first;
        Company *cp = cur_company->second;
        Director *d = cp->getDirector();
        fs << d->getID() << "\t" << d->getLastMidName() + " " + d->getFirstName() << "\t" << name_of_corp + "->" + company_name << "\t" << d->getPosition() << "\t" << d->getDateOfBirth()->getYear() << "-" << filling(d->getDateOfBirth()->getMonth()) << "-" << filling(d->getDateOfBirth()->getDay()) << "\t" << d->getBirthPlace() << "\t" << d->getEmail() << "\t" << d->getPhoneNum() << "\t" << d->getFirstDayAtWork()->getYear() << "-" << filling(d->getFirstDayAtWork()->getMonth()) << "-" << filling(d->getFirstDayAtWork()->getDay()) << "\t" << endl;
        Queue<ViceDirector *> *vice_director_list_pointer = cp->getPointerOfViceDirector();

        for (auto cur_vice_director = vice_director_list_pointer->begin(); cur_vice_director != vice_director_list_pointer->end(); ++cur_vice_director)
        {
            ViceDirector *vd = (*cur_vice_director).getValue();
            fs << vd->getID() << "\t" << vd->getLastMidName() + " " + vd->getFirstName() << "\t" << name_of_corp + "->" + company_name << "\t" << vd->getPosition() << "\t" << vd->getDateOfBirth()->getYear() << "-" << filling(vd->getDateOfBirth()->getMonth()) << "-" << filling(vd->getDateOfBirth()->getDay()) << "\t" << vd->getBirthPlace() << "\t" << vd->getEmail() << "\t" << vd->getPhoneNum() << "\t" << vd->getFirstDayAtWork()->getYear() << "-" << filling(vd->getFirstDayAtWork()->getMonth()) << "-" << filling(vd->getFirstDayAtWork()->getDay()) << "\t" << endl;
        }
        std::map<std::string, Department *> *pointer_of_department_list = cp->getPointerOfDepartmentList();

        for (auto cur_department = pointer_of_department_list->begin(); cur_department != pointer_of_department_list->end(); ++cur_department)
        {
            std::string department_name = cur_department->first;
            Department *dept = cur_department->second;
            Manager *manager = dept->getManager();
            fs << manager->getID() << "\t" << manager->getLastMidName() + " " + manager->getFirstName() << "\t" << name_of_corp + "->" + company_name + "->" + department_name << "\t" << manager->getPosition() << "\t" << manager->getDateOfBirth()->getYear() << "-" << filling(manager->getDateOfBirth()->getMonth()) << "-" << filling(manager->getDateOfBirth()->getDay()) << "\t" << manager->getBirthPlace() << "\t" << manager->getEmail() << "\t" << manager->getPhoneNum() << "\t" << manager->getFirstDayAtWork()->getYear() << "-" << filling(manager->getFirstDayAtWork()->getMonth()) << "-" << filling(manager->getFirstDayAtWork()->getDay()) << "\t" << endl;
            Queue<DeputyManager *> *pointer_of_deputy_manager_list = dept->getDeputyManagerList();
            for (auto cur_deputy_manager = pointer_of_deputy_manager_list->begin(); cur_deputy_manager != pointer_of_deputy_manager_list->end(); ++cur_deputy_manager)
            {
                DeputyManager *dm = (*cur_deputy_manager).getValue();
                fs << dm->getID() << "\t" << dm->getLastMidName() + " " + dm->getFirstName() << "\t" << name_of_corp + "->" + company_name + "->" + department_name << "\t" << dm->getPosition() << "\t" << dm->getDateOfBirth()->getYear() << "-" << filling(dm->getDateOfBirth()->getMonth()) << "-" << filling(dm->getDateOfBirth()->getDay()) << "\t" << dm->getBirthPlace() << "\t" << dm->getEmail() << "\t" << dm->getPhoneNum() << "\t" << dm->getFirstDayAtWork()->getYear() << "-" << filling(dm->getFirstDayAtWork()->getMonth()) << "-" << filling(dm->getFirstDayAtWork()->getDay()) << "\t" << endl;
            }
            std::map<unsigned short, Employee *> *pointer_of_employee_list = dept->getEmployeeList();
            for (auto cur_employee = pointer_of_employee_list->begin(); cur_employee != pointer_of_employee_list->end(); ++cur_employee)
            {
                Employee *e = cur_employee->second;
                fs << e->getID() << "\t" << e->getLastMidName() + " " + e->getFirstName() << "\t" << name_of_corp + "->" + company_name + "->" + department_name << "\t" << e->getPosition() << "\t" << e->getDateOfBirth()->getYear() << "-" << filling(e->getDateOfBirth()->getMonth()) << "-" << filling(e->getDateOfBirth()->getDay()) << "\t" << e->getBirthPlace() << "\t" << e->getEmail() << "\t" << e->getPhoneNum() << "\t" << e->getFirstDayAtWork()->getYear() << "-" << filling(e->getFirstDayAtWork()->getMonth()) << "-" << filling(e->getFirstDayAtWork()->getDay()) << "\t" << endl;
            }
        }
    }

    fs.close();
}

#endif