#pragma once

#include "Token.h"
#include "RecognitionException.h"

#include <stdexcept>
#include <string>
#include <utility>


struct MismatchedTokenException : public RecognitionException
{
  MismatchedTokenException(std::string expecting, Token const& found) :
    RecognitionException(expecting, found)
  {}  
};

