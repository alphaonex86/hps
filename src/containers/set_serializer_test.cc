#include "set_serializer.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <set>
#include "../basic_types/int_serializer.h"

TEST(SetSerializerTest, TestNoElements) {
  std::set<int> input;
  std::stringstream ss;
  hps::OutputBuffer ob(ss);
  hps::Serializer<std::set<int>>::serialize(input, ob);
  ob.flush();

  hps::InputBuffer ib(ss);
  std::set<int> output;
  hps::Serializer<std::set<int>>::parse(output, ib);
  EXPECT_THAT(output, testing::IsEmpty());
}

TEST(SetSerializerTest, TestFewElements) {
  std::set<int> input;
  input.insert(3);
  input.insert(0);
  input.insert(-133);
  std::stringstream ss;
  hps::OutputBuffer ob(ss);
  hps::Serializer<std::set<int>>::serialize(input, ob);
  ob.flush();

  hps::InputBuffer ib(ss);
  std::set<int> output;
  hps::Serializer<std::set<int>>::parse(output, ib);
  EXPECT_THAT(output, testing::UnorderedElementsAre(3, 0, -133));
}