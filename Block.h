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

#ifndef __SL_CORE_APPLICATION__BLOCK_H
#define __SL_CORE_APPLICATION__BLOCK_H

#include <usGlobalConfig.h>

#ifdef BUILD_SHARED_LIBS
	#ifdef azriel_sl_core_application_EXPORTS
		#define SL_CORE_APPLICATION_EXPORT US_ABI_EXPORT
	#else
		#define SL_CORE_APPLICATION_EXPORT US_ABI_IMPORT
	#endif
#else
#define SL_CORE_APPLICATION_EXPORT US_ABI_EXPORT
#endif

#endif /* __SL_CORE_APPLICATION__BLOCK_H */
