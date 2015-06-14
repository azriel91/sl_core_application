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
#include <google/gmock/gmock.h>

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

using ::testing::Return;
using ::testing::InSequence;

namespace sl {
namespace core {
namespace application {

class MockActivity : public Activity {
public:
	MockActivity(std::shared_ptr<sl::core::application::Activity> nextActivity =
			std::shared_ptr<sl::core::application::Activity>()) {
		setNextActivity(nextActivity);
	}
	virtual ~MockActivity() {}

	MOCK_METHOD0(run, ExitCode());
};

class ApplicationTest : public testing::Test {
protected:
	std::shared_ptr<MockActivity> activity;
	std::shared_ptr<MockActivity> activityWithNext;

	virtual void SetUp() {
		activity.reset(new MockActivity());
		activityWithNext.reset(new MockActivity(activity));
	}

	virtual void TearDown() {
	}
};

TEST_F(ApplicationTest, exitsWith_ExitCode1001_WhenNoActivitiesProvided) {
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(1000, application.run());
}

TEST_F(ApplicationTest, exitsWith_ExitCode0_WhenLastActivityEndsSuccessfully) {
	EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::SUCCESS));
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activity);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(0, application.run());
}

TEST_F(ApplicationTest, exitsWith_ExitCodeN1001_WhenLastActivityEndsWithFailure) {
	EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::FAIL));
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activity);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(-1001, application.run());
}

TEST_F(ApplicationTest, exitsWith_ExitCode1000_WhenActivityEndsWithNone) {
	EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::NONE));
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activity);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(1000, application.run());
}

TEST_F(ApplicationTest, exitsWith_ExitCode1002_WhenActivityEndsWith_Stack_ButDoesNotProvideNextActivity) {
	EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::STACK));
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activity);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(1002, application.run());
}

TEST_F(ApplicationTest, exitsWith_ExitCode1003_WhenActivityEndsWith_Replace_ButDoesNotProvideNextActivity) {
	EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::REPLACE));
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activity);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(1003, application.run());
}

TEST_F(ApplicationTest, exitsWith_ExitCode1004_WhenLastActivityEndsDueToExternalRequest) {
	EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::EXTERNAL_REQUEST));
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activity);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(1004, application.run());
}

TEST_F(ApplicationTest, stacksNextActivityAndReturnsToPreviousActivity) {
	{
		InSequence sequence;
		EXPECT_CALL(*this->activityWithNext, run()).WillOnce(Return(Activity::ExitCode::STACK));
		EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::SUCCESS));
		EXPECT_CALL(*this->activityWithNext, run()).WillOnce(Return(Activity::ExitCode::SUCCESS));
	}
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activityWithNext);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(0, application.run());
}

TEST_F(ApplicationTest, replacesActivityWithNextActivity) {
	EXPECT_CALL(*this->activityWithNext, run()).WillOnce(Return(Activity::ExitCode::REPLACE));
	EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::SUCCESS));
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activityWithNext);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(0, application.run());
}

TEST_F(ApplicationTest, runsPreviousActivityWhenActivityEndsDueToExternalRequest) {
	{
		InSequence sequence;
		EXPECT_CALL(*this->activity, run()).WillOnce(Return(Activity::ExitCode::EXTERNAL_REQUEST));
		EXPECT_CALL(*this->activityWithNext, run()).WillOnce(Return(Activity::ExitCode::SUCCESS));
	}
	std::shared_ptr<sl::core::application::ActivityStack> activityStack(new sl::core::application::ActivityStack());
	activityStack->push(this->activityWithNext);
	activityStack->push(this->activity);
	sl::core::application::Application application(activityStack);

	EXPECT_EQ(0, application.run());
}

} /* namespace application */
} /* namespace core */
} /* namespace sl */

int main(int argc, char **argv) {
	::testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
