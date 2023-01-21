// THIS PROGRAM RELEASED INTO THE PUBLIC DOMAIN UNDER CREATIVE COMMONS ZERO 1.0 UNIVERSAL PUBLIC DOMAIN DEDICATION
// VERSION: 2.0-dev
#include <iostream>
#include <cmath>
using namespace std;
//M_E AND M_PI ARE IN CMATH
//const double M_E=2.718281828459045235360;
//const double M_PI=3.14159265358979323846264338327950;
const double M_TAU=6.28318530717958647692528;
//LEFT HAND RULE
template <typename Func>double LHR(double a,double b,int n, Func func){
  double dx=(b-a)/n;
  double output;
  for(int i=0; i<n; i++){
    output += func(a+(i*dx));
  }
  output *= dx;
  return output;
}
//RIGHT HAND RULE
template <typename Func>double RHR(double a,double b,int n, Func func){
  double dx=(b-a)/n;
  double output;
  for(int i=1; i<=n; i++){
    output += func(a+(i*dx));
  }
  output *= dx;
  return output;
}
//MIDPOINT RULE
template <typename Func>double MR(double a,double b,int n, Func func){
  double dx=(b-a)/n;
  double output;
  for(int i=0; i<n; i++){
    output += func(a+((i+0.5)*dx));
  }
  output *= dx;
  return output;
}
//TREAPEZOID RULE
template <typename Func>double TR(double a,double b,int n, Func func){
  double dx=(b-a)/n;
  double output;
  for(int i=0; i<n; i++){
    output += (func(a+(i*dx))+func(a+((i+1)*dx)));
  }
  output *= (dx/2);
  return output;
}
//SIMPSON RULE
template <typename Func>double SR(double a,double b,int n, Func func){
  return (TR(a,b,n,func)/3)+(MR(a,b,n,func)*(2/3));
}

//EVALUATOR
struct Expression{
  char op;
  Expression* l;
  Expression* r;
}

Expression parse(string func){
  // OH NO THE PARSER
}

double evalaute (Expression func){
  //EVALUTE PARSED EXPRESSION
}

int main(){
  double a,b; //Endpoints of integration
  int n; //Number of sections
  string func=""; //Where the function will be
  char rule='\0'; //Which rule is used
  double integral; //Final integral
  cout << "Enter the function you want an approximate integral of, in C++ code. Use the variable name x (lowercase).\n(using the cmath library is allowed)\n";
  cout << "Three mathematical constants can be used: M_E (e, 2.71828...), M_PI (pi, 3.14159...), and M_TAU (tau = 2*pi, or 6.28318...)\n";
  cout << "The function will be placed into another file looking like this:\n\n";
  cout << "double func(double x){\n  double out=%s;\n  return out;\n}\n\n";
  cout << "Where %s contains the text of your function.\n";
  getline(cin, func);
  cout << "Enter the start and end points for your approximate integration.\n";
  cin >> a >> b;
  double temp; //To make sure a<b
  if(a>b){
    temp=a;
    a=b;
    b=temp;
  }
  cout << "Which integration method to use?\n";
  cout << "(L)eft-hand rule, (R)ight-hand rule, (M)idpoint rule, (T)rapezoid rule, or (S)impson's rule?\n";
  cin >> rule;
  cout << "How many intervals to split this into? (Must be even if Simpson's rule chosen)\n";
  cin >> n;
  switch(rule){
    case 'L': //LEFT HAND RULE
    case 'l':
      integral=LHR(a, b, n, func);
      break;
    case 'R':
    case 'r':
      integral=RHR(a,b,n,func);
      break;
    case 'M':
    case 'm':
      integral=MR(a,b,n,func);
      break;
    case 'T':
    case 't':
      integral=TR(a,b,n,func);
      break;
    case 'S':
    case 's':
      if(fmod(n,2)){
        cerr << "The number of divisions must be even for Simpson's rule.\n";
        return 1;
      }
      integral=SR(a,b,n/2,func);
      break;
    default:
      cerr << "Not a valid input.\n";
      return 1;
  }
  cout << integral << endl;
  return 0;
}
