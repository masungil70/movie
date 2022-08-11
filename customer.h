#pragma once
#include <string>
using namespace std;

//°í°´ 
class Customer {
public:
	Customer(string name, string id) : name_(name), id_(id) {
	}

private:
	string name_;
	string id_;
};
