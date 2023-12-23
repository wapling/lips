
// Generated from Graphics.g by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "GraphicsParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by GraphicsParser.
 */
class  GraphicsListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(GraphicsParser::FileContext *ctx) = 0;
  virtual void exitFile(GraphicsParser::FileContext *ctx) = 0;

  virtual void enterCommand(GraphicsParser::CommandContext *ctx) = 0;
  virtual void exitCommand(GraphicsParser::CommandContext *ctx) = 0;

  virtual void enterPoint(GraphicsParser::PointContext *ctx) = 0;
  virtual void exitPoint(GraphicsParser::PointContext *ctx) = 0;


};

