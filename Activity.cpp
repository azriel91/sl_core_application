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

#include "Activity.h"

namespace sl {
namespace core {
namespace application {

Activity::Activity() :
		nextActivity(std::shared_ptr<sl::core::application::Activity>()) {
}

Activity::~Activity() {
}

std::shared_ptr<sl::core::application::Activity> Activity::getNextActivity() const {
	return this->nextActivity;
}

void Activity::setNextActivity(std::shared_ptr<sl::core::application::Activity> nextActivity) {
	this->nextActivity = nextActivity;
}

} /* namespace application */
} /* namespace core */
} /* namespace sl */
