/*  
 *
 
 
 *
 */

#include "FastFourier.hpp"

using namespace arma;

#define PI 3.141592653589793238

/***************** Help ******************/
std::complex<double>
cexp(double x)
{
    std::complex<double> rVal(cos(x),sin(x));
    return rVal;
}

/***************** FFT/IFFT *****************/
cx_vec
_FFT(cx_vec coeffs)
{
    int     size = coeffs.size();
    cx_vec  X(size);
    if (size == 1)
    {
        X = coeffs;
    }
    else if (size % 2 == 1)
    {
        throw "Polynomial degree must be power of 2";
    }
    else
    {
        cx_vec  evens(size / 2),
                odds(size / 2),
                X_even,
                X_odd;
        
        for(int i = 0; i < size / 2; i++)
        {
            evens(i) = coeffs(2 * i);
            odds(i) = coeffs(2 * i + 1);
        }
        
        X_even = _FFT(evens);
        X_odd = _FFT(odds);
        
        for(int i = 0; i < size; i++)
        {
            X(i) = X_even(i % (size / 2)) + cexp(2 * PI * i / size) * X_odd(i % (size / 2));
        }
    }
    return X;
}

cx_vec
_IFFT(cx_vec coeffs)
{
  int     size = coeffs.size();
          cx_vec  X(size);
  if (size == 1)
  {
    X = coeffs;
  }
  else if (size % 2 == 1)
  {
    throw "Polynomial degree must be power of 2";
  }
  else
  {
    cx_vec  evens(size / 2),
            odds(size / 2),
            X_even,
            X_odd;
    
    for(int i = 0; i < size / 2; i++)
    {
      evens(i) = coeffs(2 * i);
      odds(i) = coeffs(2 * i + 1);
    }
    
    X_even = _IFFT(evens);
    X_odd = _IFFT(odds);
    
    for(int i = 0; i < size; i++)
    {
      X(i) = X_even(i % (size / 2)) + cexp(2 * PI * i / size) * X_odd(i % (size / 2));
    }
  }
  return X;
}


cx_vec
IFFT(cx_vec points)
{
  int     size = points.size();
  return _IFFT(points) / sqrt(size);
}

cx_vec
FFT(cx_vec points)
{
  int     size = points.size();
  return _FFT(points) / sqrt(size);
}

/************** Fast Convolution **************/
cx_vec
conv(cx_vec A, cx_vec B)
{
    if(A.size() != B.size())
    {
        throw "Polynomials must be of same degree";
    }
    cx_vec  A_f = FFT(A),
            B_f = FFT(B),
            C_f(A.size());
    for(int i = 0; i < A.size(); i++)
    {
        C_f(i) = A_f(i) * B_f(i);
    }
    return IFFT(C_f);
}





