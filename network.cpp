
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
           //The function should return treu
           return true;
       }
       //otherwise do not add the user and return false
       else
       {
           return false;
       }
    }
