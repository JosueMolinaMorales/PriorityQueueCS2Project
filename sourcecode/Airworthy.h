/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Airworthy.h
 * Author: twist
 *
 * Created on April 27, 2021, 6:47 PM
 */

#ifndef AIRWORTHY_H
#define AIRWORTHY_H
#include "Passenger.h"
#include "ArrayMaxHeap.h"

class Airworthy {
public:
    /**
     * Constructor for Airworthy, recieves a file name from the main method,
     * reads the file, sending information to load priorityQueue to fill the queues
     * @param fileName
     */
    Airworthy(std::string fileName);
    Airworthy(const Airworthy& orig);
    virtual ~Airworthy();
    
    /**
     * This method will run both simulations, it will first run the simulation for the currMethod
     * of boarding, then it will run the simulation for newMethod
     * The results will be printed to SimulationResults{testCapacity}.txt 
     */
    void runSimulations();
private:
     /**
      * This method will take in a string that contains a passenger info, a passenger object will be
      * created and given a key (based off of which queue they will be added to) and added to
      * the queues
      * @param info string containing the passenger data
     */
    void loadPriorityQueues(std::string info);
    
    /* Priority Queue that holds passengers. This will be used for the current
     * boarding method
     */
    ArrayMaxHeap<Passenger> currMethodPriQueue;
    
    /* Priority Queue that holds passengers. This will be used for the new
        boarding method
     */
    ArrayMaxHeap<Passenger> newMethodPriQueue;
    
    /*Used to store the time for the current boarding method*/
    int timeForCurrMethod;
    
    /*Used to store the time for the new boarding method*/
    int timeForNewMethod;
    
    /**
     * Converts seconds to minutes and returns it as a string
     * @param seconds seconds to convert
     * @return a string that contains the seconds converted to minutes
     */
    std::string secondToMinutes(int seconds);
    
    /*Name of the output file name*/
    std::string outFileName;
};

#endif /* AIRWORTHY_H */

