# KILVARS - variables of kIL
## ivar, fvar - int and float variables
## set - initialize/set variable
### Syntax:
``` c
ivar set int(address) int(value);
fvar set int(address) float(value);
```
### Example:
``` c
fvar set 0 3.14;
fvar set 2 3.3; // 1 address specially skipped
fvar set 3 16.16;
fvar set 4 52.52;
ivar set 0 11;
ivar set 2 135; // 1 address specially skipped
ivar set 3 28;
ivar set 4 34;
```
### Output:
```
    *variables initializing don't print anything in console*
```
but you can run interpreter with argument "-showvars":
```
.\kILi.exe main -showvars
```
and at the end of program tou can see:
```
Initialized float vars:
0 3.14
1 0
2 3.3
3 16.16
4 52.52
Initialized int vars:
0 11
1 0
2 135
3 28
4 34
```

## print - print variable value in console
### Syntax:
``` c
ivar print int(address);
fvar print int(address);
```
### Example:
``` c
ivar set 0 12;
ivar set 1 34;
fvar set 0 3.14;
fvar set 1 9.81;

ivar print 0; endl;
ivar print 1; endl;
fvar print 0; endl;
fvar print 1; endl;
```
### Output:
```
12
34
3.14
9.81
```

## input - set a variable value from keyboard
### Syntax:
``` c
ivar input int(address);
```
### Example:
``` c
ivar set 0 0;
ivar input 0;
ivar print 0; endl;

fvar set 0 0;
fvar input 0;
fvar print 0; endl;
```
### Output:
```
> 12
12
> 3.14
3.14
```

## sum, dif, mul, div - operations with variables
Avaliable types:
* ivar - int variable, int address
* fvar - float variable, int adress
* inum - int number, int value
* fnum - float number, float value
### Syntax:
``` c
ivar sum (changeableVariableAddress) (type) float/int(address/value) (type) float/int(address/value);
ivar dif (changeableVariableAddress) (type) float/int(address/value) (type) float/int(address/value);
ivar mul (changeableVariableAddress) (type) float/int(address/value) (type) float/int(address/value);
ivar dif (changeableVariableAddress) (type) float/int(address/value) (type) float/int(address/value);
```
All its funclions can operate with 2 or more numbers/variables
### Example:
``` c
// initializing variables
ivar set 0 12;
ivar set 1 34;
ivar set 2 0; // if you don't initialize empty variable, where you can store sum or else, your program crashed
fvar set 0 3.14;
fvar set 1 9.81;
fvar set 2 0;

ivar sum 2 ivar 0 ivar 1; // sum of ivar 0 and ivar 1
ivar print 2; endl;

fvar sum 2 fvar 0 fvar 1; // sum of fvar 0 and fvar 1
fvar print 2; endl;

ivar sum 2 inum 32 inum 2 inum 4; // sum of 32 and 2 and 4
ivar print 2; endl;

ivar dif 2 ivar 0 inum 47;
ivar print 2; endl;

ivar mul 2 fvar 0 fnum 1.55; // you can operate with floats, but store it to int variable (rounded)
ivar print 2; endl;

ivar div 2 inum 46 ivar 0 fnum 0.5;
ivar print 2; endl;

fvar sum 2 fnum 32.14 fnum 79.64; // sum of 32.14 and 79.64
fvar print 2; endl;
```
### Output:
```
46
12.95
38
-35
4
7
111.78
```

## ++ - add 1 to variable
It's more useful in cycles
### Syntax:
``` c
ivar ++ int(address);
fvar ++ int(address);
```
### Example:
``` c
ivar set 0 0;
ivar ++ 0;
ivar print 0; endl;

fvar set 0 0.5;
fvar ++ 0;
fvar print 0; endl;
```
### Output:
```
1
1.5
```