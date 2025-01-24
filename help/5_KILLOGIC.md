# KILLOGIC - logical operations of kIL
## if - if
Avaliable types:
* ivar - int variable, int address
* fvar - float variable, int adress
* inum - int number, int value
* fnum - float number, float value

Avaliable operators:
* \> - bigger then
* < - smaller then
* == - equeals to
* != - unequeals to
### Syntax:
``` c
if int(index) (type) float/int(address/value) char(oper) (type) float/int(address/value)
    // code
# int(index)
```
### Example:
``` c
ivar set 0 0;
ivar input 0;
if 0 inum 0 > ivar 0    // if 0 bigger then ivar 0
    print variable is negative; endl;
# 0 // if ending

if 0 inum 0 < ivar 0    // its like else
    print variable is positive; endl;
    if 1 ivar 0 == inum 1337    // nested conditions
        print also your value is 1337;
    # 1
    if 1 ivar 0 != inum 1337
        print your value isnt 1337;
    # 1    // nested if ending index (1) must unequal to parent if ending index (0)
# 0
```
### Output:
```
> .\kILi.exe
> 134
variable is positive
your value isnt 1337

> .\kILi.exe
> 1337
variable is positive
also your value is 1337

> .\kILi.exe
> -10
variable is negative
```

## goto - go back or forward in file reading
### Syntax:
``` c
goto int(symbols);
```
### Example:
``` c
// simple cycle
ivar set 0 0;


if 0 ivar 0 < inum 5
    ivar print 0; endl;
    ivar ++ 0;
    goto -78;
    // go 78 symbols back
# 0
```
### Output:
```
0
1
2
3
4
```