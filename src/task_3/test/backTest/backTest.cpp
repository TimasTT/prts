//
// Created by timas on 16.12.2021.
//

#include <gtest/gtest.h>

#include "mission.hpp"
#include "operation.hpp"

class OperationTests: public ::testing::Test {
protected:
    int deepSetting = 0;
    int newZ = 30;
    int deepType = 0;

    int newX = -1000;
    int newY = 1000;
    int moveType = 0;
    int deepTypeMove = 1;

    std::unique_ptr<Operation> operation = std::make_unique<Operation>();

    virtual void SetUp() {}

    virtual void TearDown() {}
};

TEST_F(OperationTests, SuccessOperationDive) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    newZ = 30;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 2);
}

TEST_F(OperationTests, ErrorOperationDive) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    newZ = 150;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 1);
}

TEST_F(OperationTests, ErrorOperationLift) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Lift>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 0;
    newZ = 200;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Lift>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 1);
}

TEST_F(OperationTests, ErrorOperationMove) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Move>(newX, newY, moveType, deepTypeMove);
    operation->SetMission(std::move(mission1));
    operation->Do();
    newX = 5000;
    std::unique_ptr<IMission> mission2 = std::make_unique<Move>(newX, newY, moveType, deepTypeMove);
    operation->SetMission(std::move(mission2));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 1);
}

TEST_F(OperationTests, SuccessOperationAll) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    newZ = 10;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    std::unique_ptr<IMission> mission3 = std::make_unique<Move>(newX, newY, moveType, deepTypeMove);
    operation->SetMission(std::move(mission3));
    operation->Do();
    newX = 3000;
    std::unique_ptr<IMission> mission4 = std::make_unique<Move>(newX, newY, moveType, deepTypeMove);
    operation->SetMission(std::move(mission4));
    operation->Do();
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 4);
}

TEST_F(OperationTests, SwapTest) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    newZ = 30;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    operation->SwapMissions(0, 1);
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 2);
}

TEST_F(OperationTests, DeleteTest) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    newZ = 30;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission2));
    operation->Do();
    operation->DeleteMission(0);
    size_t len = operation->getOperationLen();
    size_t lenDel = operation->getDeletedOperationLen();
    EXPECT_TRUE(len == 1);
    EXPECT_TRUE(lenDel == 1);
}

TEST_F(OperationTests, InsertTest) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    newZ = 30;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->InsertMission(0, std::move(mission2));
    size_t len = operation->getOperationLen();
    EXPECT_TRUE(len == 2);
}

TEST_F(OperationTests, PushDeletedTest) {
    std::unique_ptr<IMission> mission1 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->SetMission(std::move(mission1));
    operation->Do();
    deepSetting = 1;
    newZ = 30;
    deepType = 1;
    std::unique_ptr<IMission> mission2 = std::make_unique<Dive>(deepSetting, newZ, deepType);
    operation->InsertMission(0, std::move(mission2));
    operation->DeleteMission(0);
    operation->PushDeletedMission(0);
    size_t len = operation->getOperationLen();
    size_t lenDel = operation->getDeletedOperationLen();
    EXPECT_TRUE(len == 2);
    EXPECT_TRUE(lenDel == 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}