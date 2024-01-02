
# Introduction

This repo is for the code I will write as I read Language Implementation Patterns by Terence Parr.

Terence has written his excellent ANTLR tool in Java.  He has also written the book using Java examples.

I intend to use C++ for this as it fits better with my skill set.  I will translate all examples to 
equivalent C++ code.


# Warnings Building ANTLR C++ Runtime Code

It is important to note down any errors or warnings in the C++ runtime code.  
Best practice in C++ is to treat warnings as errors, especially in a library.  Libraries are expected to be of the highest quality.

I will inform the ANTLR project of these warnings and perhaps attempt some fixes myself.

When building ANTLR C++ code I encountered the following errors and warnings:

1)  warning: explicitly defaulted copy assignment: operator is implicitly deleted [-Wdefaulted-function-deleted]
  This warning occurs in the following files and locations:

  src/Vocabulary.h:19:17
  src/atn/ATNConfig.h:90:16
  src/tree/pattern/ParseTreePattern.h:33:23
  src/tree/pattern/ParseTreeMatch.h:48:21

2) warning: field 'parser' will be initialized after field 'decisionToDFA' [-Wreorder-ctor]

  src/atn/ParserATNSimulator.cpp:56:42
  
3) warning: unqualified call to 'std::move' [-Wunqualified-std-cast-call]

  src/misc/IntervalSet.cpp:40:16

# Errors and Warnings in Generated ANTLR C++ Code

## C++ Versions
I could not build the ANTLR examples with C++20 due to the following errors:

1)  error: arithmetic on a pointer to an incomplete type 'antlr4::tree::xpath::XPathElement'

  This occurred 4 times, 3 in <vector> and 1 in <allocator.h>

Switching down to C++17 solves the issue and produces the following warnings:

1) warning: explicitly defaulted copy assignment: operator is implicitly deleted [-Wdefaulted-function-deleted]

  This occurs in the same files and locations as in the ANTLR C++ Runtime Code in point 1 above.

2) warning: 'wstring_convert<std::codecvt_utf8<char32_t, 1114111, 0>, char32_t>' is deprecated [-Wdeprecated-declarations]

  include/antlr4-runtime/support/StringUtils.h:17:16

3) warning: 'codecvt_utf8<char32_t, 1114111, 0>' is deprecated [-Wdeprecated-declarations]

  include/antlr4-runtime/support/StringUtils.h:17:37

4) warning: 'UTF32Converter' is deprecated [-Wdeprecated-declarations]

  include/antlr4-runtime/support/StringUtils.h:25:5
  include/antlr4-runtime/support/StringUtils.h:37:5

Switching down to C++14 or C++11 removes the deprecated warnings leaving only the default function deleted ones.

## Issues and Errors in Generated ANTLR C++ Code

1) Usage of $start has to be replaced with $ctx.start to avoid:

  error(33):  missing code generation template ThisRulePropertyRef_startHeader

  Same goes for $stop.
  See https://github.com/antlr/antlr4/issues/2207 for more details


