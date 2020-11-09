#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "operation.h"
#include "gtest/gtest.h"


namespace

{

class hosp_test : public ::testing::Test
 {

protected:
  void SetUp()
  {

std::fstream fin;
fin.open("hospital.csv");
std::vector<std::string> row;

std::string line, word;

 while(!fin.eof())
{
    row.clear();
    getline(fin,line);

    std::stringstream s(line);

    while(getline(s,word,','))
    {
        row.push_back(word);
    }


   string id,name,address,city,state,zipcode,country,phno,hosp_type,hosp_ownership;
   id=row[0];
   name=row[1];
   address=row[2];
   city=row[3];
   state=row[4];
   zipcode=row[5];
   country=row[6];
   phno=row[7];
   hosp_type=row[8];
   hosp_ownership=row[9];

 //operation dummy;

    dummy.add_hospital(id,name,address,city,state,zipcode,country,phno,hosp_type,hosp_ownership);


}

  }
void TearDown() {}

  operation dummy;

};


TEST_F(hosp_test, getdetails ) {
 // EXPECT_NE((Trip*)NULL, trips.findTripById("SG304"));
 	base ft("10005","ST ANTHONY NORTH HEALTH CAMPUS","14300 ORCHARD PARKWAY","WESTMINSTER","CO","80023","BROOMFIELD","3034303201");
 // Trip *pt = &ft;
 	  EXPECT_STREQ("10005", ft.get_id().c_str());
 	   EXPECT_STREQ("ST ANTHONY NORTH HEALTH CAMPUS", ft.get_name().c_str());
 	    EXPECT_STREQ("14300 ORCHARD PARKWAY", ft.get_address().c_str());
 	     EXPECT_STREQ("WESTMINSTER", ft.get_city().c_str());
 	      EXPECT_STREQ("CO", ft.get_state().c_str());
 	       EXPECT_STREQ("80023", ft.get_zipcode().c_str());
 	        EXPECT_STREQ("BROOMFIELD", ft.get_country().c_str());
 	         EXPECT_STREQ("3034303201", ft.get_phno().c_str());
 	    
 
  }
  

TEST_F(hosp_test,Addhospital)
{
      // dummy.remove_patient(1);
    EXPECT_EQ(24,dummy.Number_of_hospitals());
}




TEST_F(hosp_test,removehospital)
{
    dummy.remove_hospital("10032");
    EXPECT_EQ(23,dummy.Number_of_hospitals());
}
}
