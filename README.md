# Trees
## Overview
This project consists of implimentations of red black and binary search trees in both c and java. Each version has integer and generic versions of each data structure. The puropse of this project was to produce working implimentations and to evaluate the speeds of binary search trees compared to red black trees for various operations, as well as how java compares to c for this kind of data structure. 
## Building
There is a makefile provided. Simply call:
```
$ make
```
...to build both the c and java versions. To build one implimentation at a time use:
```
$ make c
$ make java
```
***Note: Building the java implimentation requires junit-platform-console-standalone-1.9.3.jar to be in the src/java directory, which you will need to download from the internet***
## Running
### Unit Tests
For java:
```
$ make test_java
```
For c:
```
$ ./bin/c_tst.e 1
```
### Speed Tests
For java:
```
$ cd ./bin && java TreeTimeTests
```
For c:
```
$ cd ./bin && ./bin/c_tst.e 2
```
***Note: The speed tests take a while (~3 hours) to finish***
## Results / Commentary
There is a collection of result data in both the results.txt and results.md files. results.txt is output from the terminal, and results.md is the same output in a table. These look nice but if you run the tests in the terminal they are colored which looks nicer :)   
   
I personally expected the c code to be much faster and take less memory. It won on the memory side, as the java program choked on my machine on the final stages of the speed test. For speed however, the java implimentation was much faster than the c one for many of the methods. Particularly the ordered insertions for java were drastically faster than c for large input sizes. My conclusions with this are that either java's random function creates far more collisions that c's (unlikely) or that java handles pointers, memory allocation, and memory positioning much better under the hood than c. This makes sense to me becuase in c you are given full control over allocating memory and passing pointers. Becuase java handles these things for the user, I would expect them to be doing some fancy stuff to get some fast speeds. Not sure though. The java compiler could be better than the c complier, but that seems unlikely to me, especially since java compiles to java bytecode that is ran by the jvm. I guess it could still be comparable, but more layers to me seems slower. Not sure.
