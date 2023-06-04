#include <bits/stdc++.h>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;
//
//     __     ______     +-------------------------------------------------+
//    /\ \   /\  __ \    | Author:   Julius Arnold                         |
//   _\_\ \  \ \  __ \   | E-Mail:   julius.arnold@hotmail.com             |  
//  /\_____\  \ \_\ \_\  | GitHub:   https://github.com/JuliusArnold       |
//  \/_____/   \/_/\/_/  +-------------------------------------------------+ 
//

// Global Variables

int _world_x1 = -3;
int _world_x2 = 3;
int _world_y1 = -3;
int _world_y2 = 3;
int _world_z1 = 0;
int _world_z2 = 6;
double _sab = 0.1;
double _sen = 0.2;
double _mu  = 0.4;



class Particle {
  public:
    double dr, dtheta ,dphi;
    std::vector<double> X,Y,Z;

    Particle (double,double,double,double,double,double);
    void removeOne();
    void move(double);
    void change_direction(double,double);
};

Particle::Particle (double x, double y, double z, double r, double theta, double phi) {
  X.push_back(x);
  Y.push_back(y);
  Z.push_back(z);
  dr = r;
  dtheta = theta;
  dphi = phi;
}

void Particle::move(double l){
  dr = l;

  double dx = dr * sin(dtheta) * cos(dphi);
  double dy = dr * sin(dtheta) * sin(dphi);
  double dz = dr * cos(dtheta);
        
  X.push_back( X.back() + dx );
  Y.push_back( Y.back() + dy );
  Z.push_back( Z.back() + dz );
}

void Particle::removeOne(){
  X.pop_back();
  Y.pop_back();
  Z.pop_back();
}

void Particle::change_direction(double theta ,double phi){
  dtheta  = theta;
  dphi    = phi ;
}




int main(int argc, char *argv[]){

  int N = 4000;
  std::cout << "Please enter an integer value: ";
  std::cin >> N;

  for (int n = 0; n < N ; n++ ){
    Particle part (0,0,0,0,0,0);

    bool running = true;

    while (running) {
      // Check bounds
      //
      double temp_x = part.X.back();
      double temp_y = part.Y.back();
      double temp_z = part.Z.back();

      if (temp_x < _world_x1){
        part.removeOne();
        running = false;
        break ;
      } else if (temp_x > _world_x2){
        part.removeOne();
        running = false;
        break ;
      } else if (temp_y < _world_y1){
        part.removeOne();
        running = false;
        break ;
      } else if (temp_y > _world_y2){
        part.removeOne();
        running = false;
        break ;
      } else if (temp_z < _world_z1){
        part.removeOne();
        running = false;
        break ;
      } else if (temp_z > _world_z2){
        part.removeOne();
        running = false;
        break ;
      }

      double r = ((double) std::rand() / (RAND_MAX));
      double l = -1 * log(1-r)/_mu;
      part.move(l);

      double s = ((double) std::rand() / (RAND_MAX));
      if (s<=_sab){
        // Photon gets absorbed
        part.removeOne();
        running = false;
        break ;
      // else if (s <= _sab + _sen) {
      } else {
        double theta = 2 * M_PI * ((double) std::rand() / (RAND_MAX));
        double phi   = M_PI * ((double) std::rand() / (RAND_MAX));
        part.change_direction(theta,phi);
      } 
    }
    plt::plot(part.X,part.Z);
  }
  plt::show();
	return 0;
}

