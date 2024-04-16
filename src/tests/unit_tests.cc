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
  std::string file_path =
      "/Users/raisinib/Projects/in_process/3D_Viewer_v2.0/src/tests/obj/"
      "correct/cube.obj";
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
  std::string file_path = "";
  EXPECT_FALSE(model_.ProccessingObjFile(file_path));
}
