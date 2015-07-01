# SimpleQueryParserSpirit
A simple query parser written in [Boost.Spirit](http://www.boost.org/doc/libs/release/libs/spirit)

Introduction
============

This is a simple query parser written in [Boost.Spirit](http://www.boost.org/doc/libs/release/libs/spirit). It can recognizes simple queries like:

 - this AND that
 - this AND not that
 - this OR that
 - NOT (this AND that)

Compile
=======

You need boost.spirit to compile this project.

 - $ mkdir build
 - $ cd build
 - $ cmake ..
 - $ make

P.S.
====

This is a toy project. I tried three methods to build a query parser. You can find the other two:

 - [SimpleQueryParser](https://github.com/itechbear/SimpleQueryParser) : A simple query parser generated by flex and bison (C Language)
 - [SimpleQueryParserPlusPlus](https://github.com/itechbear/SimpleQueryParserPlusPlus) : A simple thread-safe query parser generated by flex and bison (C++ Language)

After I completed these three projects, my conclusions about Flex/Bison vs Boost.Spirit are as follows:

 - There are many documentations about Flex/Bison, but few of them talk about thread-safty or generating a C++ parser.
 - Boost.Spirit is harder to learn. The documentation is poor. The code is hard to debug and takes much more time to compile.
