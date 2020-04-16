//  Copyright (c)      2016 Thomas Heller
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef HPX_RUNTIME_ACTIONS_FWD_HPP
#define HPX_RUNTIME_ACTIONS_FWD_HPP

#include <hpx/config.hpp>
#include <hpx/actions_base/actions_base_fwd.hpp>
#include <hpx/runtime/actions/continuation_fwd.hpp>
#if HPX_HAVE_ITTNOTIFY != 0 && !defined(HPX_HAVE_APEX)
#include <hpx/concurrency/itt_notify.hpp>
#endif

#include <cstdint>

namespace hpx { namespace actions {
    /// \cond NOINTERNAL

    struct base_action;

    ///////////////////////////////////////////////////////////////////////////
#if defined(HPX_HAVE_NETWORKING)
    template <typename Action>
    struct transfer_action;

    template <typename Action>
    struct transfer_continuation_action;
#endif

    namespace detail {
        HPX_API_EXPORT std::uint32_t get_action_id_from_name(
            char const* action_name);

        template <typename Action>
        std::uint32_t get_action_id();

#if HPX_HAVE_ITTNOTIFY != 0 && !defined(HPX_HAVE_APEX)
        template <typename Action>
        util::itt::string_handle const& get_action_name_itt();
#endif
    }    // namespace detail

    /// \endcond
}}    // namespace hpx::actions

#endif
