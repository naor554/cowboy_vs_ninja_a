#include "Team.hpp" // replace with actual header file name
#include <stdexcept>

namespace ariel {

    Point::Point(double x, double y) {
        // TODO: Implement
    }

    double Point::distance(const Point& other) {
       return 0; // TODO: Implement
    }

    void Point::print() {
        // TODO: Implement
    }

    Point Point::moveTowards(const Point& source, const Point& destination, double distance) {
       return Point(0,0); // TODO: Implement
    }

    Character::Character(const std::string& name, const Point& location, int hit_points) 
    : name(name), location(location), hit_points(hit_points) {
    // body of the constructor (if any)
    }

    
    bool Character::isAlive() {
        return hit_points > 0;
    }

    double Character::distance(Character* other) {
       return location.distance(other->location);
    }

    void Character::hit(int damage) {
        // TODO: Implement
    }

    std::string Character::getName() {
        return name;
    }

    Point Character::getLocation() {
        return location;
    }

    string Character::print() {
        return name;
    }

   Cowboy::Cowboy(const std::string& name, const Point& location) 
    : Character(name, location, 110), bullets(6) {
    // body of the constructor (if any)
    }


    Ninja::Ninja(const std::string& name, const Point& location, int hit_points, int speed) 
        : Character(name, location, hit_points), speed(speed) {
        // body of the constructor (if any)
    }

    YoungNinja::YoungNinja(const std::string& name, const Point& location) 
        : Ninja(name, location, 100, 14) {
        // body of the constructor (if any)
    }

    TrainedNinja::TrainedNinja(const std::string& name, const Point& location) 
        : Ninja(name, location, 120, 12) {
        // body of the constructor (if any)
    }

    OldNinja::OldNinja(const std::string& name, const Point& location) 
        : Ninja(name, location, 150, 8) {
        // body of the constructor (if any)
    }

    void Cowboy::shoot(Character* enemy) {
        // TODO: Implement
    }

    bool Cowboy::hasBullets() {
        return bullets > 0;
    }

    void Cowboy::reload() {
        // TODO: Implement
    }

    string Cowboy::print() {
        return Character::print() + " (Cowboy)";
    }

    void Ninja::move(Character* enemy) {
        // TODO: Implement
    }

    void Ninja::slash(Character* enemy) {
        // TODO: Implement
    }

    Team::Team(Character* leader) {
        // TODO: Implement
    }

    void Team::add(Character* character) {
        // TODO: Implement
    }

    void Team::attack(Team* enemy_team) {
        // TODO: Implement
    }

    int Team::stillAlive() {
       return 0; // TODO: Implement
    }

    void Team::print() {
        // TODO: Implement
    }

    Team::~Team() {
        // TODO: Implement
    }

    // Team2::Team2(Character* leader) : Team(leader) {
    //     // Constructor is inherited, no additional implementation is needed
    // }

    // SmartTeam::SmartTeam(Character* leader) : Team(leader) {
    //     // Constructor is inherited, no additional implementation is needed
    // }
}
