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

#ifndef __SL_CORE_APPLICATION__ACTIVITY_H
#define __SL_CORE_APPLICATION__ACTIVITY_H

#include <memory>

#include "sl_core_application/Block.h"

namespace sl {
namespace core {
namespace application {

/**
 * An activity is a particular "phase" of an application to carry out a particular action, which may or may not be interactive.
 * For example, an activity waiting for user input to select a game mode is interactive, whereas an activity concerned with loading
 * resources is non-interactive.
 *
 * Activities are not intended to be tied to any particular View, but should be extensible to load additional resources required by views.
 * For example, an application may only require scripts to be loaded for the engine to function, but a graphical UI may also require images
 * to be loaded, and these should be loaded before the engine continues to the next activity.
 */
class SL_CORE_APPLICATION_EXPORT Activity {
public:
	/** Exit codes for activities */
	enum class ExitCode : int {
		/** Used to indicate that the activity ended with an error */
		FAIL             = -1,
		/** Default value used when an activity has not exited */
		NONE             = 0,
		/** Used to indicate that the activity ended through an automatic code path, e.g. loading was completed */
		SUCCESS          = 1,
		/** Used to indicate that the activity ended and requests that an activity be stacked above it. */
		STACK            = 2,
		/** Used to indicate that the activity ended and should be replaced with a different activity */
		REPLACE          = 3,
		/** Used to indicate that an external request was used to end the activity, e.g. cancelling a game */
		EXTERNAL_REQUEST = 4
	};

private:
	std::shared_ptr<sl::core::application::Activity> nextActivity;

public:
	Activity();
	virtual ~Activity();

	/** Runs this activity */
	virtual ExitCode run() = 0;

	std::shared_ptr<sl::core::application::Activity> getNextActivity() const;

protected:
	void setNextActivity(std::shared_ptr<sl::core::application::Activity> nextActivity);
};

} /* namespace application */
} /* namespace core */
} /* namespace sl */

#endif /* __SL_CORE_APPLICATION__ACTIVITY_H */
