//  Copyright (c) 2017-2018 Taeguk Kwon
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/hpx.hpp>
#include <hpx/hpx_init.hpp>
#include <hpx/include/parallel_remove.hpp>
#include <hpx/testing.hpp>

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <numeric>
#include <random>
#include <string>
#include <vector>

#include "test_utils.hpp"

////////////////////////////////////////////////////////////////////////////
struct user_defined_type
{
    user_defined_type() = default;
    user_defined_type(int rand_no)
      : val(rand_no)
      , name(name_list[std::rand() % name_list.size()])
    {
    }

    bool operator==(int rand_no) const
    {
        return this->val == rand_no;
    }

    bool operator==(user_defined_type const& t) const
    {
        return this->name == t.name && this->val == t.val;
    }

    static const std::vector<std::string> name_list;

    int val;
    std::string name;
};

const std::vector<std::string> user_defined_type::name_list{
    "ABB", "ABC", "ACB", "BASE", "CAA", "CAAA", "CAAB"};

struct random_fill
{
    random_fill(int rand_base, int range)
      : gen(std::rand())
      , dist(rand_base - range / 2, rand_base + range / 2)
    {
    }

    int operator()()
    {
        return dist(gen);
    }

    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
};

////////////////////////////////////////////////////////////////////////////
template <typename ExPolicy, typename DataType>
void test_remove_if(ExPolicy policy, DataType)
{
    static_assert(
        hpx::parallel::execution::is_execution_policy<ExPolicy>::value,
        "hpx::parallel::execution::is_execution_policy<ExPolicy>::value");

    using hpx::util::get;

    std::size_t const size = 10007;
    std::vector<DataType> c(size), d;
    std::generate(std::begin(c), std::end(c), random_fill(0, 6));
    d = c;

    auto pred = [](DataType const& a) -> bool { return a == 0; };

    auto result = hpx::parallel::remove_if(policy, c, pred);
    auto solution = std::remove_if(std::begin(d), std::end(d), pred);

    bool equality = test::equal(std::begin(c), result, std::begin(d), solution);

    HPX_TEST(equality);
}

template <typename ExPolicy, typename DataType>
void test_remove_if_async(ExPolicy policy, DataType)
{
    static_assert(
        hpx::parallel::execution::is_execution_policy<ExPolicy>::value,
        "hpx::parallel::execution::is_execution_policy<ExPolicy>::value");

    using hpx::util::get;

    std::size_t const size = 10007;
    std::vector<DataType> c(size), d;
    std::generate(std::begin(c), std::end(c), random_fill(0, 6));
    d = c;

    auto pred = [](DataType const& a) -> bool { return a == 0; };

    auto f = hpx::parallel::remove_if(policy, c, pred);
    auto result = f.get();
    auto solution = std::remove_if(std::begin(d), std::end(d), pred);

    bool equality = test::equal(std::begin(c), result, std::begin(d), solution);

    HPX_TEST(equality);
}

template <typename DataType>
void test_remove_if()
{
    using namespace hpx::parallel;

    test_remove_if(execution::seq, DataType());
    test_remove_if(execution::par, DataType());
    test_remove_if(execution::par_unseq, DataType());

    test_remove_if_async(execution::seq(execution::task), DataType());
    test_remove_if_async(execution::par(execution::task), DataType());
}

void test_remove_if()
{
    test_remove_if<int>();
    test_remove_if<user_defined_type>();
}

int hpx_main(hpx::program_options::variables_map& vm)
{
    unsigned int seed = (unsigned int) std::time(nullptr);
    if (vm.count("seed"))
        seed = vm["seed"].as<unsigned int>();

    std::cout << "using seed: " << seed << std::endl;
    std::srand(seed);

    test_remove_if();
    return hpx::finalize();
}

int main(int argc, char* argv[])
{
    // add command line option which controls the random number generator seed
    using namespace hpx::program_options;
    options_description desc_commandline(
        "Usage: " HPX_APPLICATION_STRING " [options]");

    desc_commandline.add_options()("seed,s", value<unsigned int>(),
        "the random number generator seed to use for this run");

    // By default this test should run on all available cores
    std::vector<std::string> const cfg = {"hpx.os_threads=all"};

    // Initialize and run HPX
    HPX_TEST_EQ_MSG(hpx::init(desc_commandline, argc, argv, cfg), 0,
        "HPX main exited with non-zero status");

    return hpx::util::report_errors();
}
