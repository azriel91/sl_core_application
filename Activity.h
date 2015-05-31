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

#include "Block.h"

namespace sl {
namespace core {
namespace application {

/**
 * An activity is a particular "phase" of an application to carry out a particular action, which may or may not be interactive.
 * For example, an activity waiting for user input to select a game mode is interactive, whereas an activity concerned with loading
 * resources is non-interactive.
 *
 * Activities are not intended to be tied to any particular View, but should be extensible to load additional resources required by views.
 * For example, an application may only require scripts to be loaded for the engine to function, but a graphical UI may also
 * require images to be loaded, and these should be loaded before the engine continues to the next activity.
 */
class SL_CORE_APPLICATION_EXPORT Activity {
public:
	Activity();
	virtual ~Activity();
};

} /* namespace application */
} /* namespace core */
} /* namespace sl */

#endif /* __SL_CORE_APPLICATION__ACTIVITY_H */
