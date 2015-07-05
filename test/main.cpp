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

#include <memory>
#include <stack>
#include <string>
#include <google/gtest/gtest.h>

#include "TestConfig.h"

#ifdef US_BUILD_SHARED_LIBS
	#include <azriel/usbundleloader/BundleLoader.h>
#else
	#include <azriel/cppmicroservices/core/include/usModuleImport.h>
	US_IMPORT_MODULE(CppMicroServices)
	US_IMPORT_MODULE(sl_core_application)
#endif

#include "../Activity.h"
#include "../Application.h"

#ifdef US_PLATFORM_WINDOWS
	static const std::string LIB_PATH = US_RUNTIME_OUTPUT_DIRECTORY;
#else
	static const std::string LIB_PATH = US_LIBRARY_OUTPUT_DIRECTORY;
#endif

namespace sl {
namespace core {
namespace application {

namespace ns = sl::core::application;

TEST(Application, exitsWhenNoActivitiesProvided) {
	std::shared_ptr<ns::ActivityStack> activityStack(new ns::ActivityStack());

	auto application = new ns::Application(activityStack);
	delete application;
}

} /* namespace application */
} /* namespace core */
} /* namespace sl */

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
