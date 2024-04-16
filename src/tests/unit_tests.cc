//
// Created by Raisin Ibben on 16/04/2024.
//

#include <gtest/gtest.h>

#include "../Model/model.h"
//#include "../Controller/controller.h"

class ViewerTest : public ::testing::Test {
 protected:
  s21::Model model_;
  //  s21::Controller controller_;

  //  void SetUp() override {
  //    controller_ = s21::Controller(&model_);
  //  }
};

TEST_F(ViewerTest, CorrectCube) {
  std::string file_path = "../obj/correct/cube.obj";
  model_.ProccessingObjFile(file_path);

  //  EXPECT_TRUE(model_.GetModelStatus());
}
TEST_F(ViewerTest, CorrectCar) {
  std::string file_path = "../obj/correct/car.obj";
  model_.ProccessingObjFile(file_path);

  //  EXPECT_TRUE(model_.GetModelStatus());
}
TEST_F(ViewerTest, CorrectNegativeCube) {
  std::string file_path = "../obj/correct/cube_neg.obj";
  model_.ProccessingObjFile(file_path);

  //  EXPECT_TRUE(model_.GetModelStatus());
}

// TEST(test, one) { EXPECT_TRUE(true); }
//
// TEST(test, two) { EXPECT_FALSE(false); }
// TEST(test, three) { EXPECT_EQ(2 + 3, 5); }
//
// TEST(test, four) { EXPECT_EQ(5 - 2, 3); }
