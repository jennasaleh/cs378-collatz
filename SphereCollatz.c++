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


using namespace std;

#define SIZE 50000

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


    /******************* CACHE *******************/
<<<<<<< HEAD
    int cache[SIZE] = {0};
=======
    #ifdef SIZE
    int cache[SIZE] = {0};
    #endif
>>>>>>> dev

    /*******************************************************/

    while (i <= j) 
    {
<<<<<<< HEAD
=======
        #ifdef SIZE
>>>>>>> dev
        if((i < SIZE) && (cache[i] != 0))
        {
            return cache[i];
        }
<<<<<<< HEAD
=======
        #endif
>>>>>>> dev

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
<<<<<<< HEAD
=======
                #ifdef SIZE
>>>>>>> dev
                if(i < SIZE)
                {
                    cache[i] = maxcycle;
                }
<<<<<<< HEAD
=======
                #endif
>>>>>>> dev
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

        // -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------



// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
 
/*
% g++-4.8 -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% cat RunCollatz.in
1 10
100 200
201 210
900 1000



% RunCollatz < RunCollatz.in > RunCollatz.out



% cat RunCollatz.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/