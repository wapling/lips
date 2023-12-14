#pragma once

#include "Token.h"
#include "RecognitionException.h"

#include <stdexcept>
#include <string>
#include <utility>


struct InvalidToken : public RecognitionException
{
  std::string expecting_;
  Token found_;

  InvalidToken(std::string expecting, Token const& found) :
    RecognitionException(expecting, found),
    expecting_(std::move(expecting)),
    found_(found)
  {}  
};

