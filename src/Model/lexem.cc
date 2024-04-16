#include "model.h"

namespace s21 {

void Lexeme::CleanLexem(std::string &str) {
  /*! \param is_first проверяет первый ли полигон мы парсим*/
  bool is_first = true;

  /*! \param lust_polygon сохраняем первый полигон для записи в конец*/
  int lust_polygon = 0;

  int num = 0;
  std::stringstream lexeme;
  size_t id = 0;

  for (size_t i = 0; i < str.length(); ++i) {
    if (std::isdigit(str[i]) || str[i + 1] == '/') {
      num = std::stoi(&str[i], &id);
      i += id;

      lexeme << num;

      /*проверяем первый полигон */
      if (is_first) {
        lust_polygon = num;
        is_first = false;
      } else {
        lexeme << num;
      }
      /* если не первый то записываем два раза*/

      //      for (; i < str.length() && str[i] != ' '; ++i) {
      //      }
    }
  }

  lexeme << lust_polygon;
  str = lexeme.str();
}

}  // namespace s21