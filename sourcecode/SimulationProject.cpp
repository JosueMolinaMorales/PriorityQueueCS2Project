/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file:   main.cpp
 * @author: cwood
 *
 * Created on April 14, 2019, 6:45 PM
 */

#include <cstdlib>
#include <iostream>
#include "ArrayMaxHeap.h"
#include "Airworthy.h"

using namespace std;

/**
 * Prints out a description of the simulation that is happening
 */
void description();
/*
 * 
 */
int main() {
    description();

    //run simulations for 70 percent capacity
    Airworthy seventyPercentSim("airworthy70.txt");
    seventyPercentSim.runSimulations();
    
    //run simulations for 85 percent capacity
    Airworthy eightyFivePercentSim("airworthy85.txt");
    eightyFivePercentSim.runSimulations();
    
    //run simulations for 100 percent capacity
    Airworthy oneHundredPercentSim("airworthy100.txt");
    oneHundredPercentSim.runSimulations();
    
    return 0;
}

void description(){
    cout << "Welcome! This program will run two different"
            << " boarding procedures for Airworthy Airlines." << endl
            << "Pre-boarding will remain the same for both procedures." << endl
            << "First to board will be families with young children or people who need help, denoted by \'H\'"
            << endl << "Next to board will be First class Passengers sitting in rows 1-4." << endl
            << "Last to pre-board will be elite passengers, denoted \'E\', and passengers seated in exit rows (10-11)" << endl
            << "\nThe current boarding procedure for general boarding will be those sitting in rows 23-26 will board first." << endl
            << "Followed by rows 17-22, 11-16 and 5-10. " << endl
            << "\nThe new boarding procedure for general boarding will be done randomly, meaning that the first passenger in line" 
            << " is the first passenger to board." << endl
            << "The simulation results will be made available in a .txt file after execution." << endl
            << "The txt files will be found in the same directory as the current project directory." << endl; 
            
}

/**
     ArrayMaxHeap<int> priQ;
    cout << boolalpha << "Empty? " << priQ.isEmpty() << endl;
    
    cout << "Adding 14 " << endl;
    priQ.add(14);
    
    cout << "Adding 18 " << endl;
    priQ.add(18);
    
    cout << "Adding 174 " << endl;
    priQ.add(174);
    
    cout << "Adding 16 " << endl;
    priQ.add(16);
    
    cout << "Adding 154 " << endl;
    priQ.add(154);
    
    cout << "Adding 1000 " << endl;
    priQ.add(1000);
    
    cout << priQ.getItemCount() << " items" << endl;
    cout << "Highest priority: " << priQ.peek() << endl;
    
    priQ.remove();
    cout << "Highest priority: " << priQ.peek() << endl;
    
    priQ.remove();
    cout << "Highest priority: " << priQ.peek() << endl;
 //    Airworthy test("test.txt");
//    test.runSimulations();
//    
//    Airworthy test2("airworthy70.txt");
//    test2.runSimulations();
//    
//    Airworthy test3("airworthy85.txt");
//    test3.runSimulations();
//    
//    Airworthy test4("airworthy100.txt");
//    test4.runSimulations();
 */

