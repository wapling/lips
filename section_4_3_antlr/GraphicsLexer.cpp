
// Generated from Graphics.g by ANTLR 4.13.1


#include "GraphicsLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct GraphicsLexerStaticData final {
  GraphicsLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  GraphicsLexerStaticData(const GraphicsLexerStaticData&) = delete;
  GraphicsLexerStaticData(GraphicsLexerStaticData&&) = delete;
  GraphicsLexerStaticData& operator=(const GraphicsLexerStaticData&) = delete;
  GraphicsLexerStaticData& operator=(GraphicsLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag graphicslexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
GraphicsLexerStaticData *graphicslexerLexerStaticData = nullptr;

void graphicslexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (graphicslexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(graphicslexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<GraphicsLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "INT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'line'", "'from'", "'to'", "','"
    },
    std::vector<std::string>{
      "", "", "", "", "", "INT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,6,36,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,1,0,
  	1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,4,4,4,30,8,4,11,
  	4,12,4,31,1,5,1,5,1,5,0,0,6,1,1,3,2,5,3,7,4,9,5,11,6,1,0,1,3,0,9,10,13,
  	13,32,32,36,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,1,13,1,0,0,0,3,18,1,0,0,0,5,23,1,0,0,0,7,26,1,0,0,0,9,
  	29,1,0,0,0,11,33,1,0,0,0,13,14,5,108,0,0,14,15,5,105,0,0,15,16,5,110,
  	0,0,16,17,5,101,0,0,17,2,1,0,0,0,18,19,5,102,0,0,19,20,5,114,0,0,20,21,
  	5,111,0,0,21,22,5,109,0,0,22,4,1,0,0,0,23,24,5,116,0,0,24,25,5,111,0,
  	0,25,6,1,0,0,0,26,27,5,44,0,0,27,8,1,0,0,0,28,30,2,48,57,0,29,28,1,0,
  	0,0,30,31,1,0,0,0,31,29,1,0,0,0,31,32,1,0,0,0,32,10,1,0,0,0,33,34,7,0,
  	0,0,34,35,6,5,0,0,35,12,1,0,0,0,2,0,31,1,1,5,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  graphicslexerLexerStaticData = staticData.release();
}

}

GraphicsLexer::GraphicsLexer(CharStream *input) : Lexer(input) {
  GraphicsLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *graphicslexerLexerStaticData->atn, graphicslexerLexerStaticData->decisionToDFA, graphicslexerLexerStaticData->sharedContextCache);
}

GraphicsLexer::~GraphicsLexer() {
  delete _interpreter;
}

std::string GraphicsLexer::getGrammarFileName() const {
  return "Graphics.g";
}

const std::vector<std::string>& GraphicsLexer::getRuleNames() const {
  return graphicslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& GraphicsLexer::getChannelNames() const {
  return graphicslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& GraphicsLexer::getModeNames() const {
  return graphicslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& GraphicsLexer::getVocabulary() const {
  return graphicslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView GraphicsLexer::getSerializedATN() const {
  return graphicslexerLexerStaticData->serializedATN;
}

const atn::ATN& GraphicsLexer::getATN() const {
  return *graphicslexerLexerStaticData->atn;
}


void GraphicsLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 5: WSAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void GraphicsLexer::WSAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: skip(); break;

  default:
    break;
  }
}



void GraphicsLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  graphicslexerLexerInitialize();
#else
  ::antlr4::internal::call_once(graphicslexerLexerOnceFlag, graphicslexerLexerInitialize);
#endif
}
