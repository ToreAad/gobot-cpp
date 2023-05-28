#include <boost/test/unit_test.hpp>
//#include "gamestate.h"
//
//BOOST_AUTO_TEST_CASE(test_does_move_violate_ko) {
//    auto states = GameState::new(5);
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 1, col : 3 }));
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 3, col : 2 }));
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 2, col : 2 }));
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 3, col : 4 }));
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 2, col : 4 }));
//    auto violates_ko = GameState::does_move_violate_ko(&states, Action::Play(Point{ row: 4, col : 3 }));
//    BOOST_REQUIRE(violates_ko == false);
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 4, col : 3 }));
//    violates_ko = GameState::does_move_violate_ko(&states, Action::Play(Point{ row: 3, col : 3 }));
//    BOOST_REQUIRE(violates_ko == false);
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 3, col : 3 }));
//    violates_ko = GameState::does_move_violate_ko(&states, Action::Play(Point{ row: 2, col : 3 }));
//    BOOST_REQUIRE(violates_ko == false);
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 2, col : 3 }));
//    violates_ko = GameState::does_move_violate_ko(&states, Action::Play(Point{ row: 3, col : 3 }));
//    BOOST_REQUIRE(violates_ko == true);
//    violates_ko = GameState::does_move_violate_ko(&states, Action::Play(Point{ row: 3, col : 3 }));
//    BOOST_REQUIRE(violates_ko == true);
//}
//
//
//BOOST_AUTO_TEST_CASE(test_is_over) {
//    auto states = GameState::new(5);
//    GameState::apply_move(&mut states, Action::Resign);
//    BOOST_REQUIRE(GameState::is_over(&states) == true);
//
//    states = GameState::new(5);
//    GameState::apply_move(&mut states, Action::Pass);
//    BOOST_REQUIRE(GameState::is_over(&states) == false);
//    GameState::apply_move(&mut states, Action::Pass);
//    BOOST_REQUIRE(GameState::is_over(&states) == true);
//
//    states = GameState::new(5);
//    GameState::apply_move(&mut states, Action::Pass);
//    BOOST_REQUIRE(GameState::is_over(&states) == false);
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 1, col : 1 }));
//    GameState::apply_move(&mut states, Action::Pass);
//    BOOST_REQUIRE(GameState::is_over(&states) == false);
//    GameState::apply_move(&mut states, Action::Pass);
//    BOOST_REQUIRE(GameState::is_over(&states) == true);
//}
//
//
//BOOST_AUTO_TEST_CASE(test_self_capture) {
//    auto states = GameState::new(3);
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 2, col : 1 }));
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 3, col : 3 }));
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 1, col : 2 }));
//    BOOST_REQUIRE(states.last().unwrap().board.is_self_capture(Player::White, &Point{ row: 1, col : 1 }) == true);
//
//
//    GameState::apply_move(&mut states, Action::Play(Point{ row: 1, col : 1 }));
//
//}
