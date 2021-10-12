/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passenger.h
 * Author: Josue
 *
 * Created on April 27, 2021, 5:59 PM
 */

#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>

class Passenger {
public:
    /**
     * Default Constructor for Passenger object
     * Sets all attributes to default values
     */
    Passenger();
    
    /**
     * Overloaded Constructor for Passenger object
     * @param key - Key for Passenger
     * @param lastName - last name of passenger
     * @param type - Type for passenger
     * @param row - Row of passenger
     */
    Passenger(int key, std::string lastName, char type, int row);
    
    /**
     * Copy Constructor
     * @param orig the original passenger object
     */
    Passenger(const Passenger& orig);
    virtual ~Passenger();
    
    //methods
    /**
     * Gets the key of the passenger
     * @return the key of the passenger
     */
    int getKey() const;
    
    /**
     * Gets the last name of the passenger
     * @return The last name of the passenger
     */
    std::string getLastName() const;
    
    /**
     * Gets the type of the passenger
     * @return the type of the passenger
     */
    char getType() const;
    
    /**
     * Gets the row of the passenger
     * @return the row of the passenger
     */
    int getRow() const;
    
    /**
     * Sets the key of the passenger
     * @param key - Key of the passenger
     */
    void setKey(int key);
    
    /**
     * Sets the last name of the passenger
     * @param lastName - Last name of the passenger
     */
    void setLastName(std::string lastName);
    
    /**
     * Sets the type of the passenger
     * @param type - the type of the passenger
     */
    void setType(char type); 
    
    /**
     * Sets the row of the passenger
     * @param row - The row of the passenger
     */
    void setRow(int row);
    
    //overloaded operators
    /**
     * Overloaded operator >, uses the key attribute to determine if this
     * passenger object is greater than the rhs
     * @param rhs The passenger object being compared to this object
     * @return True if this object is greater than rhs object
     */
    bool operator>(const Passenger& rhs) const;
    
    /**
     * Overloaded operator <, uses the key attribute to determine if this
     * passenger object is less than the rhs
     * @param rhs The passenger object being compared to this object
     * @return True if this object is less than rhs object
     */
    bool operator<(const Passenger& rhs) const;
    
    /**
     Overloaded Operator <<, Prints out the information of the passenger object
     */
    friend std::ostream& operator<<(std::ostream& out, Passenger& rhs);
    
private:
    /*Key of the passenger, will range from 10-4, 10 being the highest priority*/
    int key;
    
    /*Last name of the passenger*/
    std::string lastName;
    
    /*Type of the passenger, 'H' if they need help, 'E' if elite , 'G' General Boarding*/
    char type;
    
    /*Row of the passenger*/
    int row;

};

#endif /* PASSENGER_H */

