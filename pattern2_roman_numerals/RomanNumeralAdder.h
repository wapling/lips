#include "RomanNumeralLexer.h"

class Token;

class RomanNumeralAdder
{
  int total_;

  bool thousands_done_;
  bool five_hundred_done_;
  bool hundreds_done_;
  bool fifty_done_;
  bool tens_done_;
  bool five_done_;
  bool ones_done_;

public:

  RomanNumeralAdder() :
    total_(0),
    thousands_done_(false),
    five_hundred_done_(false),
    hundreds_done_(false),
    fifty_done_(false),
    tens_done_(false),
    five_done_(false),
    ones_done_(false)
  {}

  void add(Token const&);
  int get_total() const { return total_; }
};

