//
//  Quantum_Emu.cpp
//  
//
//  Created by John Stanco on 7/19/17.
//
//

#include "../include/Quantum_Emu.hpp"

quantum_emu::quantum_emu(unsigned m, unsigned n)
{
  i_size = m;
  o_size = n;
  i_qbits = cx_vec(pow(2, m));
  o_qbits = cx_vec(pow(2, n));
  i_qbits.zeros();
  i_qbits(0) = 1;
  Hadamard();
}

cx_vec
quantum_emu::input()
{
  return i_qbits;
}

cx_vec
quantum_emu::output()
{
  return o_qbits;
}

void
quantum_emu::X(unsigned i)
{
  i_qbits = _X(i_qbits, i) * i_qbits;
}

void
quantum_emu::Y(unsigned i)
{
  i_qbits = _Y(i_qbits, i) * i_qbits;
}

void
quantum_emu::Z(unsigned i)
{
  i_qbits = _Z(i_qbits, i) * i_qbits;
}

void
quantum_emu::H(unsigned i)
{
  i_qbits = _H(i_qbits, i) * i_qbits;
}

void
quantum_emu::Hadamard()
{
  for(int i = 0; i < i_size; i++)
  {
    H(i);
  }
}

void
quantum_emu::cX(unsigned i, unsigned j)
{
  i_qbits = _cU(i_qbits, i, j, &_X) * i_qbits;
}

void
quantum_emu::phase(unsigned i, double phi)
{
  i_qbits = _Phase(i_qbits, i, phi) * i_qbits;
}

void
quantum_emu::cPhase(unsigned i, unsigned j, double phi)
{
  i_qbits = _cU(i_qbits, i, j, phi, &_Phase) * i_qbits;
}

void
quantum_emu::SWAP(unsigned i, unsigned j)
{
  cX(i, j);
  cX(j, i);
  cX(i, j);
}