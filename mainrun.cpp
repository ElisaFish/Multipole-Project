//
//  mainrun.cpp
//  
//
//  Created by Lisa Fishenfeld on 3/19/15.
//
//

#include <stdio.h>
#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
//#include <math.h>
#include <cmath>
#include "multipolePotentials.h"

using namespace std;

int main(int argc, char **argv)
{
    int m=3;
    float x = 20;
    float y = 50;
    //float** jc[m+1] = { 1., 1., 1., 1. };
    //float** js[m+1] = { 1., 1., 1., 1. };
    cout << "main, before object creation" << endl;
    
    MultipolePotentials multi(x,y, /*&jc, &js,*/ m);
    
    cout << "main, after object creation" << endl;
    
    cout << "r = " << multi.getR() << endl;
    cout << "theta = " << multi.getTheta() << endl;
    cout << "phi = " << multi.getPhi() << endl;
    cout << "d phi / dx = " << multi.getD_phi_d_x() << endl;
    cout << "d phi / dy = " << multi.getD_phi_d_y() << endl;
    cout << "d2 phi / dx2 = " << multi.getD2_phi_d_x2() << endl;
    cout << "d2 phi / dy2 = " << multi.getD2_phi_d_y2() << endl;
    cout << "d2 phi / dx dy = " << multi.getD2_phi_d_xy() << endl;
    
    return 1;
}
