//  Copyright (c) 2019 Ste||ar Group
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>
#include <hpx/synchronization/config/defines.hpp>
#include <hpx/synchronization/detail/counting_semaphore.hpp>

#if defined(HPX_SYNCHRONIZATION_HAVE_DEPRECATION_WARNINGS)
#if defined(HPX_MSVC)
#pragma message(                                                               \
    "The header hpx/lcos/local/detail/counting_semaphore.hpp is deprecated, \
    please include hpx/synchronization/detail/counting_semaphore.hpp instead")
#else
#warning                                                                       \
    "The header hpx/lcos/local/detail/counting_semaphore.hpp is deprecated, \
    please include hpx/synchronization/detail/counting_semaphore.hpp instead"
#endif
#endif
