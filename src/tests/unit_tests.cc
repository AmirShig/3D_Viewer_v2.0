//
// Created by Raisin Ibben on 16/04/2024.
//

#include <gtest/gtest.h>

#include <iostream>

#include "../Controller/controller.h"
#include "../Model/model.h"

class ViewerTest : public ::testing::Test {
 protected:
  s21::Model model_;
  s21::Controller controller_;
  static constexpr double kEpsilon_ = 1e-6;

  void SetUp() override { controller_ = s21::Controller(&model_); }
};

TEST_F(ViewerTest, CorrectCube) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}
TEST_F(ViewerTest, CorrectCar) {
  std::string file_path = "../src/tests/obj/correct/car.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, CorrectNegativeCube) {
  std::string file_path = "../src/tests/obj/correct/cube_neg.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, IncorrectFileName) {
  std::string file_path = "../src/tests/obj/correct/abrakadabra.obj";
  EXPECT_FALSE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, IncorrectFileExtention) {
  std::string file_path = "../src/tests/obj/correct/cube.org";
  EXPECT_FALSE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, IncorrectFilePath) {
  std::string file_path = "../src/tests/obj/cor/cube.org";
  EXPECT_FALSE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, EmptyFilePath) {
  std::string file_path;
  EXPECT_FALSE(model_.ProccessingObjFile(file_path));
}

/// All incorrect files

TEST_F(ViewerTest, alot_coordinates_in_vertex) {
  std::string file_path =
      "../src/tests/obj/incorrect/alot_coordinates_in_vertex.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, dot_error) {
  std::string file_path = "../src/tests/obj/incorrect/dot_error.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, facet_that_less_than_1) {
  std::string file_path =
      "../src/tests/obj/incorrect/facet_that_less_than_1.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, facet_that_not_exist) {
  std::string file_path = "../src/tests/obj/incorrect/facet_that_not_exist.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, first_minus) {
  std::string file_path = "../src/tests/obj/incorrect/first_minus.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, incorrect_notation) {
  std::string file_path = "../src/tests/obj/incorrect/incorrect_notation.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, incorrect_number) {
  std::string file_path = "../src/tests/obj/incorrect/incorrect_number.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, invalid_pretoken) {
  std::string file_path = "../src/tests/obj/incorrect/invalid_pretoken.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, invalid_token) {
  std::string file_path = "../src/tests/obj/incorrect/invalid_token.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, more_than_1_dot_in_number) {
  std::string file_path =
      "../src/tests/obj/incorrect/more_than_1_dot_in_number.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, stash) {
  std::string file_path = "../src/tests/obj/incorrect/stash.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, stash_in_line) {
  std::string file_path = "../src/tests/obj/incorrect/stash_in_line.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, test_with_russian_symb) {
  std::string file_path =
      "../src/tests/obj/incorrect/test_with_russian_symb.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, tsar_test) {
  std::string file_path = "../src/tests/obj/incorrect/tsar_test.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, vertex_less_than_3) {
  std::string file_path = "../src/tests/obj/incorrect/vertex_less_than_3.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

TEST_F(ViewerTest, zero_vertex) {
  std::string file_path = "../src/tests/obj/incorrect/zero_vertex.obj";
  EXPECT_TRUE(model_.ProccessingObjFile(file_path));
}

// TEST AFFINE

TEST_F(ViewerTest, MovePlusX) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kMove,
                     s21::Strategy::TypeCoordinate::kX, &controller_.GetData(),
                     3);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_EQ(model_before[i].X + 3, model_after[i].X);
  }
}

TEST_F(ViewerTest, MoveMinusX) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kMove,
                     s21::Strategy::TypeCoordinate::kX, &controller_.GetData(),
                     -3);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_EQ(model_before[i].X - 3, model_after[i].X);
  }
}

TEST_F(ViewerTest, MovePlusY) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kMove,
                     s21::Strategy::TypeCoordinate::kY, &controller_.GetData(),
                     3);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_EQ(model_before[i].Y + 3, model_after[i].Y);
  }
}

TEST_F(ViewerTest, MoveMinusY) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kMove,
                     s21::Strategy::TypeCoordinate::kY, &controller_.GetData(),
                     -3);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_EQ(model_before[i].Y - 3, model_after[i].Y);
  }
}

TEST_F(ViewerTest, MovePlusZ) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kMove,
                     s21::Strategy::TypeCoordinate::kZ, &controller_.GetData(),
                     3);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_EQ(model_before[i].Z + 3, model_after[i].Z);
  }
}

TEST_F(ViewerTest, MoveMinusZ) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kMove,
                     s21::Strategy::TypeCoordinate::kZ, &controller_.GetData(),
                     -3);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_EQ(model_before[i].Z - 3, model_after[i].Z);
  }
}

TEST_F(ViewerTest, RotateX) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kRotate,
                     s21::Strategy::TypeCoordinate::kX, &controller_.GetData(),
                     180);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_NEAR(model_before[i].X, model_after[i].X, kEpsilon_);
    EXPECT_NEAR(model_before[i].Y, -model_after[i].Y, kEpsilon_);
    EXPECT_NEAR(model_before[i].Z, -model_after[i].Z, kEpsilon_);
  }
}

TEST_F(ViewerTest, RotateY) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kRotate,
                     s21::Strategy::TypeCoordinate::kY, &controller_.GetData(),
                     180);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_NEAR(model_before[i].X, -model_after[i].X, kEpsilon_);
    EXPECT_NEAR(model_before[i].Y, model_after[i].Y, kEpsilon_);
    EXPECT_NEAR(model_before[i].Z, -model_after[i].Z, kEpsilon_);
  }
}

TEST_F(ViewerTest, RotateZ) {
  std::string file_path = "../src/tests/obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  const auto model_before = controller_.GetData().GetCoordinateVertex();

  controller_.Affine(s21::Strategy::SelectionStrategy::kRotate,
                     s21::Strategy::TypeCoordinate::kZ, &controller_.GetData(),
                     180);

  const auto model_after = controller_.GetData().GetCoordinateVertex();

  for (size_t i = 0; i < model_before.size(); i++) {
    EXPECT_NEAR(model_before[i].X, -model_after[i].X, kEpsilon_);
    EXPECT_NEAR(model_before[i].Y, -model_after[i].Y, kEpsilon_);
    EXPECT_NEAR(model_before[i].Z, model_after[i].Z, kEpsilon_);
  }
}