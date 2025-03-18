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
  Num_Op(double n){
    num = n;
  }
  double eval() override{
    return num;
  }
};

class Sum_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  Sum_Op(Operator* l,Operator* r){
    left = l;
    right = r;
  }
  double eval() override{
    return left -> eval() + right -> eval();
  }
};

class Min_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  Min_Op(Operator* l,Operator* r){
    left = l;
    right = r;
  }
  double eval() override{
    return left -> eval() - right -> eval();
  }
};

class Mul_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  Mul_Op(Operator* l,Operator* r){
    left = l;
    right = r;
  }
  double eval() override{
    return left -> eval() * right -> eval();
  }
};

class Dev_Op: public Operator{
  private:
    Operator*left;
    Operator*right;
  public:
  Dev_Op(Operator* l,Operator* r){
    left = l;
    right = r;
  }
  double eval() override{
    return left -> eval() / right -> eval();
  }
};

int main(){
  Sum_Op rootsum(new Num_Op(7),new Num_Op(13));
  double resultsum = rootsum.eval();
  cout << resultsum << "  ";
  
  Min_Op rootmin(new Num_Op(7),new Num_Op(13));
  double resultmin = rootmin.eval();
  cout << resultmin << "  ";
  
  Mul_Op rootmul(new Num_Op(7),new Num_Op(13));
  double resultmul = rootmul.eval();
  cout << resultmul << "  ";
  
  Dev_Op rootdev(new Num_Op(7),new Num_Op(13));
  double resultdev = rootdev.eval();
  cout << resultdev << "  ";
  
  return 0;
}
