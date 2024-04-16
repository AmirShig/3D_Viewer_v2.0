#include "model.h"

namespace s21 {

void Lexeme::CheckLexem(std::string __attribute__((unused)) & str,
                        Data3DModel *data) {
  if (data->GetCoordinateVertex().empty()) data->ClearData();
}

}  // namespace s21