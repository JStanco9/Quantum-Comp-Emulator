//
//  operators.cpp
//  
//
//  Created by John Stanco on 7/27/17.
//
//

#include "../include/operators.hpp"

sp_cx_mat
_X(cx_vec psi, unsigned i)
{
  unsigned size = psi.size(),
           x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\noperator X : Index out of bounds.\n";
  }
  sp_cx_mat P(size, size);
  for(unsigned ind = 0; ind < size; ind++)
  {
    if((ind / x) % 2)
    {
      P(ind, ind - x) = 1;
    }
    else{
      P(ind, ind + x) = 1;
    }
  }
  return P;
}


sp_cx_mat
_Z(cx_vec psi, unsigned i)
{
  unsigned size = psi.size(),
           x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\noperator Z : Index out of bounds.\n";
  }
  sp_cx_mat P(size, size);
  for(unsigned ind = 0; ind < size; ind++)
  {
    if((ind / x) % 2)
    {
      P(ind, ind) = -1;
    }
    else{
      P(ind, ind) = 1;
    }
  }
  return P;
}


sp_cx_mat
_Y(cx_vec psi, unsigned i)
{
  unsigned size = psi.size(),
           x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\noperator Y : Index out of bounds.\n";
  }
  return std::complex<double>(0, 1) * _X(psi, i) * _Z(psi, i);
}


sp_cx_mat
_Phase(cx_vec psi, unsigned i, double phase)
{
  unsigned size = psi.size(),
  x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\noperator Z : Index out of bounds.\n";
  }
  sp_cx_mat P(size, size);
  for(unsigned ind = 0; ind < size; ind++)
  {
    if((ind / x) % 2)
    {
      P(ind, ind) = std::complex<double>(cos(phase), sin(phase));
    }
    else{
      P(ind, ind) = 1;
    }
  }
  return P;
}


sp_cx_mat
_H(cx_vec psi, unsigned i)
{
  unsigned size = psi.size(),
           x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\noperator H : Index out of bounds.\n";
  }
  return (_X(psi, i) + _Z(psi, i)) / sqrt(2);
}


cx_mat
_cU(cx_vec psi, unsigned i, unsigned j, cx_mat (*f)(cx_vec, unsigned))
{
  unsigned size = psi.size(),
           x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\ncontrol Operator : Index out of bounds.\n";
  }
  
  cx_mat U = f(psi, j);
  cx_mat I(size, size);
  I.eye();
  for(unsigned k = 0; k < size; k+=x)
  {
    for(unsigned ind = k; ind < k + x; ind++)
    {
      U.row(ind) = I.row(ind);
    }
    
  }
  return U;
}


sp_cx_mat
_cU(cx_vec psi, unsigned i, unsigned j, sp_cx_mat (*f)(cx_vec, unsigned))
{
  unsigned size = psi.size(),
           x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\ncontrol Operator : Index out of bounds.\n";
  }
  
  sp_cx_mat U = f(psi, j);
  sp_cx_mat I(size, size);
  I.eye();
  for(unsigned k = 0; k < size; k+=x)
  {
    for(unsigned ind = k; ind < k + x; ind++)
    {
      U.row(ind) = I.row(ind);
    }
    
  }
  return U;
}


sp_cx_mat
_cU(cx_vec psi, unsigned i, unsigned j, double phi, sp_cx_mat (*f)(cx_vec, unsigned, double))
{
  unsigned size = psi.size(),
  x = (unsigned)pow(2, i);
  if(x >= size)
  {
    throw "\ncontrol Operator : Index out of bounds.\n";
  }
  
  sp_cx_mat U = f(psi, j, phi);
  sp_cx_mat I(size, size);
  I.eye();
  for(unsigned k = 0; k < size; k+= 2 * x)
  {
    for(unsigned ind = k; ind < k + x; ind++)
    {
      U.row(ind) = I.row(ind);
    }
    
  }
  return U;
}