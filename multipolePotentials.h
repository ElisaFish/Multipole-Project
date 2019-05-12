//
//  multipolePotentials.h
//  
//
//  Created by Lisa Fishenfeld on 3/16/15.
//
//

#ifndef ____multipolePotentials__
#define ____multipolePotentials__

#include <stdio.h>
#include <iostream>
#include <cmath>

class MultipolePotentials
{
public:
    MultipolePotentials(float** jc, float** js, int length);
    MultipolePotentials(float** jc, float** js, int length, int m) : MultipolePotentials(float** jc, float** js, int length), m_max_(m);
    
    float findR(float x, float y) {return sqrt((x * x) + (y * y));}
    float findTheta(float x, float y) {return atan(y/x);}
    
    float computePhi(float x, float y, int m_max);
    float computeD_phi_d_x(float x, float y, int m_max);
    float computeD_phi_d_y(float x, float y, int m_max);
    float computeD2_phi_d_x2(float x, float y, int m_max);
    float computeD2_phi_d_y2(float x, float y, int m_max);
    float computeD2_phi_d_xy(float x, float y, int m_max);
    
    float computePhi(float x, float y) {return computePhi(float x, float y, m_max_);}
    float computeD_phi_d_x(float x, float y) {return computeD_phi_d_x(float x, float y, m_max_);}
    float computeD_phi_d_y(float x, float y); {return computeD_phi_d_y(float x, float y, m_max_);}
    float computeD2_phi_d_x2(float x, float y); {return computeD2_phi_d_x2(float x, float y, m_max_);}
    float computeD2_phi_d_y2(float x, float y); {return computeD2_phi_d_y2(float x, float y, m_max_);}
    float computeD2_phi_d_xy(float x, float y); {return computeD2_phi_d_xy(float x, float y, m_max_);}
    
    
private:
    const int m_max_;
    float* j_c[4];
    float j_s[4];
    
    /*
    float r;
    float theta;
    
    float phi;
    float d_phi_d_x;
    float d_phi_d_y;
    float d2_phi_d_x2;
    float d2_phi_d_y2;
    float d2_phi_d_xy;
    
    
    void setPhi();
    void setD_phi_d_x();
    void setD_phi_d_y();
    void setD2_phi_d_x2();
    void setD2_phi_d_y2();
    void setD2_phi_d_xy();
     */
    
    //void multipolePotentials(float x, float y, float phi, float d_phi_d_x, float d_phi_d_y, float d2_phi_d_x2, float d2_phi_d_y2, float d2_phi_d_xy);

};

#endif /* defined(____multipolePotentials__) */
