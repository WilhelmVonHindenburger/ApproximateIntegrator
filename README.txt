  This program is a calculator that does
approximate integration. The function integrated,
the end points, which of five methods of
approximate integration to use (Left-hand rule,
Right-hand rule, Midpoint rule, Trapezoid rule,
and Simpson's rule), and how many divisions to
split the integrated region into.

  This program is released into the Public Domain
through the Creative Commons Zero 1.0 Universal
Public Domain Dedication (see LICENSE.txt file)

VERSION SPECIFIC INFORMATION

VERSIONS 1.x:
  Any version beginning with the number 1 of this
program requires a calc.cpp file that it will
write to. If one does not exist, it should create
one itself. This external file will not be needed
when version 2 releases.

VERSIONS 1.0-1.1
  Versions 1.0 and 1.1 of this program only run
on GNU/Linux systems that have the GNU C++
compiler run with "g++". They can be adapted for
other systems but the system() commands at the
end must be changed to whatever commands are used
to run the compiler and the compiled calc.cpp
program. This problem was fixed in version 1.2.
