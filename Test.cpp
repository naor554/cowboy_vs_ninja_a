#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "sources/Team.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Testing Point class") {
    Point a(32.3, 44);
    Point b(1.3, 3.5);

    CHECK(a.distance(b) == b.distance(a));
    CHECK(Point::moveTowards(a, b, 1).distance(a) == doctest::Approx(1.0));
}

TEST_CASE("Testing Character class") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);

    CHECK(tom.isAlive() == true);
    tom.hit(110);  // Assuming cowboy has 110 hit points initially.
    CHECK(tom.isAlive() == false);
}

TEST_CASE("Testing Cowboy class") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);

    CHECK(tom.hasBullets() == true);
    tom.shoot(&tom);  // Cowboy shooting at himself for testing.
    CHECK(tom.hasBullets() == false);
}

TEST_CASE("Testing Ninja class") {
    Point b(1.3, 3.5);
    OldNinja sushi("Sushi", b);

    CHECK(sushi.isAlive() == true);
    sushi.hit(150);  // Assuming old ninja has 150 hit points initially.
    CHECK(sushi.isAlive() == false);
}

TEST_CASE("Testing Ninja subclasses") {
    Point a(32.3, 44);
    YoungNinja yogi("Yogi", a);
    TrainedNinja hikari("Hikari", a);

    CHECK(yogi.isAlive() == true);
    CHECK(hikari.isAlive() == true);
    yogi.hit(100);  // Assuming young ninja has 100 hit points initially.
    hikari.hit(120);  // Assuming trained ninja has 120 hit points initially.
    CHECK(yogi.isAlive() == false);
    CHECK(hikari.isAlive() == false);
}

TEST_CASE("Testing Team class") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    Team team_A(&tom);

    CHECK(team_A.stillAlive() == 1);
    tom.hit(110);  // Cowboy has 110 hit points initially.
    CHECK(team_A.stillAlive() == 0);
}

TEST_CASE("Testing Team attack") {
    Point a(32.3, 44);
    Point b(1.3, 3.5);
    Cowboy tom("Tom", a);
    OldNinja sushi("Sushi", b);
    
    Team team_A(&tom);
    Team team_B(&sushi);

    CHECK(sushi.isAlive() == true);
    tom.shoot(&sushi);  // Cowboy shooting at OldNinja.
    CHECK(sushi.isAlive() == true);
    team_A.attack(&team_B);
    CHECK(sushi.isAlive() == false);
}

TEST_CASE("Testing adding to team") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    YoungNinja yogi("Yogi", a);

    Team team_A(&tom);
    team_A.add(&yogi);

    CHECK(team_A.stillAlive() == 2);
}

TEST_CASE("Testing Team2 and SmartTeam classes") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);

    Team2 team2(&tom);
    SmartTeam smartTeam(&tom);

    CHECK(team2.stillAlive() == 1);
    CHECK(smartTeam.stillAlive() == 1);
    tom.hit(110);
    CHECK(team2.stillAlive() == 0);
    CHECK(smartTeam.stillAlive() == 0);
}

TEST_CASE("Testing Cowboy shooting all bullets") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    Cowboy jerry("Jerry", a);

    for(int i = 0; i < 6; i++) {
        tom.shoot(&jerry);
    }

    CHECK(tom.hasBullets() == false);
}

TEST_CASE("Testing Cowboy reload") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    Cowboy jerry("Jerry", a);

    for(int i = 0; i < 6; i++) {
        tom.shoot(&jerry);
    }
    tom.reload();
    CHECK(tom.hasBullets() == true);
}

TEST_CASE("Testing Ninja movement") {
    Point a(32.3, 44);
    Point b(1.3, 3.5);
    OldNinja sushi("Sushi", a);
    Cowboy tom("Tom", b);

    double distance_before = sushi.distance(&tom);
    sushi.move(&tom);
    double distance_after = sushi.distance(&tom);

    CHECK(distance_before > distance_after);
}

TEST_CASE("Testing Ninja slash range") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    YoungNinja yogi("Yogi", a);

    yogi.slash(&tom);
    CHECK(tom.isAlive() == true);  // YoungNinja is too far to slash.
}

TEST_CASE("Testing group attack with no ammo") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    Cowboy jerry("Jerry", a);
    Team team_A(&tom);

    for(int i = 0; i < 6; i++) {
        tom.shoot(&jerry);
    }
    Team team_B(&jerry);
    team_A.attack(&team_B);  // Should reload instead of shooting.

    CHECK(tom.hasBullets() == true);
}

TEST_CASE("Testing Team print") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    Team team_A(&tom);

    // Should not throw any exception
    CHECK_NOTHROW(team_A.print());
}

TEST_CASE("Testing Team2 class, adding more than 10 characters") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    Team2 team(&tom);

    for(int i = 0; i < 9; i++) {
        Cowboy* temp = new Cowboy("Cowboy" + std::to_string(i), a);
        team.add(temp);
    }
    // Should not throw any exception
    CHECK_NOTHROW(team.print());
}

TEST_CASE("Testing SmartTeam class, adding more than 10 characters") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);
    SmartTeam team(&tom);

    for(int i = 0; i < 9; i++) {
        Cowboy* temp = new Cowboy("Cowboy" + std::to_string(i), a);
        team.add(temp);
    }
    // Should not throw any exception
    CHECK_NOTHROW(team.print());
}

TEST_CASE("Testing Ninja subclass constructor") {
    Point a(32.3, 44);
    YoungNinja yogi("Yogi", a);

    CHECK(yogi.isAlive() == true);
    CHECK(yogi.getName() == "Yogi");
}

TEST_CASE("Testing hitting with negative damage") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);

    tom.hit(-10); // Should not alter hit_points
    CHECK(tom.isAlive() == true);
}

TEST_CASE("Testing character print after death") {
    Point a(32.3, 44);
    Cowboy tom("Tom", a);

    tom.hit(110); // Tom is now dead
    // Should not throw any exception
    CHECK_NOTHROW(tom.print());
}

