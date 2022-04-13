#include <iostream>
#include "profile.h"
#include <string>
using namespace std;

Profile::Profile(std::string usrn, std::string dspn){
  username=usrn;
  displayname=dspn;
}

Profile::Profile(){

  username=="";
  displayname="";
}
// Return username
std::string Profile::getUsername(){
  return username;
}
std::string Profile::getFullName(){

  std::string s = displayname+ "(@" + username + ")";
  return s;
}

void Profile::setDisplayName(std::string dspn){
  displayname = dspn;
}
