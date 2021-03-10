/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Itay Arcobi>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
//GOOD SNOWMAN CODE:
TEST_CASE("Good snowman code") {
    //random cases:
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces(" ___ \n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13224411)) == nospaces("_===_\n(o_o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12334411)) == nospaces("_===_\n(0.0)\n( : )\n( : )"));
//hat:
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces(" ___ \n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces("  _ \n /_\\ \n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces(" ___ \n(_*_)\n(.,.)\n( : )\n( : )"));

    // nose:
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
//left_eye:
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(0,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));
//r_eye:
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11424411)) == nospaces("_===_\n(-,o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11434411)) == nospaces("_===_\n(-,0)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11444411)) == nospaces("_===_\n(-,-)\n( : )\n( : )"));
// left arm:
    CHECK(nospaces(snowman(13111411)) == nospaces(" _===_\n (._.)\n<( : )\n ( : )"));
    CHECK(nospaces(snowman(13114111)) == nospaces("_===_\n(._.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(13112411)) == nospaces(" _===_\n\\(._.)\n ( : )\n ( : )"));
    CHECK(nospaces(snowman(13113411)) == nospaces(" _===_\n (._.)\n/( : )\n ( : )"));
// right arm:
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114111)) == nospaces("_===_\n(._.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(13114211)) == nospaces("_===_\n(._.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114311)) == nospaces("_===_\n(._.)\n( : )\\n( : )"));
    //torso
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114421)) == nospaces("_===_\n(...)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(12114431)) == nospaces("_===_\n(...)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(12114441)) == nospaces("_===_\n(...)\n(   )\n( : )"));
    //base:
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114412)) == nospaces("_===_\n(. .)\n( : )\n(" ")"));
    CHECK(nospaces(snowman(14114413)) == nospaces("_===_\n(. .)\n( : )\n(___)"));
    CHECK(nospaces(snowman(14114414)) == nospaces("_===_\n(. .)\n( : )\n(   )"));
}
//BAD SNOWMAN CODE:
TEST_CASE("size of number not 8:") {
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(123412)); 
    CHECK_THROWS(snowman(-1342121221));
    CHECK_THROWS(snowman(414141123));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(22));
    CHECK_THROWS(snowman(333));
    CHECK_THROWS(snowman(4444));
    CHECK_THROWS(snowman(55555));
    CHECK_THROWS(snowman(666666));
    CHECK_THROWS(snowman(7777777));

}
TEST_CASE("not in the right range 1-4:") {
CHECK_THROWS(snowman(12345678));
CHECK_THROWS(snowman(88888888));
CHECK_THROWS(snowman(55555555));
CHECK_THROWS(snowman(01234012));
CHECK_THROWS(snowman(-41234012));
}



