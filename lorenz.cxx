#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>

using namespace std;

void krechner(const int a,const int b, const double c, double* k, double* y);

int main(int argc, char** argv){
    if (argc != 3){
        cerr << "argc != 3" << endl;
        return 1;
    }
    
    //ofstream out("lorenzdaten0");
    ofstream out(argv[2]);
    
    const int a=10,b=28;
    const double c=8.0/3.0;
    //const int N = 10000;
    const int N = atoi(argv[1]);
    const int tend = 100;
    const double dt = double(tend)/N;
    
    double y[3],k1[3],k2[3],k3[3],k4[3],zwischen[3];
    
    y[0]=1; //x
    y[1]=1; //y
    y[2]=1; //z
    
    
    
    
    for(int i=0;i<N;i++){
        
        out << i*dt << " " << y[0] << " " << y[1] << " " << y[2] << endl;
        
        
        krechner(a,b,c,k1,y);
        
        zwischen[0] = y[0] + (dt/2.0)*k1[0];
        zwischen[1] = y[1] + (dt/2.0)*k1[1];
        zwischen[2] = y[2] + (dt/2.0)*k1[2];
        krechner(a,b,c,zwischen,y);
        
        zwischen[0] = y[0]+(dt/2.0)*k2[0];
        zwischen[1] = y[1]+(dt/2.0)*k2[1];
        zwischen[2] = y[2]+(dt/2.0)*k2[2];
        krechner(a,b,c,zwischen,y);
        
        zwischen[0] = y[0]+dt*k3[0];
        zwischen[1] = y[1]+dt*k3[1];
        zwischen[2] = y[2]+dt*k3[2];
        krechner(a,b,c,zwischen,y);
        
        
        y[0]= y[0]+(dt/6.0) * (k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
        y[1]= y[1]+(dt/6.0) * (k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);
        y[2]= y[2]+(dt/6.0) * (k1[2] + 2*k2[2] + 2*k3[2] + k4[2]);
        
        
        }
        out.close();
        return 0;
}
    
    
   void krechner(const int a,const int b, const double c, double* k, double* y){
        k[0]=a*(y[1]-y[0]);
        k[1]=y[0]*(b-y[2])-y[1];
        k[2]=y[0]*y[1]-c*y[2];
    }
        
        