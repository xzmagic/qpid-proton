#ifndef PROTON_CPP_SESSION_OPTIONS_H
#define PROTON_CPP_SESSION_OPTIONS_H

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */

#include "proton/config.hpp"
#include "proton/export.hpp"
#include "proton/pn_unique_ptr.hpp"
#include "proton/types.hpp"


namespace proton {

class handler;
class session;


/// Options for creating a session.
///
/// Options can be "chained" (@see proton::connection_options).
///
/// Normal value semantics: copy or assign creates a separate copy of
/// the options.
class session_options {
  public:

    /// Create an empty set of options.
    PN_CPP_EXTERN session_options();

    /// Copy options.
    PN_CPP_EXTERN session_options(const session_options&);

    PN_CPP_EXTERN ~session_options();

    /// Copy options.
    PN_CPP_EXTERN session_options& operator=(const session_options&);

    /// Set a handler for the session.
    PN_CPP_EXTERN session_options& handler(class handler *);

    /// @cond INTERNAL
    // Other useful session configuration TBD.
  private:
    void apply(session&) const;

    class impl;
    internal::pn_unique_ptr<impl> impl_;

    friend class session;
    /// @endcond
};

}

#endif // PROTON_CPP_SESSION_OPTIONS_H
