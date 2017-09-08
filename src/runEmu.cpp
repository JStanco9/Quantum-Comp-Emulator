//
//  runEmu.cpp
//  
//
//  Created by John Stanco on 7/27/17.
//
//

#include "../include/Quantum_Emu.hpp"
#include "../../FastFourier/FastFourier.hpp"

#define PI 3.141592653589793238

int
main()
{
  try{
    quantum_emu q(3, 3);
    q.input().print();
    std::cout << std::endl;
    
    cx_vec f = FFT(q.input());
    f.print();
    std::cout << std::endl;
    
    /***operations go here***/
   
    //Will perform Fourier Transform using quantum gates
    //and print to compare to vector obtained via FFT
    
    q.H(0);
    q.cPhase(1, 0, PI / 2);
    q.H(1);
    q.cPhase(2, 0, PI / 4);
    q.cPhase(2, 1, PI / 2);
    q.H(2);
    
    /************************/
    std::cout << std::endl;
    q.input().print();
  }
  catch(char const* err)
  {
    cerr << err << std::endl;
  }
  catch(...)
  {
    return EXIT_FAILURE;
  }
  return 0;
}