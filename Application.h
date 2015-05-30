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

#ifndef __SL_CORE_APPLICATION__APPLICATION_H
#define __SL_CORE_APPLICATION__APPLICATION_H

#include <memory>
#include <stack>

#include "Activity.h"
#include "Block.h"

namespace sl {
namespace core {
namespace application {

namespace ns = sl::core::application;
typedef std::shared_ptr<ns::Activity> ActivityPointer;
typedef std::stack<ns::ActivityPointer> ActivityStack;

class SL_CORE_APPLICATION_EXPORT Application {
private:
	/** The activity stack */
	std::shared_ptr<ns::ActivityStack> activityStack;
	/** The currently active activity */
	std::shared_ptr<ns::Activity> currentActivity;

public:
	Application(std::shared_ptr<ns::ActivityStack> activityStack);
	virtual ~Application();

private:
	Application(const Application& other) = delete; // disable copy
};

} /* namespace application */
} /* namespace core */
} /* namespace sl */

#endif /* __SL_CORE_APPLICATION__APPLICATION_H */
