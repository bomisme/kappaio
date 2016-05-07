//====================================================================================
//     The MIT License (MIT)
//
//     Copyright (c) 2011 Kapparock LLC
//
//     Permission is hereby granted, free of charge, to any person obtaining a copy
//     of this software and associated documentation files (the "Software"), to deal
//     in the Software without restriction, including without limitation the rights
//     to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//     copies of the Software, and to permit persons to whom the Software is
//     furnished to do so, subject to the following conditions:
//
//     The above copyright notice and this permission notice shall be included in
//     all copies or substantial portions of the Software.
//
//     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//     IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//     AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//     LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//     THE SOFTWARE.
//====================================================================================
#include "notification.h"
#include <map>
#include <string>
#include <functional>

namespace kapi
{
//	namespace Notification
//	{
//		std::map<std::string, std::function<void()>> _events;
//		std::map<std::string, std::map<std::string, std::function<void()>>> __events;
//		void trigger(std::string event)
//		{
//			if (_events.count(event) > 0) _events[event]();
//		}
//		void bind(std::string event, std::function<void()> handler)
//		{
//			_events[event] = handler;
//		}
//		void trigger(std::string service, std::string uri)
//		{
//			if (__events.count(service) > 0)
//			{
//				if (__events[service].count(uri) > 0) __events[service][uri]();
//			}
//		}
//		void bind(std::string service, std::string uri, std::function<void()> handler)
//		{
//			__events[service][uri] = handler;
//		}
//	}


	namespace notify
	{
		std::map<string,map<string,Handlers>> __handlers_repository;

		Handlers& __container(const string& e, const string& u)
		{
			return __handlers_repository[e][u];
		}
	} // namespace Event
}
