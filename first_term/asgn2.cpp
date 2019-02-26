/***********************************************
** Program: asgn2.cpp (Adventure Game)
** Author: Thomas Weathers
** Date: 19 January 2018
** Description: this is an adventure game where the user will try to get to the end withouit dying
** Input: prompted integer user inputs
** Output: text outputs illustrating the story of the adventure
************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
      //Welcome Statement
      cout << "Welcome to the adventure, your goal is to reach the end of the caves and claim the treasure without dying! Good Luck!" << endl;

      //First Room
      cout << "You enter the caves that you have been told contains a large amount of treasure hidden somewhere, but it is guarded heavily by violent gnomes" <<endl;
      cout << "The first thing you see in the cave is a divide down two different paths, denoted by a sign saying 'A or B' " << endl;
      int split1;
      cout << "Press 1 to go down path A \nPress 2 to go down path B" << endl;
      cin >>  split1;

      //if they go down path A
      if (split1 == 1){
          cout << "You go down path A, which opens up into a cavern. \nThis cavern looks like a barracks for the gnome army hidden in the caves. \n27 evil gnomes jump out at you and attack you." << endl;
          cout << "Do you:\n1. attempt to flee \n2.attempt to fight them with your fists " << endl;

          //fight 1
          int fight1;
          cin >> fight1;
          int outcome1;
          srand(time(NULL));
          outcome1 = rand();
          outcome1 = (outcome1 % 2) + 1;

          //you attempt to flee from the gnomes
          if (fight1 == 1){
              //succesful flee. still death
              if (outcome1 == 1){
                cout << "You have successfully fled from the fight and have ran into a safe area" << endl;
                cout << "You now have no other option but to proceed to the only path available, which looks very promising" << endl;
                cout << "You proceed down the path which opens up into a large open cavern with a stone floor. You have no other option but to cross that floor" <<endl;
                cout << "When stepping on this floor you feel the floor collapse under you and you fall into a pit of spikes and die. RIP. Thanks for playing!" << endl;
                return 1;
              }
              else{
                //didnt flee. death
                cout << "You were unable to flee from the gnomes and you have died. Thank you for playing" << endl;
                return 1;
              }
          }
          //if you attempt to fight the gnomes
          else if(fight1 == 2){
            // fought the gnomes. still death
            if (outcome1 == 1){
              cout << "You have miraculously defeated all of the gnomes, and the room is not free from threats" << endl;
              cout << "You now have no other option but to proceed to the only path available, which looks very promising" << endl;
              cout << "You proceed down the path which opens up into a large open cavern with a stone floor. You have no other option but to cross that floor" <<endl;
              cout << "When stepping on this floor you feel the floor collapse under you and you fall into a pit of spikes and die. RIP. Thanks for playing!" << endl;
              return 1;
            }
            else{
              //fought and died from gnomes
              cout <<"The 27 gnomes have destroyed you... I dont think it was a good idea to try and fight them without a weapon. You have died. Thanks for playing!" << endl;
              return 1;
            }
          }
      }
      //if start down path 2
      else if (split1 = 2){

        cout << "You go down path B, which opens up into a cavern. \nThis cavern appears to be the sleeping quarters for the gnomes.\nYou see 12 gnomes sleeping" << endl;
        cout << "Do you:\n1.attempt to sneak past them \n2.run with no regard for your volume" << endl;

        int fight2;
        cin >> fight2;
        int outcome2;

        srand(time(NULL));
	outcome2 = rand();
        outcome2 = (outcome2 % 2) + 1;

        //you attempt to be sneaky
        if (fight2 == 1){
          //successfully snuk by
          if(outcome2 == 1){
            cout <<"You have successfully attempted to be sneaky and have passed the gnomes without waking them" << endl;

            //split into room 4 or 5
            cout <<"You now come to an intersection of paths again, which will you choose? \n1. Path A \n2. Path B " <<endl;
            int split2;
            cin >> split2;

            //goes to R4
            if (split2 == 1){
              cout << "You proceed down the path which opens up into a large open cavern with a stone floor. You have no other option but to cross that floor" <<endl;
              cout << "When stepping on this floor you feel the floor collapse under you and you fall into a pit of spikes and die. RIP. Thanks for playing!" << endl;
              return 1;
            }
            //goes down path B2, leading to R5
            else if (split2 == 2){
              cout <<"You now enter a large open room with a statue in the middle of it. \nAround the room you see hundreds of gnomes, yet you see a sword on the ground next to you. \n Do you:\n1. Grab the sword and fight?\n2. Run" << endl;
              int fight3;
              cin >> fight3;
              //if you fight, you win
              if (fight3 == 1){
                cout <<"You have fought valiantly and defeated the hundreds of gnomes.....somehow.\nYou see the tresure scattered around the room. You have successfully completed the adventure!\n Thanks for playing!" << endl;
                return 1;
              }
              else if (fight3 == 2){
                cout <<"You attempted to run and ultimately got swarmed and died a very pathetic death. Thanks for playing!" << endl;
                return 1;
              }
            }


          }
          //woke them. death
          else{
            cout << "You attempted to be sneaky but fell and woke every single gnome. They attack you. You are dead. Thanks for playing!" <<endl;
            return 1;
          }
        }
        //you run without regard for stealth. death
        else if (fight2 == 2){
          cout <<"You realize this was a poor decision when they all awake and immediately attack you. You are dead. Thanks for playing!" << endl;
          return 1;
        }
      }

}
