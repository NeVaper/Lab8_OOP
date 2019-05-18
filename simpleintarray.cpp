#include "simpleintarray.h"

SimpleIntArray::SimpleIntArray()
  : m_size{0}, m_array{nullptr} {

}

SimpleIntArray::~SimpleIntArray() {
  if (m_array) {
      delete[] m_array;
    }
}

void SimpleIntArray::resize(int size) {
  assert(size > 0 && "Size of array must be positive!");

  int *arr = new int[size];
  for (int i = 0; i < size; ++i) {
      if (i < m_size) {
          arr[i] = m_array[i];
        } else {
          arr[i] = 0;
        }
    }

  delete[] m_array;
  m_array = arr;
  m_size = size;
}

void SimpleIntArray::setEl(int value) {
  resize(m_size + 1);
  m_array[m_size - 1] = value;
}

void SimpleIntArray::setEl(int value, int index) {
  if (index >= m_size) {
      resize(index + 1);
    }
  m_array[index] = value;
}

int SimpleIntArray::element(int index) {
  assert((index >= 0) && "Element of array must have non negative index!");

  if (index >= m_size) {
      resize(index + 1);
    }

  return m_array[index];
}

