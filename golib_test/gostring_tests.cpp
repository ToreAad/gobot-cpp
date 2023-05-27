#include <boost/test/unit_test.hpp>
#include "gostring.h"


BOOST_AUTO_TEST_CASE(Basic_gostring_new){
    auto player = Player::Black;
    auto stones = std::vector<Point>{Point(1, 1), Point(2, 1)};
    auto liberties = std::vector<Point>{Point(0,0), Point(1, 0)};
    auto gs = GoString(player, stones, liberties);
    BOOST_REQUIRE(gs.get_player() == player);
    BOOST_REQUIRE(gs.get_stones().size() == 2);
    BOOST_REQUIRE(gs.get_liberties().size() == 2);
}

BOOST_AUTO_TEST_CASE(GoString_add_stone){
    auto gostring = GoString();
    gostring.add_liberty(Point(1, 1));
    BOOST_REQUIRE(gostring.get_liberties().size() == 1);
}

BOOST_AUTO_TEST_CASE(GoString_add_liberty){
	auto gostring = GoString();
	gostring.add_liberty(Point(1, 1));
	BOOST_REQUIRE(gostring.get_liberties().size() == 1);
}

BOOST_AUTO_TEST_CASE(GoString_remove_stone){
	auto gostring = GoString();
	gostring.add_liberty(Point(1, 1));
	gostring.remove_liberty(Point(1, 1));
	BOOST_REQUIRE(gostring.get_liberties().size() == 0);
}

BOOST_AUTO_TEST_CASE(GoString_merged_with){
    auto gostring1 = GoString(Player::Black, std::vector<Point>{Point(1, 1)}, std::vector<Point>{Point(0, 0)});
    auto gostring2 = GoString(Player::Black, std::vector<Point>{Point(2, 2)}, std::vector<Point>{Point(1, 0)});
    gostring1.merge_with(&gostring2);
    BOOST_REQUIRE(gostring1.get_stones().size() == 2);
    BOOST_REQUIRE(gostring1.get_liberties().size() == 2);
}

BOOST_AUTO_TEST_CASE(GoString_complex_merged_with){
    auto gostring1 = GoString(Player::Black, std::vector<Point>{Point(1, 1), Point(1,2)}, std::vector<Point>{Point(2, 1)});
    auto gostring2 = GoString(Player::Black, std::vector<Point>{Point(2, 2)}, std::vector<Point>{Point(2, 1)});

    gostring1.merge_with(&gostring2);
    BOOST_REQUIRE(gostring1.get_stones().size() == 3);
    BOOST_REQUIRE(gostring1.get_liberties().size() == 1);
}