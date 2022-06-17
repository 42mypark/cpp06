#ifndef Parser_HPP
#define Parser_HPP
#include <sstream>

enum Type { kInt, kFloat, kDouble };
enum ParserState { kInit, kReadSign, kReadInteger, kReadDouble, kEnd };

class Parser {
 private:
  unsigned long int before_point_;
  double            after_point_;
  double            pow_;
  int               sign_;
  enum ParserState  state_;
  enum Type         type_;
  void (Parser::*Action_[4])(char);
  Parser();
  Parser(const Parser& p);
  Parser& operator=(const Parser& p);
  void    Init(char c);
  void    ReadSign(char c);
  void    ReadInteger(char c);
  void    ReadDouble(char c);

 public:
  ~Parser();
  Parser(std::stringstream& ss, enum Type type);
  int    getInteger() const;
  double getDouble() const;

  class NoConversionException : public std::exception {
    const char* what() const throw();
  };
  class IntegerOutOfRange : public std::exception {
    const char* what() const throw();
  };
};

#endif  // Parser_HPP