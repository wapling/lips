#pragma once

#include "RecognitionException.h"
#include "Token.h"

#include <string>

class NoViableAltException : public RecognitionException
{
public:
  NoViableAltException(std::string const& expecting, Token const& found) :
    RecognitionException(expecting, found)
  {}
};

