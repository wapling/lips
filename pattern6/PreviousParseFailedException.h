#pragma once

#include "RecognitionException.h"
#include "Token.h"

#include <string>

class PreviousParseFailedException : public RecognitionException
{
public:
  PreviousParseFailedException() :
    RecognitionException("Previous parse failed")
  {}
};

