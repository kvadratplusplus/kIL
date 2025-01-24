# KILIO - input and output of kIL
## print - prints text to console
### Syntax:
``` c
print string(text);
```
### Example:
``` c
print text; 
```
### Output:
```
text
```

## endl - make new line
### Syntax:
``` c
endl;
```
### Example:
``` c
print text;
print another text;
endl;
print new line text;
```
### Output:
```
textanother text
new line text
```

## sleep - sleep for time (ms)
### Syntax:
``` c
sleep int(ms);
```
### Example:
``` c
print hello; endl;
sleep 1000;
print goodbye;
```
### Output:
```
hello
    *1 second later*
goodbye
```