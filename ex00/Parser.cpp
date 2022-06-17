#include "Parser.hpp"

Parser::~Parser() {
}

Parser::Parser() {
}

Parser::Parser(const Parser& p) {
  (void)p;
}

Parser& Parser::operator=(const Parser& p) {
  (void)p;
  return *this;
}

Parser::Parser(std::stringstream& ss, enum Type type)
    : before_point_(0), after_point_(0), pow_(0.1), sign_(1), state_(kInit), type_(type) {
  char c;

  Action_[kInit] = &Parser::Init;
  Action_[kReadSign] = &Parser::ReadSign;
  Action_[kReadInteger] = &Parser::ReadInteger;
  Action_[kReadDouble] = &Parser::ReadDouble;

  ss >> c;
  while (!ss.eof() && state_ != kEnd) {
    (this->*Action_[state_])(c);
    ss >> c;
  }
}

void Parser::Init(char c) {
  if (std::isdigit(c)) {
    before_point_ = before_point_ * 10 + static_cast<int>(c - '0');
    state_ = kReadInteger;
  } else if (c == '.' && type_ != kInt)
    state_ = kReadDouble;
  else if (c == '+')
    state_ = kReadSign;
  else if (c == '-') {
    sign_ = -1;
    state_ = kReadSign;
  } else
    throw NoConversionException();
}

void Parser::ReadSign(char c) {
  if (std::isdigit(c)) {
    before_point_ = before_point_ * 10 + static_cast<int>(c - '0');
    state_ = kReadInteger;
  } else if (c == '.' && type_ != kInt)
    state_ = kReadDouble;
  else
    throw NoConversionException();
}

void Parser::ReadInteger(char c) {
  if (std::isdigit(c)) {
    before_point_ = before_point_ * 10 + static_cast<unsigned long int>(c - '0');
    if (type_ == kInt && (static_cast<long int>(before_point_) > static_cast<long int>(INT_MAX) ||
                          static_cast<long int>(before_point_) < static_cast<long int>(INT_MIN)))
      throw IntegerOutOfRange();
    state_ = kReadInteger;
  } else if (c == '.' && type_ != kInt)
    state_ = kReadDouble;
  else
    state_ = kEnd;
}

void Parser::ReadDouble(char c) {
  if (std::isdigit(c)) {
    after_point_ = after_point_ + pow_ * static_cast<int>(c - '0');
    pow_ *= 0.1;
    state_ = kReadDouble;
  } else
    state_ = kEnd;
}

const char* Parser::NoConversionException::what() const throw() {
  return "no conversion";
}

const char* Parser::IntegerOutOfRange::what() const throw() {
  return "integer out of range";
}

int Parser::getInteger() const {
  return sign_ * before_point_;
}

double Parser::getDouble() const {
  return sign_ * after_point_;
}