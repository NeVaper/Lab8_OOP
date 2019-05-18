#ifndef SIMPLEINTARRAY_H
#define SIMPLEINTARRAY_H

#include <cassert>

#include "intarr.h"

class SimpleIntArray : public IIntArr {
protected:
  int m_size;

  int* m_array;

  void resize(int size);

public:
  virtual void setEl(int value); // push_back analog
  virtual void setEl(int value, int index);

  virtual int element(int index);

  SimpleIntArray();
  ~SimpleIntArray();
};

#endif // SIMPLEINTARRAY_H
