
// Generated from Graphics.g by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "GraphicsListener.h"


/**
 * This class provides an empty implementation of GraphicsListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  GraphicsBaseListener : public GraphicsListener {
public:

  virtual void enterFile(GraphicsParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(GraphicsParser::FileContext * /*ctx*/) override { }

  virtual void enterCommand(GraphicsParser::CommandContext * /*ctx*/) override { }
  virtual void exitCommand(GraphicsParser::CommandContext * /*ctx*/) override { }

  virtual void enterPoint(GraphicsParser::PointContext * /*ctx*/) override { }
  virtual void exitPoint(GraphicsParser::PointContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

