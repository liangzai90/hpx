//  Copyright (c) 2019 Ste||ar Group
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <hpx/config.hpp>
#include <hpx/plugin/config/defines.hpp>
#include <hpx/plugin/detail/dll_windows.hpp>

#if defined(HPX_PLUGIN_HAVE_DEPRECATION_WARNINGS)
#if defined(HPX_MSVC)
#pragma message(                                                               \
    "The header hpx/util/plugin/detail/dll_windows.hpp is deprecated, \
    please include hpx/plugin/detail/dll_windows.hpp instead")
#else
#warning "The header hpx/util/plugin/detail/dll_windows.hpp is deprecated, \
    please include hpx/plugin/detail/dll_windows.hpp instead"
#endif
#endif
