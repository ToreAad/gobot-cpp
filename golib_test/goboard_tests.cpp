#define BOOST_TEST_MODULE GoTests

#include <boost/test/unit_test.hpp>
#include "goboard.h"

BOOST_AUTO_TEST_CASE(goboard_place_stones){
	auto board = GoBoard(2);
	board.place_stone(Player::Black, Point(1, 1));
	// TODO
}

BOOST_AUTO_TEST_CASE(place_stone){
    auto board = GoBoard(2);
    board.place_stone(Player::Black, Point(1,1));
    BOOST_REQUIRE(board.get_player(Point(1, 1 )) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 1 )) == Player::None);
    BOOST_REQUIRE(board.get_player(Point(2, 2 )) == Player::None);
    BOOST_REQUIRE(board.get_player(Point(1, 2 )) == Player::None);
}

BOOST_AUTO_TEST_CASE(place_two_different_stones){
    auto board = GoBoard(2);
    board.place_stone(Player::Black, Point(1, 1));
    board.place_stone(Player::White, Point(2, 1));
    BOOST_REQUIRE(board.get_player(Point(1, 1)) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 1)) == Player::White);
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::None);
    BOOST_REQUIRE(board.get_player(Point(1, 2)) == Player::None);
}

BOOST_AUTO_TEST_CASE(place_two_similar_stones){
    auto board = GoBoard(2);
    board.place_stone(Player::Black, Point(1, 1));
    board.place_stone(Player::Black, Point(2, 1));
    BOOST_REQUIRE(board.get_player(Point(1, 1)) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 1)) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::None);
    BOOST_REQUIRE(board.get_player(Point(1, 2)) == Player::None);
}

BOOST_AUTO_TEST_CASE(capture){
    auto board = GoBoard(19);
    board.place_stone(Player::Black, Point(2, 2));
    board.place_stone(Player::White, Point(1, 2));
    BOOST_REQUIRE(board.get_player(Point(1, 2)) == Player::White);
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    board.place_stone(Player::White, Point(2, 1));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    board.place_stone(Player::White, Point(2, 3));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    board.place_stone(Player::White, Point(3, 2));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::None);
}



BOOST_AUTO_TEST_CASE(capture_dlgo){
    auto board = GoBoard(19);
    board.place_stone(Player::Black, Point(2, 2));
    board.place_stone(Player::White, Point(1, 2));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    board.place_stone(Player::White, Point(2, 1));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    board.place_stone(Player::White, Point(2, 3));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    board.place_stone(Player::White, Point(3, 2));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::None);
}

BOOST_AUTO_TEST_CASE(capture_two_stones){
    auto board = GoBoard(19);
    board.place_stone(Player::Black, Point(2, 2));
    BOOST_REQUIRE(board.get_string(Point(2, 2))->get_liberties().size() == 4);
    board.place_stone(Player::Black, Point(2, 3));
    BOOST_REQUIRE(board.get_string(Point(2, 2))->get_liberties().size() == 6);
    board.place_stone(Player::White, Point(1, 2));
    BOOST_REQUIRE(board.get_string(Point(2, 2))->get_liberties().size() == 5);
    board.place_stone(Player::White, Point(1, 3));
    BOOST_REQUIRE(board.get_string(Point(2, 2))->get_liberties().size() == 4);
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 3)) == Player::Black);
    board.place_stone(Player::White, Point(3, 2));
    BOOST_REQUIRE(board.get_string(Point(2, 2))->get_liberties().size() == 3);
    board.place_stone(Player::White, Point(3, 3));
    BOOST_REQUIRE(board.get_string(Point(2, 2))->get_liberties().size() == 2);
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 3)) == Player::Black);
    board.place_stone(Player::White, Point(2, 1));
    board.place_stone(Player::White, Point(2, 4));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::None);
    BOOST_REQUIRE(board.get_player(Point(2, 3)) == Player::None);
}

BOOST_AUTO_TEST_CASE(capture_two_stones_dlgo){
    auto board = GoBoard(19);
    board.place_stone(Player::Black, Point(2, 2));
    board.place_stone(Player::Black, Point(2, 3));
    board.place_stone(Player::White, Point(1, 2));
    board.place_stone(Player::White, Point(1, 3));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 3)) == Player::Black);
    board.place_stone(Player::White, Point(3, 2));
    board.place_stone(Player::White, Point(3, 3));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::Black);
    BOOST_REQUIRE(board.get_player(Point(2, 3)) == Player::Black);
    board.place_stone(Player::White, Point(2, 1));
    board.place_stone(Player::White, Point(2, 4));
    BOOST_REQUIRE(board.get_player(Point(2, 2)) == Player::None);
    BOOST_REQUIRE(board.get_player(Point(2, 3)) == Player::None);
}


BOOST_AUTO_TEST_CASE(capture_is_not_suicide){
    auto board = GoBoard(19);
    board.place_stone(Player::Black, Point(1, 1));
    board.place_stone(Player::Black, Point(2, 2));
    board.place_stone(Player::Black, Point(1, 3));
    board.place_stone(Player::White, Point(2, 1));
    board.place_stone(Player::White, Point(1, 2));
    BOOST_REQUIRE(board.get_player(Point(1, 1)) == Player::None);
    BOOST_REQUIRE(board.get_player(Point(2, 1)) == Player::White);
    BOOST_REQUIRE(board.get_player(Point(1, 2)) == Player::White);
}

