// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <cmath>    // abs

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) 
{
    // error checking and weird cases
    assert(i > 0);
    assert(j > 0);
    assert(i < 1000000);
    assert(j < 1000000);

    if( (i==1) & (j==1))
        return 1;

    int temp;
    int k;
    int currentcycle, maxcycle;

    currentcycle = 1;
    maxcycle = 0;

    // if second value is lower, switch values of i and j
    if(j < i)
    {
        temp = i;
        i = j;
        j = temp;
    }
 
    while (i <= j)
    {
        k = i;

        while (k != 1)
        {
            if((k % 2) != 0)
            {
                k = 3 * k + 1;
                currentcycle++;
            }
            else 
            {
                k = k / 2;
                currentcycle++;
            } 
        }

        if(k == 1)
        {   

            if(currentcycle > maxcycle)
            {
                maxcycle = currentcycle;  
            } 
        }     

        currentcycle = 1;         
        i++;  
    }

    return maxcycle;

}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}