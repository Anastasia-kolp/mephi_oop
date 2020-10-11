#include "gtest/gtest.h"
#include "include/Dice.h"

using namespace lab3;

TEST(dice_constructor, default_constructor){
  DICE dice;
  ASSERT_EQ(0, dice.get_r_number());
  ASSERT_EQ(0, dice.get_sum_of_dice());
}

TEST(dice_constructor, initial_constructor){
  DICE dice1(3);
  ASSERT_EQ(3, dice1.get_r_number());

  int a[4] = {2, 4, 1, 5};
  DICE dice2(a, 4);
  ASSERT_EQ(4, dice2.get_r_number());
  ASSERT_EQ(12, dice2.get_sum_of_dice());
}

TEST(dice_constructor, copy_constructor){
  int b[3] = {2, 5, 6};
  DICE dice3(b, 3);
  DICE n(dice3);
  ASSERT_EQ(3, n.get_r_number());
  ASSERT_EQ(13, n.get_sum_of_dice());
}

TEST(other_methods, concurrence){
  int c[5] = {2, 3, 3, 1, 6};
  DICE dice4(c, 5);
  ASSERT_TRUE(dice4.find_concurrence());

  int d[2] = {1, 2};
  DICE dice5(c, 2);
  ASSERT_FALSE(dice5.find_concurrence());
}

TEST(overloaded_operators, test_right){
  int e[4] = {1, 3, 4, 6};
  DICE dice6(e, 4);
  ASSERT_FALSE(dice6.find_concurrence());
  dice6 += 4;
  ASSERT_EQ(4, dice6[3]);
  ASSERT_EQ(4, dice6[5]);
  ASSERT_TRUE(dice6.find_concurrence());
  dice6 -= 4;
  ASSERT_FALSE(dice6.find_concurrence());
  ASSERT_EQ(6, dice6[3]);
}

TEST(overloaded_operators, test_exception){
  DICE dice7(5);
  ASSERT_ANY_THROW(dice7 += 7);
  ASSERT_ANY_THROW(dice7 -= 8);
  ASSERT_ANY_THROW(dice7[6]);
}

TEST(dice_constructor, test_exception){
  ASSERT_ANY_THROW(DICE dice8(-1));

  int f[2] = {2, 3};
  ASSERT_ANY_THROW(DICE dice9(f, -7));
}

int main(int argc, char *argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