BOOST_AUTO_TEST_CASE(test_is_point_an_eye){
    auto board = GoBoard(5);
    board.place_stone(Player::Black, Point(1, 1));
    board.place_stone(Player::Black, Point(1, 2));
    board.place_stone(Player::Black, Point(2, 3));
    board.place_stone(Player::Black, Point(3, 3));
    board.place_stone(Player::Black, Point(4, 3));
    board.place_stone(Player::Black, Point(5, 3));

    board.place_stone(Player::White, Point(2, 1));
    board.place_stone(Player::White, Point(2, 2));
    board.place_stone(Player::White, Point(3, 2));
    board.place_stone(Player::White, Point(4, 2));
    board.place_stone(Player::White, Point(4, 1));
    board.place_stone(Player::White, Point(5, 2));

    BOOST_REQUIRE(board.is_point_an_eye(Point(3, 1), Player::White) == true);
    BOOST_REQUIRE(board.is_point_an_eye(Point(5, 1), Player::White) == true);
    BOOST_REQUIRE(board.is_point_an_eye(Point(3, 1), Player::Black) == false);
    BOOST_REQUIRE(board.is_point_an_eye(Point(5, 1), Player::Black) == false);
    BOOST_REQUIRE(board.is_point_an_eye(Point(5, 5), Player::Black) == false);
    BOOST_REQUIRE(board.is_point_an_eye(Point(5, 5), Player::White) == false);
}

BOOST_AUTO_TEST_CASE(self_capture){
    auto board = GoBoard(5);
    board.place_stone(Player::Black, Point(1, 1));
    board.place_stone(Player::Black, Point(1, 3));
    board.place_stone(Player::White, Point(2, 1));
    board.place_stone(Player::White, Point(2, 2));
    board.place_stone(Player::White, Point(2, 3));
    board.place_stone(Player::White, Point(1, 4));

    BOOST_REQUIRE(board.is_self_capture(Player::Black, Point(1, 2)) == true);
}



BOOST_AUTO_TEST_CASE(test_self_capture_simple){
    auto board = GoBoard(3);
    board.place_stone(Player::Black, Point(1, 2));
    board.place_stone(Player::Black, Point(2, 1));

    BOOST_REQUIRE(board.is_self_capture(Player::White, Point(1, 1)) == true);
}


BOOST_AUTO_TEST_CASE(not_self_capture_is_other_capture){
    auto board = GoBoard(5);
    board.place_stone(Player::Black, Point(3, 1));
    board.place_stone(Player::Black, Point(3, 2));
    board.place_stone(Player::Black, Point(2, 3));
    board.place_stone(Player::Black, Point(1, 1));
    board.place_stone(Player::White, Point(2, 1));
    board.place_stone(Player::White, Point(2, 2));
    board.place_stone(Player::White, Point(1, 3));

    BOOST_REQUIRE(board.is_self_capture(Player::Black, Point(1, 2)) == false);
}
BOOST_AUTO_TEST_CASE(empty_triangle){
    auto board = GoBoard(5);
    board.place_stone(Player::Black, Point(1, 1));
    BOOST_REQUIRE(board.get_string(Point(1, 1))->get_liberties().size() == 2);
    board.place_stone(Player::Black, Point(1, 2));
    BOOST_REQUIRE(board.get_string(Point(1, 1))->get_liberties().size() == 3);
    board.place_stone(Player::Black, Point(2, 2));
    BOOST_REQUIRE(board.get_string(Point(1, 1))->get_liberties().size() == 4);

    board.place_stone(Player::White, Point(2, 1));

    auto black_string = board.get_string(Point(1, 1));
    BOOST_REQUIRE(black_string->get_liberties().size() == 3);
}

BOOST_AUTO_TEST_CASE(remove_liberties_dlgo){
    auto board = GoBoard(5);
    board.place_stone(Player::Black, Point(3, 3));
    board.place_stone(Player::White, Point(2, 2));
    auto white_string = board.get_string(Point(2, 2));
    BOOST_REQUIRE(white_string->get_liberties().size() == 4);
    board.place_stone(Player::Black, Point(3, 2));
    white_string = board.get_string(Point(2, 2));
    BOOST_REQUIRE(white_string->get_liberties().size() == 3);
}

BOOST_AUTO_TEST_CASE(remove_liberties){
    auto board = GoBoard(5);
    board.place_stone(Player::Black, Point(3, 3));
    board.place_stone(Player::White, Point(2, 2));
    auto white_string = board.get_string(Point(2, 2));
    BOOST_REQUIRE(white_string->get_liberties().size() == 4);
    board.place_stone(Player::Black, Point(3, 2));
    white_string = board.get_string(Point(2, 2));
    BOOST_REQUIRE(white_string->get_liberties().size() == 3);
}


