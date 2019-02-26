#include "state_facts.h"
//functions with full bodies
using namespace std;
//checks if correct file

/****************************************
function name:is_int
Description: can tell if the string input is an integer
parameters: string a
*****************************************/
bool is_int(string a){
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
int stoi(string input){
        int val;
        int res = 0;
        for(int i = (input.length()-1); i >= 0; i--) {
                val = ((int) input[i]) - 48;
                res +=  val * pow(10,(input.length() - i -1));
        }
}

/****************************************
function name:is_float()
Description:checks if a string is a float
parameters:string input
*****************************************/
bool is_float(string input){
        int count  = 0;
        for(int i=0; i<input.length(); i++){
                if (input[i] < '0' || input[i] > '9') {
                        if (input[i] == '.') {
                                count++;
                                if (count > 1) {
                                        return false;
                                }
                        }
                        else {
                                return false;
                        }
                }
        }
        return true;
}

/****************************************
function name:delete info
Description: deletes the info in all of states and county array
post-conditions:deletes all heap memory
*****************************************/
void delete_info(state ** states, int len){
  cout<<"here1"<<endl;
  for(int i = 0; i < len; i++){
    for(int b = 0; b < (*states)[i].counties;b++){
      delete [] (*states)[i].c[b].city;
      cout<<"here2"<<endl;
    }
    delete [] (*states)[i].c;
    cout<<"here3"<<endl;
  }
  delete [] (*states);
  cout<<"here4"<<endl;
  states = NULL;
}

/****************************************
function name: stof
Description: converts a string to a float
parameters: string input
pre-conditions:has only numbers
*****************************************/
float stof(string input){
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

/****************************************
function name: is_valid_arguments
Description:  checks if there are valif command line arguments
parameters:command line args
*****************************************/
bool is_valid_arguments(int argc, char **argv){
  if(strlen(*argv) < 5){
    return false;
  }
  //-s then -f
  if (argv[1][1] == 's' && argv[1][0] == '-'){
    if (argv[3][1] == 'f' && argv[3][0] == '-'){
      if ((argv[2][0] >= 48 && argv[2][0] <= 57) || (argv[2][0] >= 48 && argv[2][0] <= 57) && (argv[2][1] >= 48 && argv[2][1] <= 57))
        return true;
    }
  }
  //-f then -s
  else if (argv[1][1] == 'f' && argv[1][0] == '-'){
    if (argv[3][1] == 's' && argv[3][0] == '-'){
      if ((argv[4][0] >= 48 && argv[4][0] <= 57) || (argv[4][0] >= 48 && argv[4][0] <= 57) && (argv[4][1] >= 48 && argv[2][1] <= 57))
        return true;
    }
  }
  return false;
}

/****************************************
function name:
Description:
parameters:
pre-conditions:
post-conditions:
*****************************************/
state *create_states(int length){
  state *output = new state[length];
  return output;
}

/****************************************
function name:get_state_data
Description: takes in all state data from the file
parameters:state array, length of array, file to read from
*****************************************/
void get_state_data(state * states, int len, ifstream &file){
  int countylen = 0;
  string statename, state_pops, numcounties;
  int state_pop;
  int numcounty;
  for(int i = 0; i < len; i++){
    getline(file,statename,' ');
    getline(file,state_pops,' ');
    state_pop = stoi(state_pops);
    getline(file,numcounties);
    numcounty = stoi(numcounties);
    states[i].name = statename;
    states[i].population = state_pop;
    states[i].counties = numcounty;
    states[i].c = create_counties(numcounty);
    get_county_data((states[i]).c,numcounty,file);
  }
}

/****************************************
function name: create_counties
Description: creates blank county arrays
parameters: int length
*****************************************/
county *create_counties(int length){
  county *output = new county[length];
  return output;
}

/****************************************
function name:get_county_data
Description: collects data from counties in file
parameters: county array, int length, file to read from
*****************************************/
void get_county_data(county * counties, int len, ifstream &file){
  string population, avg_inc, avg_houses;
  int citiesnum;
  for(int i = 0; i < len; i++){
    getline(file,(counties[i]).name,' ');
    getline(file,population,' ');
    getline(file,avg_inc,' ');
    getline(file,avg_houses,' ');
    file>>citiesnum;
    counties[i].city = new string[citiesnum];
    for(int b = 0; b < citiesnum; b++){
      if(b == citiesnum - 1){
        getline(file,counties[i].city[b]);
      }
      else{
        getline(file,counties[i].city[b],' ');
      }
    }
    (counties[i]).population = stoi(population);
    (counties[i]).cities = citiesnum;
    (counties[i]).avg_income = stof(avg_inc);
    (counties[i]).avg_house = stof(avg_houses);
  }
}

/****************************************
function name: largest_state_pop
Description: finds largest state population
parameters:state array, length
*****************************************/
string largest_state_pop(state *states, int len){
  int indexlargest = 0;
  if (len == 1){
    //cout<<"state largest population: "<<(states[0]).name<<endl;
    return (states[0]).name;
  }
  else{
    for(int i = 1; i < len; i++){
      if((states[i]).population > (states[indexlargest]).population){
        indexlargest = i;
      }
    }
    return (states[indexlargest]).name;
  }
}

/****************************************
function name: swap_states
Description:swaps state locations
parameters: state arrays, index 1, index 2
*****************************************/
void swap_states(state *states,int index1, int index2){
  state temp = states[index1];
  states[index1] = states[index2];
  states[index2] = temp;
}

/****************************************
function name: swap_counties
Description: swaps the location of two indexes of a county array
parameters:county array and two indexes
*****************************************/
void swap_counties(county *counties, int index1, int index2){
  county temp = counties[index1];
  counties[index1] = counties[index2];
  counties[index2] = temp;
}

/****************************************
function name: largest_county_pop
Description: finds largest population in county array
parameters: county array, length
*****************************************/
string largest_county_pop(county *counties, int len){
  int indexlargest = 0;
  if (len == 1){
    return (counties[0]).name;
  }
  else{
    for(int i = 1; i < len; i++){
      if((counties[i]).population > (counties[indexlargest]).population){
        indexlargest = i;
      }
    }
    return (counties[indexlargest]).name;
  }
}

/****************************************
function name: income_above
Description: finds the income above a given val
parameters:state array, int length, int pointer counting array
*****************************************/
county *income_above(state *states, int len, int *counts){
  int count = 0;
  double input;
  string inputs = "";
  do{
    cin.ignore();
    cout<<"please provide an income that you would like to see : "<<endl;
    cin>>inputs;
  }while(is_float(inputs) == false || stof(inputs) < 0);
  input = (double)stof(inputs);
  *counts = 0;
  for(int i = 0; i < len; i++){
    for(int b = 0; b < states[i].counties; b++){
      if (states[i].c[b].population > input){
        *counts = *counts + 1;
      }
    }
  }
  county *output = new county[*counts];
  for(int i = 0; i < len; i++){
    for(int b = 0; b < states[i].counties; b++){
      if (states[i].c[b].population > input){
        output[count] = states[i].c[b];
        count++;
      }
    }
  }

  return output;
}

/****************************************
function name: avg_household_cost
Description: finds average household cost of counties
parameters:states array, int length
*****************************************/
float *avg_household_cost(state *states, int len){
  int count = 0;
  float total = 0.0;
  float *household_avgs = new float[len];
  for(int i = 0; i < len; i++){
    for(int b = 0; b < (states[i]).counties; b++){
      total += states[i].c[b].avg_house;
      count++;
    }
    household_avgs[i] = total / (float)(count);
    total = 0.0;
    count = 0;
  }
  return household_avgs;
}

/****************************************
function name:alphebetically
Description: sorts states and counties alphabetically
parameters: string array, int length
post-conditions: sorted array of strings by alphabet
*****************************************/
void alphebetically(string *strings, int len){
  bool keepgoing = false;
  state *temp;
  do{
    keepgoing = false;
    for (int i = 0; i < len-1; i++){
      if(strings[i] > strings[i+1]){
        strings[i].swap(strings[i+1]);
        keepgoing = true;
        break;
      }
    }
  }while(keepgoing);
}

/****************************************
function name: sort_int
Description: sorts state array by integer population
parameters: state array, int length
*****************************************/
void sort_int(state *states, int len){
  int temp;
  bool keepgoing = false;
  do{
    keepgoing = false;
    for(int i = 0; i< len-1; i++){
      if(states[i].population < states[i+1].population){
        swap_states(states,i,i+1);
        keepgoing = true;
        break;
      }
    }
  }while(keepgoing);
}

/****************************************
function name:sort_counties
Description: sorts array of counties by population
parameters: county array, int length
pre-conditions: unsorted array
post-conditions: sorted array of counites
*****************************************/
void sort_counties(county *counties, int len){
  int temp;
  bool keepgoing = false;
  do{
    keepgoing = false;
    for(int i = 0; i< len-1; i++){
      if(counties[i].population < counties[i+1].population){
        swap_counties(counties,i,i+1);
        keepgoing = true;
        break;
      }
    }
  }while(keepgoing);
}

/****************************************
function name:find_file_index
Description: fidns the index of file in command line
parameters: argc and argv, command line args
*****************************************/
int find_file_index(int argc, char **argv){
  int output = 1;
  for(int i = 1; i < argc; i++){
    if(argv[i][0] == '-' && argv[i][1] == 'f'){
      output = i + 1;
    }
  }
  return output;
}

/****************************************
function name:finds integer index to find length
Description: finds the index of int in command line
parameters: argc and argc of command line
*****************************************/
int find_int_index(int argc, char **argv){
  int output = 1;
  for(int i = 1; i < argc; i++){
    if(argv[i][0] == '-' && argv[i][1] == 's'){
      output = i + 1;
    }
  }
  return output;
}

/****************************************
function name:to_file_input
Description: takes in file input from user
*****************************************/
bool to_file_input(){
  string input;
  do{
    cout<<"would you like to print to the screen or file? (0 for screen, 1 for file)? "<<endl;
    cin>>input;
  }while(is_int(input) == false || (stoi(input) > 1 || stoi(input) < 0));
  return stoi(input);
}

/****************************************
function name: get_file_name
Description: asks the user for a file name
*****************************************/
char *get_file_name(){
  char *input = new char[256];
  cout<<"what would you like to name your file? "<<endl;
  cin.ignore();
  cin.get(input,250);
  return input;
}

/****************************************
function name: counties_above_return
Description: finds the counties above what is prompted by user
parameters:state array, number of states
*****************************************/
string counties_above_return(state *states, int numstates){
  string output = "";
  county *countiesabove;
  int *totalcounties;
  *totalcounties = 0;
  countiesabove = income_above(states,numstates,totalcounties);
  for(int i = 0;i < *totalcounties; i++){
    output += countiesabove[i].name + " ";
  }
  return output;
}

/****************************************
function name: alphabatize_print
Description: aplhabatizes the states and prints them
parameters:state array integer number of states
*****************************************/
void alphebatize_print(state *states, int numstates){
  cout<<"sorted names: "<<endl;
  string *statesstring = new string[numstates];
  string *countystring;
  for(int i = 0; i < numstates; i++){
    statesstring[i] = states[i].name;
  }
  alphebetically(statesstring,numstates);
  for(int b = 0; b < numstates; b++){
    cout<<statesstring[b]<<": "<<endl;
    for(int c = 0; c < numstates; c++){
      if(statesstring[b] == states[c].name){
        countystring = new string[states[c].counties];
        for(int a = 0; a < states[c].counties; a++){
          countystring[a] = states[c].c[a].name;
        }
        alphebetically(countystring,states[c].counties);
        for(int i = 0; i < states[c].counties;i++){
          cout<<countystring[i]<<endl;
        }
      }
    }
  }
  delete [] statesstring;
  delete [] countystring;
}

/****************************************
function name:alphabatize_write
Description: takes alphabize list and writes to a file
parameters:states array, int number of states, file to print to
*****************************************/
void alphebatize_write(state *states, int numstates, ofstream &file_out){
  file_out<<"sorted names: "<<endl;
  string *statesstring = new string[numstates];
  string *countystring;
  for(int i = 0; i < numstates; i++){
    statesstring[i] = states[i].name;
  }
  alphebetically(statesstring,numstates);
  for(int b = 0; b < numstates; b++){
    file_out<<statesstring[b]<<": "<<endl;
    for(int c = 0; c < numstates; c++){
      if(statesstring[b] == states[c].name){
        countystring = new string[states[c].counties];
        for(int a = 0; a < states[c].counties; a++){
          countystring[a] = states[c].c[a].name;
        }
        alphebetically(countystring,states[c].counties);
        for(int i = 0; i < states[c].counties;i++){
          file_out<<countystring[i]<<endl;
        }
      }
    }
  }
  delete [] statesstring;
  delete [] countystring;
}

/****************************************
function name:sort_pop_print
Description: sorts the population and then prints it
parameters:states array and integer of length
*****************************************/
void sort_pop_print(state *states, int numstates){
  cout<<"sorted populations: "<<endl;
  sort_int(states,numstates);
  for(int b = 0; b < numstates; b++){
    cout<<states[b].name<<": "<<states[b].population<<endl;
    sort_counties(states[b].c,states[b].counties);
      for(int c = 0; c < states[b].counties;c++){
        cout<<states[b].c[c].name<<" "<<states[b].c[c].population<<endl;
      }
  }
}

/****************************************
function name:sort_pop_write
Description: sorts array of population and writes to file
parameters:file, states array, number of states
*****************************************/
void sort_pop_write(state *states, int numstates,ofstream &file_out){
  file_out<<"sorted populations: "<<endl;
  sort_int(states,numstates);
  for(int b = 0; b < numstates; b++){
    file_out<<states[b].name<<": "<<states[b].population<<endl;
    sort_counties(states[b].c,states[b].counties);
      for(int c = 0; c < states[b].counties;c++){
        file_out<<states[b].c[c].name<<" "<<states[b].c[c].population<<endl;
      }
  }
}

/****************************************
function name: to_file
Description: collects all to-file functions to run
parameters: states array and number of states
*****************************************/
void to_file(state *states, int numstates){
  char *file_name = new char[256];
  file_name = get_file_name();
  strcat(file_name,".txt");
  ofstream file_out(file_name);
  file_out<<"LARGEST STATE POPULATION: "<<largest_state_pop(states,numstates)<<endl;
  file_out<<"\n";
  file_out<<"LARGEST COUNTY POPULATION: "<<endl;
  for(int i = 0; i < numstates; i++){
    file_out<<states[i].name<<": "<<largest_county_pop((states[i]).c,numstates)<<endl;
  }
  string temp = counties_above_return(states,numstates);
  file_out<<"COUNTIES ABOVE(INCOME): \n"<<temp<<endl;
  file_out<<"\n";
  file_out<<"AVERAGE HOUSEHOLD COST: "<< *avg_household_cost(states,numstates)<<endl;
  file_out<<"\n";
  alphebatize_write(states,numstates,file_out);
  file_out<<"\n";
  sort_pop_write(states,numstates,file_out);
  delete [] file_name;
  file_name = NULL;
  file_out.close();
  cout<<"herehere"<<endl;
}

/****************************************
function name:to_screen
Description: takes all commands and executes for all printing functions
parameters: states array, number of states
*****************************************/
void to_screen(state *states, int numstates){
  cout<<"LARGEST STATE POPULATION: "<<largest_state_pop(states,numstates)<<endl;
  cout<<"\n";
  cout<<"LARGEST COUNTY POPULATION: "<<endl;
  for(int i = 0; i < numstates; i++){
    cout<<states[i].name<<": "<<largest_county_pop((states[i]).c,numstates)<<endl;
  }
  cout<<"COUNTIES ABOVE(INCOME): \n"<<counties_above_return(states,numstates)<<endl;
  cout<<"\n";
  cout<<"AVG HOUSEHOLD COST: "<< *avg_household_cost(states,numstates)<<endl;
  cout<<"\n";
  alphebatize_print(states,numstates);
  cout<<"\n";
  sort_pop_print(states,numstates);
}
