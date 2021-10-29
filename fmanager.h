#ifndef FMANAGER_H
#define FMANAGER_H

#include <fstream>
#include <array>

#include "string.h"
#include "utilidades.h"

using std::array;

class fmanager
{
public:
    fmanager(string DataFile = "Data.txt");

    void ReadData();
    void SaveData();

    array<array<string, 5>, 50> Data() const;
    void setData(const array<array<string, 5>, 50> &Data);
    void addItem(string UserName, string UserPass);
    void changeData(string UserName, int lvl, int hp, int pts);

private:
    array<array<string, 5>, 50> m_Data;
    string FileName;

};

#endif // FMANAGER_H
