//  Copyright (c) 2019 Ste||ar Group
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>
#include <hpx/serialization/config/defines.hpp>
#include <hpx/serialization/traits/needs_automatic_registration.hpp>

#if defined(HPX_SERIALIZATION_HAVE_DEPRECATION_WARNINGS)
#if defined(HPX_MSVC)
#pragma message(                                                               \
    "The header hpx/traits/needs_automatic_registration.hpp is deprecated, \
    please include hpx/serialization/traits/needs_automatic_registration.hpp instead")
#else
#warning                                                                       \
    "The header hpx/traits/needs_automatic_registration.hpp is deprecated, \
    please include hpx/serialization/traits/needs_automatic_registration.hpp instead"
#endif
#endif
