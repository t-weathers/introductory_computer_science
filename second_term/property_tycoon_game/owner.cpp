#include <string>

#include "owner.h"
#include "house.h"
#include "aptcomplex.h"
#include "businesscomplex.h"
#include "property.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
//#include "main.cpp"

using namespace std;

/****************************************
function name:is_int
Description: can tell if the string input is an integer
parameters: string a
*****************************************/
bool Owner::is_int(string a){
  int len = a.length();
  for(int i = 0; i < len; i++){
    if ((((char)(a[i]) > 57)) || ((char)(a[i]) < 48)) {
        return false;
    }
  }
  return true;
}

/****************************************
function name: stoi
Description:takes in a string to return to an int that it is
parameters: string input
*****************************************/
int Owner::stoi(string input){
        int val;
        int res = 0;
        for(int i = (input.length()-1); i >= 0; i--) {
                val = ((int) input[i]) - 48;
                res +=  val * pow(10,(input.length() - i -1));
        }
}

/*********************************************************************
** Function:is_float()
** Description: checks if given string is a float
** Parameters: string a
** Pre-Conditions: string a
** Post-Conditions: boolean true or false
*********************************************************************/
bool Owner::is_float(string a){
   int len = a.length();
   bool hasdecimal = false;
   for(int i = 0; i < len; i++){
     if (((((char)(a[i]) > 57)) || ((char)(a[i]) < 48)) && (char)(a[i]) != 46){
         return false;
     }
     if((char)a[i] == 46){
       hasdecimal = true;
     }
   }
   if (hasdecimal == false){
     return false;
   }
   else{
     return true;
   }
}

/*********************************************************************
** Function:stof()
** Description: takes a string and turns it into a float
** Parameters: string input
** Pre-Conditions: the string taken in only contains numbers, decimal point, or negative
*********************************************************************/
//implemented from my work in lab 5
float Owner::stof(string input){
    int len = input.length();
    float output = 0.0,temp = 0.0;
    bool neg = false;
    int indexdeci = input.length();
    for(int b = 0; b < len; b++){
      if ((char)(input[b]) == 46){
        indexdeci = b;
      }
    }
    //ints before the decimal
    for(int i = 0; i < indexdeci; i++){
      //ints before the decimal
      if(((char)(input[i]) != 46)){
        if(input[i]== 45){
          neg = true;
        }
        else{
        temp = (float)(input[i] - 48);
        output += temp * pow(10, indexdeci - (i+1));
      }
      }
    }
    //ints after decimal
    if (indexdeci != 0){
      for(int c = indexdeci + 1; c < len; c++){
        if(((char)(input[c]) != 46)){
          temp = (float)(input[c] - 48);
          output += temp * (1 / pow(10,c - indexdeci));
        }
    }
    if(neg == true){
      output *= -1;
    }
    return output;
  }
}

