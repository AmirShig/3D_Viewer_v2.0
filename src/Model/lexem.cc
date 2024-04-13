#include "model.h"

namespace s21 {

void Lexeme::CleanLexem(std::string &str) {
  /*! \param is_first проверяет первый ли полигон мы парсим*/
  bool is_first = true;

  /*! \param lust_polygon сохраняем первый полигон для записи в конец*/
  std::string lust_polygon;

  std::string lexeme;

  for (size_t i = 0; i < str.length(); ++i) {
    if (std::isdigit(str[i]) && str[i + 1] == '/') {
      lexeme += str[i];

      /*module 1*/
      if (is_first) {
        lust_polygon = str[i];
        is_first = false;
      } else {
        lexeme += str[i];
      }
      /*module 1*/

      for (; i < str.length() && str[i] != ' '; ++i) {
      }
    }
  }

  lexeme += lust_polygon;
  str = lexeme;
}

} // namespace s21