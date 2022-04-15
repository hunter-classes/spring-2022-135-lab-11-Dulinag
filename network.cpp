
#include <iostream>
#include "profile.h"
#include "network.h"
#include <string>
#include <cctype>

int Network::findID(std::string usrn){
  for (int j = 0; j <= numUsers; j++){

    if (profiles[j].getUsername() == usrn){

      return j;
    }
  }
  return -1;
}

Network::Network(){

  numUsers = 0;
}

bool Network::addUser(std::string usrn, std::string dspn){

  if (numUsers < Network::MAX_USERS && Network::findID(usrn) == -1)
  {

      for (int i = 0; i < usrn.length(); i++)
      {

          if (!isdigit(usrn[i]) && !isalpha(usrn[i]))
          {
              return false;
          }
        }

        Profile pFinal(usrn, dspn);
           profiles[numUsers] = pFinal;
           numUsers++;

           return true;
       }

       else
       {
           return false;
       }
     }




 bool Network::follow(std::string usrn1, std::string usrn2){
/*
ALternate way
if((findID(usrn1) != -1) && (findID(usrn2) != -1)){
  int x = findID(usrn1);
  int y = findID(usrn2);
  following[x][y] = true;

  return true;
}

  return false;
}
*/


    for (int i = 0; i < numUsers; i++){

   if (profiles[i].getUsername().compare(usrn1))
   {

       for (int jack = 0; jack < numUsers; jack++)
       {

            if (profiles[jack].getUsername().compare(usrn2))
           {
               following[i][jack] = true;
               return true;
           }
         }
       }
       }
       return false;
     }



void Network::printDot()
{
  std::cout << "digraph {" << std::endl;
  for (int i = 0; i < numUsers; i++)
  {
   std::cout << "\"@" << profiles[i].getUsername() << '*' << std::endl;
  }
  std::cout << std::endl;

  for (int v = 0; v < numUsers; v++)
  {
   for (int c = 0; c < numUsers; c++)
   {
    if (following[v][c] == true)
    {
     std::cout << "\"@" << profiles[v].getUsername() << "\" -> \"@" << profiles[c].getUsername() << "\"" << std::endl;
    }
   }
  }

  std::cout << std::endl;
  std::cout << "}";
}
