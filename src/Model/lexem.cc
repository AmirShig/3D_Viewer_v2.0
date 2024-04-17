#include "model.h"

namespace s21 {

void Lexeme::CheckLexem(Data3DModel *data) {
  if (!data->GetCoordinateVertex().size()) data->ClearData();
}

}  // namespace s21