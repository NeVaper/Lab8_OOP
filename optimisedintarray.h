#ifndef OPTIMISEDINTARRAY_H
#define OPTIMISEDINTARRAY_H

#include <cassert>

#include "intarr.h"

class OptimisedIntArray : public IIntArr {
protected:
  int m_size;
  int m_capacity;
  int m_currBlocksAmount;

  int** m_array;

  void changeBlocksAmount(int amount);

  void resize(int size);

public:
  virtual void setEl(int value); // push_back analog
  virtual void setEl(int value, int index);

  virtual int element(int index);

  OptimisedIntArray();
  virtual ~OptimisedIntArray();
};

#endif // OPTIMISEDINTARRAY_H
