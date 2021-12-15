//
// Created by timas on 16.12.2021.
//

#include <gtest/gtest.h>

#include "mission.hpp"
#include "operation.hpp"
#include "position.hpp"

class OperationTests: public ::testing::Test {
protected:
    int deepSetting = 0;
    int deepValue = 30;
    int deepType = 0;

    std::unique_ptr<Operation> operation = std::make_unique<Operation>();

    virtual void SetUp() {}

    virtual void TearDown() {}
};

TEST_F(OperationTests, SuccessOperationDive) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, deepValue, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    deepValue = 30;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, deepValue, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 2);
}

TEST_F(OperationTests, ErrorOperationDive) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, deepValue, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    deepValue = 35;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, deepValue, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 1);
}

TEST_F(OperationTests, ErrorOperationLift) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Lift>(deepSetting, deepValue, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 0;
    deepValue = -35;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Lift>(deepSetting, deepValue, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}