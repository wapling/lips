
// Generated from Graphics.g by ANTLR 4.7.1


#include "GraphicsListener.h"

#include "GraphicsParser.h"


using namespace antlrcpp;
using namespace antlr4;

GraphicsParser::GraphicsParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GraphicsParser::~GraphicsParser() {
  delete _interpreter;
}

std::string GraphicsParser::getGrammarFileName() const {
  return "Graphics.g";
}

const std::vector<std::string>& GraphicsParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GraphicsParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

GraphicsParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GraphicsParser::CommandContext *> GraphicsParser::FileContext::command() {
  return getRuleContexts<GraphicsParser::CommandContext>();
}

GraphicsParser::CommandContext* GraphicsParser::FileContext::command(size_t i) {
  return getRuleContext<GraphicsParser::CommandContext>(i);
}


size_t GraphicsParser::FileContext::getRuleIndex() const {
  return GraphicsParser::RuleFile;
}

void GraphicsParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphicsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void GraphicsParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphicsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

GraphicsParser::FileContext* GraphicsParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, GraphicsParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(7); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(6);
      command();
      setState(9); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GraphicsParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

GraphicsParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GraphicsParser::PointContext *> GraphicsParser::CommandContext::point() {
  return getRuleContexts<GraphicsParser::PointContext>();
}

GraphicsParser::PointContext* GraphicsParser::CommandContext::point(size_t i) {
  return getRuleContext<GraphicsParser::PointContext>(i);
}


size_t GraphicsParser::CommandContext::getRuleIndex() const {
  return GraphicsParser::RuleCommand;
}

void GraphicsParser::CommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphicsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand(this);
}

void GraphicsParser::CommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphicsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand(this);
}

GraphicsParser::CommandContext* GraphicsParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 2, GraphicsParser::RuleCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11);
    match(GraphicsParser::T__0);
    setState(12);
    match(GraphicsParser::T__1);
    setState(13);
    point();
    setState(14);
    match(GraphicsParser::T__2);
    setState(15);
    point();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointContext ------------------------------------------------------------------

GraphicsParser::PointContext::PointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GraphicsParser::PointContext::INT() {
  return getTokens(GraphicsParser::INT);
}

tree::TerminalNode* GraphicsParser::PointContext::INT(size_t i) {
  return getToken(GraphicsParser::INT, i);
}


size_t GraphicsParser::PointContext::getRuleIndex() const {
  return GraphicsParser::RulePoint;
}

void GraphicsParser::PointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphicsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPoint(this);
}

void GraphicsParser::PointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GraphicsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPoint(this);
}

GraphicsParser::PointContext* GraphicsParser::point() {
  PointContext *_localctx = _tracker.createInstance<PointContext>(_ctx, getState());
  enterRule(_localctx, 4, GraphicsParser::RulePoint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17);
    match(GraphicsParser::INT);
    setState(18);
    match(GraphicsParser::T__3);
    setState(19);
    match(GraphicsParser::INT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> GraphicsParser::_decisionToDFA;
atn::PredictionContextCache GraphicsParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GraphicsParser::_atn;
std::vector<uint16_t> GraphicsParser::_serializedATN;

std::vector<std::string> GraphicsParser::_ruleNames = {
  "file", "command", "point"
};

std::vector<std::string> GraphicsParser::_literalNames = {
  "", "'line'", "'from'", "'to'", "','"
};

std::vector<std::string> GraphicsParser::_symbolicNames = {
  "", "", "", "", "", "INT", "WS"
};

dfa::Vocabulary GraphicsParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GraphicsParser::_tokenNames;

GraphicsParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x8, 0x18, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x3, 0x2, 0x6, 0x2, 0xa, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0xb, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x2, 0x2, 0x5, 0x2, 0x4, 0x6, 0x2, 
    0x2, 0x2, 0x15, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x13, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa, 0x5, 0x4, 0x3, 0x2, 0x9, 
    0x8, 0x3, 0x2, 0x2, 0x2, 0xa, 0xb, 0x3, 0x2, 0x2, 0x2, 0xb, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xb, 0xc, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0xd, 0xe, 0x7, 0x3, 0x2, 0x2, 0xe, 0xf, 0x7, 0x4, 0x2, 0x2, 0xf, 
    0x10, 0x5, 0x6, 0x4, 0x2, 0x10, 0x11, 0x7, 0x5, 0x2, 0x2, 0x11, 0x12, 
    0x5, 0x6, 0x4, 0x2, 0x12, 0x5, 0x3, 0x2, 0x2, 0x2, 0x13, 0x14, 0x7, 
    0x7, 0x2, 0x2, 0x14, 0x15, 0x7, 0x6, 0x2, 0x2, 0x15, 0x16, 0x7, 0x7, 
    0x2, 0x2, 0x16, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3, 0xb, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GraphicsParser::Initializer GraphicsParser::_init;
