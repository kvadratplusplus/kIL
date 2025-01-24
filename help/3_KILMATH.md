# KILMATH - mathematical operations of kIL
## sum, dif, mul, div - operations with integers
### Syntax:
``` c
sum int(value) int(value);
sum int(value) int(value) ...;
dif int(value) int(value);
dif int(value) int(value) ...;
mul int(value) int(value);
mul int(value) int(value) ...;
div int(value) int(value);
div int(value) int(value) ...;
```
All its funclions can operate with 2 or more int numbers (it can be negative)
### Example:
``` c
sum 2 1; endl;
dif 10 5; endl;
mul 8 7; endl;
div 14 7; endl;
sum 14 36 81; endl;
dif 112 34 52; endl;
mul 2 3 7; endl;
div 16 2 2; endl;
```
### Output:
```
3
5
56
2
131
26
42
4
```
## fsum, fdif, fmul, fdiv - operations with floats
### Syntax:
``` c
fsum float(value) float(value);
fsum float(value) float(value) ...;
fdif float(value) float(value);
fdif float(value) float(value) ...;
fmul float(value) float(value);
fmul float(value) float(value) ...;
fdiv float(value) float(value);
fdiv float(value) float(value) ...;
```
All its funclions can operate with 2 or more float numbers (it can be negative)
### Example:
``` c
fsum 2.5 6.3; endl;
fdif 11.15 12.2; endl;
fmul 2.5 2.3; endl;
fdiv 14.4 2.5; endl;
fsum 2.14 3.48 53.3; endl;
fdif 123.24 65.2 5.1246; endl;
fmul 3.256 5.48 9.3; endl;
fdiv 100.128 23.1 2.2; endl;
```
### Output:
```
8.8
-1.05
5.75
5.76
58.92
52.9154
165.939
1.97025
```