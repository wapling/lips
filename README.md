
# Introduction

This repo is for the code I will write as I read Language Implementation Patterns by Terence Parr.

Terence has written his excellent ANTLR tool in Java.  He has also written the book using Java examples.

I intend to use C++ for this as it fits better with my skill set.  I will translate all examples to 
equivalent C++ code.  Once I have things working I will follow up with Python and Go.

# Differences between ANTLR v3 and ANTLR v4

There are substantial differences between these versions which drastically affect the approaches taken in the book.
Some approaches now seem impossible, in particular the chapters on AST creation, Tree Grammars and Tree Rewriting.
Even the chapters on Symbol Tables seem to suffer from this with Java code woven throughout the grammars.
When one tries to replicate this in ANTLR v4 with injected C++ code to pass the symbol table to the start rule etc. then one finds that certain dynamic casts fail in the generated code, which does not check the returned pointer from the cast, and simply dereferences and of course segfaults.  There is no excuse for such naive code generation.

It would save people a lot of time if ANTLR produced warnings and/or errors for these cases as the user is simply going to spend a long time debugging generated code and ultimately failing in their pursuit.  I certainly did.
I intend to raise this as a bug with ANTLR and to then fix it (note to self, polish up your Java chops!)

It is surprising that the Definitive ANTLR v4 reference simply airbrushes over these important changes and does not even include the terms "AST" or "abstract syntax" (see results from web searches below).  This does both new and existing users a huge disservice and renders the reference far from "Definitive" even if it is narrowly scoped to v4.

https://stackoverflow.com/questions/36858750/converting-from-antlr3-to-antlr4

  Extract: ANTLR4 has no tree-rewriting. So, remove -> ... entirely
  Extract: There is no way in ANTLR 4 to rewrite a (parse) tree.

https://stackoverflow.com/questions/15823333/how-can-i-build-an-ast-using-antlr4

  Extract: For example, the output=AST option is no longer recognized. Furthermore neither "AST" nor "abstract syntax" appears in the text of "The Definitive ANTLR4 reference".

https://stackoverflow.com/questions/43030478/attribute-references-not-allowed-in-lexer-actions



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


