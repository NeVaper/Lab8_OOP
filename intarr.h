#ifndef ARRAY_H
#define ARRAY_H

class IIntArr {
public:
  virtual void setEl(int value) = 0; // push_back analog
  virtual void setEl(int value, int index) = 0;

  virtual int element(int index) = 0;

  virtual ~IIntArr() {}
};

#endif // ARRAY_H
