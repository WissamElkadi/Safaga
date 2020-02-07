#pragma once

#include <memory>

#include <DataStructure.h>

#include "Scene.h"

namespace Safaga
{
	namespace Core
	{
		class View
		{
		public:
			View() = default;
			View(std::shared_ptr<Scene> _scene);

		private:
			std::shared_ptr<Scene> mScene;
			Color                  mBackgroundColor;
			size_t                 mFPS;
		};
	}
}