/********************************************************************
** Function: randomize_number()
** Description: randomizes a number and returns it
** parameters: upper bound and lower lowerbound
********************************************************************/
int Owner::randomize_number(int upperbound, int lowerbound){
  int output = rand() % (upperbound - lowerbound) + lowerbound;
  return output;
}
/********************************************************************
** Function: Owner()
** Description: creation of new owner class and calls randomize fields
** parameters:
********************************************************************/
Owner::Owner(){
  wallet = 500000;
  num_houses = 0;
  num_apts = 0;
  num_businesses = 0;
  houses = NULL;
  apts = NULL;
  businesses = NULL;
  total_properties = 0;
  num_turn = 0;
}
/********************************************************************
** Function: ~owner()
** Description: destructor for Owner class
** parameters:
********************************************************************/
Owner::~Owner(){
  delete houses;
  delete apts;
  delete businesses;
}
/********************************************************************
** Function: run_game()
** Description: runs all the game and organizes function calls
** parameters:
********************************************************************/
void Owner::run_game(){
  num_turn = 0;

  //create array of properties to choose to buy
  House *house_market = new House[5];
  int *h_market_len = new int;
  *h_market_len = 5;
  Businesscomplex *business_market = new Businesscomplex[5];
  int *b_market_len = new int;
  *b_market_len = 5;
  Aptcomplex *apt_market = new Aptcomplex[5];
  int *a_market_len = new int;
  *a_market_len = 5;

  //choose starting property
  cout<<"FUNDS: $"<<wallet<<endl;
  buy_property(house_market,h_market_len,business_market,b_market_len,apt_market,a_market_len);
  do{
    /*
    pay_mortgages();
    collect_rent();
    cout<<"rent collected"<<endl;
    cout<<"FUNDS: $"<<wallet<<endl;
    natural_disaster();
    if(prompt_buy_property())
      buy_property(house_market,h_market_len,business_market,b_market_len,apt_market,a_market_len);
    if(prompt_to_sell()){
      sell_property();
    }
    cout<<"FUNDS: $"<<wallet<<endl;
    change_rent();
    if(num_turn % 12 == 0){
      pay_property_tax();
    }
    num_turn = num_turn + 1;
  }while(wallet > 0 && wallet < 1000000);
  if(wallet <= 0)
    cout<<"you have gone bankrupt, im sorry you lose"<<endl;
  else if(wallet >= 1000000)
    cout<<"you have made over $1,000,000 congratulations you win"<<endl;
  delete h_market_len;
  delete a_market_len;
  delete b_market_len;
  delete [] house_market;
  delete [] business_market;
  delete [] apt_market;
*/

}

/********************************************************************
** Function: natural_disaster()
** Description: provides an overarching function caller for natural disasters
** parameters:
********************************************************************/
void Owner::natural_disaster(){
  int num = randomize_number(5,0);
  if(num == 0){
    hurricane();
  }
  else if(num == 1){
    tornado();
  }
  else if(num == 2){
    earthquake();
  }
  else if (num  == 3){
    wildfire();
  }
  else if(num  == 4){
    stock_market_crash();
  }
  else if(num == 5){
    gentrification();
  }
}

/********************************************************************
** Function: hurricane()
** Description: simulates a hurricane on properties
** parameters: n/a
********************************************************************/
void Owner::hurricane(){
  cout<<"a hurricane has occured in the SE"<<endl;
  for(int i = 0; i < num_houses; i++){
    if(houses[i].get_location() == "SE"){
      houses[i].modify_value(0.5);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<houses[i].get_value()<<endl;
    }
  }
  for(int b = 0; b < num_apts; b++){
    if(apts[b].get_location() == "SE"){
      apts[b].modify_value(0.5);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<apts[b].get_value()<<endl;
    }
  }
  for(int c = 0; c < num_businesses; c++){
    if(businesses[c].get_location() == "SE"){
      businesses[c].modify_value(0.5);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<businesses[c].get_value()<<endl;
    }
  }
}

/********************************************************************
** Function: tornado
** Description: simulates a tornado on properties
** parameters:n/a
********************************************************************/
void Owner::tornado(){
  cout<<"a Tornado has cocured in the MidWest"<<endl;
  for(int i = 0; i < num_houses; i++){
    if(houses[i].get_location() == "MW"){
      houses[i].modify_value(0.7);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<houses[i].get_value()<<endl;
    }
  }
  for(int b = 0; b < num_apts; b++){
    if(apts[b].get_location() == "MW"){
      apts[b].modify_value(0.7);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<apts[b].get_value()<<endl;
    }
  }
  for(int c = 0; c < num_businesses; c++){
    if(businesses[c].get_location() == "MW"){
      businesses[c].modify_value(0.7);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<businesses[c].get_value()<<endl;
    }
  }
}
/********************************************************************
** Function:earthquake()
** Description: simulates an earthquake on properties
** parameters:n/a
********************************************************************/
void Owner::earthquake(){
  cout<<"an earhtquake has occured in the NW"<<endl;
  for(int i = 0; i < num_houses; i++){
    if(houses[i].get_location() == "NW"){
      houses[i].modify_value(0.1);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<houses[i].get_value()<<endl;
    }
  }
  for(int b = 0; b < num_apts; b++){
    if(apts[b].get_location() == "NW"){
      apts[b].modify_value(0.1);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<apts[b].get_value()<<endl;
    }
  }
  for(int c = 0; c < num_businesses; c++){
    if(businesses[c].get_location() == "NW"){
      businesses[c].modify_value(0.1);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<businesses[c].get_value()<<endl;
    }
  }
}

/********************************************************************
** Function:wildfire()
** Description: simulates a wildfire on properties
** parameters:n/a
********************************************************************/
void Owner::wildfire(){
  cout<<"a wildfire has occured in the SW "<<endl;
  for(int i = 0; i < num_houses; i++){
    if(houses[i].get_location() == "SW"){
      houses[i].modify_value(0.75);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<houses[i].get_value()<<endl;
    }
  }
  for(int b = 0; b < num_apts; b++){
    if(apts[b].get_location() == "SW"){
      apts[b].modify_value(0.75);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<apts[b].get_value()<<endl;
    }
  }
  for(int c = 0; c < num_businesses; c++){
    if(businesses[c].get_location() == "SW"){
      businesses[c].modify_value(0.75);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<businesses[c].get_value()<<endl;
    }
  }
}

/********************************************************************
** Function:stock_market_crash()
** Description:  simulates a stock market crash on properties
** parameters:n/a
********************************************************************/
void Owner::stock_market_crash(){
  cout<<"a stock market crash has occured"<<endl;
  for(int i = 0; i < num_houses; i++){
      houses[i].modify_value(0.7);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<houses[i].get_value()<<endl;
  }
  for(int b = 0; b < num_apts; b++){
      apts[b].modify_value(0.7);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<apts[b].get_value()<<endl;
  }
  for(int c = 0; c < num_businesses; c++){
      businesses[c].modify_value(0.7);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<businesses[c].get_value()<<endl;
  }
}

/********************************************************************
** Function: gentrification()
** Description: simulates gentrification on properties
** parameters: n/a
********************************************************************/
void Owner::gentrification(){
  int num = randomize_number(4,0);
  string a = "";
  if(num == 0)
    a = "SW";
  else if(num == 1)
    a = "MW";
  else if(num == 2)
    a = "NW";
  else if(num == 3)
    a = "NE";
  else if(num == 4);
    a = "SE";
  cout<<"gentrification has occured in the "<<a<<endl;
  for(int i = 0; i < num_houses; i++){
    if(houses[i].get_location() == a){
      houses[i].modify_value(1.2);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<houses[i].get_value()<<endl;
    }
  }
  for(int b = 0; b < num_apts; b++){
    if(apts[b].get_location() == a){
      apts[b].modify_value(1.2);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<apts[b].get_value()<<endl;
    }
  }
  for(int c = 0; c < num_businesses; c++){
    if(businesses[c].get_location() == a){
      businesses[c].modify_value(1.2);
      cout<<"one of your property has been effected by this event"<<endl;
      cout<<"new property value: "<<businesses[c].get_value()<<endl;
    }
  }
}

/********************************************************************
** Function: pay_property_tax()
** Description: organizes the property tax paymet by looping in properties
** parameters: n/a
********************************************************************/
void Owner::pay_property_tax(){
  for(int i = 0; i < num_houses; i++){
    wallet = wallet - (houses[i].get_value() * houses[i].get_propTax());
  }
  for(int b = 0; b < num_apts; b++){
    wallet = wallet - (apts[b].get_value() * apts[b].get_propTax());
  }
  for(int c = 0; c < num_businesses; c++){
    wallet = wallet - (businesses[c].get_value() * businesses[c].get_propTax());
  }
  cout<<"property taxes have been paid"<<endl;
  cout<<"FUNDS: $"<<wallet<<endl;
}

/********************************************************************
** Function: pay_mortgages()
** Description: organizes the process of paying mortgages of all properties
** parameters:n/a
********************************************************************/
void Owner::pay_mortgages(){
  for(int i = 0; i < num_houses; i++){
    if(houses[i].get_mortgage_duration() > 0){
      wallet = wallet - houses[i].get_mortgage();
    }
  }
  for(int b = 0; b < num_apts; b++){
    if(apts[b].get_mortgage_duration() > 0){
      wallet = wallet - apts[b].get_mortgage();
    }
  }
  for(int c = 0; c < num_businesses; c++){
    if(businesses[c].get_mortgage_duration() > 0){
      wallet = wallet - businesses[c].get_mortgage();
    }
  }
  cout<<"paid mortgages"<<endl;
  cout<<"FUNDS: $"<<wallet<<endl;
}

/********************************************************************
** Function:collect_house_rent()
** Description: collects rent from house properties
** parameters:n/a
********************************************************************/
void Owner::collect_house_rent(){
  for(int i = 0; i < num_houses; i++){
      if(houses[i].get_occupant()->budget > houses[i].get_rent()){
          wallet = wallet + houses[i].get_rent();
        }
      else if(houses[i].get_occupant()->agreeNum < 2){//no rent not agreeable
        cout<<"this resident is not agreeable and cannot afford rent, they will remain on the property until rent is lowered"<<endl;
      }
      else{//cannot pay rent, but are agreeable
        cout<<"the resident could not afford this property, therefore they have been evicted"<<endl;
        houses[i].get_occupant()->budget = 0;
      }
    }
}
/********************************************************************
** Function:collect_apts_rent()
** Description:  collects rent from apartment properties
** parameters:n/a
********************************************************************/
void Owner::collect_apts_rent(){
  for(int b = 0; b < num_apts; b++){
    for(int c = 0; c < apts[b].get_num_tenants(); c++)
        if(apts[b].get_apartments_at(c)->budget > apts[b].get_rent()){
            wallet = wallet + apts[b].get_rent();
          }
        else if(apts[b].get_apartments_at(c)->agreeNum < 2){//no rent not agreeable
          cout<<"this resident is not agreeable and cannot afford rent, they will remain on the property until rent is lowered"<<endl;
        }
        else{//cannot pay rent, but are agreeable
          cout<<"the resident could not afford this property, therefore they have been evicted"<<endl;
          apts[b].get_apartments_at(c)->budget = 0;
        }
    }
}
/********************************************************************
** Function:collect_business_rent()
** Description: collects rent from business properties individually
** parameters: n/a
********************************************************************/
void Owner::collect_business_rent(){
  for(int b = 0; b < num_businesses; b++){
    for(int c = 0; c < businesses[b].get_num_businesses(); c++)
        if(businesses[b].get_businesses_at(c)->budget > businesses[b].get_rent_at(c)){
            wallet = wallet + businesses[b].get_rent_at(c);
            businesses[b].modify_value(1.01);
          }
        else if(businesses[b].get_businesses_at(c)->agreeNum < 2){//no rent not agreeable
          cout<<"this resident (business complex "<<b + 1<<", office "<<c + 1<<")"<<" is not agreeable and cannot afford rent, they will remain on the property until rent is lowered"<<endl;
        }
        else{//cannot pay rent, but are agreeable
          cout<<"the resident could not afford this property, (business complex "<<b + 1<<", office "<<c + 1<<")"<<"therefore they have been evicted"<<endl;
          businesses[b].get_businesses_at(c)->budget = 0;
        }
    }
}
/********************************************************************
** Function:collect_rent()
** Description: overarching rent collection function that calls different property types
** parameters: n/a
********************************************************************/
void Owner::collect_rent(){
  collect_house_rent();
  collect_apts_rent();
  collect_business_rent();
}

/********************************************************************
** Function: print_properties_w_rent
** Description: prints out properties with their rent for user
** parameters:n/a
********************************************************************/
void Owner::print_properties_w_rent(){
  cout<<"HOUSES"<<endl;
  for(int i = 0; i < num_houses; i++){
    cout<<"[#"<<i+1<<" $"<<houses[i].get_rent()<<"] ";
  }
  cout<<endl;
  cout<<"APARTMENT COMPLEXES"<<endl;
  for(int b = 0; b < num_apts; b++){
      cout<<"[#"<<b+1<<" $"<<apts[b].get_rent()<<"] ";
    }
    cout<<endl;
    cout<<"BUSINESS COMPLEXES"<<endl;
  for(int c = 0; c < num_businesses; c++){
    cout<<"[#"<<c+1<<"]"<<endl;
    for(int d = 0; d < businesses[c].get_num_businesses(); d++){
      cout<<"[$"<<businesses[c].get_rent_at(d)<<"] ";
    }
    cout<<endl;
  }
  cout<<endl;
}

/********************************************************************
** Function:change_rent()
** Description: changes the rent of a property depending on type of property
** parameters:n/a
********************************************************************/
void Owner::change_rent(){
  print_properties_w_rent();
  string input;
  do{
    cout<<"would you like to change the rent of a house (1), apartment complex(2), business complex(3), or none(4)?"<<endl;
    cin>>input;
  }while(is_int(input)== false || stoi(input) < 1 || stoi(input) > 4);
  if(stoi(input) == 1){//change house rent
    change_house_rent();
  }
  else if(stoi(input) == 2){//change apt complex rent
    change_apt_rent();
  }
  else if(stoi(input) == 3){//change business rent
    change_business_rent();
  }
}
/********************************************************************
** Function: change_house_rent()
** Description:changes rent of a house
** parameters: n/a
********************************************************************/
void Owner::change_house_rent(){
  string input;
  string newrent;
  do{
    cout<<"which house's rent would you like to change? (1 - "<<num_houses<<")"<<endl;
    cin>>input;
  }while(is_int(input) == false || stoi(input) < 1 || stoi(input) > num_houses);
  do{
    cout<<"what would you like the new rent to be? (include decimal point)"<<endl;
    cin>>newrent;
  }while(stof(newrent) < 0 || is_float(newrent) == false);
  houses[stoi(input)-1].set_rent(stof(newrent));
}
/********************************************************************
** Function: change_apt_rent()
** Description: changes rent of an aprtment complex
** parameters: n/a
********************************************************************/
void Owner::change_apt_rent(){
  string input;
  string newrent;
  do{
    cout<<"which apartment complex's rent would you like to change? (1 - "<<num_apts<<")"<<endl;
    cin>>input;
  }while(is_int(input) == false || stoi(input) < 1 || stoi(input) > num_apts);
  do{
    cout<<"what would you like the new rent to be? (include decimal point)"<<endl;
    cin>>newrent;
  }while(stof(newrent) < 0 || is_float(newrent) == false);
  apts[stoi(input)-1].set_rent(stof(newrent));
}
/********************************************************************
** Function: change_business_rent()
** Description:changes the rent of a business complex but of a specific unit
** parameters: n/a
********************************************************************/
void Owner::change_business_rent(){
  string input;
  string input2;
  string newrent;
  do{
    cout<<"which business complex's rent would you like to change? (1 - "<<num_businesses<<")"<<endl;
    cin>>input;
  }while(is_int(input) == false || stoi(input) < 1 || stoi(input) > num_businesses);
  for(int i = 0; i < num_businesses; i++){
    businesses[i].print_rents();
  }
  do{
    cout<<"which business' rent would you like to change? (1 - "<<businesses[stoi(input)-1].get_num_businesses()<<")"<<endl;
    cin>>input2;
  }while(is_int(input2) == false || stoi(input2) < 1 || stoi(input2) > businesses[stoi(input)-1].get_num_businesses());
  do{
    cout<<"what would you like the new rent to be? (include decimal point)"<<endl;
    cin>>newrent;
  }while(stof(newrent) < 0 || is_float(newrent) == false);
  businesses[stoi(input)-1].set_rent_at(stoi(input2) - 1,stof(newrent));
}

/********************************************************************
** Function: buy_property()
** Description:this simulates the user buying a new property
** parameters: house array, business array, and apartment array and their lengths
********************************************************************/
void Owner::buy_property(House *house_market,int *len1, Businesscomplex *business_market, int *len2, Aptcomplex *apt_market, int *len3){
  string input;
  int *output = print_properties_on_market(house_market,len1,business_market,len2,apt_market,len3);
  do{
    cout<<"do you want to purchase the house (1), apartment complex (2), or business complex (3)?"<<endl;
    cin>>input;
  }while(is_int(input) == false || stoi(input) > 3 || stoi(input) < 1);
  if(stoi(input) == 1){
    houses = new House[num_houses + 1];
    houses[num_houses] = house_market[output[0]];
    num_houses++;
    total_properties++;
    House *temp = new House[(*len1)-1];
    for(int i = 0; i < (*len1)-1; i++){
      if(i != output[0])
        temp[i] = house_market[i];
    }
    house_market = temp;
    delete [] temp;
  }
  else if(stoi(input) == 2){
    apts = new Aptcomplex[num_apts + 1];
    apts[num_apts] = apt_market[output[1]];
    num_apts++;
    total_properties++;
    Aptcomplex *temp = new Aptcomplex[(*len2)-1];
    for(int i = 0; i < (*len2)-1; i++){
      if(i != output[1])
        temp[i] = apt_market[i];
    }
    apt_market = temp;
    delete [] temp;
  }
  else if (stoi(input) == 3){
    businesses = new Businesscomplex[num_businesses + 1];
    businesses[num_businesses] = business_market[output[2]];
    num_businesses++;
    total_properties++;
    Businesscomplex *temp = new Businesscomplex[(*len3)-1];
    for(int i = 0; i < (*len3)-1; i++){
      if(i != output[2])
        temp[i] = business_market[i];
    }
    business_market = temp;
    delete [] temp;
  }
  delete [] output;
}
/********************************************************************
** Function: print_properties_on_market()
** Description:prints the properties on a market that could be purchased
** parameters: house, apartment, and business markets and their lenths
********************************************************************/
int *Owner::print_properties_on_market(House *house_market,int *len1, Businesscomplex *business_market, int *len2, Aptcomplex *apt_market, int *len3){
  int *output = new int[3];
  for(int i = 0; i < (*len1); i++){
    if(house_market[i].get_mortgage() < wallet)
      cout<<"House: #"<<i + 1<<"mortgage: "<<house_market[i].get_mortgage()<<" for "<<house_market[i].get_mortgage_duration()<<" months"<<endl;
      cout<<endl;
      output[0] = i;
      break;

  }
  for(int b = 0; b < (*len2); b++){
    if(apt_market[b].get_mortgage() < wallet){
      cout<<"AptComplex: #"<<b + 1<<"mortgage: "<<apt_market[b].get_mortgage()<<" for "<<apt_market[b].get_mortgage_duration()<<" months"<<endl;
      cout<<"num units: "<<apt_market[b].get_num_tenants()<<endl;
      cout<<endl;
      output[1] = b;
      break;
    }
  }
  for(int c = 0; c < (*len3); c++){
    if(business_market[c].get_mortgage() < wallet){
      cout<<"BusinessComplex: #"<<c + 1<<"mortgage: "<<business_market[c].get_mortgage()<<" for "<<business_market[c].get_mortgage_duration()<<" months"<<endl;
      cout<<"num units: "<<business_market[c].get_num_businesses()<<endl;
      cout<<endl;
      output[2] = c;
      break;
    }
  }
  return output;
}

/********************************************************************
** Function: prompt_buy_property()
** Description: prompts user to buy property
** parameters: n/a
********************************************************************/
bool Owner::prompt_buy_property(){
  string input;
  do{
    cout<<"would you like to buy a property? (1 yes, 2 no)"<<endl;
    cin>>input;
  }while(is_int(input) == false || stoi(input) < 1 || stoi(input) > 2);
  if(stoi(input) == 2)
    return false;
  else
    return true;
}
/********************************************************************
** Function: able_to_sell()
** Description: checks if property is able to be sold
** parameters: string of type of property, and index of property
********************************************************************/
bool Owner::able_to_sell(string type, int index){
  if(type == "H"){
    if(houses[index].get_occupant()->budget == 0){
      return true;
    }
  }
  else if(type == "A"){
    for(int i = 0; i < num_apts; i++){
      if(apts[index].get_apartments_at(i)->budget != 0){
        return false;
      }
    }
  return true;
}
  else if(type == "B"){
    for(int b = 0; b < num_businesses; b++){
      if(businesses[index].get_businesses_at(b)->budget != 0){
        return false;
      }
    }
  return true;
  }
}
/********************************************************************
** Function: prompt_to_sell()
** Description: prompts the user what they would like to sell
** parameters: n/a
********************************************************************/
bool Owner::prompt_to_sell(){
  string input;
  do{
    cout<<"would you like to sell a property? (1 yes, 2 no)"<<endl;
    cin>>input;
  }while(is_int(input) == false || stoi(input) < 1 || stoi(input) > 2);
  if(stoi(input) == 1){
      return true;
  }
  else if(stoi(input) == 2){
    return false;
  }
}
/********************************************************************
** Function: sell_property
** Description: sells the property from the user and compensates accordingly
** parameters: n/a
********************************************************************/
void Owner::sell_property(){
  string input;
  string input2;
  do{
    print_properties_w_rent();
    cout<<"would you like to sell a house(1), apartment complex(2), or business complex(3)?"<<endl;
    cin>>input;
  }while(stoi(input) > 3 || stoi(input) < 1 || is_int(input) == false);
  do{
    cout<<"which of these would you like to sell? (give a number of the facility)";
    cin>>input2;
  }while(stoi(input2) == false || stoi(input2) < 1);
  if(stoi(input) == 1){
    if(able_to_sell("H",stoi(input2)-1)){
      wallet = wallet + houses[stoi(input2)-1].get_value();
      House *temp = new House[num_houses-1];
      for(int i = 0; i < num_houses-1; i++){
        if(i != stoi(input2) - 1){
          temp[i] = houses[i];
        }
      }
      num_houses = num_houses - 1;
      houses = temp;
      delete [] temp;
    }
    else{
      cout<<"im sorry you cannot sell that property"<<endl;
    }
  }
  else if(stoi(input) == 2){
    if(able_to_sell("A",stoi(input2)-1)){
      wallet = wallet + apts[stoi(input2)-1].get_value();
      Aptcomplex *temp = new Aptcomplex[num_apts-1];
      for(int i = 0; i < num_apts-1; i++){
        if(i != stoi(input2) - 1)
          temp[i] = apts[i];
      }
      num_apts = num_apts - 1;
      apts = temp;
      delete [] temp;
    }
    else{
      cout<<"im sorry you cannot sell that property"<<endl;
    }
  }
  else if(stoi(input) == 3){
    if(able_to_sell("B",stoi(input2)-1)){
      wallet = wallet + businesses[stoi(input2)-1].get_value();
      Businesscomplex *temp = new Businesscomplex[num_businesses-1];
      for(int i = 0; i < num_businesses-1; i++){
        if(i != stoi(input2) - 1)
          temp[i] = businesses[i];
      }
      num_businesses = num_businesses - 1;
      businesses = temp;
      delete [] temp;
    }
    else{
      cout<<"im sorry you cannot sell that property"<<endl;
    }
  }
}
