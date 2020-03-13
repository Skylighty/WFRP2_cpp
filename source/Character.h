#pragma once
#include <map>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Character
{
public:
  map <string, int> Attributes;
  string Race;
  string Clas;
  int WW;
  int US;
  int K;
  int ODP;
  int ZR;
  int INTE;
  int SW;
  int OGD;
  int A;
  int ZYW;
  int S;
  int WT;
  int SZ;
  int MAG;
  int PO;
  int PP;
  int inline k10()
  {
    srand(unsigned int(time(NULL)));
    return rand() % 10 + 1;
  }
  int k100()
  {
    srand(unsigned int(time(NULL)));
    return rand() % 100 + 1;
  }
  int dk10()
  {
    return k10() + k10();
  }
  int DivStat(int s)
  {
    return int(s / 10);
  }
  void HP_Roll()
  {
    int roll = k10();
    if (roll <= 3) ZYW = 10;
    else if (roll >= 4 && roll < 7) ZYW = 11;
    else if (roll >= 7 && roll <= 9) ZYW = 12;
    else ZYW = 13;
    if (Race == "Krasnolud") ZYW++;
    else if (Race == "Elf") ZYW--;
    else if (Race == "Niziolek") ZYW -= 2;
  }
  void PP_Roll()
  {
    int roll = k10();
    if (Race == "Czlowiek")
    {
      if (roll <= 4) PP = 2;
      else PP = 3;
    }
    else if (Race == "Krasnold")
    {
      if (roll <= 4) PP = 1;
      else if (roll > 4 && roll <= 7) PP = 2;
      else PP = 3;
    }
    else if (Race == "Elf")
    {
      if (roll <= 4) PP = 1;
      else PP = 2;
    }
    else
    {
      if (roll <= 7) PP = 2;
      else PP = 3;
    }
  }
  void Speed_Roll()
  {
    if (Race == "Elf") SZ = 5;
    else if (Race == "Krasnolud") SZ = 3;
    else SZ = 4;
  }
  void StatRoll()
  {
    WW = 20+dk10();
    US = 20+dk10();
    K = 20+dk10();
    ODP = 20+dk10();
    ZR = 20+dk10();
    INTE = 20+dk10();
    SW = 20 + dk10();
    OGD = 20 + dk10();
    A = 1;
    MAG = 0;
    PO = 0;
    if (Race == "Elf")
    {
      US += 10;
      ZR += 10;
    }
    else if(Race == "Krasnolud")
    {
      WW += 10;
      ODP += 10;
      OGD -= 10;
      ZR -= 10;
    }
    else if (Race=="Niziolek")
    {
      WW -= 10;
      K -= 10;
      ODP -= 10;
      US += 10;
      ZR += 10;
      OGD += 10;
    }
    S = DivStat(K);
    WT = DivStat(ODP);
  }
  void RaceRoll()
  {
    int roll = k10();
    if (roll <= 3) Race = "Czlowiek";
    else if (roll > 3 && roll <= 5) Race = "Elf";
    else if (roll > 5 && roll <= 8) Race = "Krasnolud";
    else Race = "Niziolek";
  }
  //TODO void ClassRoll(){}
  Character()
  {
    RaceRoll();
    StatRoll();
    HP_Roll();
    PP_Roll();
    Speed_Roll();
    //ClassRoll();
    Attributes.insert(pair<string, int>("WW", WW));
    Attributes.insert(pair<string, int>("US", US));
    Attributes.insert(pair<string, int>("K", K));
    Attributes.insert(pair<string, int>("ODP", ODP));
    Attributes.insert(pair<string, int>("ZR", ZR));
    Attributes.insert(pair<string, int>("INT", INTE));
    Attributes.insert(pair<string, int>("SW", SW));
    Attributes.insert(pair<string, int>("OGD", OGD));
    Attributes.insert(pair<string, int>("A", A));
    Attributes.insert(pair<string, int>("ZYW", ZYW));
    Attributes.insert(pair<string, int>("S", S));
    Attributes.insert(pair<string, int>("WT", WT));
    Attributes.insert(pair<string, int>("SZ", SZ));
    Attributes.insert(pair<string, int>("MAG", MAG));
    Attributes.insert(pair<string, int>("PO", PO));
    Attributes.insert(pair<string, int>("PP", PP));
  }
};


