// THIS PROGRAM RELEASED INTO THE PUBLIC DOMAIN UNDER CREATIVE COMMONS ZERO 1.0 UNIVERSAL PUBLIC DOMAIN DEDICATION
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;
ofstream out;
int main(){
    double a,b; //Endpoints of integration
    int n; //Number of sections
    string func=""; //Where the function will be
    char rule='\0'; //Which rule is used
    cout << "Enter the function you want an approximate integral of, in C++ code. Use the variable name x (lowercase).\n(using the cmath library is allowed)\n";
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
    out.open("calc.cpp");
    switch(rule){
        case 'L': //Left-hand rule
        case 'l':
        out << "#include <iostream>\n";
        out << "#include <cmath>\n";
        out << "using namespace std;\n";
        out << "double func(double x){\n";
        out << "  double out=" << func << ";\n";
        out << "  return out;\n";
        out << "}\n";
        out << "int main(){\n";
        out << "  double a=" << a << ";\n";
        out << "  double b=" << b << ";\n";
        out << "  int n=" << n << ";\n";
        out << "  double dx=(b-a)/n;\n";
        out << "  double output;\n";
        out << "  for(int i=0; i<n; i++){\n";
        out << "    output += func(a+(i*dx));\n";
        out << "  }\n";
        out << "  output *= dx;\n";
        out << "  cout << output << endl;\n";
        out << "  return 0;\n";
        out << "}\n";
        break;
        case 'R': //Right-hand rule
        case 'r':
        out << "#include <iostream>\n";
        out << "#include <cmath>\n";
        out << "using namespace std;\n";
        out << "double func(double x){\n";
        out << "  double out=" << func << ";\n";
        out << "  return out;\n";
        out << "}\n";
        out << "int main(){\n";
        out << "  double a=" << a << ";\n";
        out << "  double b=" << b << ";\n";
        out << "  int n=" << n << ";\n";
        out << "  double dx=(b-a)/n;\n";
        out << "  double output;\n";
        out << "  for(int i=1; i<=n; i++){\n";
        out << "    output += func(a+(i*dx));\n";
        out << "  }\n";
        out << "  output *= dx;\n";
        out << "  cout << output << endl;\n";
        out << "  return 0;\n";
        out << "}\n";
        break;
        case 'M': //Midpoint rule
        case 'm':
        out << "#include <iostream>\n";
        out << "#include <cmath>\n";
        out << "using namespace std;\n";
        out << "double func(double x){\n";
        out << "  double out=" << func << ";\n";
        out << "  return out;\n";
        out << "}\n";
        out << "int main(){\n";
        out << "  double a=" << a << ";\n";
        out << "  double b=" << b << ";\n";
        out << "  int n=" << n << ";\n";
        out << "  double dx=(b-a)/n;\n";
        out << "  double output;\n";
        out << "  for(int i=0; i<n; i++){\n";
        out << "    output += func(a+((i+0.5)*dx));\n";
        out << "  }\n";
        out << "  output *= dx;\n";
        out << "  cout << output << endl;\n";
        out << "  return 0;\n";
        out << "}\n";
        break;
        case 'T': //Trapezoid rule
        case 't':
        out << "#include <iostream>\n";
        out << "#include <cmath>\n";
        out << "using namespace std;\n";
        out << "double func(double x){\n";
        out << "  double out=" << func << ";\n";
        out << "  return out;\n";
        out << "}\n";
        out << "int main(){\n";
        out << "  double a=" << a << ";\n";
        out << "  double b=" << b << ";\n";
        out << "  int n=" << n << ";\n";
        out << "  double dx=(b-a)/n;\n";
        out << "  double output;\n";
        out << "  for(int i=0; i<n; i++){\n";
        out << "    output += (func(a+(i*dx))+func(a+((i+1)*dx)));\n";
        out << "  }\n";
        out << "  output *= (dx/2);\n";
        out << "  cout << output << endl;\n";
        out << "  return 0;\n";
        out << "}\n";
        break;
        case 'S': //Simpson's rule
        case 's':
        if(fmod(n,2)){
            cout << "The number of divisions must be even for Simpson's rule.\n";
            return 1;
        }
        out << "#include <iostream>\n";
        out << "#include <cmath>\n";
        out << "using namespace std;\n";
        out << "double func(double x){\n";
        out << "  double out=" << func << ";\n";
        out << "  return out;\n";
        out << "}\n";
        out << "int main(){\n";
        out << "  double a=" << a << ";\n";
        out << "  double b=" << b << ";\n";
        out << "  int n=" << n/2 << ";\n"; //A weighted average of Midpoint and Trapezoid with n/2 divisions is equal to Simpson with n divisions
        out << "  double dx=(b-a)/n;\n";
        out << "  double output;\n";
        out << "  for(int i=0; i<n; i++){\n";
        out << "    output += dx*(func(a+(i*dx))+func(a+((i+1)*dx)))/2;\n";
        out << "    output +=dx*func(a+((i+0.5)*dx))*2;\n";
        out << "  }\n";
        out << "  output /= 3;\n";
        out << "  cout << output << endl;\n";
        out << "  return 0;\n";
        out << "}\n";
        break;
        default:
        cout << "Not a valid input.\n";
        return 1;
    }
    out.close();
    system("g++ calc.cpp -o calc"); //Compile and run the program created
    system("./calc");
    return 0;
}
