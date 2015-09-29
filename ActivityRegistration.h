/*=============================================================================

	Library: Silver

	Copyright (c) Azriel Hoh

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

=============================================================================*/

#ifndef __SL_CORE_APPLICATION__ACTIVITYREGISTRATION_H
#define __SL_CORE_APPLICATION__ACTIVITYREGISTRATION_H

#include <string>

#include "Activity.h"
#include "sl_core_application/Block.h"

namespace sl {
namespace core {
namespace application {

class SL_CORE_APPLICATION_EXPORT ActivityRegistration {
public:
	virtual ~ActivityRegistration() = default;

	/**
	 * Get the unique name of the activity that this ActivityRegistration is for
	 */
	virtual std::string getName() const = 0;
	/**
	 * Get the activity associated with this service
	 */
	virtual sl::core::application::ActivityPointer getActivity() const = 0;
};

} /* namespace application */
} /* namespace core */
} /* namespace sl */

#endif /* __SL_CORE_APPLICATION__ACTIVITYREGISTRATION_H */
