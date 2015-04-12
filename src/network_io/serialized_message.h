#pragma once

#include "remote_command.pb.h"

namespace network_io
{

	class serialized_message 
	{
	public :
		serialized_message(const char* buffer, const int& buffer_size)
			: buffer_(buffer), buffer_size_(buffer_size) { }

		const int size() const {
			return buffer_size_;
		}

		const char* buffer() const {
			return buffer_;
		}

	private:
		int buffer_size_;
		const char* buffer_;
	};

	Request build_request(const serialized_message& message);
	serialized_message serialize_response(const Response& response);
	Response clear_response(Response& response, const std::string& message);

}
