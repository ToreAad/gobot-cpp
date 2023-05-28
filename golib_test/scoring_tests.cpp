#include <boost/test/unit_test.hpp>
#include <goboard.h>
//#include <scoring.h>
//
//BOOST_AUTO_TEST_CASE(test_scoring) {
//    auto board = Board::new(5);
//    board.place_stone(Player::Black, Point::new(1, 2));
//    board.place_stone(Player::Black, Point::new(1, 4));
//    board.place_stone(Player::Black, Point::new(2, 2));
//    board.place_stone(Player::Black, Point::new(2, 3));
//    board.place_stone(Player::Black, Point::new(2, 4));
//    auto territory = evaluate_territory(&board);
//    BOOST_REQUIRE(5 == territory.num_black_stones);
//    BOOST_REQUIRE(20 == territory.num_black_territory);
//    BOOST_REQUIRE(0 == territory.num_white_stones);
//    BOOST_REQUIRE(0 == territory.num_white_territory);
//    BOOST_REQUIRE(0 == territory.num_dame);
//    board.place_stone(Player::Black, Point::new(2, 5));
//    board.place_stone(Player::Black, Point::new(3, 1));
//    board.place_stone(Player::Black, Point::new(3, 2));
//    auto territory = evaluate_territory(&board);
//    BOOST_REQUIRE(8 == territory.num_black_stones);
//    BOOST_REQUIRE(17 == territory.num_black_territory);
//    BOOST_REQUIRE(0 == territory.num_white_stones);
//    BOOST_REQUIRE(0 == territory.num_white_territory);
//    BOOST_REQUIRE(0 == territory.num_dame);
//    board.place_stone(Player::Black, Point::new(3, 3));
//    auto territory = evaluate_territory(&board);
//    BOOST_REQUIRE(9 == territory.num_black_stones);
//    BOOST_REQUIRE(16 == territory.num_black_territory);
//    BOOST_REQUIRE(0 == territory.num_white_stones);
//    BOOST_REQUIRE(0 == territory.num_white_territory);
//    BOOST_REQUIRE(0 == territory.num_dame);
//    board.place_stone(Player::White, Point::new(3, 4));
//    board.place_stone(Player::White, Point::new(3, 5));
//    board.place_stone(Player::White, Point::new(4, 1));
//    board.place_stone(Player::White, Point::new(4, 2));
//    board.place_stone(Player::White, Point::new(4, 3));
//    board.place_stone(Player::White, Point::new(4, 4));
//    auto territory = evaluate_territory(&board);
//    BOOST_REQUIRE(9 == territory.num_black_stones);
//    BOOST_REQUIRE(4 == territory.num_black_territory);
//    BOOST_REQUIRE(6 == territory.num_white_stones);
//    BOOST_REQUIRE(6 == territory.num_white_territory);
//    BOOST_REQUIRE(0 == territory.num_dame);
//    board.place_stone(Player::White, Point::new(5, 2));
//    board.place_stone(Player::White, Point::new(5, 4));
//    board.place_stone(Player::White, Point::new(5, 5));
//    auto territory = evaluate_territory(&board);
//    BOOST_REQUIRE(9 == territory.num_black_stones);
//    BOOST_REQUIRE(4 == territory.num_black_territory);
//    BOOST_REQUIRE(9 == territory.num_white_stones);
//    BOOST_REQUIRE(3 == territory.num_white_territory);
//    BOOST_REQUIRE(0 == territory.num_dame);
//}
//
//BOOST_AUTO_TEST_CASE(test_print_board) {
//    auto board = Board::new(5);
//    board.place_stone(Player::Black, Point::new(1, 2));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(1, 4));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(2, 2));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(2, 3));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(2, 4));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(2, 5));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(3, 1));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(3, 2));
//    print!("{}\n", board);
//    board.place_stone(Player::Black, Point::new(3, 3));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(3, 4));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(3, 5));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(4, 1));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(4, 2));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(4, 3));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(4, 4));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(5, 2));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(5, 4));
//    print!("{}\n", board);
//    board.place_stone(Player::White, Point::new(5, 5));
//    print!("{}\n", board);
//}