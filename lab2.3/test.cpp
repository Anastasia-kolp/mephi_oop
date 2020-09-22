#include <math.h>
#include "gtest/gtest.h"
#include "FoliumOfDescrates.cpp"

using namespace lab2;

TEST(FOD_Constructor, Default_Constructor){
  FOD fod;
  ASSERT_EQ(1, fod.get());
}

TEST(FOD_Constructor, Init_Constructor){
  FOD fod1(5);
  ASSERT_EQ(5, fod1.get());

  FOD fod2(-2);
  ASSERT_EQ(-2, fod2.get());
}

TEST (FOD_Constructor, TestExpection){
  ASSERT_ANY_THROW(FOD fod3(0));
}

TEST(Others_Methods, Setters){
  FOD fod4;
  int a = 2;
  fod4.set(a);
  ASSERT_EQ(2, fod4.get());
  ASSERT_ANY_THROW(fod4.set(0));
}

TEST(Others_Methods, Parameters){
  FOD a;
  ASSERT_EQ(1/sqrt(2), a.SideOfSquare());
  ASSERT_EQ(abs((sin(1)*cos(1))/(sin(1)*sin(1)*sin(1) + cos(1)*cos(1)*cos(1))), a.DistanceInPolarSystem(1));
  ASSERT_EQ(0.125/sqrt(2), a.RadiusOfCurvatureTop());
  ASSERT_EQ(0.5, a.RadiusOfCurvatureKnot());
  ASSERT_EQ(1./6, a.AreaOfList());
  ASSERT_EQ((sqrt(2)*sqrt(2*sqrt(3)-3))/3, a.LoopDiameter());
  ASSERT_EQ(1/sqrt(6), a.DistanceFromLoopDiameter());

  FOD a1(3);
  ASSERT_EQ(3/sqrt(2), a1.SideOfSquare());
  ASSERT_EQ(abs((3*sin(1)*cos(1))/(sin(1)*sin(1)*sin(1) + cos(1)*cos(1)*cos(1))), a1.DistanceInPolarSystem(1));
  ASSERT_EQ(0.375/sqrt(2), a1.RadiusOfCurvatureTop());
  ASSERT_EQ(1.5, a1.RadiusOfCurvatureKnot());
  ASSERT_EQ(1.5, a1.AreaOfList());
  ASSERT_EQ((3*sqrt(2)*sqrt(2*sqrt(3)-3))/3, a1.LoopDiameter());
  ASSERT_EQ(3/sqrt(6), a1.DistanceFromLoopDiameter());

  FOD a2(-2);
  ASSERT_EQ(2/sqrt(2), a2.SideOfSquare());
  ASSERT_EQ(abs((2*sin(1)*cos(1))/(sin(1)*sin(1)*sin(1) + cos(1)*cos(1)*cos(1))), a2.DistanceInPolarSystem(1));
  ASSERT_EQ(-0.25/sqrt(2), a2.RadiusOfCurvatureTop());
  ASSERT_EQ(-1, a2.RadiusOfCurvatureKnot());
  ASSERT_EQ(2./3, a2.AreaOfList());
  ASSERT_EQ((2*sqrt(2)*sqrt(2*sqrt(3)-3))/3, a2.LoopDiameter());
  ASSERT_EQ(2/sqrt(6), a2.DistanceFromLoopDiameter());
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
