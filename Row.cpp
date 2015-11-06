#include"Row.h"
#include<iostream>
#include<vector>
using std::cout;
using std::endl;

Row::Row(int num){
    numValues = num;
    for (int entry = 0; entry < numValues; entry++){
        row.push_back(0);
    }
}