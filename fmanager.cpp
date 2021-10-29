#include "fmanager.h"

fmanager::fmanager(string DataFile)
{
    for(uint i = 0; m_Data.size() < i; i++)
        for(uint j = 0; m_Data[0].size() < j; j++)
            m_Data[i][j] = "";

    FileName = DataFile;
    ReadData();
}

void fmanager::ReadData()
{
    std::ifstream File;
    string Data;
    File.open("../proyectoFinal/" + FileName, std::ios::in);
    if(File.fail()){
        qDebug() << QString("Archivo no encontrado.");

        File.close();

        std::ofstream Temp;
        Temp.open("../proyectoFinal/" + FileName, std::ios::out);
        Temp << "admin;admin;1;3;0;\n";
        Temp.close();

        File.open("../proyectoFinal/" + FileName, std::ios::in);
        if(File.fail())
            exit(-1);
    }

    uint c = 0, j = 0, k = 0;

    while(!File.eof()){

        getline(File,Data);

        for(uint i = 0; i < Data.length(); i++){

            c = uint(Data[i]);

            if(c == ';'){
                j++;
                continue;
            }

            m_Data[k][j].push_back(char(c));

        }
        k++;
        j = 0;
    }
}

void fmanager::SaveData()
{
    std::ofstream File;
    File.open("../proyectoFinal/" + FileName, std::ios::out);

    for(uint i = 0; m_Data.size() < i || m_Data[i][0] != ""; i++){
        File << m_Data[i][0] + ";" + m_Data[i][1] + ";" + m_Data[i][2] + ";" + m_Data[i][3] + ";" + m_Data[i][4] + ";\n";
    }
}

array<array<string, 5>, 50> fmanager::Data() const{return m_Data;}
void fmanager::setData(const array<array<string, 5>, 50> &Data){m_Data = Data;}

void fmanager::addItem(std::string UserName, std::string UserPass)
{
    uint Free = 0;
    for(uint i = 0; i < m_Data.size(); i++){
        if(m_Data[i][0] == ""){
            Free = i;
            break;
        }
    }

    m_Data[Free][0] = UserName;
    m_Data[Free][1] = UserPass;
    m_Data[Free][2] = "1";
    m_Data[Free][3] = "3";
    m_Data[Free][4] = "0";

    SaveData();
}

void fmanager::changeData(std::string UserName, int lvl, int hp, int pts)
{
    for(uint i = 0; m_Data.size() > i; i++){
        if(m_Data[i][0] == UserName){
            m_Data[i][2] = char(lvl + 48);
            m_Data[i][3] = char(hp + 48);
            m_Data[i][4] = char(pts + 48);
            SaveData();
            return;
        }
    }
}
