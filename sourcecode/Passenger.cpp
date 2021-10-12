/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passenger.cpp
 * Author: Josue
 * 
 * Created on April 27, 2021, 5:59 PM
 */

#include "Passenger.h"


using namespace std;

Passenger::Passenger(): key(0), lastName(""), type(' '), row(0) {}

Passenger::Passenger(int key, string lastName, char type, int row){
    this->key = key;
    this->lastName = lastName;
    this->type = type;
    this->row = row;
}

Passenger::Passenger(const Passenger& orig)
:key(orig.key), lastName(orig.lastName), type(orig.type), row(orig.row) 
{}

Passenger::~Passenger() {
}

int Passenger::getKey() const{
    return key;
}

string Passenger::getLastName() const{
    return lastName;
}

char Passenger::getType() const{
    return type;
}

int Passenger::getRow() const{
    return row;
}

void Passenger::setKey(int key){
    this->key = key;
}

void Passenger::setLastName(string lastName){
    this->lastName = lastName;
}

void Passenger::setType(char type){
    this->type = type;
}

void Passenger::setRow(int row){
    this->row = row;
}

bool Passenger::operator>(const Passenger& rhs) const{
    return (this->key > rhs.key);
}

bool Passenger::operator<(const Passenger& rhs) const{
    return (this->key < rhs.key);
}

ostream& operator<<(ostream& out, Passenger& rhs){
    return out << "Passenger Last Name: " << rhs.getLastName() << endl
            << "Type: " << rhs.getType() << endl
            << "Row Number: " << rhs.getRow() << endl
            << "Priority Value: " << rhs.getKey() << endl;
}

