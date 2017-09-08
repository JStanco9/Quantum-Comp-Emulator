//
//  FastFourier.hpp
//  
//
//  Created by John Stanco on 5/31/17.
//
//

#ifndef FastFourier_h
#define FastFourier_h

#include <armadillo>
#include <iostream>
#include <fstream>

arma::cx_vec FFT(arma::cx_vec coeffs);
arma::cx_vec IFFT(arma::cx_vec points);

#endif /* FastFourier_h */
