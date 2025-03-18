#include <iostream>

using namespace std;
class Operator{
  public:
  virtual eval(Operator a; Operator b) = 0;
};
class Num_Op: public Operator{
  public:
  int eval(int a) override{
    return a;
  }
};

class Sum_Op: public Operator{
  public:
  int eval(int a; int b) override{
    return a + b;
  }
};

class Min_Op: public Operator{
  public:
  int eval(int a; int b) override{
    return a - b;
  }
};

class Mul_Op: public Operator{
  public:
  int eval(int a; int b) override{
    return a * b;
  }
};

class Dev_Op: public Operator{
  public:
  int eval(int a; int b) override{
    return a / b;
  }
};

int main(){
  return 0;
}
