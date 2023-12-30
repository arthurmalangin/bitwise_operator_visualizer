# bitwise_operator_visualizer
_Simple Tool for learn and understand bitwise operator !_

## Global

Visualize the bitwise operator.

## Compilation

For compilation type this command in terminal ( When you are in the file )
```
$ make
```

## Exec

Do this command in terminal:
```
$ ./executable "1" "toggle" "5"
CODE: 1 ^ (1 << 5)
OLD      NEW
11001110 11101110
```
For help, do this command
```
$ ./executable
=========================================================
List of operator: "set" "clear" "leftshift" "rightshift" "toggle" "swapshift"
Examples:
                - ./a.out "10" "set" "2"
                - ./a.out "2" "rightshift" "1"
                - ./a.out "5" "toggle" "5"
=========================================================
```
***
