//  Copyright (c) 2019 Ste||ar Group
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>
#include <hpx/execution/config/defines.hpp>
#include <hpx/execution/traits/detail/vc/vector_pack_load_store.hpp>

#if defined(HPX_EXECUTION_HAVE_DEPRECATION_WARNINGS)
#if defined(HPX_MSVC)
#pragma message(                                                               \
    "The header hpx/parallel/traits/detail/vc/vector_pack_load_store.hpp is deprecated, \
    please include hpx/execution/traits/detail/vc/vector_pack_load_store.hpp \
    instead")
#else
#warning                                                                       \
    "The header hpx/parallel/traits/detail/vc/vector_pack_load_store.hpp is deprecated, \
    please include hpx/execution/traits/detail/vc/vector_pack_load_store.hpp \
    instead"
#endif
#endif
