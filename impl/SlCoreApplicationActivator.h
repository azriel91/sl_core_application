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

#ifndef __SL_CORE_APPLICATION_IMPL__SLCOREAPPLICATIONACTIVATOR_H
#define __SL_CORE_APPLICATION_IMPL__SLCOREAPPLICATIONACTIVATOR_H

//! [Activator]
#include <azriel/cppmicroservices/core/include/usModuleActivator.h>
#include <azriel/cppmicroservices/core/include/usModuleContext.h>

US_USE_NAMESPACE

namespace sl {
namespace core {
namespace application {
namespace impl {

class SlCoreApplicationActivator : public ModuleActivator {
private:
	void Load(ModuleContext* context);
	void Unload(ModuleContext* context);
};

} /* namespace impl */
} /* namespace application */
} /* namespace core */
} /* namespace sl */

US_EXPORT_MODULE_ACTIVATOR(sl::core::application::impl::SlCoreApplicationActivator)

//! [Activator]

#endif /* __SL_CORE_APPLICATION_IMPL__SLCOREAPPLICATIONACTIVATOR_H */
