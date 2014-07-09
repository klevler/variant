// Eggs.Variant
//
// Copyright Agustin K-ballo Berge, Fusion Fenix 2014
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <eggs/variant.hpp>
#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("get<I>(variant<Ts...>&)", "[variant.elem]")
{
    eggs::variant<int, std::string> v(42);

    REQUIRE(v.which() == 0);
    REQUIRE(*v.target<int>() == 42);

    int& ref = eggs::variants::get<0>(v);

    REQUIRE(ref == 42);

    SECTION("throws")
    {
        try
        {
            eggs::variants::get<1>(v);
        } catch (eggs::variants::bad_variant_access&) {
            REQUIRE(true);
        } catch (...) {
            REQUIRE(false);
        }
    }
}

TEST_CASE("get<I>(variant<Ts...> const&)", "[variant.elem]")
{
    eggs::variant<int, std::string> const v(42);

    REQUIRE(v.which() == 0);
    REQUIRE(*v.target<int>() == 42);

    int const& ref = eggs::variants::get<0>(v);

    REQUIRE(ref == 42);

    SECTION("throws")
    {
        try
        {
            eggs::variants::get<1>(v);
        } catch (eggs::variants::bad_variant_access&) {
            REQUIRE(true);
        } catch (...) {
            REQUIRE(false);
        }
    }
}

TEST_CASE("get<I>(variant<Ts...>&&)", "[variant.elem]")
{
    eggs::variant<int, std::string> v(42);

    REQUIRE(v.which() == 0);
    REQUIRE(*v.target<int>() == 42);

    int&& ref = eggs::variants::get<0>(std::move(v));

    REQUIRE(ref == 42);
}

TEST_CASE("get<T>(variant<Ts...>&)", "[variant.elem]")
{
    eggs::variant<int, std::string> v(42);

    int& ref = eggs::variants::get<int>(v);

    REQUIRE(ref == 42);

    SECTION("throws")
    {
        try
        {
            eggs::variants::get<1>(v);
        } catch (eggs::variants::bad_variant_access&) {
            REQUIRE(true);
        } catch (...) {
            REQUIRE(false);
        }
    }
}

TEST_CASE("get<T>(variant<Ts...> const&)", "[variant.elem]")
{
    eggs::variant<int, std::string> const v(42);

    int const& ref = eggs::variants::get<int>(v);

    REQUIRE(ref == 42);

    SECTION("throws")
    {
        try
        {
            eggs::variants::get<1>(v);
        } catch (eggs::variants::bad_variant_access&) {
            REQUIRE(true);
        } catch (...) {
            REQUIRE(false);
        }
    }
}

TEST_CASE("get<T>(variant<Ts...>&&)", "[variant.elem]")
{
    eggs::variant<int, std::string> v(42);

    int&& ref = eggs::variants::get<int>(std::move(v));

    REQUIRE(ref == 42);
}