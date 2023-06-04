#include <bits/stdc++.h>
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <matplotlibcpp.h>

namespace plt = matplotlibcpp;


//
//     __     ______     +-------------------------------------------------+
//    /\ \   /\  __ \    | Author:   Julius Arnold                         |
//   _\_\ \  \ \  __ \   | E-Mail:   julius.arnold@hotmail.com             |  
//  /\_____\  \ \_\ \_\  | GitHub:   https://github.com/JuliusArnold       |
//  \/_____/   \/_/\/_/  +-------------------------------------------------+ 
// 




int main(int argc, char *argv[]){
std::cout << "Main Function\n" ;

  int N = 4000;
  std::cout << "Please enter an integer value: ";
  std::cin >> N;

  std::vector<double> Y ;
  Y.reserve(N);

  double inside = 1;
  double outside = 1;

  for (int i = 0 ; i < N ; i++ ){
    double x;
    double y;
    double pi_estimate;


    x = ((double) std::rand() / (RAND_MAX));
    y = ((double) std::rand() / (RAND_MAX));
    
    x = x - 0.5;
    y = y - 0.5;

    if ( x*x + y*y < 0.25) {
      inside++;  
      outside++;  
    } else {
      outside++;  
    }

    pi_estimate = 4 * inside / outside;
    Y.push_back(pi_estimate); 

    std::cout << inside << "    " << outside << "     " << pi_estimate << "\n";
  }
  
  plt::plot(Y);
  plt::show();

	return 0;
}

