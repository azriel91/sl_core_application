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

#include "Application.h"

namespace sl {
namespace core {
namespace application {

Application::Application(std::shared_ptr<ns::ActivityStack> activityStack) :
		activityStack(activityStack),
		currentActivity(std::shared_ptr<ns::Activity>(nullptr)) {
}

Application::~Application() {
}

} /* namespace application */
} /* namespace core */
} /* namespace sl */
