//
//  operators.hpp
//  
//
//  Created by John Stanco on 7/27/17.
//
//

#ifndef operators_hpp
#define operators_hpp

#include <stdio.h>
#include <armadillo>

using namespace arma;

sp_cx_mat _X(cx_vec psi, unsigned i);
sp_cx_mat _Y(cx_vec psi, unsigned i);
sp_cx_mat _Z(cx_vec psi, unsigned i);
sp_cx_mat _H(cx_vec psi, unsigned i);
sp_cx_mat _Phase(cx_vec psi, unsigned i, double phase);
cx_mat _cU(cx_vec psi, unsigned i, unsigned j, cx_mat (*f)(cx_vec, unsigned));
sp_cx_mat _cU(cx_vec psi, unsigned i, unsigned j, sp_cx_mat (*f)(cx_vec, unsigned));
sp_cx_mat _cU(cx_vec psi, unsigned i, unsigned j, double phi, sp_cx_mat (*f)(cx_vec, unsigned, double));
cx_vec _SWAP(cx_vec psi, unsigned i, unsigned j);
sp_cx_mat _cX(cx_vec psi, unsigned i, unsigned j);

#endif /* operators_hpp */
