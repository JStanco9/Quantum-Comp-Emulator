//
//  Quantum_Emu.hpp
//  
//
//  Created by John Stanco on 7/19/17.
//
//

#ifndef Quantum_Emu_hpp
#define Quantum_Emu_hpp

#include <cstdlib>
#include <ctime>
#include <operators.hpp>

#endif /* Quantum_Emu_hpp */

//Functional approach to creating a set of operations on a theoretical quantum system


class quantum_emu
{
private:
  unsigned i_size,
           o_size;
  cx_vec   i_qbits,
           o_qbits;

public:
  quantum_emu(unsigned, unsigned);
  cx_vec input();
  cx_vec output();
  void X(unsigned i);
  void Y(unsigned i);
  void Z(unsigned i);
  void H(unsigned i);
  void Hadamard();
  void phase(unsigned i, double phase);
  void cPhase(unsigned i, unsigned j, double phase);
  void cX(unsigned i, unsigned j);
  void SWAP(unsigned i, unsigned j);
};