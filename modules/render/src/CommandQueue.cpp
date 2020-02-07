#include "CommandQueue.h"

namespace Safaga
{
	namespace Render
	{
		std::shared_ptr<CommandBuffer> CommandQueue::makeCommandBuffer()
		{
			return std::make_shared<CommandBuffer>();
		}

		void CommandQueue::push(std::shared_ptr<CommandBuffer> _commandBuffer)
		{
			std::unique_lock<std::mutex> mlock(mAccess);
			mQueue.push(_commandBuffer);
			mlock.unlock();
			mConditionVariable.notify_one();
		}

		std::shared_ptr<CommandBuffer> CommandQueue::pop()
		{
			std::unique_lock<std::mutex> mlock(mAccess);
			while (mQueue.empty())
			{
				mConditionVariable.wait(mlock);
			}
			auto commandBuffer = mQueue.front();
			mQueue.pop();
			return commandBuffer;
		}
	}
}
