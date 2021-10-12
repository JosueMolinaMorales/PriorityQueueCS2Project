/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Airworthy.cpp
 * Author: twist
 * 
 * Created on April 27, 2021, 6:47 PM
 */

#include "Airworthy.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

Airworthy::Airworthy(string fileName) {
    string input = "";
    
    ifstream inFS(fileName);
    if(!inFS){
        cout << "Error opening file.. Program Terminating." << endl;
        exit(1);
    }
    
    //determine output file name
    
    if(fileName.find("100") != string::npos){
        outFileName = "results100.txt";
    }else if(fileName.find("85") != string::npos){
        outFileName = "results85.txt";
    }else if(fileName.find("70") != string::npos){
        outFileName = "results70.txt";
    }else{
        outFileName = "resultsUnknown.txt";
    }
    
    //create a file for information to be appended to
    ofstream simulationOutput;
    simulationOutput.open(outFileName);
    simulationOutput << "Simulation Results with data from: " << fileName << endl;
    simulationOutput << "Passengers on flight: " << endl;
    simulationOutput << left << setw(20) << "Last Name" << setw(10) << "Type" << setw(10) << "Row" << endl;
    simulationOutput <<"=========================================================" << endl;
    simulationOutput.close();
    
    //load queues
    getline(inFS, input);
    while(!inFS.eof()){
        loadPriorityQueues(input);
        getline(inFS, input);
    }
    
    
    timeForCurrMethod = 0;
    timeForNewMethod = 0;
    
}

Airworthy::Airworthy(const Airworthy& orig) {
}

Airworthy::~Airworthy() {
}

void Airworthy::loadPriorityQueues(string info){
    //open file and add each passenger to file
    ofstream simulationOutput;
    simulationOutput.open(outFileName, ios_base::app);
    
    //local variables for passenger obj
    string lastName = "";
    char type = ' ';
    int row = 0;
    int key = 0;
    
    
    istringstream iSS(info);
    
    iSS >> lastName;
    iSS >> type;
    iSS >> row;
    
    //add passenger information to file
    simulationOutput << left << setw(20) << lastName << setw(10) << type << setw(10) << row << endl;
    simulationOutput.close();
    
    //since both methods have the same pre-boarding we will test for that first.
    if(type == 'H'){ //Those who need help/children
        key = 10;
    }else if(row >= 1 and row <= 4){ //first class 
        key = 9;
    }else if (type == 'E' or row == 10 or row == 11){ //Elite Passengers & exit rows
        key = 8;
    }
    
    //currMethod will have general boarding be separated by row number
    if(key == 0){ //key was not given a value from pre-boarding
        if(row >= 23 and row <= 26){ 
            key = 7;
        }else if(row >= 17 and row <= 22){
            key = 6;
        }else if(row >= 12 and row <= 16){
            key = 5;
        }else if(row >= 5 and row <= 9){
            key = 4;
        }
    }
    
    //now create passenger obj and store into queue
    Passenger aPassenger(key, lastName, type, row);
    //cout << "Adding To CurrMethod: \n" << aPassenger << endl;
    currMethodPriQueue.add(aPassenger);
    
    //NewMethod will have general boarding have the same priority, so since we tested for
    //preboarding at the top everyone else will have a priority level of 7.
    if(key < 8){ //if key = 8, 9, 10 they are of highest priority
        key = 7;
    }
    
    //edit key and add to newMethod queue
    aPassenger.setKey(key);
    //cout << "Adding To NewMethod: \n" << aPassenger << endl;
    newMethodPriQueue.add(aPassenger);
    
}

void Airworthy::runSimulations(){
    //output file
    ofstream simulationOutput;
    simulationOutput.open(outFileName, ios_base::app);
    
    Passenger currPassenger;
    int previousPassengerRow = 30; //cannot initialize value to 0, there are only 26 seats.
    
    //separator 
    simulationOutput << "=========================================================\n" << endl;
    //currMethod
    simulationOutput << "Running Current Method simulation..... " << endl;
    simulationOutput << "Current Passengers Boarding: " << endl;
    simulationOutput << left << setw(20) << "Last Name" << setw(10) << "Type" 
            << setw(10) << "Row" << setw(10) << "Key" << endl;
    simulationOutput <<"=========================================================" << endl;
    
    while(!currMethodPriQueue.isEmpty()){
        currPassenger = currMethodPriQueue.peek();
        
        //if the previous passenger is closer to the front than the current passenger
        //then boarding time is 25 seconds
        if(previousPassengerRow <= currPassenger.getRow()){
            timeForCurrMethod += 25;
            //cout << "Adding 25 current time is: " << timeForCurrMethod << endl;
        }else{
            timeForCurrMethod += 1;
            //cout << "Adding 1 current time is: " << timeForCurrMethod << endl;
        }
        
        //output information to file
        simulationOutput << left << setw(20) << currPassenger.getLastName() << setw(10) << currPassenger.getType()
                << setw(10) << currPassenger.getRow() << setw(10) << currPassenger.getKey() << endl;
        
        //dequeue passenger
        currMethodPriQueue.remove();
        
        //set new previous passenger row
        previousPassengerRow = currPassenger.getRow();
    }
    
    simulationOutput << "Current time for current method: " << secondToMinutes(timeForCurrMethod) << endl;
    //simulationOutput << "Seconds: " << timeForCurrMethod << endl;
    simulationOutput << endl;
    
    //reset previous passenger row
    previousPassengerRow = 30;
    
    simulationOutput << "Running New Method simulation..... " << endl;
    simulationOutput << "Current Passengers Boarding: " << endl;
    simulationOutput << left << setw(20) << "Last Name" << setw(10) << "Type" 
            << setw(10) << "Row" << setw(10) << "Key" << endl;
    simulationOutput <<"=========================================================" << endl;
    //new method
    while(!newMethodPriQueue.isEmpty()){
        currPassenger = newMethodPriQueue.peek();
        
        if(previousPassengerRow <= currPassenger.getRow()){
            timeForNewMethod += 25;
        }else{
            timeForNewMethod += 1;
        }
        
        //output information to file
        simulationOutput << left << setw(20) << currPassenger.getLastName() << setw(10) << currPassenger.getType()
                << setw(10) << currPassenger.getRow() << setw(10) << currPassenger.getKey() << endl;
        
        //dequeue passenger
        newMethodPriQueue.remove();
        
        previousPassengerRow = currPassenger.getRow();
    }
    
    simulationOutput << "Current time for new method: " << secondToMinutes(timeForNewMethod) << endl;
    //simulationOutput << "Seconds: " << timeForNewMethod << endl;
    
    simulationOutput.close();
}

string Airworthy::secondToMinutes(int seconds){
    int minutes = seconds / 60;
    int leftOverSeconds = seconds % 60;
    return to_string(minutes) + " minutes " + to_string(leftOverSeconds) + " seconds";
}

