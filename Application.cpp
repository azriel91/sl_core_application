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

Application::Application(std::shared_ptr<sl::core::application::ActivityStack> activityStack) :
		activityStack(activityStack),
		currentActivity(std::shared_ptr<sl::core::application::Activity>(nullptr)) {
}

Application::~Application() {
}

const int Application::run() {
	auto exitCode = Activity::ExitCode::NONE;
	while(!this->activityStack->empty()) {
		this->currentActivity = this->activityStack->top();
		exitCode = this->currentActivity->run();

		switch(exitCode) {
			case Activity::ExitCode::FAIL:
				this->activityStack->pop();
				break;
			case Activity::ExitCode::NONE:
				this->activityStack->pop();
				break;
			case Activity::ExitCode::SUCCESS:
				this->activityStack->pop();
				break;
			case Activity::ExitCode::STACK:
				{
					auto nextActivity = this->currentActivity->getNextActivity();
					if (nextActivity) {
						this->activityStack->push(nextActivity);
					} else {
						// null ptr
						return 1002;
					}
				}
				break;
			case Activity::ExitCode::REPLACE:
				{
					auto nextActivity = this->currentActivity->getNextActivity();
					if (nextActivity) {
						this->activityStack->pop();
						this->activityStack->push(nextActivity);
					} else {
						// null ptr
						return 1003;
					}
				}
				break;
			case Activity::ExitCode::EXTERNAL_REQUEST:
				this->activityStack->pop();
				break;
			default: // never reached
				break;
		}
	}

	switch(exitCode) {
		case Activity::ExitCode::FAIL:
			return -1001;
		case Activity::ExitCode::NONE:
			return 1000;
		case Activity::ExitCode::SUCCESS:
			return 0;
		case Activity::ExitCode::EXTERNAL_REQUEST:
			return 1004;
		default:
			break;
	}

	return 999; // should never be reached
}

} /* namespace application */
} /* namespace core */
} /* namespace sl */
