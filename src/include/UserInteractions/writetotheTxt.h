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
void writetotheFile(Corporation *corp, std::string file_path)
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
    fs << p->getID() << "; " << p->getLastMidName() + " " + p->getFirstName() << "; " << name_of_corp << "; " << p->getPosition() << "; " << p->getDateOfBirth() << "; " << p->getBirthPlace() << "; " << p->getEmail() << "; " << p->getPhoneNum() << "; " << p->getFirstDayAtWork() << "; " << endl;
    Queue<VicePresident *> *vp_list_pointer = corp->getPointerofVicePresidentList();
    for (auto cur = vp_list_pointer->begin(); cur != vp_list_pointer->end(); ++cur)
    {
        VicePresident *vp = (*cur).getValue();
        fs << vp->getID() << "; " << vp->getLastMidName() + " " + vp->getFirstName() << "; " << name_of_corp << "; " << vp->getPosition() << "; " << vp->getDateOfBirth() << "; " << vp->getBirthPlace() << "; " << vp->getEmail() << "; " << vp->getPhoneNum() << "; " << vp->getFirstDayAtWork() << "; " << endl;
    }
    std::map<std::string, Company *> *pointer_of_company_list = corp->getPointerofCompanyList();
    for (auto cur_company = pointer_of_company_list->begin(); cur_company != pointer_of_company_list->end(); ++cur_company)
    {
        std::string company_name = cur_company->first;
        Company *cp = cur_company->second;
        Director *d = cp->getDirector();
        fs << d->getID() << "; " << d->getLastMidName() + " " + d->getFirstName() << "; " << name_of_corp + "->" + company_name << "; " << d->getPosition() << "; " << d->getDateOfBirth() << "; " << d->getBirthPlace() << "; " << d->getEmail() << "; " << d->getPhoneNum() << "; " << d->getFirstDayAtWork() << "; " << endl;
        Queue<ViceDirector *> *vice_director_list_pointer = cp->getPointerOfViceDirector();
        for (auto cur_vice_director = vice_director_list_pointer->begin(); cur_vice_director != vice_director_list_pointer->end(); ++cur_vice_director)
        {
            ViceDirector *vd = (*cur_vice_director).getValue();
            fs << vd->getID() << "; " << vd->getLastMidName() + " " + vd->getFirstName() << "; " << name_of_corp + "->" + company_name << "; " << vd->getPosition() << "; " << vd->getDateOfBirth() << "; " << vd->getBirthPlace() << "; " << vd->getEmail() << "; " << vd->getPhoneNum() << "; " << vd->getFirstDayAtWork() << "; " << endl;
        }
        std::map<std::string, Department *> *pointer_of_department_list = cp->getPointerOfDepartmentList();
        for (auto cur_department = pointer_of_department_list->begin(); cur_department != pointer_of_department_list->end(); ++cur_department)
        {
            std::string department_name = cur_department->first;
            Department *dept = cur_department->second;
            Manager *manager = dept->getManager();
            fs << manager->getID() << "; " << manager->getLastMidName() + " " + manager->getFirstName() << "; " << name_of_corp + "->" + company_name + "->" + department_name << "; " << manager->getPosition() << "; " << manager->getDateOfBirth() << "; " << manager->getBirthPlace() << "; " << manager->getEmail() << "; " << manager->getPhoneNum() << "; " << manager->getFirstDayAtWork() << "; " << endl;
            Queue<DeputyManager *> *pointer_of_deputy_manager_list = dept->getDeputyManagerList();
            for (auto cur_deputy_manager = pointer_of_deputy_manager_list->begin(); cur_deputy_manager != pointer_of_deputy_manager_list->end(); ++cur_deputy_manager)
            {
                DeputyManager *dm = (*cur_deputy_manager).getValue();
                fs << dm->getID() << "; " << dm->getLastMidName() + " " + dm->getFirstName() << "; " << name_of_corp + "->" + company_name + "->" + department_name << "; " << dm->getPosition() << "; " << dm->getDateOfBirth() << "; " << dm->getBirthPlace() << "; " << dm->getEmail() << "; " << dm->getPhoneNum() << "; " << dm->getFirstDayAtWork() << "; " << endl;
            }
            std::map<unsigned short, Employee *> *pointer_of_employee_list = dept->getEmployeeList();
            for (auto cur_employee = pointer_of_employee_list->begin(); cur_employee != pointer_of_employee_list->end(); ++cur_employee)
            {
                Employee *e = cur_employee->second;
                fs << e->getID() << "; " << e->getLastMidName() + " " + e->getFirstName() << "; " << name_of_corp + "->" + company_name + "->" + department_name << "; " << e->getPosition() << "; " << e->getDateOfBirth() << "; " << e->getBirthPlace() << "; " << e->getEmail() << "; " << e->getPhoneNum() << "; " << e->getFirstDayAtWork() << "; " << endl;
            }
        }
    }

    fs.close();
}
