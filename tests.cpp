#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"


TEST_CASE("Checks .getusername and .getfullname runs good: "){

  Profile p1("marco", "Marco");

  CHECK(p1.getUsername()== "marco");
  CHECK(p1.getFullName()== "Marco(@marco)");



}

TEST_CASE("Checks adduser function works "){

  Network nw;

  CHECK( nw.addUser("mario", "Mario")== true);
  CHECK(nw.addUser("mario", "Mario2")== false);



}


TEST_CASE("Checks follow function works "){

  Network nw;



  CHECK(nw.follow("mario2", "luigi") == false);



}
