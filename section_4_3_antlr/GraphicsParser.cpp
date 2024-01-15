
// Generated from Graphics.g by ANTLR 4.13.1


#include "GraphicsListener.h"

#include "GraphicsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct GraphicsParserStaticData final {
  GraphicsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GraphicsParserStaticData(const GraphicsParserStaticData&) = delete;
  GraphicsParserStaticData(GraphicsParserStaticData&&) = delete;
  GraphicsParserStaticData& operator=(const GraphicsParserStaticData&) = delete;
  GraphicsParserStaticData& operator=(GraphicsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag graphicsParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
GraphicsParserStaticData *graphicsParserStaticData = nullptr;

void graphicsParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (graphicsParserStaticData != nullptr) {
    return;
  }
#else
  assert(graphicsParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GraphicsParserStaticData>(
    std::vector<std::string>{
      "file", "command", "point"
    },
    std::vector<std::string>{
      "", "'line'", "'from'", "'to'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,6,22,2,0,7,0,2,1,7,1,2,2,7,2,1,0,4,0,8,8,0,11,0,12,0,9,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,0,0,3,0,2,4,0,0,19,0,7,1,0,0,0,2,11,
  	1,0,0,0,4,17,1,0,0,0,6,8,3,2,1,0,7,6,1,0,0,0,8,9,1,0,0,0,9,7,1,0,0,0,
  	9,10,1,0,0,0,10,1,1,0,0,0,11,12,5,1,0,0,12,13,5,2,0,0,13,14,3,4,2,0,14,
  	15,5,3,0,0,15,16,3,4,2,0,16,3,1,0,0,0,17,18,5,5,0,0,18,19,5,4,0,0,19,
  	20,5,5,0,0,20,5,1,0,0,0,1,9
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  graphicsParserStaticData = staticData.release();
}

}

GraphicsParser::GraphicsParser(TokenStream *input) : GraphicsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

GraphicsParser::GraphicsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  GraphicsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *graphicsParserStaticData->atn, graphicsParserStaticData->decisionToDFA, graphicsParserStaticData->sharedContextCache, options);
}

GraphicsParser::~GraphicsParser() {
  delete _interpreter;
}

const atn::ATN& GraphicsParser::getATN() const {
  return *graphicsParserStaticData->atn;
}

std::string GraphicsParser::getGrammarFileName() const {
  return "Graphics.g";
}

const std::vector<std::string>& GraphicsParser::getRuleNames() const {
  return graphicsParserStaticData->ruleNames;
}

const dfa::Vocabulary& GraphicsParser::getVocabulary() const {
  return graphicsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GraphicsParser::getSerializedATN() const {
  return graphicsParserStaticData->serializedATN;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

void GraphicsParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  graphicsParserInitialize();
#else
  ::antlr4::internal::call_once(graphicsParserOnceFlag, graphicsParserInitialize);
#endif
}
