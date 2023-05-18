#include <string>
#include <vector>
using namespace std;

namespace ariel{
    class Point {
    public:
        Point(double x, double y);
        double distance(const Point& other);
        void print();
        static Point moveTowards(const Point& source, const Point& destination, double distance);
    private:
        double x, y;
    };

    class Character {
    public:
        Character(const std::string& name, const Point& location, int hit_points);
        bool isAlive();
        double distance(Character* other);
        void hit(int damage);
        std::string getName();
        Point getLocation();
        virtual string print();
    protected:
        std::string name;
        Point location;
        int hit_points;
    };

    class Cowboy : public Character {
    public:
        Cowboy(const std::string& name, const Point& location);
        void shoot(Character* enemy);
        bool hasBullets();
        void reload();
        string print() override;
    private:
        int bullets;
    };

    class Ninja : public Character {
    public:
        Ninja(const std::string& name, const Point& location, int hit_points, int speed);
        void move(Character* enemy);
        void slash(Character* enemy);
    protected:
        int speed;
    };

    class YoungNinja : public Ninja {
    public:
        YoungNinja(const std::string& name, const Point& location);
    };

    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const std::string& name, const Point& location);
    };

    class OldNinja : public Ninja {
    public:
        OldNinja(const std::string& name, const Point& location);
    };

    class Team {
    public:
        Team(Character* leader);
        void add(Character* character);
        void attack(Team* enemy_team);
        int stillAlive();
        void print();
        ~Team();
    protected:
        std::vector<Character*> members;
        Character* leader;
    };

    class Team2 : public Team {
    public:
        using Team::Team; // inherit constructor
    };

    class SmartTeam : public Team {
    public:
        using Team::Team; // inherit constructor
    };
}