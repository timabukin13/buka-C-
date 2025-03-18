#include <iostream>

using namespace std;
class Operator{
  public:
  virtual double eval() = 0;
};
class Num_Op: public Operator{
  private:
  double num;
  public:
  double eval() override{
    return num;
  }
};

class Sum_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  double eval() override{
    return left -> eval() + right -> eval();
  }
};

class Min_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  double eval() override{
    return left -> eval() - right -> eval();
  }
};

class Mul_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  double eval() override{
    return left -> eval() * right -> eval();
  }
};

class Dev_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  double eval() override{
    return left -> eval() / right -> eval();
  }
};

int main(){
  return 0;
}
