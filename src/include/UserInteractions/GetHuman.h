#ifndef GETHUMAN_H
#define GETHUMAN_H

#include "../UserLib/Human.h"
#include "../UserLib/Corporation.h"

Human getHumanFromFile(const Corporation &corporation, const std::string file_path);
Human getHumanFromTerminal(const Corporation &corporation);

Human getHumanFromFile(const Corporation &corporation, const std::string file_path)
{

}

Human getHumanFromTerminal(const Corporation &corporation)
{
    //* HUMAN ATTRIBUTES
    int ID;
    std::string name;
    std::string work_place;
    std::string position;
    std::string date_of_birth;
    std::string birth_place;
    std::string email;
    std::string phone_num;
    std::string first_day_at_work;

    //* GET INPUT
    cout << "Nhap ID:";
    cin >> ID;

    cout << "Nhap ho va ten";
    cin >> name;
}

#endif