//
//  multipolePotentials.cpp
//  
//
//  Created by Lisa Fishenfeld on 3/16/15.
//
//

#include "multipolePotentials.h"


//MultipolePotentials::MultipolePotentials(float x, float y, /*float** jc, float** js,*/ int m) : m_max_(m) //, j_c[m+1](), j_s[m+1]()
/*{
    for(int i=0; i<=m_max; i++)
    {
        j_c[i] = (float) i;
        j_s[i] = (float) i;
    }
    
    r = sqrt((x * x) + (y * y));
    theta = atan(y/x);
    
    setPhi();
    setD_phi_d_x();
    setD_phi_d_y();
    setD2_phi_d_x2();
    setD2_phi_d_y2();
    setD2_phi_d_xy();
}
 */

MultipolePotentials::MultipolePotentials(float** jc, float** js, int length)
{
    //save jc and js
}

float MultipolePotentials::computePhi(float x, float y, int m_max)
{
    float r = findR(x, y);
    float theta = findTheta(x, y);
    float summation = 0;
    
    for (int m=1; m<=m_max; m++)
    {
        summation += ((j_c[m] * cos(m * theta))+(j_s[m] * sin(m * theta))) * pow(r, (float) m) / m;
    }
    
    return 2 * (j_c[0] - summation);
}

float MultipolePotentials::computeD_phi_d_x(float x, float y, int m_max)
{
    float r = findR(x, y);
    float theta = findTheta(x, y);
    float summation = 0;
    
    for (int m=1; m<=m_max; m++)
    {
        summation += ((j_c[m] * cos((m-1) * theta)) + (j_s[m] * sin((m-1) * theta))) * pow(r, m-1);
    }
    
    return -2 * summation;
}

void MultipolePotentials::computeD_phi_d_y(float x, float y, int m_max)
{
    float r = findR(x, y);
    float theta = findTheta(x, y);
    float summation = 0;
    
    for (int m=1; m<=m_max; m++)
    {
        summation += ((-1 * j_c[m] * sin((m-1) * theta)) + (j_s[m] * cos((m-1) * theta))) * pow(r, m-1);
    }
    
    return -2 * summation;
}
                      
void MultipolePotentials::computeD2_phi_d_x2(float x, float y, int m_max)
{
    float r = findR(x, y);
    float theta = findTheta(x, y);
    float summation = 0;
            
    for (int m=1; m<=m_max; m++)
    {
        summation += ((j_c[m] * cos((m-2) * theta)) + (j_s[m] * sin((m-2) * theta))) * (m-1) * pow(r, m-2);
    }
            
    return -2 * summation;
}
                      
void MultipolePotentials::computeD2_phi_d_y2(float x, float y, int m_max)
{
    //d2_phi_d_y2 = -1 * d2_phi_d_x2;
    return -1 * computeD2_phi_d_x2(x, y, m_max);
}

void MultipolePotentials::computeD2_phi_d_xy(float x, float y, int m_max)
{
    float r = findR(x, y);
    float theta = findTheta(x, y);
    float summation = 0;

    for (int m=1; m<=m_max; m++)
    {
        summation += ((-1 * j_c[m] * sin((m-2) * theta)) + (j_s[m] * cos((m-2) * theta))) * (m-1) * pow(r, m-2);
    }

    return -2 * summation;
}

/*
void multipolePotentials(float x, float y, float phi, float d_phi_d_x, float d_phi_d_y, float d2_phi_d_x2, float d2_phi_d_y2, float d2_phi_d_xy)
{
    r = sqrt((x * x) + (y * y));
    theta = atan(y/x);
    
    phi = phi(r, theta);
    d_phi_d_x = d_phi_d_x(r, theta);
    d_phi_d_y = d_phi_d_y(r, theta);
    d2_phi_d_x2 = d2_phi_d_x2(r, theta);
    d2_phi_d_y2 = d2_phi_d_y2(r, theta);
    d2_phi_d_xy = d2_phi_d_xy(r, theta);
}
*/