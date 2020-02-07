#pragma once

#include <memory>
#include <thread>
#include <future>
#include <functional>
#include <queue>

#include "Types.h"
#include "CommandBuffer.h"

namespace Safaga
{
	namespace Render
	{
		class Device;

		//Thread Safe, multithread producer, multithread consumer
		class CommandQueue
		{
		public:
			std::shared_ptr<CommandBuffer> makeCommandBuffer();

			void push(std::shared_ptr<CommandBuffer> _commandBuffer);
			std::shared_ptr<CommandBuffer> pop();

		private:
			std::mutex                                  mAccess;
			std::condition_variable                     mConditionVariable;
			std::queue<std::shared_ptr<CommandBuffer>>  mQueue;

			CommandQueue() = default;

			friend class Device;
			friend class std::_Ref_count_obj<CommandQueue>;
		};
	}
}
