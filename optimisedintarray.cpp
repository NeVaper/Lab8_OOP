#include "optimisedintarray.h"

OptimisedIntArray::OptimisedIntArray()
  : m_size{0}, m_capacity{0}, m_currBlocksAmount{0}, m_array{nullptr} {

}

OptimisedIntArray::~OptimisedIntArray() {
  if (m_array) {
      for (int i = 0; i < m_currBlocksAmount; ++i) {
          delete[] m_array[i];
        }
      delete[] m_array;
    }
}

void OptimisedIntArray::changeBlocksAmount(int amount) {
  // allocate new memory
  int **newArray = new int*[amount];

  for (int i = 0; i < amount; ++i) {
      newArray[i] = new int[(i + 1)];

      if (i < m_currBlocksAmount) {
          for (int j = 0; j <= i; ++j) {
              newArray[i][j] = m_array[i][j];
            }
        }
      else {
          for (int j = 0; j <= i; ++j) {
              newArray[i][j] = 0;
            }
        }
    }

  //delete past memory
  for (int i = 0; i < m_currBlocksAmount; ++i) {
      delete[] m_array[i];
    }
  if (m_array) {
      delete[] m_array;
    }

  //update state and set pointer to new allocated memory
  m_currBlocksAmount = amount;

  m_capacity = 0;
  for (int i = m_currBlocksAmount; i > 0; --i) {
      m_capacity += i;
    }

  m_array = newArray;
}

void OptimisedIntArray::resize(int size) {
  assert(size >= 0 && "Size of array must be non negative!");

  if (size <= m_capacity) {
      m_size = size;

    } else {
      int i = 0;
      int capacityCounter = 0;

      while (capacityCounter < size) {
          capacityCounter += ++i;
        }

      changeBlocksAmount(i);
      m_size = size;
    }
}

int OptimisedIntArray::element(int index) {
  assert((index >= 0) && "Element of array must have non negative index!");

  if (index >= m_size) {
      resize(index + 1);
    }

  int i = 0;
  int capacityCounter = 0;

  while (capacityCounter < index + 1) {
      capacityCounter += ++i;
    }

  return m_array[i - 1][(i - 1) - (capacityCounter - (index + 1))];
}

void OptimisedIntArray::setEl(int value, int index) {
  if (index >= m_size) {
      resize(index + 1);
    }

  int i = 0;
  int capacityCounter = 0;

  while (capacityCounter < index + 1) {
      capacityCounter += ++i;
    }

  m_array[i - 1][(i - 1) - (capacityCounter - (index + 1))] = value;
}

void OptimisedIntArray::setEl(int value) {
  setEl(value, m_size);
}
