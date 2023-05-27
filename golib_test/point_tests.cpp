#include <boost/test/unit_test.hpp>
#include <point.h>
 

BOOST_AUTO_TEST_CASE(Check_that_point_returns_correct_neighbours){
    auto p = Point(2, 3);
    auto neighbours = p.neighbours();
    BOOST_REQUIRE(neighbours.size() == 4);
    BOOST_REQUIRE(neighbours[0].row == 1);
    BOOST_REQUIRE(neighbours[0].col == 3);
    BOOST_REQUIRE(neighbours[1].row == 3);
    BOOST_REQUIRE(neighbours[1].col == 3);
    BOOST_REQUIRE(neighbours[2].row == 2);
    BOOST_REQUIRE(neighbours[2].col == 2);
    BOOST_REQUIRE(neighbours[3].row == 2);
    BOOST_REQUIRE(neighbours[3].col == 4);
}